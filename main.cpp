#include <iostream>
#include "Movie.h"

int main() {
    Movie m("Indiana Jones and the Last Crusade",1989,"PG-13","Action/Adventure/Fantasy",127,0);
    printf("%s", m.getTitle());
    return 0;
}
