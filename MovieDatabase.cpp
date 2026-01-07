#include "MovieDatabase.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

// Initialize empty database
MovieDatabase::MovieDatabase() : movieCount(0) {}

// Try to add a movie if there's space
bool MovieDatabase::addMovie(const Movie& movie) {
    if (movieCount < MAX_MOVIES) {
        movies[movieCount] = movie;
        movieCount++;
        return true;
    }
    return false;
}

// Remove a movie by its ID
bool MovieDatabase::removeMovie(int id) {
    // Find the movie with the given ID
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getId() == id) {
            // Shift all movies after this one to the left
            for (int j = i; j < movieCount - 1; j++) {
                movies[j] = movies[j + 1];
            }
            movieCount--;
            return true;
        }
    }
    return false; // Movie not found
}

// Update movie information
bool MovieDatabase::updateMovie(int id, const std::string& name, int year, const std::string& language, double rating) {
    Movie* movie = findMovieById(id);
    if (movie != nullptr) {
        movie->setName(name);
        movie->setYear(year);
        movie->setLanguage(language);
        movie->setRating(rating);
        return true;
    }
    return false;
}

// Find a movie by ID and return pointer to it
Movie* MovieDatabase::findMovieById(int id) {
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getId() == id) {
            return &movies[i];
        }
    }
    return nullptr; // Not found
}

// Display all movies with a nice table format
void MovieDatabase::displayAllMovies() const {
    if (movieCount == 0) {
        std::cout << "\nThe database is empty!" << std::endl;
        return;
    }
    
    std::cout << "\n" << std::string(100, '=') << std::endl;
    std::cout << "                           COMPLETE MOVIE DATABASE" << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(50) << "Movie Name" 
              << std::setw(6) << "Year" 
              << std::setw(15) << "Language" 
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    for (int i = 0; i < movieCount; i++) {
        movies[i].displayInfo();
    }
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total movies: " << movieCount << " | Capacity: " << MAX_MOVIES << " | Available: " << (MAX_MOVIES - movieCount) << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Find the highest rating and display all movies with that rating
void MovieDatabase::displayTopRatedMovies() const {
    if (movieCount == 0) {
        std::cout << "\nThe database is empty!" << std::endl;
        return;
    }
    
    // First loop: find the maximum rating
    int maxRating = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getRating() > maxRating) {
            maxRating = movies[i].getRating();
        }
    }
    
    std::cout << "\n" << std::string(100, '=') << std::endl;
    std::cout << "                           TOP-RATED MOVIE(S) [Rating: " << maxRating << "/5]" << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(50) << "Movie Name" 
              << std::setw(6) << "Year" 
              << std::setw(15) << "Language" 
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    // Second loop: display all movies that have the max rating
    int count = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getRating() == maxRating) {
            movies[i].displayInfo();
            count++;
        }
    }
    
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total top-rated movies: " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Add a method to get all unique languages
void MovieDatabase::displayAvailableLanguages() const {
    std::cout << "\nAvailable languages in database:" << std::endl;
    
    // Count movies by language
    int englishCount = 0, frenchCount = 0, koreanCount = 0, japaneseCount = 0;
    int italianCount = 0, spanishCount = 0, portugueseCount = 0;
    
    for (int i = 0; i < movieCount; i++) {
        std::string lang = movies[i].getLanguage();
        std::transform(lang.begin(), lang.end(), lang.begin(), ::tolower);
        
        if (lang == "english") englishCount++;
        else if (lang == "french") frenchCount++;
        else if (lang == "korean") koreanCount++;
        else if (lang == "japanese") japaneseCount++;
        else if (lang == "italian") italianCount++;
        else if (lang == "spanish") spanishCount++;
        else if (lang == "portuguese") portugueseCount++;
    }
    
    std::cout << "  1. English     - " << std::setw(2) << englishCount << " movies" << std::endl;
    std::cout << "  2. French      - " << std::setw(2) << frenchCount << " movies" << std::endl;
    std::cout << "  3. Korean      - " << std::setw(2) << koreanCount << " movies" << std::endl;
    std::cout << "  4. Japanese    - " << std::setw(2) << japaneseCount << " movies" << std::endl;
    std::cout << "  5. Italian     - " << std::setw(2) << italianCount << " movies" << std::endl;
    std::cout << "  6. Spanish     - " << std::setw(2) << spanishCount << " movies" << std::endl;
    std::cout << "  7. Portuguese  - " << std::setw(2) << portugueseCount << " movies" << std::endl;
    
    std::cout << "\n  Total: " << movieCount << " movies across 7 languages" << std::endl;
}

