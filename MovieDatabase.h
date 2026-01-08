#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H

#include "Movie.h"
#include <vector>

// This class manages a collection of movies
class MovieDatabase
{
private:
    static const int MAX_MOVIES = 100000; // Maximum capacity: 100,000 movies!
    Movie *movies;                        // Dynamic array to store all movies (heap allocation)
    int movieCount;                       // Keep track of how many movies we have

public:
    // Constructor
    MovieDatabase();

    // Destructor to free memory
    ~MovieDatabase();

    // Add a movie to the database
    bool addMovie(const Movie &movie);

    // Remove a movie by ID
    bool removeMovie(int id);

    // Update movie information
    bool updateMovie(int id, const std::string &name, int year, const std::string &language, double rating);

    // Find a movie by ID
    Movie *findMovieById(int id);

    // Show all movies in the database
    void displayAllMovies() const;

    // Find and show the highest rated movies
    void displayTopRatedMovies() const;

    // Add a method to get all unique languages
    void displayAvailableLanguages() const;

    // Show movies in a specific language
    void displayMoviesByLanguage(const std::string &language) const;

    // Show the most recent movies
    void displayLatestMovies() const;

    // Search movie by name
    void searchMovieByName(const std::string &searchTerm) const;

    // Get total number of movies
    int getMovieCount() const;

    // Get next available ID
    int getNextId() const;

    // Check if database is full
    bool isFull() const;

    // Get maximum capacity
    int getMaxCapacity() const;

    // File persistence methods
    bool saveToFile(const std::string &filename = "movies.dat") const;
    bool loadFromFile(const std::string &filename = "movies.dat");

    // Load movies from movies.txt file into database
    void initializeSampleData();
};

#endif // MOVIEDATABASE_H
