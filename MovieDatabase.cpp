//
// Created by danny on 03/04/2020.
//

#include <algorithm>
#include "MovieDatabase.h"

void MovieDatabase::tester(){
    MovieDatabase database = MovieDatabase("../films.txt");
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
 * reads in the file line by line
 * for each line it constructs a movie object and adds it to the database
 * @param fileName the name of the file to build the database from
 */
MovieDatabase::MovieDatabase(string fileName){
    ifstream file(fileName);
    string line;
    MovieDatabase();//constructs new movie database obj
    while (getline(file, line)) {//while there is still another line
        m_db.emplace_back(line);  // construct a new Movie directly into the database
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
 * @param m movie to add
 */
void MovieDatabase::add(Movie m) {
    m_db.push_back(m); // Add to the end of the database
}
/**
 * Accessor
 * Gets the Movie at index i in the vector
 * @param i index to get
 * @return Movie at index i
 */
Movie MovieDatabase::get(int i){
    return m_db.at(i);//a vector has this method at already however the vector is private so needs its own accessor method
}
/**
 * @return The number of elements in the vector
 */
int MovieDatabase::size() const{
    return m_db.size();
}
/**
 * prints out the movie database overloading the << operator
 * @param out output stream
 * @param md movie database
 * @return the output stream full with the movie database
 */
ostream& operator<< (std::ostream &out, const MovieDatabase &md) {
    for (auto const& m : md.m_db) {
        out << m;
    }
    return out; // return std::ostream so we can chain calls to operator<<
}

/**
 * I implemented 4 different methods to sort the database on the 4 different fields
 * I wanted to explore different ways of using the std::sort method
 */
namespace {
    /**
     * Comparator function for movie title length
     * The function that returns a boolean that I am using in SortMoviesByTitleLength
     * @param a referance to first movie
     * @param b reverance to second movie
     * @return if the first title is longer than the second
     */
    bool CompareMoviesByTitleLength(const Movie& a, const Movie& b) {
        return (a.getTitle().length() > b.getTitle().length());
    }
}
/**
 * The actual sorting function that would be called to sort the database obj
 * This uses the comparator function obove as a third parameter in std::sort
 * highest to lowest
 */
void MovieDatabase::sortByTitleLength(){//function
    sort(m_db.begin(),m_db.end(),CompareMoviesByTitleLength);
}
/**
 * Sorting function to sort the movies by year or release
 * Uses a relational comparator overrride therefore only two parameters in std::sort
 * lowest to highest
 */
void MovieDatabase::sortByReleaseYear(){
    sort(m_db.begin(),m_db.end());
}
/**
 * Creates a new movie database
 * for each movie in the current database
 * if the movie certificate matches the desired one
 * add that movie to the new database
 * @param certificateToMatch the certificate that all the movies must have
 * @return a movie database of all the movies that have this certificate
 */
MovieDatabase MovieDatabase::filterByCertificate(string certificateToMatch){
    MovieDatabase newdb = MovieDatabase();
    for(auto m: m_db){
        if (m.getCertificate() == certificateToMatch){
            newdb.add(m);
        }
    }
    return newdb;
}
/**
 * Constructs a new movie database obj
 * for each movie in the current database obj
 * if the movie has that genre in
 * add it to the new database
 * @param genreToMatch the genre to match
 * @return a new database obj of all the films in the desired genre
 */
MovieDatabase MovieDatabase::filterByGenre(string genreToMatch){
    MovieDatabase newdb = MovieDatabase();
    for(auto m: m_db){
        if (m.hasGenre(genreToMatch)){
            newdb.add(m);
        }
    }
    return newdb;
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
 * Unused in the code
 * Sorts the database by average rating
 * This uses a lambda to sort
 * highest to lowest
 */
void MovieDatabase::sortByAverageRating() {
    sort(m_db.begin(), m_db.end(),[](const Movie & a, const Movie & b) -> bool {
        return a.getAverageRating() > b.getAverageRating();
    });
}