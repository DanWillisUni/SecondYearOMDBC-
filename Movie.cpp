//
// Created by danny on 03/04/2020.
//

#include <string>
#include "Movie.h"
using namespace std;

Movie::Movie(char * title, int releaseYear, char * certificate, string genres, int duration, int averageRating) {//Constructor
    this->title = title;
    this->releaseYear = releaseYear;
    this->certificate = certificate;
    //splitting the genres up
    //this->genres = ;
    this->duration = duration;
    this->averageRating = averageRating;
}
//accessor methods
char * Movie::getTitle(){
    return title;
}
int Movie::getReleaseYear(){
    return releaseYear;
}
char * Movie::getCertificate(){
    return certificate;
}
string * Movie::getGenres(){
    return genres;
}
int Movie::getDuration(){
    return duration;
}
int Movie::getAverageRating(){
    return averageRating;
}






