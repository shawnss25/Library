#include <iostream>
#include "Library.hpp"
#include <string>

using std::cerr;
using std::endl;
using std::string;
using std::exception;
using std::getline;
using std::cin;
using std::cout;

Library::Library() {}

void Library::ProcessBooks(std::ifstream& in, std::ostream& out) {
    string title, author, genre; // Store the productName from a text file
    
    try {
        // Loop through inputted data from input file while not end of file
        while (!in.eof()) {
            // If UnsortedBooks is not full -> Add title, author, genre to list
            if (!UnsortedBooks.IsFull()) {
                
                // Takes in title, author, genre from in file
                getline(in, title);
                getline(in, author);
                getline(in, genre);
                
                InitializeBooks(title, author, genre, out); // Initialize books
            }else
                cerr << "\nError: List is full!\n\n";
        }
    } catch (exception& ex) {cerr << "\nFailed to process books.\n";}
}

void Library::InsertBook(std::ifstream& in, std::ostream& out) {
    // title, author, genre: Used for InitializeBooks() -> received from user
    // userResponse: If the user wants to insert another book
    // isCorrectInput: If user enters a valid input for either title, author or genre
    // moreBooksToEnter: Flag for if user wants to enter more books or not
    string title, author, genre, userResponse;
    bool isCorrectInput, moreBooksToEnter;
    
    cout << "\n---------\nINSERT\n---------\n";
    do{
        isCorrectInput = false;
        moreBooksToEnter = true;
        
        // Check to see if UnsortedBooks is full, if not get title, author and genre from user
        if(!UnsortedBooks.IsFull()) {
            do{
                cout << "Please enter the book's title: ";
                getline(cin, title);
                
                if(title != "")
                    isCorrectInput = true;
                else
                    cout << "\nThe entered title is invalid...Please enter a non-blank title.\n";
            }while(!isCorrectInput);
            isCorrectInput = false;
            
            do{
                cout << "\nPlease enter the book's author: ";
                getline(cin, author);
                
                if(author != "")
                    isCorrectInput = true;
                else
                    cout << "\nThe entered author is invalid...Please enter a non-blank author.\n";
            }while(!isCorrectInput);
            
            do{
                cout << "\nPlease enter the book's genre: ";
                getline(cin, genre);
                cout << endl;
                
                if(genre != "")
                    isCorrectInput = true;
                else
                    cout << "\nThe entered genre is invalid...Please enter a non-blank genre.\n";
            }while(!isCorrectInput);
            isCorrectInput = false;
            
            InitializeBooks(title, author, genre, out); // Initialize books
            
            cout << "\n~~~~~\nWould you like to enter another book? (YES/NO)";
            do {
                cout << "\nInput: ";
                getline(cin, userResponse);
                // If user is YES/NO, set bool flag to appropriate t/f
                if(userResponse == "YES" || userResponse == "NO") {
                    if(userResponse == "YES")
                        moreBooksToEnter = true;
                    else
                        moreBooksToEnter = false;
                    cout << "~~~~~\n";
                    isCorrectInput = true;
                }
                else
                    cerr << "\n******\nInvalid command...\nPlease enter either YES, or NO\n******\n";
                
            }while(!isCorrectInput);
        } else
            cerr << "\nError: List is full!\n\n";
        
    }while(moreBooksToEnter);
    cout << "\n---INSERT COMMAND COMPLETE---\n\n";
}

void Library::WriteInsert(std::ostream& out, BookType *TempBook) {
    
    //TempItem: Initialized to *TempBook which is the current book being saved
    //Item: Holds item from sorted lists
    // isTrue: used for GetCurrentItemPos
    ItemType TempItem, *Item = NULL;
    bool isTrue = false;
    
    TempItem.Initialize(*TempBook);
    
    // Print current unsorted book and current location in list
    cout << "INSERT. ";
    out << "INSERT. ";
    TempBook->Print(out);
    cout << ", CurPos: " << UnsortedBooks.GetCurrentItemPos(*TempBook, isTrue) << ", UnsortedBooks\n";
    out << ", CurPos: " << UnsortedBooks.GetCurrentItemPos(*TempBook, isTrue) << ", UnsortedBooks\n";
    
    // Print current unsorted book's corresponding title from SortedByTitle list and current location in list
    Item = SortedByTitle.GetItem(TempItem, isTrue, 't');
    cout << "INSERT. ";
    out << "INSERT. ";
    Item->PrintTitle(out);
    cout << ", CurPos: " << SortedByTitle.GetCurrentItemPos(*Item, isTrue, 't') << ", SortedByTitle\n";
    out << ", CurPos: " << SortedByTitle.GetCurrentItemPos(*Item, isTrue, 't') << ", SortedByTitle\n";
    
    // Print current unsorted book's corresponding author from SortedByTitle list and current location in list
    Item = SortedByAuthor.GetItem(TempItem, isTrue, 'a');
    cout << "INSERT. ";
    out << "INSERT. ";
    Item->PrintAuthor(out);
    cout << ", CurPos: " << SortedByAuthor.GetCurrentItemPos(*Item, isTrue, 'a') << ", SortedByAuthor\n";
    out << ", CurPos: " << SortedByAuthor.GetCurrentItemPos(*Item, isTrue, 'a') << ", SortedByAuthor\n";
    
    // Print current unsorted book's corresponding genre from SortedByTitle list and current location in list
    Item = SortedByGenre.GetItem(TempItem, isTrue, 'g');
    cout << "INSERT. ";
    out << "INSERT. ";
    Item->PrintGenre(out);
    cout << ", CurPos: " << SortedByGenre.GetCurrentItemPos(*Item, isTrue, 'g') << ", SortedByGenre\n";
    out << ", CurPos: " << SortedByGenre.GetCurrentItemPos(*Item, isTrue, 'g') << ", SortedByGenre\n";
}

