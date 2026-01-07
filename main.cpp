#include <iostream>
#include <iomanip>
#include <limits>
#include "MovieDatabase.h"

using namespace std;

// Current rating display style (can be changed by user)
int currentRatingStyle = 0; // 0=bars, 1=blocks, 2=numbers, 3=dots, 4=plus

// Function to clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to display the main menu
void displayMenu() {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              MOVIE DATABASE MENU" << endl;
    cout << string(100, '=') << endl;
    cout << "  1.  View All Movies" << endl;
    cout << "  2.  View Top-Rated Movies" << endl;
    cout << "  3.  View Movies by Language" << endl;
    cout << "  4.  View Latest Movies" << endl;
    cout << "  5.  Search Movie by Name" << endl;
    cout << "  6.  Add New Movie" << endl;
    cout << "  7.  Remove Movie" << endl;
    cout << "  8.  Update Movie Information" << endl;
    cout << "  9.  View Database Statistics" << endl;
    cout << "  10. Change Display Style" << endl;
    cout << "  0.  Exit Program" << endl;
    cout << string(100, '=') << endl;
    cout << "Enter your choice (0-10): ";
}

// Function to change rating display style
void changeDisplayStyle() {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              CHOOSE RATING DISPLAY STYLE" << endl;
    cout << string(100, '=') << endl;
    cout << "\nAvailable styles:" << endl;
    cout << "  1. Stars/Bars      [**********] [*******---]" << endl;
    cout << "  2. Blocks          [##########] [#######...]" << endl;
    cout << "  3. Circles         [oooooooooo] [ooooooo...]" << endl;
    cout << "  4. Plus Signs      [++++++++++] [+++++++   ]" << endl;
    cout << "  5. Numbers Only    9.5/10.0" << endl;
    cout << "\nCurrent style: ";
    
    switch(currentRatingStyle) {
        case 0: cout << "Stars/Bars"; break;
        case 1: cout << "Blocks"; break;
        case 2: cout << "Circles"; break;
        case 3: cout << "Plus Signs"; break;
        case 4: cout << "Numbers Only"; break;
    }
    
    cout << "\n\nEnter new style (1-5): ";
    int choice;
    cin >> choice;
    
    if (choice >= 1 && choice <= 5) {
        currentRatingStyle = choice - 1;
        cout << "\n? Display style updated!" << endl;
    } else {
        cout << "\n? Invalid choice!" << endl;
    }
}

// Function to add a new movie
void addNewMovie(MovieDatabase& database) {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              ADD NEW MOVIE" << endl;
    cout << string(100, '=') << endl;
    
    if (database.isFull()) {
        cout << "\nError: Database is full! Cannot add more movies." << endl;
        return;
    }
    
    string name, language;
    int year;
    double rating;
    int id = database.getNextId();
    
    clearInput();
    
    cout << "\nEnter movie name: ";
    getline(cin, name);
    
    cout << "Enter release year: ";
    cin >> year;
    
    clearInput();
    
    cout << "Enter language: ";
    getline(cin, language);
    
    cout << "Enter rating (1.0-10.0): ";
    cin >> rating;
    
    Movie newMovie(name, id, year, language, rating);
    
    if (database.addMovie(newMovie)) {
        cout << "\n" << string(60, '=') << endl;
        cout << "  SUCCESS! Movie added to database" << endl;
        cout << string(60, '=') << endl;
        cout << "  Movie ID: " << id << endl;
        cout << "  Name: " << name << endl;
        cout << "  Rating: ";
        
        // Show rating in current style
        cout << "[";
        int stars = (int)rating;
        switch(currentRatingStyle) {
            case 0: for (int i = 0; i < stars; i++) cout << "*"; for (int i = stars; i < 10; i++) cout << "-"; break;
            case 1: for (int i = 0; i < stars; i++) cout << "#"; for (int i = stars; i < 10; i++) cout << "."; break;
            case 2: for (int i = 0; i < stars; i++) cout << "o"; for (int i = stars; i < 10; i++) cout << "."; break;
            case 3: for (int i = 0; i < stars; i++) cout << "+"; for (int i = stars; i < 10; i++) cout << " "; break;
            case 4: cout << fixed << setprecision(1) << rating << "/10.0"; break;
        }
        if (currentRatingStyle != 4) {
            cout << "] " << fixed << setprecision(1) << rating << "/10";
        }
        cout << endl;
        cout << string(60, '=') << endl;
    } else {
        cout << "\n? Failed to add movie." << endl;
    }
}

