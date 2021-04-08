#ifndef BookType_hpp
#define BookType_hpp

#include <fstream>
#include <string>

using std::string;

const int MAX_BOOKS = 1000;
enum RelationBookType  {LES, GTR, EQL, ERR};

class BookType
{
public:
    BookType();
    /*******************************************************************************
     *  Function Name: BookType()
     *  Parameters: None
     *  Return Value: None
     *  Purpose: Constructor
     *******************************************************************************/
    
    RelationBookType ComparedTo(BookType) const;
    /*******************************************************************************
     *  Function Name: ComparedTo()
     *  Parameters: BookType
     *  Return Value: RelationBookType
     *  Purpose: Compare BookType objects
     *******************************************************************************/
    
    void Print(std::ostream&) const;
    /*******************************************************************************
     *  Function Name: Print()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Print title, author and genre
     *******************************************************************************/
    
    void Initialize(string, string, string);
    /*******************************************************************************
     *  Function Name: Initialize()
     *  Parameters: string, string, string
     *  Return Value: void
     *  Purpose: Initialize passed in strings to respective title, author and genre values
     *******************************************************************************/
    
    void Initialize(string);
    /*******************************************************************************
     *  Function Name: Initialize()
     *  Parameters: string
     *  Return Value: void
     *  Purpose: Initialize passed in string to title
     *******************************************************************************/
    
    string GetTitle();
    /*******************************************************************************
     *  Function Name: GetTitle()
     *  Parameters: None
     *  Return Value: string
     *  Purpose: return the string title
     *******************************************************************************/
    
    string GetAuthor();
    /*******************************************************************************
     *  Function Name: GetAuthor()
     *  Parameters: None
     *  Return Value: string
     *  Purpose: return the string author
     *******************************************************************************/
    
    string GetGenre();
    /*******************************************************************************
     *  Function Name: GetGenre()
     *  Parameters: None
     *  Return Value: string
     *  Purpose: return the string genre
     *******************************************************************************/
    
private:
    // Store title, author and genre in strings
    string title;
    string author;
    string genre;
};
#endif
