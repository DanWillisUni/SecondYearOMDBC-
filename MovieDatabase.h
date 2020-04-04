//
// Created by danny on 03/04/2020.
//
#include <string>
#include "Movie.h"
using namespace std;
#ifndef COURSEWORK2_MOVIEDATABASE_H
#define COURSEWORK2_MOVIEDATABASE_H
class MovieDatabase{
private:
    int dbSize;
    int* db;
public:
    MovieDatabase(Movie db[]);
    MovieDatabase(string fileName);
    MovieDatabase(Movie m);
    void add(Movie m);
    void print();
};

#endif //COURSEWORK2_MOVIEDATABASE_H
