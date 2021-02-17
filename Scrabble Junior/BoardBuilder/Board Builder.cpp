#include "Board.h"
#include "Useful.h"


//welcomes the user
void menu() { 
    cout << "\n\n\n\n\n\n\n\n\n\n" << setw(101) << "Welcome!!! This program has the purpose to make a board for Scrabble Junior game.\n\n\n" << setw(70) << "To start press any key.";
    (void)_getch(); clrscr();
}

//add words to the board
bool addWords(Board& board) {
    string wordToCheck;
    cout << "Type the word you want to place in the board bigger than one character" << endl << "(If you don't want to place more words press 'CTRL-Z', if you want to delete\neverything and end the game type 'STOPPP' or 'stoppp'): ";
    while (true) {
        board.setWord();
        wordToCheck = board.getWord();
        if (cin.eof()) { //if the input equal to 'CTRL-Z'
            cin.clear();
            int countLetters = 0;
            for (int i = 0; i < board.getLines(); i++) { //counts the number of letters to check if there are 28
                for (int j = 0; j < board.getColumns(); j++) {
                    if (board.getBoard()[i][j] != ' ') {
                        countLetters++;
                    }
                }
            }
            if (countLetters < 28) {
                cout << endl << "You need at least 28 letters to make the board. \n\nIf there aren't any positions to put more words type 'STOPPP' or 'stoppp'\nand nothing will be saved, otherwise introduce more words: ";
            }
            else {
                break;
            }
        }
        else if (wordToCheck == "STOPPP") { //clears all the board
            board.clearVec();
            break;
        }
        else if (cin.peek() != '\n' || wordToCheck.size() == 1 || !(board.validateWords(wordToCheck))) { //checks if the input is valid or exists
            cout << endl << "The word is invalid. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');

        }
        else {
            if (board.validateWords(wordToCheck)) { //if the input is valid, return true
                board.setOrientation();
                board.setPosition();
                return true;
            }
        }
    }
    return false;
}

//add all of the elements to the file
void addToFile(Board& board) {
    if (board.getLines() == 0 && board.getColumns() == 0) {
        return;
    }
    ofstream outfile("board.txt");
    outfile << board.getLines() << " x " << board.getColumns(); //write on the .txt file the size of the board
    for (size_t i = 0; i < board.getVecWords().size(); i++) {
        outfile << endl << board.getVecPositions()[i] << " " << board.getVecOrientations()[i] << " " << board.getVecWords()[i]; //write on the .txt file the words, orientations and positions
    }
    outfile.close();
}

int main()
{
    menu();
    Board board;
    board.updateBoard(); //outputs the empty board
    while (addWords(board)) { //while the user wnats to add words
        if (board.validateposition()) {
            board.addToVectores();
            board.updateBoard();
        }
        else {
            board.updateBoard();
        }
    }
    addToFile(board);
}

