#include <iostream>
#include "MovieDatabase.h"

using namespace std;

/**
 * @brief Main function demonstrating the Movie Database System
 * 
 * This program showcases Object-Oriented Programming principles:
 * - Encapsulation: Data hiding through private members and public methods
 * - Abstraction: Complex operations hidden behind simple interfaces
 * - Composition: MovieDatabase contains Movie objects
 * - Information Hiding: Implementation details hidden from users
 */
int main() {
    // Create MovieDatabase object
    MovieDatabase database;
    
    // Initialize with 20 carefully selected movies
    database.initializeSampleData();
    
    // Display program header
    cout << "\n";
    cout << string(100, '*') << endl;
    cout << "**                                                                                                  **" << endl;
    cout << "**          MASTERING OBJECT-ORIENTED PROGRAMMING                                                   **" << endl;
    cout << "**          Building a Robust Movie Database System in C++                                          **" << endl;
    cout << "**                                                                                                  **" << endl;
    cout << "**          Demonstrating: Classes, Objects, Encapsulation & Abstraction                            **" << endl;
    cout << "**                                                                                                  **" << endl;
    cout << string(100, '*') << endl;
    
    cout << "\nTotal Movies in Database: " << database.getMovieCount() << endl;
    
    // Requirement 1: Display all movies
    database.displayAllMovies();
    
    // Wait for user input
    cout << "\nPress Enter to view TOP-RATED movies...";
    cin.get();
    
    // Requirement 2: Display top-rated movie(s)
    database.displayTopRatedMovies();
    
    // Wait for user input
    cout << "\nPress Enter to view FRENCH movies...";
    cin.get();
    
    // Requirement 3: Display movies in French
    database.displayMoviesByLanguage("French");
    
    // Wait for user input
    cout << "\nPress Enter to view LATEST movies...";
    cin.get();
    
    // Requirement 4: Display latest movie(s)
    database.displayLatestMovies();
    
    // Program summary
    cout << "\n" << string(100, '*') << endl;
    cout << "**                              OOP CONCEPTS DEMONSTRATED                                           **" << endl;
    cout << string(100, '*') << endl;
    cout << "  1. CLASS DEFINITION     : Movie and MovieDatabase classes with attributes and methods" << endl;
    cout << "  2. ENCAPSULATION        : Private data members with public getter/setter methods" << endl;
    cout << "  3. ABSTRACTION          : Complex search logic hidden behind simple method calls" << endl;
    cout << "  4. COMPOSITION          : MovieDatabase contains an array of Movie objects" << endl;
    cout << "  5. CONSTRUCTORS         : Default and parameterized constructors for initialization" << endl;
    cout << "  6. CONST CORRECTNESS    : Const methods ensure data integrity" << endl;
    cout << "  7. INFORMATION HIDING   : Implementation details hidden from main program" << endl;
    cout << string(100, '*') << endl;
    
    cout << "\nProgram completed successfully. Press Enter to exit...";
    cin.get();
    
    return 0;
}
