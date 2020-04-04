//
// Created by danny on 03/04/2020.
//

#include "MovieDatabase.h"

MovieDatabase::MovieDatabase(Movie db[]){

}
MovieDatabase::MovieDatabase(string fileName){
    //read in the file
    //for each line create new movie and add it to the database
}
MovieDatabase::MovieDatabase(Movie m){
    db = new Movie[0]; //fix
    dbSize = 1;
    db[0] = m;
}
void MovieDatabase::add(Movie m){
    //create new array one element larger
    //copy all elements into new array
    //set the end element to m in the new array
    //delete memory allocated to db
    //reallocate dp pointer to the new array
}
void MovieDatabase::print(){
    //for each item in the database
    //print movie
}