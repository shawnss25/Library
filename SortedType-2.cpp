#include "SortedType.hpp"
#include <iostream>

SortedType::SortedType()
{
    length = 0;
}

void SortedType::MakeEmtpy()
{
    length = 0;
}

bool SortedType::IsFull() const
{
    return (length == MAX_ITEMS);
}

int SortedType::GetLength() const
{
    return length;
}

ItemType* SortedType::GetItem(ItemType &item, bool& found, char typeOfSort)
{
    int midPoint;
    int first = 0;
    int last = length - 1;
    ItemType *ptr = NULL;
    
    bool moreToSearch = first <= last;
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        switch (item.ComparedTo(info[midPoint], typeOfSort))
        {
            case LESS    : last = midPoint - 1;
                moreToSearch = first <= last;
                break;
            case GREATER : first = midPoint + 1;
                moreToSearch = first <= last;
                break;
            case EQUAL   : found = true;
                ptr = &info[midPoint];
                break;
            case ERROR:
                std::cerr << "\n*** Item could not be found ***\n";
                break;
        }
    }
    return ptr;
}

void SortedType::DeleteItem(ItemType &item, char typeOfSort)
{
    int location = 0;
    
    while (item.ComparedTo(info[location], typeOfSort) != EQUAL)
        location++;
    for (int index = location + 1; index < length; index++)
        info[index - 1] = info[index];
    length--;
}

void SortedType::PutItem(ItemType &item, char typeOfSort)
{
    bool moreToSearch;
    int location = 0;
    
    moreToSearch = (location < length);
    while (moreToSearch)
    {
        switch (item.ComparedTo(info[location], typeOfSort))
        {
            case LESS    : moreToSearch = false;
                break;
            case GREATER : location++;
                moreToSearch = (location < length);
                break;
            case EQUAL:
                break;
            case ERROR:
                std::cerr << "\nCouldn't add type: " << typeOfSort << std::endl;
                moreToSearch = false;
                break;
        }
    }
    for (int index = length; index > location; index--)
        info[index] = info[index - 1];
    info[location] = item;
    length++;
}

void SortedType::ResetList()
// Post: currentPos has been initialized.
{
    currentPos = -1;
}

ItemType SortedType::GetNextItem()
// Post: item is current item.
//       Current position has been updated.
{
    currentPos++;
    return info[currentPos];
}

int SortedType::GetCurrentItemPos(ItemType item, bool& found, char typeOfSort) {
    int midPoint;
    int first = 0;
    int last = length - 1;
    
    bool moreToSearch = first <= last;
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        switch (item.ComparedTo(info[midPoint], typeOfSort))
        {
            case LESS    : last = midPoint - 1;
                moreToSearch = first <= last;
                break;
            case GREATER : first = midPoint + 1;
                moreToSearch = first <= last;
                break;
            case EQUAL   : found = true;
                item = info[midPoint];
                break;
            case ERROR:
                std::cerr << "\n*** Item could not be found ***\n";
                break;
        }
    }
    return midPoint;
}
