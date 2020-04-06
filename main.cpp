#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    MovieDatabase database = MovieDatabase("../films.txt");
    database.sortByReleaseYear();
    database.print();
    MovieDatabase filmNoir = database.filterByGenre("Film-Noir");
    filmNoir.sortByDuration();
    filmNoir.get(2).print();
    MovieDatabase unratedFilms = database.filterByCertificate("UNRATED");
    unratedFilms.get(unratedFilms.size()-8).print();
    database.sortByTitleLength();
    database.get(0).print();
    return 0;
}
