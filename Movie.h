#ifndef MOVIE_H
#define MOVIE_H

#include <string>

/**
 * @class Movie
 * @brief Represents a movie with its core attributes
 * 
 * This class encapsulates movie information including name, ID, 
 * release year, language, and rating using proper OOP principles.
 */
class Movie {
private:
    std::string name;
    int id;
    int year;
    std::string language;
    int rating; // Rating scale: 1-5

public:
    // Constructors
    Movie();
    Movie(const std::string& name, int id, int year, const std::string& language, int rating);
    
    // Getters (Accessors)
    std::string getName() const;
    int getId() const;
    int getYear() const;
    std::string getLanguage() const;
    int getRating() const;
    
    // Setters (Mutators)
    void setName(const std::string& name);
    void setId(int id);
    void setYear(int year);
    void setLanguage(const std::string& language);
    void setRating(int rating);
    
    // Utility methods
    void displayInfo() const;
    bool isLanguage(const std::string& lang) const;
};

#endif // MOVIE_H