// Function to remove a movie
void removeMovie(MovieDatabase& database) {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              REMOVE MOVIE" << endl;
    cout << string(100, '=') << endl;
    
    int id;
    cout << "\nEnter the ID of the movie to remove: ";
    cin >> id;
    
    if (database.removeMovie(id)) {
        cout << "\n" << string(60, '=') << endl;
        cout << "  SUCCESS! Movie removed from database" << endl;
        cout << "  Movie ID: " << id << endl;
        cout << string(60, '=') << endl;
    } else {
        cout << "\n? Movie not found with ID: " << id << endl;
    }
}

// Function to update a movie
void updateMovie(MovieDatabase& database) {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              UPDATE MOVIE" << endl;
    cout << string(100, '=') << endl;
    
    int id;
    cout << "\nEnter the ID of the movie to update: ";
    cin >> id;
    
    Movie* movie = database.findMovieById(id);
    if (movie == nullptr) {
        cout << "\n? Movie not found with ID: " << id << endl;
        return;
    }
    
    // Display current information
    cout << "\n" << string(60, '-') << endl;
    cout << "Current movie information:" << endl;
    cout << string(60, '-') << endl;
    cout << "Name: " << movie->getName() << endl;
    cout << "Year: " << movie->getYear() << endl;
    cout << "Language: " << movie->getLanguage() << endl;
    cout << fixed << setprecision(1);
    cout << "Rating: " << movie->getRating() << "/10" << endl;
    cout << string(60, '-') << endl;
    
    // Get new information
    string name, language;
    int year;
    double rating;
    
    clearInput();
    
    cout << "\nEnter new movie name (or press Enter to keep current): ";
    getline(cin, name);
    if (name.empty()) name = movie->getName();
    
    cout << "Enter new release year (or 0 to keep current): ";
    cin >> year;
    if (year == 0) year = movie->getYear();
    
    clearInput();
    
    cout << "Enter new language (or press Enter to keep current): ";
    getline(cin, language);
    if (language.empty()) language = movie->getLanguage();
    
    cout << "Enter new rating 1.0-10.0 (or 0 to keep current): ";
    cin >> rating;
    if (rating == 0.0) rating = movie->getRating();
    
    if (database.updateMovie(id, name, year, language, rating)) {
        cout << "\n" << string(60, '=') << endl;
        cout << "  SUCCESS! Movie updated" << endl;
        cout << string(60, '=') << endl;
    } else {
        cout << "\n? Failed to update movie." << endl;
    }
}

// Function to search movies by name
void searchMovies(MovieDatabase& database) {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              SEARCH MOVIES" << endl;
    cout << string(100, '=') << endl;
    
    string searchTerm;
    clearInput();
    
    cout << "\nEnter movie name to search: ";
    getline(cin, searchTerm);
    
    database.searchMovieByName(searchTerm);
}

// Function to view movies by language
void viewByLanguage(MovieDatabase& database) {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              FILTER BY LANGUAGE" << endl;
    cout << string(100, '=') << endl;
    
    // Show available languages
    database.displayAvailableLanguages();
    
    string language;
    clearInput();
    
    cout << "\nEnter language name (case-insensitive): ";
    getline(cin, language);
    
    // Handle empty input
    if (language.empty()) {
        cout << "\n? No language entered!" << endl;
        return;
    }
    
    database.displayMoviesByLanguage(language);
}

