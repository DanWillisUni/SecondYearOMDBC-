#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    MovieDatabase database = MovieDatabase("../films.txt");//creates a movie database from file
    database.sortByReleaseYear();//sorts the database lowest to highest of year of release
    database.print();//prints the database in order
    cout << " " << endl; //just to put a space between it to make it clear
    MovieDatabase filmNoir = database.filterByGenre("Film-Noir");//creates a new database with all the Film-Noir films in
    filmNoir.sortByDuration();//sorts the filmnoir database by duration longest to shortest
    filmNoir.get(2).print();//counting from 0 so for the task I need to get the second element and print it
    cout << " " << endl; //just to put a space between it to make it clear
    MovieDatabase unratedFilms = database.filterByCertificate("UNRATED");//gets all the unrated films in a new database
    unratedFilms.get(unratedFilms.size()-8).print();//already sorted by release year, but needs the size of it subtract 8 to get most recent
    cout << " " << endl; //just to put a space between it to make it clear
    database.sortByTitleLength();//sort the whole database by title length
    database.get(0).print();//prints the longest title length movie
    return 0;
}
