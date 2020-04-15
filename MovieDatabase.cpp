//
// Created by danny on 03/04/2020.
//

#include <algorithm>
#include "MovieDatabase.h"

/**
 * test harness
 * constructs a database from the file
 * sorts the database by release year
 * displays the size of the database
 * filters by PG certificate
 * displays the sie of the database to prove the differance
 * sorts by the title length of the movies
 * filters by the genre of comedy
 * displays the size to show the differance in size
 * sorts by average rating
 * sorts by duration
 * prints the longest film
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
 * reads in the file line by line if the file exists
 * while there is a line, it constructs a movie object and adds it to the database
 * closes the file
 * @param fileName, the name of the file to build the database from
 */
MovieDatabase::MovieDatabase(const string& fileName){
    ifstream file(fileName);
    MovieDatabase();//constructs new movie database obj
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
 * @param m movie to add
 */
void MovieDatabase::add(const Movie& m) {
    m_db.push_back(m); // Add to the end of the database
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
 * Gets the Movie at index i in the vector
 * @param i index to get
 * @return Movie at index i
 */
Movie MovieDatabase::get(const int& i){
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
 * This uses the comparator function above as a third parameter in std::sort
 * highest to lowest
 */
void MovieDatabase::sortByTitleLength(){//function
    sort(m_db.begin(),m_db.end(),CompareMoviesByTitleLength);
}
/**
 * Sorting function to sort the movies by year or release
 * Uses a relational comparator override therefore only two parameters in std::sort
 * lowest to highest
 */
void MovieDatabase::sortByReleaseYear(){
    sort(m_db.begin(),m_db.end());
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
 * for each movie in the current database obj
 * if the movie has that genre in
 * add it to the new database
 * @param genreToMatch the genre to match
 * @return a new database obj of all the films in the desired genre
 */
MovieDatabase MovieDatabase::filterByGenre(const string& genreToMatch){
    MovieDatabase newdb = MovieDatabase();//make a empty new database
    for(auto m: m_db){
        if (m.hasGenre(genreToMatch)){//if the movie contains the desired genre
            newdb.add(m);//add the movie to the database
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