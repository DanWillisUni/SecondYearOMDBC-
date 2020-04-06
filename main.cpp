#include <iostream>
#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    MovieDatabase database = MovieDatabase("../films.txt");
    database.print();
    database.sortByReleaseYear();
    database.print();
    database.sortByTitleLength();
    database.print();
    database.sortByDuration();
    database.print();
    database.sortByAverageRating();
    database.print();
    database = database.filterByGenre("Comedy");
    database.print();
    database = database.filterByCertificate("R");
    database.print();
    return 0;
}
