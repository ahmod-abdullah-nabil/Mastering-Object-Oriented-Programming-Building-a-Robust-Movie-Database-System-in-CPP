#ifndef MOVIE_H
#define MOVIE_H

#include <string>

// Movie class represents a single movie with its properties
class Movie {
private:
    // Movie attributes
    std::string name;
    int id;
    int year;
    std::string language;
    double rating; // Rating from 1.0 to 10.0
    
    // Static variable to hold the current display style
    static int displayStyle; // 0=stars, 1=blocks, 2=circles, 3=plus, 4=numbers
    
public:
    // Constructors
    Movie();
    Movie(const std::string& name, int id, int year, const std::string& language, double rating);
    
    // Getters to access private data
    std::string getName() const;
    int getId() const;
    int getYear() const;
    std::string getLanguage() const;
    double getRating() const;
    
    // Setters to modify private data
    void setName(const std::string& name);
    void setId(int id);
    void setYear(int year);
    void setLanguage(const std::string& language);
    void setRating(double rating);
    
    // Static method to set display style for all movies
    static void setDisplayStyle(int style);
    static int getDisplayStyle();
    
    // Display movie information
    void displayInfo() const;
    
    // Check if movie is in a specific language
    bool isLanguage(const std::string& lang) const;
};

#endif // MOVIE_H
