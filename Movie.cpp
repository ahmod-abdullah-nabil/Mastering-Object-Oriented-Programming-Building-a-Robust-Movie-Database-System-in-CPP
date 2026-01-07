#include "Movie.h"
#include <iostream>
#include <iomanip>

// Default constructor initializes everything to default values
Movie::Movie() : name(""), id(0), year(0), language(""), rating(0) {}

// Constructor that takes all movie details as parameters
Movie::Movie(const std::string& name, int id, int year, const std::string& language, int rating)
    : name(name), id(id), year(year), language(language), rating(rating) {
    
    // Make sure rating stays between 1 and 5
    if (this->rating < 1) this->rating = 1;
    if (this->rating > 5) this->rating = 5;
    
    // Validate year to be reasonable (first film was 1888, future limit 2030)
    if (this->year < 1888) this->year = 1888;
    if (this->year > 2030) this->year = 2030;
    
    // ID should not be negative
    if (this->id < 0) this->id = 0;
}

// Return the movie name
std::string Movie::getName() const {
    return name;
}

// Return the movie ID
int Movie::getId() const {
    return id;
}

// Return the release year
int Movie::getYear() const {
    return year;
}

// Return the movie language
std::string Movie::getLanguage() const {
    return language;
}

// Return the rating
int Movie::getRating() const {
    return rating;
}

// Update the movie name
void Movie::setName(const std::string& name) {
    this->name = name;
}

// Update the movie ID
void Movie::setId(int id) {
    this->id = id;
}

// Update the release year
void Movie::setYear(int year) {
    this->year = year;
}

// Update the language
void Movie::setLanguage(const std::string& language) {
    this->language = language;
}

// Update the rating (only accepts 1-5)
void Movie::setRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        this->rating = rating;
    }
}

// Print movie information in a nice format with stars
void Movie::displayInfo() const {
    std::cout << std::left << std::setw(5) << id 
              << std::setw(50) << name 
              << std::setw(6) << year 
              << std::setw(15) << language 
              << std::setw(8);
    
    // Show rating as stars
    for (int i = 0; i < rating; i++) {
        std::cout << "?";
    }
    for (int i = rating; i < 5; i++) {
        std::cout << "?";
    }
    std::cout << " (" << rating << "/5)" << std::endl;
}

// Helper function to check if this movie is in a particular language
bool Movie::isLanguage(const std::string& lang) const {
    return language == lang;
}
