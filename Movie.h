//
// Created by danny on 03/04/2020.
//
#include <string.h>
#include <string>
#ifndef COURSEWORK2_MOVIE_H
#define COURSEWORK2_MOVIE_H
class Movie{
private:
    char * title; //title of the movie
    int releaseYear;//year of release of the movie
    char * certificate;//certificate of who can watch the movie
    std::string * genres;//genres the movie fits into
    int duration;//duration of the film in minutes
    int averageRating;//average viewer rating
public:
    Movie(char * title,int releaseYear,char * certificate,std::string * genres,int duration,int averageRating);
    Movie(std::string line);
    char * getTitle();
    int getReleaseYear();
    char * getCertificate();
    std::string * getGenres();
    int getDuration();
    int getAverageRating();
};


#endif //COURSEWORK2_MOVIE_H
