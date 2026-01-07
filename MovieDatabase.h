#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H

#include "Movie.h"
#include <vector>

/**
 * @class MovieDatabase
 * @brief Manages a collection of movies and provides search/filter operations
 * 
 * This class demonstrates composition and encapsulation by managing
 * an array of Movie objects and providing various query operations.
 */
class MovieDatabase {
private:
    static const int MAX_MOVIES = 20;
    Movie movies[MAX_MOVIES];
    int movieCount;

public:
    // Constructor
    MovieDatabase();
    
    // Add movie to database
    bool addMovie(const Movie& movie);
    
    // Display all movies
    void displayAllMovies() const;
    
    // Find and display top-rated movie(s)
    void displayTopRatedMovies() const;
    
    // Find and display movies by language
    void displayMoviesByLanguage(const std::string& language) const;
    
    // Find and display the latest movie(s)
    void displayLatestMovies() const;
    
    // Get total number of movies
    int getMovieCount() const;
    
    // Initialize database with sample data
    void initializeSampleData();
};

#endif // MOVIEDATABASE_H
