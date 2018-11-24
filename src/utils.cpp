#include <iostream>
#include <string>
#include "./../headers/utils.h"
#include "./../headers/BooksList.h"

void showMenu(BooksList booksList) {

    int option;
    std::string title;
    std::string publisher;
    std::string ISBN;

    std::cout << "\nOptions: \n1) Create book\n2) Show books\n3) Search by title\n4) Search by publisher\n5) Search by ISBN\n6) Close\nEnter option number: ";
    std::cin >> option;

    // Reset the STD::CIN

    std::cin.clear();
    std::cin.ignore();

    switch (option)
    {
        case 1:
            booksList.createBook();
            break;

        case 2:
            booksList.showBooks();
            break;

        case 3: {
            std::cout << "Enter book title you want to find: ";
            std::getline(std::cin, title);    
            booksList.searchByTitle(title);
            break;
        }

        case 4: {
            std::cout << "Enter book publisher you want to find: ";
            std::getline(std::cin, publisher);
            booksList.searchByPublisher(publisher);
            break;
        }

        case 5: {

            std::cout << "Enter book ISBN you want to find: ";
            std::getline(std::cin, ISBN);

            while(!booksList.isISBNValid(ISBN)) {
                std::cout << "Enter valid ISBN: ";
                std::getline(std::cin, ISBN);
            }

            booksList.searchByISBN(ISBN);
            break;
        }
        case 6:
            exit(0);
            break;
        default:
            showMenu(booksList);
            break;
    }
}