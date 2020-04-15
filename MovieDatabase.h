//
// Created by danny on 03/04/2020.
//

#include <string>
#include <vector>
#include <fstream>

#include "Movie.h"

using namespace std;
#ifndef COURSEWORK2_MOVIEDATABASE_H
#define COURSEWORK2_MOVIEDATABASE_H
class MovieDatabase{
private:
    vector<Movie> m_db;//vector of movies in the database
public:
    static void tester();//test harness
    explicit MovieDatabase(const string& fileName);//constructor from file name
    MovieDatabase();//constructor of empty database
    explicit MovieDatabase(const size_t& size);
    void add(const Movie& m);//add a movie
    void resize(const size_t& newSize);
    Movie get(const int& i) ;//get a movie in position i
    int size() const;//the size of the database

    friend ostream& operator<< (std::ostream &out, const MovieDatabase &md);

    void sortByTitleLength();//sorts the database by title length
    void sortByReleaseYear();//sorts the movies by release year
    MovieDatabase filterByCertificate(const string& certificateToMatch);//gives a new database of movies with a specific certificate
    MovieDatabase filterByGenre(const string& genreToMatch);//gives a new database with all the movies that have a specific genre
    void sortByDuration();//sorts the database by duration
    void sortByAverageRating();//sorts the database by average rating
};
#endif //COURSEWORK2_MOVIEDATABASE_H