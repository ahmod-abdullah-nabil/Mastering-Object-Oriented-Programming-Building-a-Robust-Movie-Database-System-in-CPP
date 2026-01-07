#include <iostream>
#include "MovieDatabase.h"

using namespace std;

int main() {
    // Create a database to store movies
    MovieDatabase database;
    
    // Load the 20 movies
    database.initializeSampleData();
    
    // Program header
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
    
    // Show all movies
    database.displayAllMovies();
    
    cout << "\nPress Enter to view TOP-RATED movies...";
    cin.get();
    
    // Show top-rated movies
    database.displayTopRatedMovies();
    
    cout << "\nPress Enter to view FRENCH movies...";
    cin.get();
    
    // Show French movies
    database.displayMoviesByLanguage("French");
    
    cout << "\nPress Enter to view LATEST movies...";
    cin.get();
    
    // Show latest movies
    database.displayLatestMovies();
    
    // Summary of OOP concepts used
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
