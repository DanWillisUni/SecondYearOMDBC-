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
void MovieDatabase::sortByReleaseYear(){
    sort(m_db.begin(),m_db.end());
}
