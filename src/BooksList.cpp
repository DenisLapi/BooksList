#include <iostream>
#include <string>
#include <sstream>
#include "./../headers/BooksList.h"

BooksList::BooksList() {
    this->head = new Book;
    this->head->next = NULL;
}

void BooksList::insertBook(Book *book) {

    book->next = this->head->next;
    this->head->next = book;

}

void BooksList::createBook() {

    Book *newBook = new Book;

    // Get title

    std::cout << "\nEnter book title: ";
    std::getline(std::cin, newBook->title);

    // Get author

    std::cout << "Enter book author: ";
    std::getline(std::cin, newBook->author);

    // Get publisher

    std::cout << "Enter book publisher: ";
    std::getline(std::cin, newBook->publisher);

    // Get ISBN
    std::string ISBN;
    
    std::cout << "Enter book ISBN: ";
    std::getline(std::cin, ISBN);

    while(!this->isISBNValid(ISBN)) {
        std::cout << "Enter valid ISBN: ";
        std::getline(std::cin, ISBN);
    }

    newBook->ISBN = ISBN;

    // Get age of release

    std::cout << "Enter book age of release: ";
    std::cin >> newBook->age;

    // Get price

    std::cout << "Enter book price: ";
    std::cin >> newBook->price;

    // Reset the STD::CIN

    std::cin.clear();
    std::cin.ignore();

    // Add new created node to the list of nodes

    this->insertBook(newBook);

}

void BooksList::showBook(Book *book) {
    std::cout << "Book title: " << book->title << "\n";
    std::cout << "Book author: " << book->author << "\n";
    std::cout << "Book publisher: " << book->publisher << "\n";
    std::cout << "Book ISBN: " << book->ISBN << "\n";
    std::cout << "Book age of release: " << book->age << "\n";
    std::cout << "Book price: " << book->price << "\n";
}

void BooksList::showBooks() {

    Book *iterator = new Book;

    iterator = this->head->next;

    while(iterator != NULL) {
        std::cout << "\n-----------------------------\n";
        this->showBook(iterator);
        iterator = iterator->next;
    }
}

void BooksList::searchByTitle(const std::string& title) {

    Book *iterator = new Book;

    iterator = this->head->next;

    std::cout << "\nSearch by title result: \n";

    while(iterator != NULL) {
        if(title.compare(iterator->title) == 0) {
            std::cout << "\n-----------------------------\n";
            this->showBook(iterator);
        }
        iterator = iterator->next;
    }

}

void BooksList::searchByPublisher(const std::string& publisher) {

    Book *iterator = new Book;

    iterator = this->head->next;

    std::cout << "\nSearch by publisher result: \n";

    while(iterator != NULL) {
        if(publisher.compare(iterator->publisher) == 0) {
            std::cout << "\n-----------------------------\n";
            this->showBook(iterator);
        }
        iterator = iterator->next;
    }

}

void BooksList::searchByISBN(const std::string& ISBN) {

    Book *iterator = new Book;

    iterator = this->head->next;

    std::cout << "\nSearch by ISBN result: \n";

    while(iterator != NULL) {
        if(ISBN.compare(iterator->ISBN) == 0) {
            std::cout << "\n-----------------------------\n";
            this->showBook(iterator);
        }
        iterator = iterator->next;
    }

}

bool BooksList::isISBNValid(const std::string& ISBN) {

    int isbnLength = ISBN.length();
    
    if(isbnLength == 10) {

        int sum = 0; 

        for (int i = 0; i < 9; i++)  { 

            int digit = ISBN[i] - '0'; 

            if (0 > digit || 9 < digit) {
                return false; 
            }

            sum += (digit * (10 - i)); 

        } 
    
        char last = ISBN[9]; 

        if (last != 'X' && (last < '0' ||  last > '9')) {
            return false; 
        }
    
        sum += ((last == 'X') ? 10 : (last - '0')); 
    
        return (sum % 11 == 0); 

    } else if(isbnLength == 13) {

        int sum = 0;
        int reminder = 0;

        for(int i = 0; i < 12; i++) {

            int digit = ISBN[i] - '0'; 

            if (0 > digit || 9 < digit) {
                return false; 
            }

            if(i % 2 == 0) {
                sum += digit * 1;
            } else {
                sum += digit * 3;
            }

        }

        reminder = sum % 10;

        int lastDigit = ISBN[12] - '0';

        if(reminder == 0) {
            return (reminder == lastDigit) ? true : false;
        } else {
            int result = 10 - reminder;
            return (result == lastDigit) ? true : false;
        }
    } 
    return false;
}