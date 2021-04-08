#include <fstream>
#include <iostream>
#include "ItemType.hpp"

ItemType::ItemType() { ptr = NULL; }

RelationType ItemType::ComparedTo(ItemType otherBook, char typeOfSort) const {
    if(typeOfSort == 't' || typeOfSort == 'T') { // Checking by title
        if (ptr->GetTitle() < otherBook.ptr->GetTitle())
            return LESS;
        else if (ptr->GetTitle() > otherBook.ptr->GetTitle())
            return GREATER;
        else return EQUAL;
    } else if (typeOfSort == 'a' || typeOfSort == 'A') { // Checking by author
        if (ptr->GetAuthor() < otherBook.ptr->GetAuthor())
            return LESS;
        else if (ptr->GetAuthor() > otherBook.ptr->GetAuthor())
            return GREATER;
        else return EQUAL;
    } else if (typeOfSort == 'g' || typeOfSort == 'G') { // Checking by genre
        if (ptr->GetGenre() < otherBook.ptr->GetGenre())
            return LESS;
        else if (ptr->GetGenre() > otherBook.ptr->GetGenre())
            return GREATER;
        else return EQUAL;
    } else { // Error if t/T, a/A, or g/G not entered
        std::cerr << "\nInvalid typeOfSort entered\n";
        return ERROR;
    }
    
}

void ItemType::Initialize(BookType& book) { ptr = &book; }

BookType* ItemType::GetPtr() { return ptr; }

void ItemType::PrintTitle(std::ostream &out) {
    std::cout << "Title: " << ptr->GetTitle();
    out << "Title: " << ptr->GetTitle();
}

void ItemType::PrintAuthor(std::ostream &out) {
    std::cout << "Author: " << ptr->GetAuthor();
    out << "Author: " << ptr->GetAuthor();
}

void ItemType::PrintGenre(std::ostream &out) {
    std::cout << "Genre: " << ptr->GetGenre();
    out << "Genre: " << ptr->GetGenre();
}