// Function to display database statistics
void displayStatistics(MovieDatabase& database) {
    cout << "\n" << string(100, '=') << endl;
    cout << "                              DATABASE STATISTICS" << endl;
    cout << string(100, '=') << endl;
    
    int total = database.getMovieCount();
    int capacity = 100;
    int available = capacity - total;
    float percentFull = (total * 100.0) / capacity;
    
    cout << "\n  Total Movies........: " << total << endl;
    cout << "  Database Capacity...: " << capacity << endl;
    cout << "  Available Slots.....: " << available << endl;
    cout << "  Usage Percentage....: " << percentFull << "%" << endl;
    cout << "  Database Status.....: " << (database.isFull() ? "FULL" : "Available") << endl;
    
    // Draw progress bar
    cout << "\n  Capacity Usage: [";

    int bars = (int)(percentFull / 5);
    for (int i = 0; i < bars; i++) cout << "#";
    for (int i = bars; i < 20; i++) cout << "-";
    cout << "] " << percentFull << "%" << endl;
    
    cout << "\n" << string(100, '=') << endl;
}

// Main program entry point
int main() {
    // Create a database to store movies
    MovieDatabase database;
    
    // Load the 20 sample movies
    database.initializeSampleData();
    
    // Program header
    cout << "\n";
    cout << string(100, '=') << endl;
    cout << string(100, '=') << endl;
    cout << "                      MOVIE DATABASE MANAGEMENT SYSTEM" << endl;
    cout << "                 Mastering Object-Oriented Programming in C++" << endl;
    cout << string(100, '=') << endl;
    cout << string(100, '=') << endl;
    
    cout << "\nWelcome! The database has been initialized with " << database.getMovieCount() << " movies." << endl;
    cout << "Tip: Try option 10 to change the rating display style!" << endl;
    
    // Main program loop
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        cin >> choice;
        
        // Check for input errors
        if (cin.fail()) {
            cout << "\n? Invalid input! Please enter a number between 0 and 10." << endl;
            clearInput();
            continue;
        }
        
        switch (choice) {
            case 1:
                database.displayAllMovies();
                break;
                
            case 2:
                database.displayTopRatedMovies();
                break;
                
            case 3:
                viewByLanguage(database);
                break;
                
            case 4:
                database.displayLatestMovies();
                break;
                
            case 5:
                searchMovies(database);
                break;
                
            case 6:
                addNewMovie(database);
                break;
                
            case 7:
                removeMovie(database);
                break;
                
            case 8:
                updateMovie(database);
                break;
                
            case 9:
                displayStatistics(database);
                break;
                
            case 10:
                changeDisplayStyle();
                break;
                
            case 0:
                cout << "\n" << string(100, '=') << endl;
                cout << "                      THANK YOU FOR USING THE SYSTEM!" << endl;
                cout << string(100, '=') << endl;
                cout << "\nOOP Concepts Demonstrated:" << endl;
                cout << "  • Encapsulation: Private data with public methods" << endl;
                cout << "  • Abstraction: Complex operations hidden behind simple interfaces" << endl;
                cout << "  • Composition: MovieDatabase contains Movie objects" << endl;
                cout << "  • Data Validation: Input checking and error handling" << endl;
                cout << "  • User Interaction: Menu-driven interface with multiple display styles" << endl;
                cout << "\nTotal Movies in Database: " << database.getMovieCount() << endl;
                cout << "\nProgram terminated successfully." << endl;
                cout << string(100, '=') << endl;
                running = false;
                break;
                
            default:
                cout << "\n? Invalid choice! Please enter a number between 0 and 10." << endl;
                break;
        }
        
        // Pause before showing menu again (except on exit)
        if (running) {
            cout << "\nPress Enter to continue...";
            clearInput();
            cin.get();
        }
    }
    
    return 0;
}
