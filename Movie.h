//
// Created by danny on 03/04/2020.
//

#include <vector>
#include <string>
#include <iostream>
#include <map>

#ifndef COURSEWORK2_MOVIE_H
#define COURSEWORK2_MOVIE_H
using namespace std;
class Movie{
public:
    enum certificateEnum {
        PG_13,
        PG,
        APPROVED,
        R,
        NOT_RATED,
        G,
        UNRATED,
        PASSED,
        NA,
        TV14,
        M,
        X
    };
private:
    string m_title; //title of the movie
    int m_releaseYear;//year of release of the movie
    certificateEnum m_certificate;//certificate of who can watch the movie
    string m_genres;//genres the movie fits into
    int m_duration;//duration of the film in minutes
    int m_averageRating;//average viewer rating
    vector<string> splitString(const string& str, const string& seperator); //split string function
public:
    static const map<string, certificateEnum> certificateStringToEnum;
    static void tester();
    Movie(string title,int releaseYear,string certificate,string genres,int duration,int averageRating);
    Movie(string line);
    string getTitle() const;
    int getReleaseYear() const;
    certificateEnum getCertificate() const;
    string getGenres() const;
    int getDuration() const;
    int getAverageRating() const;
    bool hasGenre(string genreToMatch);

    friend ostream& operator<< (std::ostream &out, const Movie &m);
    bool operator< (Movie other) const {//overrides the less than operator
        return this->getReleaseYear() < other.getReleaseYear();
    }
    struct CompareMoviesByDuration { //struct used to compare movies by duration
        bool operator () (Movie a,Movie b) const {
            return a.getDuration() > b.getDuration();
        }
    };
    static string searchForKey(certificateEnum cE);
};
#endif //COURSEWORK2_MOVIE_H
