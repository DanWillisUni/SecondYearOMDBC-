//
// Created by danny on 03/04/2020.
//

#include <algorithm>
#include "MovieDatabase.h"

/**
 * Test harness
 *
 * Constructs a database from the file
 * Sorts the database by release year
 * Displays the size of the database
 * Filters by PG certificate
 * Displays the size of the database to prove the difference
 * Sorts by the title length of the movies
 * Filters by the genre of comedy
 * Displays the size to show the difference in size
 * Sorts by average rating
 * Sorts by duration
 * Prints the longest film
 */
void MovieDatabase::tester(){
    MovieDatabase database = MovieDatabase("films.txt");
    cout << "In from file\n";
    cout << database;
    database.sortByReleaseYear();
    cout << "Sorted by release year\n";
    cout << database;
    cout << "Size: " << database.size() << "\n";
    database = database.filterByCertificate("PG");
    cout << "Filter by Certificate \"PG\"\n";
    cout << "Size: " << database.size() << "\n";
    cout << database;
    database.sortByTitleLength();
    cout << "Sort by title length\n";
    cout << database;
    database = database.filterByGenre("Comedy");
    cout << "filter by genre \"Comedy\"\n";
    cout << "Size: " << database.size() << "\n";
    cout << database;
    database.sortByAverageRating();
    cout << "Sort by average rating\n";
    cout << database;
    database.sortByDuration();
    cout << "Sort by duration\n";
    cout << database;
    cout << "First (longest duration): " << database.get(0) << "\n";
}

/**
 * Constructor
 * Reads in the file line by line if the file exists
 * While there is a line, it constructs a movie object and adds it to the database
 * Closes the file
 * @param fileName, the name of the file to build the database from
 */
MovieDatabase::MovieDatabase(const string& fileName){
    ifstream file(fileName);
    if (file.is_open()){
        string line;
        while (getline(file, line)) {//while there is still another line
            m_db.emplace_back(line);  // construct a new Movie directly into the database
        }
        file.close();
    } else {
        cout << "Error: Unable to find file " << fileName << endl;
    }
}

/**
 * Constructor
 * Creates a new movie database obj by creating a brand new empty vector
 */
MovieDatabase::MovieDatabase():m_db(){
}

/**
 * Modifier
 * Adds a movie to the database
 * @param movie to add
 */
void MovieDatabase::add(const Movie& movie) {
    m_db.push_back(movie); // Add to the end of the database
}

/**
 * Modifier
 * Resizes the database vector to new size
 * @param newSize, the new size to set the vector to
 */
void MovieDatabase::resize(const size_t& newSize){
    m_db.resize(newSize);//resize the new vector
}

/**
 * Accessor
 * Gets the Movie at index in the vector
 * @param index to get
 * @return Movie at index
 */
Movie MovieDatabase::get(int index){
    return m_db.at(index);//a vector has this method at already however the vector is private so needs its own accessor method
}

/**
 * @return The number of elements in the vector
 */
int MovieDatabase::size() const{
    return m_db.size();
}

/**
 * Prints out the movie database overloading the << operator
 * @param out output stream
 * @param movieDatabase movie database
 * @return the output stream full with the movie database
 */
ostream& operator<< (std::ostream &out, const MovieDatabase &movieDatabase) {
    for (auto const& movie : movieDatabase.m_db) {
        out << movie;
    }
    return out; // return std::ostream so we can chain calls to operator<<
}

/**
 * I implemented 4 different methods to sort the database on the 4 different fields
 * For the title length I used a function
 * For the release year I overloaded the < operator in the movie header file
 * For the duration I used a functor
 * For the average rating I used a lambda
 * I wanted to explore different ways of using the std::sort method
 * And the 2 different methods to filter the database
 * For Filtering by genre I used for loop with an if statement
 * For filtering by certificate I used a copy_if function with iterator
 */
namespace {
    /**
     * Comparator function for movie title length
     * The function that returns movie1 boolean that I am using in SortMoviesByTitleLength
     * @param movie1 referance to first movie
     * @param movie2 reverance to second movie
     * @return if the first title is longer than the second
     */
    bool CompareMoviesByTitleLength(const Movie& movie1, const Movie& movie2) {
        return (movie1.getTitle().length() > movie2.getTitle().length());
    }
}

/**
 * The actual sorting function that would be called to sort the database obj
 * This uses the comparator function above as a third parameter in std::sort
 * highest to lowest
 */
void MovieDatabase::sortByTitleLength(){//function
    sort(m_db.begin(),m_db.end(),CompareMoviesByTitleLength);
}

/**
 * Sorting function to sort the movies by year of release
 * Uses a relational comparator override therefore only two parameters in std::sort
 * lowest to highest
 */
void MovieDatabase::sortByReleaseYear(){
    sort(m_db.begin(),m_db.end());
}

/**
 * Sorts the database by duration of the movies
 * Create a functor (i.e. a callable object) that implements operator()
 * Such that when it is called it returns true if it's  first parameter
 * should come before its second parameter
 * Uses a functor
 */
void MovieDatabase::sortByDuration(){
    Movie::CompareMoviesByDuration compareFunctor; //Create a functor that implements operator()
    sort(m_db.begin(),m_db.end(), compareFunctor);// Call sort, passing the functor object as the third parameter
}

/**
 * Unused for the task on blackboard
 * Sorts the database by average rating
 * This uses a lambda to sort
 * highest to lowest
 */
void MovieDatabase::sortByAverageRating() {
    sort(m_db.begin(), m_db.end(),[](const Movie & a, const Movie & b) -> bool {//use an lamda to sort
        return a.getAverageRating() > b.getAverageRating();
    });
}

/**
 * Creates a new movie database of the current size
 * Directly edits the new databases vector of movies and copies the movies in
 * Resizes the new databases vector of movies
 * @param certificateToMatch the certificate that all the movies must have
 * @return a movie database of all the movies that have this certificate
 */
MovieDatabase MovieDatabase::filterByCertificate(const string& certificateToMatch){
    MovieDatabase newDatabase = MovieDatabase();
    newDatabase.resize(m_db.size());
    auto it = copy_if(m_db.begin(), m_db.end(), newDatabase.m_db.begin(), [& certificateToMatch](const Movie& m) {//use copy if and a lambda
        return (m.getCertificate() == Movie::certificateStringToEnum.at(certificateToMatch));//filter by the certificate
    });
    newDatabase.resize(distance(newDatabase.m_db.begin(),it));//resizes the array in the database to the correct size so no empty movies
    return newDatabase;
}

/**
 * Constructs a new movie database obj
 * For each movie in the current database obj
 * If the movie has that genre in
 * Add it to the new database
 * @param genreToMatch the genre to match
 * @return a new database obj of all the films in the desired genre
 */
MovieDatabase MovieDatabase::filterByGenre(const string& genreToMatch){
    MovieDatabase newdb = MovieDatabase();//make a empty new database
    for(auto movie: m_db){
        if (movie.hasGenre(genreToMatch)){//if the movie contains the desired genre
            newdb.add(movie);//add the movie to the database
        }
    }
    return newdb;
}