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
    MovieDatabase(string fileName);//constructor from file name
    MovieDatabase();//constructor of empty database
    void add(Movie m);//add a movie
    void print();//print the entire database
    Movie get(int i);//get a movie in position i
    int size();//the size of the database

    void sortByTitleLength();//sorts the database by titlelength
    void sortByReleaseYear();//sorts the movies by release year
    MovieDatabase filterByCertificate(string certificateToMatch);//gives a new database of movies with a specific certificate
    MovieDatabase filterByGenre(string genreToMatch);//gives a new database with all the movies that have a specific genre
    void sortByDuration();//sorts the database by duration
    void sortByAverageRating();//sorts the database by average rating
};

#endif //COURSEWORK2_MOVIEDATABASE_H
