//
// Created by danny on 03/04/2020.
//
#include <string>
#include <vector>
#include "Movie.h"
using namespace std;
#ifndef COURSEWORK2_MOVIEDATABASE_H
#define COURSEWORK2_MOVIEDATABASE_H
class MovieDatabase{
private:
    vector<Movie> m_db;
public:
    //MovieDatabase(Movie db[]);
    //MovieDatabase(string fileName);
    MovieDatabase();
    void add(Movie m);
    void print();
};

#endif //COURSEWORK2_MOVIEDATABASE_H