void Library::InitializeBooks(string title, string author, string genre, std::ostream& out) {
    
    BookType NewBook, *ptr = NULL; // To store the new productName, itemNumber, price, and taxable
    ItemType NewTitle, NewAuthor, NewGenre; // To store title, author and genre in respective lists
    
    // Initialize book, put in unsorted list, print
    NewBook.Initialize(title, author, genre);
    ptr = UnsortedBooks.PutItem(NewBook);
    
    // Initialize NewTitle to address of NewBook title, add to sorted list, print
    NewTitle.Initialize(*ptr);
    SortedByTitle.PutItem(NewTitle, 't');
    
    // Initialize NewAuthor to address of NewBook author, add to sorted list, print
    NewAuthor.Initialize(*ptr);
    SortedByAuthor.PutItem(NewAuthor, 'a');
    
    // Initialize NewGenre to address of NewBook genre, add to sorted list, print
    NewGenre.Initialize(*ptr);
    SortedByGenre.PutItem(NewGenre, 'g');
    
    WriteInsert(out, ptr); // Write out to console and file INSERT commands
}

void Library::List(std::ostream& out) {
    string userInput; // Stores user's input
    bool isCorrectInput = false; // For do-while loop
    
    if(!UnsortedBooks.IsFull()) {
        cout << "\n---------\nLIST\n---------\n"
        << "Please enter how you would like to sort the books..."
        << "\nIf you would like to sort by title, please enter TITLE"
        << "\nIf you would like to sort by author, please enter AUTHOR"
        << "\nIf you would like to sort by genre, please enter GENRE\n---------";
        
        do{
            cout << "\nInput: ";
            getline(cin, userInput);
            cout << endl;
            // User input has to equal either TITLE, AUTHOR or GENRE. If not, re-loop
            if(userInput == "TITLE" || userInput == "AUTHOR" || userInput == "GENRE") {
                if(userInput == "TITLE") { PrintSortedByTitle(out); }
                if(userInput == "AUTHOR") { PrintSortedByAuthor(out); }
                if(userInput == "GENRE") { PrintSortedByGenre(out); }
                isCorrectInput = true;
            } else
                cerr << "\n******\nInvalid command...\nPlease enter either TITLE, AUTHOR, or GENRE\n******\n";
        }while(!isCorrectInput);
    } else
        cerr << "\nList is full!\n\n";
    cout << "\n---LIST COMMAND COMPLETE---\n";
}

void Library::PrintSortedByTitle(std::ostream& out) {
    ItemType Temp; // Temporarily holds next item
    bool isTrue; // Used for GetCurrentItemPos()
    SortedByTitle.ResetList(); // Reset list for looping
    
    // Loops through SortedByTitle list to print out items in order
    for(int itor = 0; itor < UnsortedBooks.GetLength(); itor++) {
        Temp = SortedByTitle.GetNextItem();
        cout << "LIST. ";
        out << "LIST. ";
        Temp.PrintTitle(out);
        cout << ", CurPos: " << SortedByTitle.GetCurrentItemPos(Temp, isTrue, 't') << ", SortedByTitle\n";
        out << ", CurPos: " << SortedByTitle.GetCurrentItemPos(Temp, isTrue, 't') << ", SortedByTitle\n";
    }
}

void Library::PrintSortedByAuthor(std::ostream& out) {
    ItemType Temp; // Temporarily holds next item
    bool isTrue; // Used for GetCurrentItemPos()
    SortedByAuthor.ResetList(); // Reset list for looping
    
    // Loops through SortedByAuthor list to print out items in order
    for(int itor = 0; itor < UnsortedBooks.GetLength(); itor++) {
        Temp = SortedByAuthor.GetNextItem();
        cout << "LIST. ";
        out << "LIST. ";
        Temp.PrintAuthor(out);
        cout << ", CurPos: " << SortedByAuthor.GetCurrentItemPos(Temp, isTrue, 'a') << ", SortedByAuthor\n";
        out << ", CurPos: " << SortedByAuthor.GetCurrentItemPos(Temp, isTrue, 'a') << ", SortedByAuthor\n";
    }
}

