//
// Created by danny on 03/04/2020.
//

#include "MovieDatabase.h"

//MovieDatabase::MovieDatabase(Movie db[]){
//    this->db = *db;
//}
//MovieDatabase::MovieDatabase(string fileName){
//    //read in the file
//    //for each line create new movie and add it to the database
//}
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