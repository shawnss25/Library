#include "BookType.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::cerr;
using std::endl;
using std::string;

BookType::BookType()
{
    title = "";
    author = "";
    genre = "";
}
RelationBookType BookType::ComparedTo(BookType otherBook) const {
    
    if (title < otherBook.title)
        return LES;
    else if (title > otherBook.title)
        return GTR;
    else return EQL;
}
void BookType::Initialize(string thisTitle, string thisAuthor, string thisGenre)
{
    title = thisTitle;
    author = thisAuthor;
    genre = thisGenre;
}

void BookType::Initialize(string thisTitle) { title = thisTitle; }

void BookType::Print(std::ostream& out) const
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
    out << "Book: " << title << ", " << author << ", " << genre;
    std::cout  << "Book: " << title << ", " << author << ", " << genre;
}

string BookType::GetTitle() { return title; }

string BookType::GetAuthor() { return author; }

string BookType::GetGenre() { return genre; }
