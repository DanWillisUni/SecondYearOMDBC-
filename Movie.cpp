//
// Created by danny on 03/04/2020.
//

#include "Movie.h"
using namespace std;

Movie::Movie(string title, int releaseYear, string certificate, string genres[], int duration, int averageRating) {//Constructor
    this->title = title;
    this->releaseYear = releaseYear;
    this->certificate = certificate;
    //this->genres = genres;
    this->duration = duration;
    this->averageRating = averageRating;
}
Movie::Movie(string line){
    //split the line by ','
    //remove quotes from title, certificate, genres
    //split genres by '/'
}
//accessor methods
string Movie::getTitle(){
    return title;
}
int Movie::getReleaseYear(){
    return releaseYear;
}
string Movie::getCertificate(){
    return certificate;
}
//string* Movie::getGenres(){
//    return genres;
//}
int Movie::getDuration(){
    return duration;
}
int Movie::getAverageRating(){
    return averageRating;
}

string Movie::getGenreString(){
    //string* allGenres = new string[0];
    //allGenres = getGenres();
    //for each item in array
    //add '/' inbetween them
    return "theGenres";
}
void Movie::print(){
    cout << getTitle() << ", " << to_string(getReleaseYear()) << ", " << getCertificate() << ", " << getGenreString() <<  ", " << to_string(getDuration()) << ", " << to_string(getAverageRating()) << endl;
}