// Filter and display movies by language (case-insensitive)
void MovieDatabase::displayMoviesByLanguage(const std::string& language) const {
    std::cout << "\n" << std::string(100, '=') << std::endl;
    std::cout << "                           MOVIES IN " << language << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(50) << "Movie Name" 
              << std::setw(6) << "Year" 
              << std::setw(15) << "Language" 
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    int count = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].isLanguage(language)) {
            movies[i].displayInfo();
            count++;
        }
    }
    
    if (count == 0) {
        std::cout << "No movies found in " << language << std::endl;
        std::cout << "\nTip: Language names are case-insensitive (e.g., 'english', 'ENGLISH', 'English' all work)" << std::endl;
        displayAvailableLanguages();
    }
    
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total movies in " << language << ": " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Find and display the latest movies by year
void MovieDatabase::displayLatestMovies() const {
    if (movieCount == 0) {
        std::cout << "\nThe database is empty!" << std::endl;
        return;
    }
    
    // Find the most recent year
    int latestYear = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getYear() > latestYear) {
            latestYear = movies[i].getYear();
        }
    }
    
    std::cout << "\n" << std::string(100, '=') << std::endl;
    std::cout << "                           LATEST MOVIE(S) [Year: " << latestYear << "]" << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(50) << "Movie Name" 
              << std::setw(6) << "Year" 
              << std::setw(15) << "Language" 
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    // Display all movies from that year
    int count = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getYear() == latestYear) {
            movies[i].displayInfo();
            count++;
        }
    }
    
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total latest movies: " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Search for movies by name (partial match, case-insensitive)
void MovieDatabase::searchMovieByName(const std::string& searchTerm) const {
    std::cout << "\n" << std::string(100, '=') << std::endl;
    std::cout << "                           SEARCH RESULTS FOR: \"" << searchTerm << "\"" << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(50) << "Movie Name" 
              << std::setw(6) << "Year" 
              << std::setw(15) << "Language" 
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;
    
    int count = 0;
    std::string lowerSearchTerm = searchTerm;
    std::transform(lowerSearchTerm.begin(), lowerSearchTerm.end(), lowerSearchTerm.begin(), ::tolower);
    
    for (int i = 0; i < movieCount; i++) {
        std::string movieName = movies[i].getName();
        std::transform(movieName.begin(), movieName.end(), movieName.begin(), ::tolower);
        
        // Check if movie name contains the search term
        if (movieName.find(lowerSearchTerm) != std::string::npos) {
            movies[i].displayInfo();
            count++;
        }
    }
    
    if (count == 0) {
        std::cout << "No movies found matching \"" << searchTerm << "\"" << std::endl;
        std::cout << "\nSearch Tips:" << std::endl;
        std::cout << "  • Search is case-insensitive ('inception', 'INCEPTION', 'Inception' all work)" << std::endl;
        std::cout << "  • Partial names work (search 'lord' finds 'Lord of the Rings')" << std::endl;
        std::cout << "  • Try different keywords or spellings" << std::endl;
        std::cout << "\nExamples: 'godfather', 'dark knight', 'spirited', 'parasite'" << std::endl;
    }
    
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total matches: " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Return how many movies are in the database
int MovieDatabase::getMovieCount() const {
    return movieCount;
}

// Get the next available ID
int MovieDatabase::getNextId() const {
    int maxId = 0;
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].getId() > maxId) {
            maxId = movies[i].getId();
        }
    }
    return maxId + 1;
}

