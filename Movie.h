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
    vector<string> splitString(const string& str, const string& seperator); //split string function
public:
    Movie(string title,int releaseYear,string certificate,string genres,int duration,int averageRating);
    Movie(string line);
    string getTitle() const;
    int getReleaseYear() const;
    string getCertificate() const;
    string getGenres() const;
    int getDuration() const;
    int getAverageRating() const;
    bool hasGenre(string genreToMatch);
    void print() const;

    bool operator< (Movie other) const {//overrides the less than operator
        return this->getReleaseYear() < other.getReleaseYear();
    }
    struct CompareMoviesByDuration { //struct used to compare movies by duration
        bool operator () (Movie a,Movie b) const {
            return a.getDuration() > b.getDuration();
        }
    };
};
#endif //COURSEWORK2_MOVIE_H
