#include <iostream>
#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    MovieDatabase database = MovieDatabase("../films.txt");
    database.print();
//    database.sortByReleaseYear();
//    database.print();
//    database.sortByTitleLength();
//    database.print();
    database = database.filterByGenre("Comedy");
    database.print();
    return 0;
}
