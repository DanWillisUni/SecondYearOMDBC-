#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    //Movie::tester();//movie class test harness
    //MovieDatabase::tester();//movie database class test harness

    // 1. Read in the database from the file films.txt, using the relative path “films.txt”,
    // provided via BlackBoard (when using CLion, the program will expect to find the file
    // in the cmake-build-debug directory). This is necessary to ensure that the program
    //runs correctly using PASS.
    cout << "Task 1\nReading in films\n" << endl;
    MovieDatabase database = MovieDatabase("films.txt");//creates a movie database from file

    // 2. Display the entire collection of movies, arranged in chronological order. The movies
    // must be displayed in the same format in which they appear in films.txt.
    cout << "Task 2\nSort by the release year" << endl;
    database.sortByReleaseYear();//sorts the database lowest to highest of year of release
    cout << database << endl;//prints the database in order

    // 3. Display the third longest Film-Noir
    cout << "Task 3\nThird longest Film-Noir" << endl;
    MovieDatabase filmNoir = database.filterByGenre("Film-Noir");//creates a new database with all the Film-Noir films in
    filmNoir.sortByDuration();//sorts the filmnoir database by duration longest to shortest
    cout << filmNoir.get(2) << endl;//counting from 0 so for the task I need to get the second element and print it

    //4. Display the eighth most recent UNRATED film
    cout << "Task 4\nEighth most recent UNRATED film" << endl;
    MovieDatabase unratedFilms = database.filterByCertificate("UNRATED");//gets all the unrated films in a new database
    cout << unratedFilms.get(unratedFilms.size()-8) << endl;//already sorted by release year, but needs the size of it subtract 8 to get most recent

    //5. Display the film with the longest title.
    cout << "Task 5\nLongest title" << endl;
    database.sortByTitleLength();//sort the whole database by title length
    cout << database.get(0);//prints the longest title length movie

    return 0;
}