// Check if database is full
bool MovieDatabase::isFull() const {
    return movieCount >= MAX_MOVIES;
}

// Load 50 movies into the database (mix of different languages and years)
void MovieDatabase::initializeSampleData() {
    // ENGLISH MOVIES (15 movies)
    addMovie(Movie("The Shawshank Redemption", 1, 1994, "English", 9.3));
    addMovie(Movie("The Godfather", 2, 1972, "English", 9.2));
    addMovie(Movie("The Dark Knight", 3, 2008, "English", 9.0));
    addMovie(Movie("Inception", 4, 2010, "English", 8.8));
    addMovie(Movie("Interstellar", 5, 2014, "English", 8.7));
    addMovie(Movie("The Matrix", 6, 1999, "English", 8.7));
    addMovie(Movie("Forrest Gump", 7, 1994, "English", 8.8));
    addMovie(Movie("Pulp Fiction", 8, 1994, "English", 8.9));
    addMovie(Movie("The Lord of the Rings: The Return of the King", 9, 2003, "English", 9.0));
    addMovie(Movie("Fight Club", 10, 1999, "English", 8.8));
    addMovie(Movie("Dune: Part Two", 11, 2024, "English", 8.6));
    addMovie(Movie("The Departed", 12, 2006, "English", 8.5));
    addMovie(Movie("Oppenheimer", 13, 2023, "English", 8.4));
    addMovie(Movie("Eternal Sunshine of the Spotless Mind", 14, 2004, "English", 8.3));
    addMovie(Movie("Everything Everywhere All at Once", 15, 2022, "English", 7.8));
    
    // FRENCH MOVIES (8 movies)
    addMovie(Movie("Intouchables", 16, 2011, "French", 8.5));
    addMovie(Movie("Amélie (Le Fabuleux Destin d'Amélie Poulain)", 17, 2001, "French", 8.3));
    addMovie(Movie("La Haine", 18, 1995, "French", 8.1));
    addMovie(Movie("Le Samouraï", 19, 1967, "French", 8.1));
    addMovie(Movie("La Vie en Rose (La Môme)", 20, 2007, "French", 7.6));
    addMovie(Movie("The 400 Blows (Les Quatre Cents Coups)", 21, 1959, "French", 8.1));
    addMovie(Movie("Portrait of a Lady on Fire", 22, 2019, "French", 8.1));
    addMovie(Movie("A Prophet (Un Prophète)", 23, 2009, "French", 7.9));
    
    // KOREAN MOVIES (6 movies)
    addMovie(Movie("Parasite (Gisaengchung)", 24, 2019, "Korean", 8.5));
    addMovie(Movie("Oldboy", 25, 2003, "Korean", 8.4));
    addMovie(Movie("Memories of Murder", 26, 2003, "Korean", 8.1));
    addMovie(Movie("The Handmaiden", 27, 2016, "Korean", 8.1));
    addMovie(Movie("Train to Busan", 28, 2016, "Korean", 7.6));
    addMovie(Movie("Burning", 29, 2018, "Korean", 7.5));
    
    // JAPANESE MOVIES (7 movies)
    addMovie(Movie("Spirited Away (Sen to Chihiro no Kamikakushi)", 30, 2001, "Japanese", 8.6));
    addMovie(Movie("Seven Samurai (Shichinin no Samurai)", 31, 1954, "Japanese", 8.6));
    addMovie(Movie("Your Name (Kimi no Na wa)", 32, 2016, "Japanese", 8.4));
    addMovie(Movie("Grave of the Fireflies (Hotaru no Haka)", 33, 1988, "Japanese", 8.5));
    addMovie(Movie("Princess Mononoke (Mononoke-hime)", 34, 1997, "Japanese", 8.3));
    addMovie(Movie("Rashomon", 35, 1950, "Japanese", 8.2));
    addMovie(Movie("Akira", 36, 1988, "Japanese", 8.0));
    
    // ITALIAN MOVIES (5 movies)
    addMovie(Movie("Cinema Paradiso (Nuovo Cinema Paradiso)", 37, 1988, "Italian", 8.5));
    addMovie(Movie("Life Is Beautiful (La Vita è Bella)", 38, 1997, "Italian", 8.6));
    addMovie(Movie("The Great Beauty (La Grande Bellezza)", 39, 2013, "Italian", 7.7));
    addMovie(Movie("Bicycle Thieves (Ladri di Biciclette)", 40, 1948, "Italian", 8.3));
    addMovie(Movie("8½ (Otto e Mezzo)", 41, 1963, "Italian", 8.0));
    
    // SPANISH MOVIES (5 movies)
    addMovie(Movie("Pan's Labyrinth (El Laberinto del Fauno)", 42, 2006, "Spanish", 8.2));
    addMovie(Movie("The Others (Los Otros)", 43, 2001, "Spanish", 7.6));
    addMovie(Movie("The Secret in Their Eyes (El Secreto de Sus Ojos)", 44, 2009, "Spanish", 8.2));
    addMovie(Movie("All About My Mother (Todo Sobre Mi Madre)", 45, 1999, "Spanish", 7.8));
    addMovie(Movie("Talk to Her (Hable con Ella)", 46, 2002, "Spanish", 7.9));
    
    // PORTUGUESE MOVIES (4 movies)
    addMovie(Movie("City of God (Cidade de Deus)", 47, 2002, "Portuguese", 8.6));
    addMovie(Movie("Elite Squad (Tropa de Elite)", 48, 2007, "Portuguese", 8.0));
    addMovie(Movie("Central Station (Central do Brasil)", 49, 1998, "Portuguese", 8.0));
    addMovie(Movie("The Second Mother (Que Horas Ela Volta?)", 50, 2015, "Portuguese", 7.7));
}

