#ifndef Library_hpp
#define Library_hpp

#include "BookType.hpp"
#include "ItemType.hpp"
#include "UnsortedType.hpp"
#include "SortedType.hpp"

class Library {
    
private:
    UnsortedType UnsortedBooks; // Store BookType objects that are INSERTed and read in from text file
    SortedType SortedByTitle; // Store pointers to BookType objects title from unsorted list
    SortedType SortedByAuthor; // Store pointers to BookType objects author from unsorted list
    SortedType SortedByGenre; // Store pointers to BookType objects genre from unsorted list
public:
    Library();
    /*******************************************************************************
     *  Function Name: Library()
     *  Parameters: None
     *  Return Value: None
     *  Purpose: Constructor
     *******************************************************************************/
    
    void ProcessBooks(std::ifstream&, std::ostream&);
    /*******************************************************************************
     *  Function Name: ProcessBooks()
     *  Parameters: std::ifstream&, std::ostream&
     *  Return Value: void
     *  Purpose: Read books in from text file
     *******************************************************************************/
    
    void InsertBook(std::ifstream&, std::ostream&);
    /*******************************************************************************
     *  Function Name: InsertBook()
     *  Parameters: std::ifstream&, std::ostream&
     *  Return Value: void
     *  Purpose: Prompt user to insert a book (title, author, genre) and put into respective lists
     *******************************************************************************/
    
    void WriteInsert(std::ostream&, BookType*);
    /*******************************************************************************
     *  Function Name: WriteInsert()
     *  Parameters: std::ostream&, BookType*
     *  Return Value: void
     *  Purpose: Write INSERT message to console and commandFile
     *******************************************************************************/
    
    void InitializeBooks(string, string, string, std::ostream&);
    /*******************************************************************************
     *  Function Name: InitializeBooks()
     *  Parameters: string, string, string, std::ostream&
     *  Return Value: void
     *  Purpose: Initialize the entered books and store them in respective lists
     *******************************************************************************/
    
    void List(std::ostream&);
    /*******************************************************************************
     *  Function Name: List()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Prompt user to see how they want to list the books (by title, author, or genre)
     *******************************************************************************/
    
    void DeleteBook(std::ostream& out);
    /*******************************************************************************
     *  Function Name: DeleteBook()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Prompt user to see which book they want to delete. Delete book from unsorted list and remove respective objects in sorted lists
     *******************************************************************************/
    
    void PrintSortedByTitle(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintSortedByTitle()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Print all contents of the SortedByTitle list
     *******************************************************************************/
    
    void PrintSortedByAuthor(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintSortedByAuthor()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Print all contents of the SortedByAuthor list
     *******************************************************************************/
    
    void PrintSortedByGenre(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintSortedByGenre()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Print all contents of the SortedByGenre list
     *******************************************************************************/
    
    void PrintBooks(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintBooks()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Print Title, Author, Genre to Books.txt
     *******************************************************************************/
};
#endif

