//
// Created by danny on 03/04/2020.
//

#include <vector>
#include <string>
#include <iostream>
#include <map>

#pragma once
using namespace std;

class Movie{
public:
    enum certificateEnum {//enum of all the certificates that are in the films.txt file
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

    static const map<string, certificateEnum> certificateStringToEnum;//map for converting the string to the enum type
    static void tester();//test harness

    Movie(const string& title, const int& releaseYear, const string& certificate, const string& genres, const int& duration, const int& averageRating);//constructs from all the attributes
    explicit Movie(const string& line);//creates a movie from the line in the file
    Movie();//empty movie constructor
    /**
     * Gets the title of the movie
     * @return the movie title
     */
    string getTitle() const; //gets the title of the movie
    /**
     * Gets the year of release of the film
     * @return the release year
     */
    int getReleaseYear() const;//gets the release year of the movie
    /**
     * Gets the certificate value of the movie
     * @return certificate
     */
    certificateEnum getCertificate() const;//gets the certificate of the movie
    /**
     * Gets all genres as a string seperated by '/'
     * @return genre string
     */
    string getGenres() const;//gets the genre string of the movie
    /**
     * Gets the duration of the movie in minutes
     * @return duration of the movie
     */
    int getDuration() const;//gets the duration of the movie
    /**
     * Gets the average rating of the movie
     * @return average rating
     */
    int getAverageRating() const;//gets the average rating of the movie
    /**
     * Finds if a movie is of a specified genre
     * Using find function
     * @param genreToMatch desired genre
     * @return true if the movie is of the desired genre
     */
    bool hasGenre(const string& genreToMatch) const;//gets if the movie is of the specified genre

    friend ostream& operator<< (std::ostream &out, const Movie &m);//override the operator
    bool operator< (const Movie& other) const {//overrides the less than operator
        return this->getReleaseYear() < other.getReleaseYear();//oldest to most recent
    }
    struct CompareMoviesByDuration { //struct used to compare movies by duration using a functor
        bool operator () (const Movie& a, const Movie& b) const {
            return a.getDuration() > b.getDuration();//longest to shortest
        }
    };
private:
    string m_title; //title of the movie
    int m_releaseYear;//year of release of the movie
    certificateEnum m_certificate;//certificate of who can watch the movie
    string m_genres;//genres the movie fits into
    int m_duration;//duration of the film in minutes
    int m_averageRating;//average viewer rating
    static vector<string> splitString(const string& str, const string& seperator); //split string function
    static string searchForKey(const certificateEnum& certificateEnum);
};
