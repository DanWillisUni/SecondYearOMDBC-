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
    vector<string> lineSplit = splitString(line,"\"");
    m_title = lineSplit[1];
    m_releaseYear = stoi(lineSplit[2].substr(1,lineSplit[2].size() - 2));
    m_certificate = lineSplit[3];
    m_genres = lineSplit[5];
    vector<string> runtimeAndRatingSplit = splitString(lineSplit[6],",");
    m_duration = stoi(runtimeAndRatingSplit[1]);
    m_averageRating = stoi(runtimeAndRatingSplit[2]);
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
    vector<string> genreSplit = splitString(m_genres,genreToMatch);
    return(genreSplit.size()>1);
}
void Movie::print(){
    cout << "\"" << getTitle() << "\"," << to_string(getReleaseYear()) << ",\"" << getCertificate() << "\",\"" << getGenres() <<  "\"," << to_string(getDuration()) << "," << to_string(getAverageRating()) << endl;
}

vector<string> Movie::splitString(const string& str, const string& seperator) {
    vector<string> parts;
    size_t pos = 0;
    while (true) {
        size_t newPos = str.find(seperator, pos);
        if (newPos == std::string::npos) {
            // No more seperators
            parts.push_back(str.substr(pos));
            break;
        }
        // Found seperator at newPos
        parts.push_back(str.substr(pos, newPos - pos));
        pos = newPos + seperator.length();
    }
    return parts;
}