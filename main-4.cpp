/*******************************************************************************
 *  Program Name: Program 4
 *  Created Date: 3/28/19
 *  Created By: Shawn Sewell-Snyder
 *  Purpose: To keep track of books
 *  Acknowledgements: None
 *******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "Library.hpp"

using std::ifstream;
using std::ofstream;
using std::cerr;
using std::endl;
using std::exception;
using std::string;
using std::cout;

void PromptUser();
string GetUserInput();


int main() {
    Library myLibrary; // Library object created
    string userInput; // Holds userInput from GetUserInput()
    bool isTrue = false;
    
    try {
        // Create files
        ifstream iFile;
        ofstream commandFile;
        ofstream oFile;
        
        // Open files
        iFile.open("Books.txt");
        commandFile.open("commandFile.txt");
        
        myLibrary.ProcessBooks(iFile, commandFile); // Process input file with books
        
        iFile.close(); // Close iFile so it can be opened as an output file
        oFile.open("Books.txt");
        
        PromptUser(); // Prompt the user with the user interface
        
        do{
            userInput = GetUserInput(); // Get user input for if they want to insert, delete, list or quit
            if (userInput == "INSERT"){
                cout << "INSERT. User Input\n";
                commandFile << "INSERT. User Input\n";
                myLibrary.InsertBook(iFile, commandFile); // Call INSERT command
            }else if (userInput == "LIST"){
                cout << "LIST. User Input\n";
                commandFile << "LIST. User Input\n";
                myLibrary.List(commandFile); // Call LIST command
            }else if (userInput == "QUIT") {
                cout << "QUIT. \n";
                commandFile << "QUIT. \n";
                myLibrary.PrintBooks(oFile); // Print final list of books
                return 0;
            }
            else if (userInput == "DELETE") {
                cout << "DELETE. User Input\n";
                commandFile << "DELETE. User Input \n";
                myLibrary.DeleteBook(commandFile); // call DELETE command
            }
            
            cout << "\n----\nWould you like to enter another command? (YES/NO)";
            do {
                cout << "\nInput: ";
                getline(std::cin, userInput);
                if(userInput == "YES" || userInput == "NO") {
                    if(userInput == "NO") {
                        cout << "QUIT. \n";
                        commandFile << "QUIT. \n";
                        myLibrary.PrintBooks(oFile); // Print final list of books
                        isTrue = true;
                    } else {
                        cout << "\nOptions: INSERT, LIST, DELETE, QUIT";
                        break;
                    }
                } else
                    cerr << "\n******\nInvalid command...\nPlease enter either YES, or NO\n******\n";
            }while(userInput != "NO");
        }while(!isTrue);
        
        // Close files
        commandFile.close();
        oFile.close();
        
    }catch(exception& ex) {
        cerr << "\nSomething went wrong...\n";
    }
    return 0;
}

void PromptUser() {
    cout << "\n---------\nWelcome to the library inventory database\n---------\n"
    << "If you would like to insert a new book, type INSERT\n"
    << "If you would like to delete a book, type DELETE\n"
    << "If you would like to list the books in a specific order, type LIST\n"
    << "If you would like to quit this program, type QUIT\n---------";
}

string GetUserInput() {
    string userInput = ""; // Store user input
    bool isCorrectInput = false; // Boolean flag for do-while loop
    
    do{
        cout << "\nCommand: ";
        getline(std::cin, userInput);
        
        // If user input is equal to any of the correct commands- end loop, else- loop again to get user's new input
        if(userInput == "INSERT" || userInput == "DELETE" || userInput == "LIST" || userInput == "QUIT")
            isCorrectInput = true;
        else
            cerr << "\n******\nInvalid command...\nPlease enter either INSERT, DELETE, LIST or QUIT\n******\n";
    }while(!isCorrectInput);
    
    return userInput;
}
