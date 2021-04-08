// ItemType for sorted list

#ifndef ItemType_hpp
#define ItemType_hpp

#include <fstream>
#include "BookType.hpp"

enum RelationType  {LESS, GREATER, EQUAL, ERROR};
const int MAX_ITEMS = 1000;

class ItemType
{
public:
    ItemType();
    /*******************************************************************************
     *  Function Name: ItemType()
     *  Parameters: None
     *  Return Value: None
     *  Purpose: Constructor
     *******************************************************************************/
    
    RelationType ComparedTo(ItemType, char) const;
    /*******************************************************************************
     *  Function Name: ComparedTo()
     *  Parameters: ItemType, char
     *  Return Value: RelationType Enum
     *  Purpose: Depending on the type of sort, compare objects on either title, author or genre
     *******************************************************************************/
    
    void Initialize(BookType&);
    /*******************************************************************************
     *  Function Name: Initialize()
     *  Parameters: BookType&
     *  Return Value: void
     *  Purpose: Set BookType address to the stored pointer
     *******************************************************************************/
    
    BookType* GetPtr();
    /*******************************************************************************
     *  Function Name: GetPtr()
     *  Parameters: None
     *  Return Value: BookType*
     *  Purpose: Get the pointer to the object
     *******************************************************************************/
    
    void PrintTitle(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintTitle()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Prints title to console and writes to file
     *******************************************************************************/
    
    void PrintAuthor(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintAuthor()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Prints author to console and writes to file
     *******************************************************************************/
    
    void PrintGenre(std::ostream&);
    /*******************************************************************************
     *  Function Name: PrintGenre()
     *  Parameters: std::ostream&
     *  Return Value: void
     *  Purpose: Prints genre to console and writes to file
     *******************************************************************************/
    
private:
    // Store address to BookType object
    BookType *ptr;
};
#endif
