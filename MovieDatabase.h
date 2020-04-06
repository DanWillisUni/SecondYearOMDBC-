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
    vector<Movie> m_db;
public:
    MovieDatabase(string fileName);
    MovieDatabase();
    void add(Movie m);
    void print();
    Movie get(int i);

    void sortByTitleLength();
    void sortByReleaseYear();
    MovieDatabase filterByCertificate(string certificateToMatch);
    MovieDatabase filterByGenre(string genreToMatch);
    void sortByDuration();
    void sortByAverageRating();
};

#endif //COURSEWORK2_MOVIEDATABASE_H
