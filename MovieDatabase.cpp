#include "MovieDatabase.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

// Initialize empty database with dynamic memory allocation
MovieDatabase::MovieDatabase() : movieCount(0)
{
    movies = new Movie[MAX_MOVIES]; // Allocate memory on heap for 100,000 movies
}

// Destructor to free allocated memory
MovieDatabase::~MovieDatabase()
{
    delete[] movies; // Free the dynamically allocated memory
}

// Try to add a movie if there's space
bool MovieDatabase::addMovie(const Movie &movie)
{
    if (movieCount < MAX_MOVIES)
    {
        movies[movieCount] = movie;
        movieCount++;
        return true;
    }
    return false;
}

// Remove a movie by its ID
bool MovieDatabase::removeMovie(int id)
{
    // Find the movie with the given ID
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getId() == id)
        {
            // Shift all movies after this one to the left
            for (int j = i; j < movieCount - 1; j++)
            {
                movies[j] = movies[j + 1];
            }
            movieCount--;
            return true;
        }
    }
    return false; // Movie not found
}

// Update movie information
bool MovieDatabase::updateMovie(int id, const std::string &name, int year, const std::string &language, double rating)
{
    Movie *movie = findMovieById(id);
    if (movie != nullptr)
    {
        movie->setName(name);
        movie->setYear(year);
        movie->setLanguage(language);
        movie->setRating(rating);
        return true;
    }
    return false;
}

// Find a movie by ID and return pointer to it
Movie *MovieDatabase::findMovieById(int id)
{
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getId() == id)
        {
            return &movies[i];
        }
    }
    return nullptr; // Not found
}

// Display all movies with a nice table format
void MovieDatabase::displayAllMovies() const
{
    if (movieCount == 0)
    {
        std::cout << "\nThe database is empty!" << std::endl;
        return;
    }

    std::cout << "\n"
              << std::string(100, '=') << std::endl;
    std::cout << "                           COMPLETE MOVIE DATABASE" << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(50) << "Movie Name"
              << std::setw(6) << "Year"
              << std::setw(15) << "Language"
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    for (int i = 0; i < movieCount; i++)
    {
        movies[i].displayInfo();
    }
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total movies: " << movieCount << " | Capacity: " << MAX_MOVIES << " | Available: " << (MAX_MOVIES - movieCount) << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Find the highest rating and display all movies with that rating
void MovieDatabase::displayTopRatedMovies() const
{
    if (movieCount == 0)
    {
        std::cout << "\nThe database is empty!" << std::endl;
        return;
    }

    // First loop: find the maximum rating
    int maxRating = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getRating() > maxRating)
        {
            maxRating = movies[i].getRating();
        }
    }

    std::cout << "\n"
              << std::string(100, '=') << std::endl;
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
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getRating() == maxRating)
        {
            movies[i].displayInfo();
            count++;
        }
    }

    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total top-rated movies: " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Add a method to get all unique languages
void MovieDatabase::displayAvailableLanguages() const
{
    std::cout << "\nAvailable languages in database:" << std::endl;

    // Count movies by language
    int englishCount = 0, frenchCount = 0, koreanCount = 0, japaneseCount = 0;
    int italianCount = 0, spanishCount = 0, portugueseCount = 0;

    for (int i = 0; i < movieCount; i++)
    {
        std::string lang = movies[i].getLanguage();
        std::transform(lang.begin(), lang.end(), lang.begin(), ::tolower);

        if (lang == "english")
            englishCount++;
        else if (lang == "french")
            frenchCount++;
        else if (lang == "korean")
            koreanCount++;
        else if (lang == "japanese")
            japaneseCount++;
        else if (lang == "italian")
            italianCount++;
        else if (lang == "spanish")
            spanishCount++;
        else if (lang == "portuguese")
            portugueseCount++;
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
void MovieDatabase::displayMoviesByLanguage(const std::string &language) const
{
    std::cout << "\n"
              << std::string(100, '=') << std::endl;
    std::cout << "                           MOVIES IN " << language << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(50) << "Movie Name"
              << std::setw(6) << "Year"
              << std::setw(15) << "Language"
              << "Rating" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    int count = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].isLanguage(language))
        {
            movies[i].displayInfo();
            count++;
        }
    }

    if (count == 0)
    {
        std::cout << "No movies found in " << language << std::endl;
        std::cout << "\nTip: Language names are case-insensitive (e.g., 'english', 'ENGLISH', 'English' all work)" << std::endl;
        displayAvailableLanguages();
    }

    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total movies in " << language << ": " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Find and display the latest movies by year
void MovieDatabase::displayLatestMovies() const
{
    if (movieCount == 0)
    {
        std::cout << "\nThe database is empty!" << std::endl;
        return;
    }

    // Find the most recent year
    int latestYear = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getYear() > latestYear)
        {
            latestYear = movies[i].getYear();
        }
    }

    std::cout << "\n"
              << std::string(100, '=') << std::endl;
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
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getYear() == latestYear)
        {
            movies[i].displayInfo();
            count++;
        }
    }

    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total latest movies: " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Search for movies by name (partial match, case-insensitive)