void Library::PrintSortedByGenre(std::ostream& out) {
    ItemType Temp; // Temporarily holds next item
    bool isTrue; // Used for GetCurrentItemPos()
    SortedByGenre.ResetList(); // Reset list for looping
    
    // Loops through SortedByGenre list to print out items in order
    for(int itor = 0; itor < UnsortedBooks.GetLength(); itor++) {
        Temp = SortedByGenre.GetNextItem();
        cout << "LIST. ";
        out << "LIST. ";
        Temp.PrintGenre(out);
        cout << ", CurPos: " << SortedByGenre.GetCurrentItemPos(Temp, isTrue, 'g') << ", SortedByGenre\n";
        out << ", CurPos: " << SortedByGenre.GetCurrentItemPos(Temp, isTrue, 'g') << ", SortedByGenre\n";
    }
}

void Library::DeleteBook(std::ostream& out) {
    string userInput; // Store user's input
    bool isTrue = false, deleteMore = false, isValid = false; // Used for do-while loop
    BookType TempBook, *ptr = NULL; // TempBook: Initializes user's input | *ptr: holds object that user wants to delete
    ItemType *DeleteObject, TempItem;
    
    cout << "\n---------\nDELETE\n---------\n";
    
    do {
        UnsortedBooks.ResetList(); // Reset list for looping
        cout << "\nPlease enter the title of the book you want to delete...\n"
        << "---\nTITLES:\n---\n";
        
        // Loop through all of the stored titles and display them on the screen
        for(int itor = 0; itor < UnsortedBooks.GetLength(); itor++) {
            ptr = UnsortedBooks.GetNextItem();
            cout << ptr->GetTitle() << endl;
        }
        
        do{
            cout << "---\nInput: ";
            getline(cin, userInput);
            
            TempBook.Initialize(userInput); // Initialize the user input title
            ptr = UnsortedBooks.GetItem(TempBook, isTrue); // Set ptr to the book, assuming it's found
            
            if(isTrue == false)
                cerr << "\n***\nInvalid title...\nPlease try again\n***\n";
        }while(!isTrue);
        
        cout << "DELETE. Book: " << TempBook.GetTitle() << ", Pos: " << UnsortedBooks.GetCurrentItemPos(TempBook, isTrue) << ", UnsortedBooks\n";
        out << "DELETE. Book: " << TempBook.GetTitle() << ", Pos: " << UnsortedBooks.GetCurrentItemPos(TempBook, isTrue) << ", UnsortedBooks\n";
        
        TempItem.Initialize(*ptr); // Initialize the address of the found book to DeleteTitle
        DeleteObject = SortedByTitle.GetItem(TempItem, isTrue, 't'); // Search for pointer associated with the deleted book's title
        SortedByTitle.DeleteItem(*DeleteObject, 't'); // Delete pointer to title
        
        DeleteObject = SortedByAuthor.GetItem(TempItem, isTrue, 'a'); // Search for pointer associated with the deleted book's author
        SortedByAuthor.DeleteItem(*DeleteObject, 'a'); // Delete pointer to author
        
        DeleteObject = SortedByGenre.GetItem(TempItem, isTrue, 'g'); // Search for the pointer associated with the deleted books's genre
        SortedByGenre.DeleteItem(*DeleteObject, 'g'); // Delete pointer to genre
        
        UnsortedBooks.DeleteItem(TempBook); // Delete book
        
        cout << "\nWould you like to delete another book? (YES/NO)\n";
        
        do {
            cout << "Input: ";
            getline(cin, userInput);
            
            if(userInput == "YES" || userInput == "NO") {
                if(userInput == "YES") {
                    isValid = false;
                    deleteMore = true;
                }else {
                    isValid = false;
                    deleteMore = false;
                }
            }
            else
                cerr << "\n***\nInvalid input...\nPlease enter either YES or NO\n***\n";
            
        }while(isValid);
    }while(deleteMore);
    
    cout << "\n---DELETE COMMAND COMPLETE---\n";
}

void Library::PrintBooks(std::ostream &out) {
    UnsortedBooks.ResetList(); // Reset list for printing
    BookType *TempBook; // Temporary BookType TempBook to hold the new .GetNextItem()
    
    cout << "\nUpdated Book's List:\n----\n";
    // Loop through all of the unsorted books in the list
    for(int itor = 0; itor < UnsortedBooks.GetLength(); itor++) {
        TempBook = UnsortedBooks.GetNextItem(); // Set TempBook to the returned book in UnsortedBooks
        
        // Console log and write to file title, author and genre
        cout << TempBook->GetTitle() << endl;
        cout << TempBook->GetAuthor() << endl;
        cout << TempBook->GetGenre() << endl;
        out << TempBook->GetTitle() << endl;
        out << TempBook->GetAuthor() << endl;
        out << TempBook->GetGenre() << endl;
    }
}
