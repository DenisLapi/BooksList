#include <iostream>
#include <string>
#include "./headers/utils.h"
#include "./headers/BooksList.h"

int main() {
    
    BooksList booksList;
    
    while(1) {
        showMenu(booksList);
    }

    return 0;
}