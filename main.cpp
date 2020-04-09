#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    //Movie::tester();
    //MovieDatabase::tester();
    MovieDatabase database = MovieDatabase("../films.txt");//creates a movie database from file
    database.sortByReleaseYear();//sorts the database lowest to highest of year of release
    cout << database << endl;//prints the database in order
    MovieDatabase filmNoir = database.filterByGenre("Film-Noir");//creates a new database with all the Film-Noir films in
    filmNoir.sortByDuration();//sorts the filmnoir database by duration longest to shortest
    cout << filmNoir.get(2) << endl;//counting from 0 so for the task I need to get the second element and print it
    MovieDatabase unratedFilms = database.filterByCertificate("UNRATED");//gets all the unrated films in a new database
    cout << unratedFilms.get(unratedFilms.size()-8) << endl;//already sorted by release year, but needs the size of it subtract 8 to get most recent
    database.sortByTitleLength();//sort the whole database by title length
    cout << database.get(0);//prints the longest title length movie
    return 0;
}
