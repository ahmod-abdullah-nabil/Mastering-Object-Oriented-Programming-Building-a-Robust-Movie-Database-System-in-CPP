#include "MovieDatabase.h"
#include <iostream>
#include <iomanip>
#include <string>

// Constructor
MovieDatabase::MovieDatabase() : movieCount(0) {}

// Add a movie to the database
bool MovieDatabase::addMovie(const Movie& movie) {
    if (movieCount < MAX_MOVIES) {
        movies[movieCount] = movie;
        movieCount++;
        return true;
    }
    return false;
}

// Display all movies with formatted header
void MovieDatabase::displayAllMovies() const {
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
    std::cout << std::string(100, '=') << std::endl;
}

// Find and display top-rated movies
void MovieDatabase::displayTopRatedMovies() const {
    // Find maximum rating
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
    
    // Display all movies with maximum rating
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

// Find and display movies in a specific language
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
    }
    
    std::cout << std::string(100, '-') << std::endl;
    std::cout << "Total movies in " << language << ": " << count << std::endl;
    std::cout << std::string(100, '=') << std::endl;
}

// Find and display the latest movie(s)
void MovieDatabase::displayLatestMovies() const {
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
    
    // Display all movies from the latest year
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

// Get the total movie count
int MovieDatabase::getMovieCount() const {
    return movieCount;
}

// Initialize database with 20 critically acclaimed and diverse movies
void MovieDatabase::initializeSampleData() {
    // Mix of classic and modern cinema from different languages and genres
    addMovie(Movie("The Shawshank Redemption", 1, 1994, "English", 5));
    addMovie(Movie("The Godfather", 2, 1972, "English", 5));
    addMovie(Movie("Amélie (Le Fabuleux Destin d'Amélie Poulain)", 3, 2001, "French", 5));
    addMovie(Movie("Parasite (Gisaengchung)", 4, 2019, "Korean", 5));
    addMovie(Movie("Spirited Away (Sen to Chihiro no Kamikakushi)", 5, 2001, "Japanese", 5));
    addMovie(Movie("The Dark Knight", 6, 2008, "English", 5));
    addMovie(Movie("La Haine", 7, 1995, "French", 4));
    addMovie(Movie("Inception", 8, 2010, "English", 5));
    addMovie(Movie("Intouchables", 9, 2011, "French", 4));
    addMovie(Movie("Cinema Paradiso (Nuovo Cinema Paradiso)", 10, 1988, "Italian", 5));
    addMovie(Movie("The Departed", 11, 2006, "English", 4));
    addMovie(Movie("Interstellar", 12, 2014, "English", 5));
    addMovie(Movie("La Vie en Rose (La Môme)", 13, 2007, "French", 4));
    addMovie(Movie("Eternal Sunshine of the Spotless Mind", 14, 2004, "English", 5));
    addMovie(Movie("Pan's Labyrinth (El Laberinto del Fauno)", 15, 2006, "Spanish", 5));
    addMovie(Movie("Dune: Part Two", 16, 2024, "English", 5));
    addMovie(Movie("Le Samouraï", 17, 1967, "French", 4));
    addMovie(Movie("City of God (Cidade de Deus)", 18, 2002, "Portuguese", 5));
    addMovie(Movie("Oppenheimer", 19, 2023, "English", 5));
    addMovie(Movie("Everything Everywhere All at Once", 20, 2022, "English", 5));
}
