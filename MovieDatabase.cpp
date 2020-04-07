//
// Created by danny on 03/04/2020.
//

#include "MovieDatabase.h"

MovieDatabase::MovieDatabase(string fileName){
    ifstream file(fileName);
    string str;
    MovieDatabase();
    while (getline(file, str)) {
        add(Movie(str));
    }
}
MovieDatabase::MovieDatabase():m_db(){
}

void MovieDatabase::add(Movie m) {
    m_db.push_back(m);
}
void MovieDatabase::print(){
    for(auto m: m_db){
        m.print();
    }
}
Movie MovieDatabase::get(int i){
    return m_db.at(i);
}
int MovieDatabase::size(){
    return m_db.size();
}
namespace {
    bool CompareMoviesByTitleLength(const Movie& a, const Movie& b) {
        return (a.getTitle().length() > b.getTitle().length());
    }

}
void MovieDatabase::sortByTitleLength(){//function
    sort(m_db.begin(),m_db.end(),CompareMoviesByTitleLength);
}
void MovieDatabase::sortByReleaseYear(){//override
    sort(m_db.begin(),m_db.end());
}
MovieDatabase MovieDatabase::filterByCertificate(string certificateToMatch){
    MovieDatabase newdb = MovieDatabase();
    for(auto m: m_db){
        if (m.getCertificate() == certificateToMatch){
            newdb.add(m);
        }
    }
    return newdb;
}
MovieDatabase MovieDatabase::filterByGenre(string genreToMatch){
    MovieDatabase newdb = MovieDatabase();
    for(auto m: m_db){
        if (m.hasGenre(genreToMatch)){
            newdb.add(m);
        }
    }
    return newdb;
}
void MovieDatabase::sortByDuration(){//functor
    sort(m_db.begin(),m_db.end(),Movie::CompareMoviesByDuration());
}
void MovieDatabase::sortByAverageRating() {//lambda
    sort(m_db.begin(), m_db.end(),[](const Movie & a, const Movie & b) -> bool {
        return a.getAverageRating() > b.getAverageRating();
    });
}