void MovieDatabase::searchMovieByName(const std::string &searchTerm) const
{
    std::cout << "\n"
              << std::string(100, '=') << std::endl;
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

    for (int i = 0; i < movieCount; i++)
    {
        std::string movieName = movies[i].getName();
        std::transform(movieName.begin(), movieName.end(), movieName.begin(), ::tolower);

        // Check if movie name contains the search term
        if (movieName.find(lowerSearchTerm) != std::string::npos)
        {
            movies[i].displayInfo();
            count++;
        }
    }

    if (count == 0)
    {
        std::cout << "No movies found matching \"" << searchTerm << "\"" << std::endl;
        std::cout << "\nSearch Tips:" << std::endl;
        std::cout << "  � Search is case-insensitive ('inception', 'INCEPTION', 'Inception' all work)" << std::endl;
        std::cout << "  � Partial names work (search 'lord' finds 'Lord of the Rings')" << std::endl;
        std::cout << "  � Try different keywords or spellings" << std::endl;
        std::cout << "\nExamples: 'godfather', 'dark knight', 'spirited', 'parasite'" << std::endl;
    }

    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total matches: " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Return how many movies are in the database
int MovieDatabase::getMovieCount() const
{
    return movieCount;
}

// Get the next available ID
int MovieDatabase::getNextId() const
{
    int maxId = 0;
    for (int i = 0; i < movieCount; i++)
    {
        if (movies[i].getId() > maxId)
        {
            maxId = movies[i].getId();
        }
    }
    return maxId + 1;
}

// Check if database is full
bool MovieDatabase::isFull() const
{
    return movieCount >= MAX_MOVIES;
}

// Get maximum capacity
int MovieDatabase::getMaxCapacity() const
{
    return MAX_MOVIES;
}

// Load movies from text file into the database
void MovieDatabase::initializeSampleData()
{
    std::ifstream file("movies.txt");

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open movies.txt file!" << std::endl;
        std::cerr << "Please ensure movies.txt exists in the program directory." << std::endl;
        return;
    }

    std::string line;
    int loadedCount = 0;

    while (std::getline(file, line))
    {
        // Skip empty lines
        if (line.empty())
        {
            continue;
        }

        // Parse the line: Name|ID|Year|Language|Rating
        std::string name, language;
        int id, year;
        double rating;

        // Find delimiter positions
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);
        size_t pos4 = line.find('|', pos3 + 1);

        if (pos1 == std::string::npos || pos2 == std::string::npos ||
            pos3 == std::string::npos || pos4 == std::string::npos)
        {
            std::cerr << "Warning: Skipping malformed line: " << line << std::endl;
            continue;
        }

        try
        {
            // Extract fields
            name = line.substr(0, pos1);
            id = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            year = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            language = line.substr(pos3 + 1, pos4 - pos3 - 1);
            rating = std::stod(line.substr(pos4 + 1));

            // Add movie to database
            if (addMovie(Movie(name, id, year, language, rating)))
            {
                loadedCount++;
            }
            else
            {
                std::cerr << "Warning: Could not add movie (database full): " << name << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Warning: Error parsing line: " << line << std::endl;
            std::cerr << "  Exception: " << e.what() << std::endl;
        }
    }

    file.close();

    std::cout << "Successfully loaded " << loadedCount << " movies from movies.txt" << std::endl;
}

// Save database to file
bool MovieDatabase::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return false;
    }

    // Write movie count
    file.write(reinterpret_cast<const char *>(&movieCount), sizeof(movieCount));

    // Write each movie
    for (int i = 0; i < movieCount; i++)
    {
        // Write movie ID
        int id = movies[i].getId();
        file.write(reinterpret_cast<const char *>(&id), sizeof(id));

        // Write movie name (length + string)
        std::string name = movies[i].getName();
        size_t nameLen = name.length();
        file.write(reinterpret_cast<const char *>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);

        // Write year
        int year = movies[i].getYear();
        file.write(reinterpret_cast<const char *>(&year), sizeof(year));

        // Write language (length + string)
        std::string language = movies[i].getLanguage();
        size_t langLen = language.length();
        file.write(reinterpret_cast<const char *>(&langLen), sizeof(langLen));
        file.write(language.c_str(), langLen);

        // Write rating
        double rating = movies[i].getRating();
        file.write(reinterpret_cast<const char *>(&rating), sizeof(rating));
    }

    file.close();
    return true;
}

// Load database from file
bool MovieDatabase::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        // File doesn't exist yet - not an error, just use default data
        return false;
    }

    // Read movie count
    int count;
    file.read(reinterpret_cast<char *>(&count), sizeof(count));

    if (count < 0 || count > MAX_MOVIES)
    {
        std::cerr << "Error: Invalid movie count in file" << std::endl;
        file.close();
        return false;
    }

    // Clear current database
    movieCount = 0;

    // Read each movie
    for (int i = 0; i < count; i++)
    {
        int id, year;
        double rating;
        std::string name, language;
        size_t nameLen, langLen;

        // Read movie ID
        file.read(reinterpret_cast<char *>(&id), sizeof(id));

        // Read movie name
        file.read(reinterpret_cast<char *>(&nameLen), sizeof(nameLen));
        name.resize(nameLen);
        file.read(&name[0], nameLen);

        // Read year
        file.read(reinterpret_cast<char *>(&year), sizeof(year));

        // Read language
        file.read(reinterpret_cast<char *>(&langLen), sizeof(langLen));
        language.resize(langLen);
        file.read(&language[0], langLen);

        // Read rating
        file.read(reinterpret_cast<char *>(&rating), sizeof(rating));

        // Add movie to database
        addMovie(Movie(name, id, year, language, rating));
    }

    file.close();
    return true;
}
