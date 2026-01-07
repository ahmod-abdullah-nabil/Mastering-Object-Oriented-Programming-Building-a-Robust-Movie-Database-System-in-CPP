#include "Movie.h"
#include <iostream>
#include <iomanip>

// Default Constructor
Movie::Movie() : name(""), id(0), year(0), language(""), rating(0) {}

// Parameterized Constructor
Movie::Movie(std::string name, int id, int year, std::string language, int rating)
    : name(name), id(id), year(year), language(language), rating(rating) {
    // Validate rating range
    if (this->rating < 1) this->rating = 1;
    if (this->rating > 5) this->rating = 5;
    
    // Validate year (reasonable range: 1888 - current year + 5 for future releases)
    if (this->year < 1888) this->year = 1888;  // First film ever made
    if (this->year > 2030) this->year = 2030;  // Reasonable future limit
    
    // Validate ID (must be positive)
    if (this->id < 0) this->id = 0;
}

// Getters Implementation
std::string Movie::getName() const {
    return name;
}

int Movie::getId() const {
    return id;
}

int Movie::getYear() const {
    return year;
}

std::string Movie::getLanguage() const {
    return language;
}

int Movie::getRating() const {
    return rating;
}

// Setters Implementation
void Movie::setName(const std::string& name) {
    this->name = name;
}

void Movie::setId(int id) {
    this->id = id;
}

void Movie::setYear(int year) {
    this->year = year;
}

void Movie::setLanguage(const std::string& language) {
    this->language = language;
}

void Movie::setRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        this->rating = rating;
    }
}

// Display movie information in a formatted manner
void Movie::displayInfo() const {
    std::cout << std::left << std::setw(5) << id 
              << std::setw(50) << name 
              << std::setw(6) << year 
              << std::setw(15) << language 
              << std::setw(8);
    
    // Display rating with stars
    for (int i = 0; i < rating; i++) {
        std::cout << "?";
    }
    for (int i = rating; i < 5; i++) {
        std::cout << "?";
    }
    std::cout << " (" << rating << "/5)" << std::endl;
}

// Check if movie is in specified language
bool Movie::isLanguage(const std::string& lang) const {
    return language == lang;
}
