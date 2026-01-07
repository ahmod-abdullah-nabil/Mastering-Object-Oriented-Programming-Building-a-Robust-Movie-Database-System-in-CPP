#include "Movie.h"
#include <iostream>
#include <iomanip>

// Default constructor initializes everything to default values
Movie::Movie() : name(""), id(0), year(0), language(""), rating(0.0) {}

// Constructor that takes all movie details as parameters
Movie::Movie(const std::string& name, int id, int year, const std::string& language, double rating)
    : name(name), id(id), year(year), language(language), rating(rating) {
    
    // Make sure rating stays between 1.0 and 10.0
    if (this->rating < 1.0) this->rating = 1.0;
    if (this->rating > 10.0) this->rating = 10.0;
    
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
double Movie::getRating() const {
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

// Update the rating (only accepts 1.0-10.0)
void Movie::setRating(double rating) {
    if (rating >= 1.0 && rating <= 10.0) {
        this->rating = rating;
    }
}

// Print movie information in a nice format
void Movie::displayInfo() const {
    std::cout << std::left << std::setw(5) << id 
              << std::setw(50) << name 
              << std::setw(6) << year 
              << std::setw(15) << language;
    
    // Show rating as visual bar (scale to 10)
    std::cout << "[";
    int stars = (int)(rating); // Full stars
    for (int i = 0; i < stars; i++) {
        std::cout << "*";
    }
    for (int i = stars; i < 10; i++) {
        std::cout << "-";
    }
    std::cout << "] " << std::fixed << std::setprecision(1) << rating << "/10" << std::endl;
}

// Helper function to check if this movie is in a particular language (case-insensitive)
bool Movie::isLanguage(const std::string& lang) const {
    std::string lowerLang1 = language;
    std::string lowerLang2 = lang;
    
    // Convert both to lowercase for case-insensitive comparison
    for (size_t i = 0; i < lowerLang1.length(); i++) {
        lowerLang1[i] = tolower(lowerLang1[i]);
    }
    for (size_t i = 0; i < lowerLang2.length(); i++) {
        lowerLang2[i] = tolower(lowerLang2[i]);
    }
    
    return lowerLang1 == lowerLang2;
}