// Save database to file
bool MovieDatabase::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return false;
    }
    
    // Write movie count
    file.write(reinterpret_cast<const char*>(&movieCount), sizeof(movieCount));
    
    // Write each movie
    for (int i = 0; i < movieCount; i++) {
        // Write movie ID
        int id = movies[i].getId();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        // Write movie name (length + string)
        std::string name = movies[i].getName();
        size_t nameLen = name.length();
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);
        
        // Write year
        int year = movies[i].getYear();
        file.write(reinterpret_cast<const char*>(&year), sizeof(year));
        
        // Write language (length + string)
        std::string language = movies[i].getLanguage();
        size_t langLen = language.length();
        file.write(reinterpret_cast<const char*>(&langLen), sizeof(langLen));
        file.write(language.c_str(), langLen);
        
        // Write rating
        double rating = movies[i].getRating();
        file.write(reinterpret_cast<const char*>(&rating), sizeof(rating));
    }
    
    file.close();
    return true;
}

// Load database from file
bool MovieDatabase::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        // File doesn't exist yet - not an error, just use default data
        return false;
    }
    
    // Read movie count
    int count;
    file.read(reinterpret_cast<char*>(&count), sizeof(count));
    
    if (count < 0 || count > MAX_MOVIES) {
        std::cerr << "Error: Invalid movie count in file" << std::endl;
        file.close();
        return false;
    }
    
    // Clear current database
    movieCount = 0;
    
    // Read each movie
    for (int i = 0; i < count; i++) {
        int id, year;
        double rating;
        std::string name, language;
        size_t nameLen, langLen;
        
        // Read movie ID
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        // Read movie name
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        name.resize(nameLen);
        file.read(&name[0], nameLen);
        
        // Read year
        file.read(reinterpret_cast<char*>(&year), sizeof(year));
        
        // Read language
        file.read(reinterpret_cast<char*>(&langLen), sizeof(langLen));
        language.resize(langLen);
        file.read(&language[0], langLen);
        
        // Read rating
        file.read(reinterpret_cast<char*>(&rating), sizeof(rating));
        
        // Add movie to database
        addMovie(Movie(name, id, year, language, rating));
    }
    
    file.close();
    return true;
}
