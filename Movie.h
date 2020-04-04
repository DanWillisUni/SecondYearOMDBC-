//
// Created by danny on 03/04/2020.
//

#ifndef COURSEWORK2_MOVIE_H
#define COURSEWORK2_MOVIE_H
using namespace std;
class Movie{
private:
    string title; //title of the movie
    int releaseYear;//year of release of the movie
    string certificate;//certificate of who can watch the movie
    string * genres;//genres the movie fits into
    int duration;//duration of the film in minutes
    int averageRating;//average viewer rating
public:
    Movie(string title,int releaseYear,string certificate,string * genres,int duration,int averageRating);
    Movie(string line);
    string getTitle();
    int getReleaseYear();
    string getCertificate();
    string * getGenres();
    int getDuration();
    int getAverageRating();
    string getGenreString();
    void print();
};
#endif //COURSEWORK2_MOVIE_H
