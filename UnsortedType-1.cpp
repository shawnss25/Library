#include "UnsortedType.hpp"
#include <iostream>

UnsortedType::UnsortedType()
{
    length = 0;
}
bool UnsortedType::IsFull() const
{
    return (length == MAX_BOOKS);
}
int UnsortedType::GetLength() const
{
    return length;
}

BookType* UnsortedType::GetItem(BookType &item, bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the
//       list and a copy of that element has been returned;
//       otherwise, item is returned.
{
    bool moreToSearch;
    int location = 0;
    found = false;
    BookType *ptr = NULL;
    
    moreToSearch = (location < length);
    
    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LES    :
            case GTR : location++;
                moreToSearch = (location < length);
                break;
            case EQL   : found = true;
                ptr = &info[location];
                break;
            case ERR:
                std::cerr << "\nItem not found\n";
        }
    }
    return ptr;
}
void UnsortedType::MakeEmpty()
// Post: list is empty.
{
    length = 0;
}
BookType* UnsortedType::PutItem(BookType &item)
// Post: item is in the list.
{
    info[length] = item;
    length++;
    
    return &info[length-1];
}

void UnsortedType::DeleteItem(BookType &item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    int location = 0;
    
    while (item.ComparedTo(info[location]) != EQL)
        location++;
    
    info[location] = info[length - 1];
    length--;
}
void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}

BookType* UnsortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
    currentPos++;
    return &info[currentPos];
}

int UnsortedType::GetCurrentItemPos(BookType item, bool& found) {
    bool moreToSearch;
    int location = 0;
    found = false;
    
    moreToSearch = (location < length);
    
    while (moreToSearch && !found)
    {
        switch (item.ComparedTo(info[location]))
        {
            case LES    :
            case GTR : location++;
                moreToSearch = (location < length);
                break;
            case EQL   : found = true;
                item = info[location];
                break;
            case ERR:
                std::cerr << "\nItem not found\n";
        }
    }
    return location;
}
