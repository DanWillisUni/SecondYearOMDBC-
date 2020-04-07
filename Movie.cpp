//
// Created by danny on 03/04/2020.
//

#include "Movie.h"
using namespace std;
/**
 * Unused Constructor
 * Constructs a movie from all the attributes passed in
 * @param title title of the movie
 * @param releaseYear year or release of the movie
 * @param certificate certificate of the movie
 * @param genres genres of the movie
 * @param duration duration of the movie
 * @param averageRating average rating of the movie
 */
Movie::Movie(string title, int releaseYear, string certificate, string genres, int duration, int averageRating) {//Constructor
    m_title = title;
    m_releaseYear = releaseYear;
    m_certificate = certificate;
    m_genres = genres;
    m_duration = duration;
    m_averageRating = averageRating;
}
/**
 * Constructor
 * Creates a movie from a line in a file
 * @param line the line of the file
 */
Movie::Movie(string line){
    vector<string> lineSplit = splitString(line,"\"");//splits the line by "
    m_title = lineSplit[1];//splitting makes the title the 1st element
    m_releaseYear = stoi(lineSplit[2].substr(1,lineSplit[2].size() - 2));//remove the commas and convert to integer
    m_certificate = lineSplit[3];//splitting makes the certificate 3rd
    m_genres = lineSplit[5];//all the genres are stored together and a hasGenre function was created
    vector<string> runtimeAndRatingSplit = splitString(lineSplit[6],",");//splits the already split line by commas to seperate the runtime and rating
    m_duration = stoi(runtimeAndRatingSplit[1]);//converts to integer
    m_averageRating = stoi(runtimeAndRatingSplit[2]);//converts to integer
}
//accessor methods
string Movie::getTitle() const{
    return m_title;
}
int Movie::getReleaseYear() const{
    return m_releaseYear;
}
string Movie::getCertificate() const{
    return m_certificate;
}
string Movie::getGenres() const{
    return m_genres;
}
int Movie::getDuration() const{
    return m_duration;
}
int Movie::getAverageRating() const{
    return m_averageRating;
}
/**
 * split on the desired genre
 * if there is more than one element in the new vector
 * that means that it must be of the desired genre
 * @param genreToMatch desired genre
 * @return true if the movie is of the desired genre
 */
bool Movie::hasGenre(string genreToMatch){
    vector<string> genreSplit = splitString(m_genres,genreToMatch);
    return(genreSplit.size()>1);
}
/**
 * outputs to the console the movie
 * in the exact format it is in the films.txt file
 */
void Movie::print(){
    cout << "\"" << getTitle() << "\"," << to_string(getReleaseYear()) << ",\"" << getCertificate() << "\",\"" << getGenres() <<  "\"," << to_string(getDuration()) << "," << to_string(getAverageRating()) << endl;
}
/**
 * Splits the string to split on each seperator string
 * @param str string to split
 * @param seperator string to split on
 * @return vector of all the substrings split
 */
vector<string> Movie::splitString(const string& str, const string& seperator) {
    vector<string> parts;//parts of the string after split
    size_t pos = 0;// start at the begining
    while (true) {
        size_t newPos = str.find(seperator, pos);//try to find the place of the next seperator
        if (newPos == string::npos) {// No more seperators
            parts.push_back(str.substr(pos));//pushback last substring
            break;//exit the while
        }
        // Found seperator at newPos
        parts.push_back(str.substr(pos, newPos - pos));//push back new substring
        pos = newPos + seperator.length();//jumps to the end of the seperator
    }
    return parts;
}