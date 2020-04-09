//
// Created by danny on 03/04/2020.
//

#include "Movie.h"
using namespace std;

void Movie::tester(){
    Movie a = Movie("Indiana Jones and the Last Crusade",1989,"PG-13","Action/Adventure/Fantasy",127,0);
    Movie b = Movie("\"Aliens\",1986,\"R\",\"Action/Adventure/Sci-Fi\",137,0");
    cout << "a: ";
    cout << a;
    cout << "b: ";
    cout << b;
    cout << "a has genre \"Action\": " << a.hasGenre("Action") << "\n";
    cout << "b has genre \"Action\": " << b.hasGenre("Action")<< "\n";
    cout << "a has genre \"Fantasy\": " << a.hasGenre("Fantasy")<< "\n";
    cout << "b has genre \"Fantasy\": " << b.hasGenre("Fantasy")<< "\n";
}
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
    m_certificate = Movie::stringToEnumMap.at(certificate);
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
    m_certificate = Movie::stringToEnumMap.at(lineSplit[3]);//splitting makes the certificate 3rd
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
Movie::certificateEnum Movie::getCertificate() const{
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
 * prints out the movie overloading the << operator
 * @param out output stream
 * @param m movie
 * @return the output stream full with the movie
 */
ostream& operator<< (ostream &out, const Movie &m) {
    out << "\"" << m.getTitle() << "\"," << to_string(m.getReleaseYear()) << ",\"" << Movie::searchForKey(m.getCertificate()) << "\",\"" << m.getGenres() <<  "\"," << to_string(m.getDuration()) << "," << to_string(m.getAverageRating()) << "\n";
    return out; // return ostream so I can chain calls to operator<< used for the
}
/**
 * Splits the string to split on each separator string
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
string Movie::searchForKey(Movie::certificateEnum cE){
    string key;
    for (auto &i : Movie::stringToEnumMap) {
        if (i.second == cE) {
            key = i.first;
            break; // to stop searching
        }
    }
    return key;
}