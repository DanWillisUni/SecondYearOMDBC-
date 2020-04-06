#include <iostream>
#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    MovieDatabase database = MovieDatabase("../films.txt");
    cout << "Printing database:" << endl;
    database.print();
    return 0;
}
