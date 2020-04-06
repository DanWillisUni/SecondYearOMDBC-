//
// Created by danny on 03/04/2020.
//
#include <vector>
#include <string>
#include <iostream>

#ifndef COURSEWORK2_MOVIE_H
#define COURSEWORK2_MOVIE_H
using namespace std;
class Movie{
private:
    string m_title; //title of the movie
    int m_releaseYear;//year of release of the movie
    string m_certificate;//certificate of who can watch the movie
    string m_genres;//genres the movie fits into
    int m_duration;//duration of the film in minutes
    int m_averageRating;//average viewer rating
    vector<string> splitString(const string& str, const string& seperator);
public:
    Movie(string title,int releaseYear,string certificate,string genres,int duration,int averageRating);
    Movie(string line);
    string getTitle();
    int getReleaseYear();
    string getCertificate();
    string getGenres();
    int getDuration();
    int getAverageRating();
    bool hasGenre(string genreToMatch);
    void print();
    bool operator< (Movie other) const {
        return m_releaseYear < other.getReleaseYear();
    }
};
#endif //COURSEWORK2_MOVIE_H
