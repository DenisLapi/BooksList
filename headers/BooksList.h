#ifndef BOOKS_LIST_H
#define BOOKS_LIST_H

#include <iostream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    std::string publisher;
    std::string ISBN;
    int age;
    float price;
    struct Book *next;
};

class BooksList {
    private:
        struct Book *head;
        void insertBook(Book *book);
    public:
        BooksList();
        void showSomething();
        void createBook();
        void showBook(Book *book);
        void showBooks();
        void searchByTitle(const std::string& title);
        void searchByPublisher(const std::string& publisher);
        void searchByISBN(const std::string& ISBN);
        bool isISBNValid(const std::string& ISBN);
};

#endif // BOOKS_LIST_H