//
// Created by danny on 03/04/2020.
//

#include "Movie.h"
using namespace std;

const map<string, Movie::certificateEnum> Movie::certificateStringToEnum = {
        {"PG-13", PG_13},
        {"PG", PG},
        {"APPROVED", APPROVED},
        {"R", R},
        {"NOT RATED", NOT_RATED},
        {"G", G},
        {"UNRATED", UNRATED},
        {"PASSED",PASSED},
        {"N/A",NA},
        {"TV-14",TV14},
        {"M",M},
        {"X",X}
};

/**
 * Test harness
 * Constructs 2 movies, a and b using two different constructors
 * Prints the 2 movies
 * See if each movie has genre action
 * See if each movie has the genre fantasy
 */
void Movie::tester(){
    Movie a = Movie("Indiana Jones and the Last Crusade",1989,"PG-13","Action/Adventure/Fantasy",127,0);
    Movie b = Movie(R"("Aliens",1986,"R","Action/Adventure/Sci-Fi",137,0)");
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
 * Constructor
 * Constructs a movie from all the attributes passed in
 * @param title, title of the movie
 * @param releaseYear, year or release of the movie
 * @param certificate, certificate of the movie
 * @param genres, genres of the movie
 * @param duration, duration of the movie
 * @param averageRating, average rating of the movie
 */
Movie::Movie(const string& title, int releaseYear, const string& certificate, const string& genres, int duration, int averageRating) {//Constructor
    m_title = title;
    m_releaseYear = releaseYear;
    m_certificate = Movie::certificateStringToEnum.at(certificate);
    m_genres = genres;
    m_duration = duration;
    m_averageRating = averageRating;
}

/**
 * Constructor
 * Creates a movie from a line in a file
 * Has to be in the correct format
 * @param line the line of the file
 */
Movie::Movie(const string& line){
    vector<string> lineSplit = splitString(line,"\"");//splits the line by "
    m_title = lineSplit[1];//splitting makes the title the 1st element
    m_releaseYear = stoi(lineSplit[2].substr(1,lineSplit[2].size() - 2));//remove the commas and convert to integer
    m_certificate = Movie::certificateStringToEnum.at(lineSplit[3]);//splitting makes the certificate 3rd
    m_genres = lineSplit[5];//all the genres are stored together and a hasGenre function was created
    vector<string> runtimeAndRatingSplit = splitString(lineSplit[6],",");//splits the already split line by commas to seperate the runtime and rating
    m_duration = stoi(runtimeAndRatingSplit[1]);//converts to integer
    m_averageRating = stoi(runtimeAndRatingSplit[2]);//converts to integer
}

Movie::Movie(){}

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

bool Movie::hasGenre(const string& genreToMatch) const{
    size_t found = getGenres().find(genreToMatch);//gets the position of the start of the the string to find
    return found != string::npos; // Return true if the genreToMatch was found
}

/**
 * Prints out the movie overloading the << operator
 * @param out output stream
 * @param movie movie
 * @return the output stream full with the movie
 */
ostream& operator<< (ostream &out, const Movie &movie) {
    out << "\"" << movie.getTitle() << "\"," << to_string(movie.getReleaseYear()) << ",\"" << Movie::searchForKey(movie.getCertificate()) << "\",\"" << movie.getGenres() << "\"," << to_string(movie.getDuration()) << "," << to_string(movie.getAverageRating()) << "\n";
    return out; // return ostream so I can chain calls to operator<< used for the
}

/**
 * Splits the string to split on each separator string into a vector
 * @param str string to split
 * @param seperator string to split on
 * @return vector of all the substrings split
 */
vector<string> Movie::splitString(const string& str, const string& seperator) {
    vector<string> parts;//parts of the string after split
    size_t pos = 0;//start at the beginning
    while (true) {
        size_t newPos = str.find(seperator, pos);//try to find the place of the next separator
        if (newPos == string::npos) {// No more separators
            parts.push_back(str.substr(pos));//push back last substring
            break;//exit the while
        }
        // Found separator at newPos
        parts.push_back(str.substr(pos, newPos - pos));//push back new substring
        pos = newPos + seperator.length();//jumps to the end of the separator
    }
    return parts;
}

/**
 * Search for the key string of the certificate from the certificate enum
 * @param certificateEnum certificate enum to match
 * @return the string, matching the certificate enum
 */
string Movie::searchForKey(const Movie::certificateEnum& certificateEnum){
    string key;
    for (auto &item : Movie::certificateStringToEnum) {//goes through the map
        if (item.second == certificateEnum) {//compares the second item (the value) to
            key = item.first; //the key is set
            break; //To stop searching
        }
    }
    return key;
}