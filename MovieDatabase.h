#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H

#include "Movie.h"
#include <vector>

// This class manages a collection of movies
class MovieDatabase {
private:
    static const int MAX_MOVIES = 20;
    Movie movies[MAX_MOVIES]; // Array to store all movies
    int movieCount; // Keep track of how many movies we have

public:
    // Constructor
    MovieDatabase();
    
    // Add a movie to the database
    bool addMovie(const Movie& movie);
    
    // Show all movies in the database
    void displayAllMovies() const;
    
    // Find and show the highest rated movies
    void displayTopRatedMovies() const;
    
    // Show movies in a specific language
    void displayMoviesByLanguage(const std::string& language) const;
    
    // Show the most recent movies
    void displayLatestMovies() const;
    
    // Get total number of movies
    int getMovieCount() const;
    
    // Load the 20 sample movies into database
    void initializeSampleData();
};

#endif // MOVIEDATABASE_H
