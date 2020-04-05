#include <iostream>
#include "Movie.h"
#include "MovieDatabase.h"

int main() {
//    Movie ma("Indiana Jones and the Last Crusade", 1989, "PG-13", "Action/Adventure/Fantasy", 127, 0);
//    ma.print();
//    Movie mb("'The Great Dictator',1940,'APPROVED','Comedy/Drama/War',125,0");
//    mb.print();
//    MovieDatabase database;
//    database.add(ma);
//    database.add(mb);
    MovieDatabase database = MovieDatabase("C:\\Users\\danny\\CLionProjects\\CourseWork2\\films.txt");
    cout << "Printing database:" << endl;
    database.print();
    return 0;
}
