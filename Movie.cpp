//
// Created by danny on 03/04/2020.
//

#include "Movie.h"
using namespace std;

Movie::Movie(string title, int releaseYear, string certificate, string genres, int duration, int averageRating) {//Constructor
    m_title = title;
    m_releaseYear = releaseYear;
    m_certificate = certificate;
    m_genres = genres;
    m_duration = duration;
    m_averageRating = averageRating;
}
Movie::Movie(string line){
    //split the line by ','
    //remove quotes from m_title, certificate, genres
}
//accessor methods
string Movie::getTitle(){
    return m_title;
}
int Movie::getReleaseYear(){
    return m_releaseYear;
}
string Movie::getCertificate(){
    return m_certificate;
}
string Movie::getGenres(){
    return m_genres;
}
int Movie::getDuration(){
    return m_duration;
}
int Movie::getAverageRating(){
    return m_averageRating;
}

bool Movie::hasGenre(string genreToMatch){
    //check if genreToMatch is in the genre String
    return false;
}
void Movie::print(){
    cout << getTitle() << ", " << to_string(getReleaseYear()) << ", " << getCertificate() << ", " << getGenres() <<  ", " << to_string(getDuration()) << ", " << to_string(getAverageRating()) << endl;
}








