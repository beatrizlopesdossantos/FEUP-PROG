#include "Board.h"


Board::Board() {

    cout << "What's the number of lines (minimum 6 and maximum 20)? "; //define the number of lines
    while (true) {
        cin >> lines;
        if (cin.peek() != '\n' || cin.fail() || lines > 20 || lines < 6) { //check if the input is correct
            cout << endl << "Error, invalid entry. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }

    cout << endl << "What's the number of columns(minimum 6 and maximum 20)? "; //define the number of columns
    while (true) {
        cin >> columns;
        if (cin.peek() != '\n' || cin.fail() || columns > 20 || columns < 6) { //check if the input is correct
            cout << endl << "Error, invalid entry. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }

    board.resize(lines); //define the size of the 2D vector with the number of lines and columns
    for (size_t i = 0; i < lines; ++i) {
        board[i].resize(columns);
        for (size_t j = 0; j < columns; j++) {
            board[i][j] = ' ';
        }
    }

    word = "";
    orientation = ' ';
    position = "";
}


void Board::setWord() { 
    cin >> word;
    word = upper(word);
}


void Board::setOrientation() { 
    cout << endl << "Which direction you want to put the word? Choose between 'V' (vertical) or 'H' (horizontal): ";
    while (true) {
        cin >> orientation;
        orientation = toupper(orientation);
        if (cin.peek() != '\n' || (orientation != 'V' && orientation != 'H')) { //check if the input is correct
            cout << endl << "The input is invalid. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            if (orientation == 'V') { //check if the word fits in the vertical
                if (word.size() > lines) {
                    cout << endl << "The word is to big for the board." << endl; 
                    cout << "Press any key to continue...";
                    (void)_getch(); clrscr();
                }
            }
            else if (orientation == 'H') { //check if the word fits in the horizontal
                if (word.size() > columns) {
                    cout << endl << "The word is to big for the board." << endl; 
                    cout << "Press any key to continue...";
                    (void)_getch(); clrscr();
                }
            }
            break;
        }
    }
}


void Board::setPosition() {
    cout << endl << "Now choose the line(from 'A' to '" << char(64 + lines) << "') and column (from 'a' to '" << char(96 + lines) << "') you want to put the word (example: Ab): ";
    while (true) { 
        cin >> position;
        position[0] = toupper(position[0]); //put the first letter in uppercase
        position[1] = tolower(position[1]); //put the second letter in lower case
        if (cin.peek() != '\n' || position.size() > 2 || position.size() < 2 || int(position[0]) < 64 || int(position[0]) > char(64 + lines) || int(position[1]) < 96 || int(position[1]) > char(96 + columns)) { //check if the input is correct
            cout << endl << "The input is invalid. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            break;
        }
    }
}


int Board::getLines() { 
    return lines;
} 


int Board::getColumns() {
    return columns;
}


string Board::getWord() {
    return word;
}


vector<string> Board::getVecWords() {
    return vecWords;
}


vector<char> Board::getVecOrientations() {
    return vecOrientations;
}


vector<string> Board::getVecPositions() {
    return vecPositions;
}


vector <vector<char>> Board::getBoard() {
    return board;
}


bool Board::validateWords(string wordToCheck) {                              
    string Myfileword;
    ifstream Myfile;
    Myfile.open("WORDS.txt");
    if (!Myfile.is_open()) { //check if the file is open
        cerr << "\nUnable to open the dictionary file to check if the word is valid. Please put the file available and try again.\n";
        exit(-1);
    }
    while (!Myfile.eof()) {
        while (getline(Myfile, Myfileword)) {
            Myfileword = upper(Myfileword); //put the word of the dictionary in uppercase
            if (Myfileword == word) {
                return true;
            }
        }
        break;
    }
    Myfile.close(); //close the file
    return false;
}


bool Board::validateposition() {
    int indexl = position[0] - 65; //index of the line
    int indexc = position[1] - 97; //index of the colum
    int indexlastl = indexl + word.size() - 1; //index of line of the last letter of the word 
    int indexlastc = indexc + word.size() - 1; //index of column of the last letter of the word 
    if ((orientation == 'V' && indexl + word.size() > lines) || (orientation == 'H' && indexc + word.size() > columns)) { //see if the word fits in the position
        cout << "\nThe word doesn't fit the position you entered.\n\nPress any key to continue...";
        (void)_getch(); clrscr();
        return false;
    }
    for (int i = 0; i < word.size(); i++) { //see if the word doesn't interfier with others
        if (orientation == 'V') {
            if (board[indexl + i][indexc] != word[i] && board[indexl + i][indexc] != ' ') {
                cout << "\nThe position interfiers with other words.\n\nPress any key to continue...";
                (void)_getch(); clrscr();
                return false;
            }
        }
        else if (orientation == 'H') {
            if (board[indexl][indexc + i] != word[i] && board[indexl][indexc + i] != ' ') {
                cout << "\nThe position interfiers with other words.\n\nPress any key to continue...";
                (void)_getch(); clrscr();
                return false;
            }
        }
    }
    if (orientation == 'V' && indexl != 0 && board[indexl - 1][indexc] != ' ') { //see if the word is not right before or after other word
        cout << "\nThere is a word right before that position, they need to have at least one free case between them.\n\nPress any key to continue...";
        (void)_getch(); clrscr();
        return false;
    }
    else if (orientation == 'V' && indexlastl != (lines - 1) && board[indexl + word.size()][indexc] != ' ') {
        cout << "\nThere is a word right after that position, they need to have at least one free case between them.\n\nPress any key to continue...";
        (void)_getch(); clrscr();
        return false;
    }
    else if (orientation == 'H' && indexc != 0 && board[indexl][indexc - 1] != ' ') {
        cout << "\nThere is a word right before that position, they need to have at least one free case between them.\n\nPress any key to continue...";
        (void)_getch(); clrscr();
        return false;
    }
    else if (orientation == 'H' && indexlastc != (columns - 1) && board[indexl][indexc + word.size()] != ' ') {
        cout << "\nThere is a word right after that position, they need to have at least one free case between them.\n\nPress any key to continue...";
        (void)_getch(); clrscr();
        return false;
    }
    for (int i = 0; i < word.size(); i++) { //if it can be added, put it in the board vector
        if (orientation == 'V') {
            board[indexl + i][indexc] = word[i];
        }
        else if (orientation == 'H') {
            board[indexl][indexc + i] = word[i];
        }
    }
    return true;
}


void Board::addToVectores() {
    vecWords.push_back(word);
    vecOrientations.push_back(orientation);
    vecPositions.push_back(position);
}


void Board::updateBoard() {
    clrscr();
    for (int i = 0; i <= columns; i++) {
        setcolor(DARKGRAY, BLACK);
        if (i == 0) {
            cout << "   ";
        }
        else {
            cout << " " << char(96 + i) << " "; //add the columns letters, from 'a' to the size that the user wants
        }
    }
    cout << endl;
    for (int i = 0; i < lines; i++) {
        setcolor(8, 0);
        cout << " " << char(65 + i) << " "; //add the lines letters, from 'A' to the size that the user wants
        for (int j = 0; j < columns; j++) {
            setcolor(BLACK, DARKGRAY);
            cout << " " << board[i][j] << " "; //add the new words
           
        }
        setcolor(DARKGRAY, BLACK);
        cout << endl;
    }
    cout << endl;
    setcolor(WHITE, BLACK);
}


void Board::clearVec() { //clears all the board
    board.clear();
    vecWords.clear();
    vecOrientations.clear();
    vecPositions.clear();
    lines = 0;
    columns = 0;
}