#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include<conio.h>

using namespace std;
#define BLUE 1
#define MAGENTA 5
#define LIGHTBLUE 9
#define LIGHTCYAN 11
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
int scoreplayer1 = 0, scoreplayer2 = 0;
const int holes = 12;
int board[holes];
int turnNum = 1;
bool playing = true;

void clrscr(void)
{
    COORD coordScreen = { 0, 0 }; // upper left corner
    DWORD cCharsWritten;
    DWORD dwConSize;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hCon, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    // fill with spaces
    FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hCon, &csbi);
    FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    // cursor to upper left corner
    SetConsoleCursorPosition(hCon, coordScreen);
}

void Color(unsigned int color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}

void Rules() {
    Color(14); cout << endl << setw(65) << "OWARE GAME" << endl;
    Color(11); cout << "\nRules:\n\nEach move of the game is done in three phases: collecting, sowing and capturing." << endl << "1. The player who is to move chooses one of the holes on his own side of the board collecting all the seeds from it.\n2. The player distributes the seeds collected in the first phase along the board in a counterclockwise direction\ndropping one seed in each holes until all the seeds are distributed.\n3. A player will never sow in the holes from which the seeds were collected.\n4. When the last sown seed is dropped in one of the opponent's hole, and after dropping the seed\nthe hole contains exactly two or three seeds, the player will capture and save them.\n5. When the hole on the right of the last pit from which seeds were captured contains also two or three seeds,\nthe player will capture them too, and so on until the player cannot capture more seeds.\n6. The game is over when one of the players has captured more than 24 seeds or when both have captured 24 seeds." << endl;
    cout << endl << "The first player to make a move is in the south side (blue player)." << endl << "Each letter corresponds to the hole above (blue player) or below (magenta player).\nYou have to choose the letter you want to move the seeds.\n\n" << endl << "Press any key to continue...";
    _getch(); Color(15); clrscr();
}

int Board(int board[]) {
    Color(14); cout << endl << setfill(' ') << setw(65) << "OWARE GAME" << endl;
    Color(13); cout << endl << "Score: " << scoreplayer2 << endl;
    Color(5); cout << endl << "    l        k        j        i        h        g";
    Color(15); cout << endl << "-------------------------------------------------------" << endl << "|        |        |        |        |        |        |" << endl << "|   ";
    for (int i = 11; i > 6; i--) {
        if (board[i] == 0) {
            Color(15); cout << setfill(' ') << setw(2) << board[i] << "   |   ";
        }
        else {
            Color(13); cout << setfill(' ') << setw(2) << board[i];
            Color(15); cout << "   |   ";
        }
    }
    if (board[6] == 0) {
        Color(15); cout << setfill(' ') << setw(2) << board[6];
    }
    else {
        Color(13); cout << setfill(' ') << setw(2) << board[6];
    }
    Color(15); cout << "   |" << endl << "|        |        |        |        |        |        |" << endl << "|-----------------------------------------------------|" << endl << "|        |        |        |        |        |        |" << endl << "|   ";
    for (int i = 0; i < 5; i++) {
        if (board[i] == 0) {
            Color(15); cout << setfill(' ') << setw(2) << board[i] << "   |   ";
        }
        else {
            Color(9); cout << setfill(' ') << setw(2) << board[i];
            Color(15); cout << "   |   ";
        }
    }
    if (board[5] == 0) {
        Color(15); cout << setfill(' ') << setw(2) << board[5];
    }
    else {
        Color(9); cout << setfill(' ') << setw(2) << board[5];
    }
    Color(15); cout << "   |" << endl << "|        |        |        |        |        |        |" << endl << "-------------------------------------------------------" << endl;
    Color(1); cout << "    a        b        c        d        e        f" << endl;
    Color(9); cout << endl << "Score: " << scoreplayer1 << endl;
    Color(15);
    return 0;
}

int Playagain(bool Validoperation) {
    Color(14); cout << endl << setw(65) << "OWARE GAME" << endl;
    Color(11); cout << endl << setw(68) << "_______________\n" << setw(52) << "|" << setw(16) << "|" << endl << setw(69) << "| 1. Play Game  |\n" << setw(61) << "| 2. Rules" << setw(8) << "|\n" << setw(61) << "| 3. Quit " << setw(7) << "|" << endl << setw(69) << "|_______________|\n" << endl << endl << setw(73) << "Enter the number you want: ";
    for (int i = 0; i < 12; i++) {
        board[i] = 4;
    }
    scoreplayer1 = 0;
    scoreplayer2 = 0;
    int command;
    cin >> command;
    bool notit = false;
    while (notit == false) {
        if (cin.peek() != '\n' || cin.fail() || (command != 1 && command != 2 && command != 3)) {
            clrscr();
            Color(14); cout << endl << setw(65) << "OWARE GAME" << endl;
            Color(11); cout << endl << setw(68) << "_______________\n" << setw(52) << "|" << setw(16) << "|" << endl << setw(69) << "| 1. Play Game  |\n" << setw(61) << "| 2. Rules" << setw(8) << "|\n" << setw(61) << "| 3. Quit " << setw(7) << "|" << endl << setw(69) << "|_______________|\n";
            cin.clear();
            cin.ignore(10000000, '\n');
            cout << endl << endl << setw(74) << "Choose only between 1, 2 and 3: ";
            cin >> command;
            notit = false;
        }
        else {
            notit = true;
        }
    }
    switch (command) {
    case 1:
        clrscr();
        Board(board);
        Validoperation = true;
        turnNum = 1;
        playing = true;
        break;
    case 2:
        clrscr();
        Rules();
        Playagain(Validoperation);
        Validoperation = true;
        turnNum = 1;
        playing = true;
        break;
    case 3:
        clrscr();
        Validoperation = true;
        playing = false;
        exit(1);
        break;
    }
    
    return 0;
}

int Winner(bool Validoperation) {
    clrscr();
    Board(board);
    if (scoreplayer1 > scoreplayer2) {
        Color(1); cout << "\nThe winner is PLAYER ONE (blue side)! Congratulations.\n" << endl;
    }
    else if (scoreplayer1 < scoreplayer2) {
        Color(5); cout << "\nThe winner is PLAYER TWO (magenta side)! Congratulations.\n" << endl;
    }
    else if (scoreplayer1 == scoreplayer2) {
        Color(14); cout << "\nIt's a tie *_*.\n" << endl;
    }
    cout << "Press any key to continue...";
    _getch(); clrscr();
    Playagain(Validoperation);
    return 0;
}

int Impossible(bool Validoperation) {
    if ((board[6] == 0) && (board[7] == 0) && (board[8] == 0) && (board[9] == 0) && (board[10] == 0) && (board[11] == 0)) {
        if (((board[0] < 6) && (board[1] < 5) && (board[2] < 4) && (board[3] < 3) && (board[4] < 2) && (board[5] == 0)) || (turnNum == 2)) {
            Color(11); cout << "\nThere is no more possible moves. The game is over.\n" << endl;
            cout << "Press any key to continue...";
            _getch();
            scoreplayer1 = scoreplayer1 + board[0] + board[1] + board[2] + board[3] + board[4] + board[5];
            for (int i = 0; i < 12; i++) {
                board[i] = 0;
            }
        }
    }
    else if ((board[0] == 0) && (board[1] == 0) && (board[2] == 0) && (board[3] == 0) && (board[4] == 0) && (board[5] == 0)) {
        if (((board[6] <= 5) && (board[7] <= 4) && (board[8] <= 3) && (board[9] <= 2) && (board[10] <= 1) && (board[11] == 0)) || (turnNum == 1)) {
            Color(11); cout << "\nThere is no more possible moves. The game is over.\n" << endl;
            cout << "Press any key to continue...";
            _getch();
            scoreplayer2 = scoreplayer2 + board[6] + board[7] + board[8] + board[9] + board[10] + board[11];
            for (int i = 0; i < 12; i++) {
                board[i] = 0;
            }
        }
    }
    Winner(Validoperation);
    return 0;
}

int Player1(bool Validoperation) {
    bool rightletter = false;
    Color(1); cout << "\nPlayer One (blue side): ";
    char letter;
    //Saber se a letra é a certa
    while (rightletter == false) {
        Color(11); cin >> letter;
        letter = tolower(letter);
        if (cin.peek() != '\n' || (letter != 'a') && (letter != 'b') && (letter != 'c') && (letter != 'd') && (letter != 'e') && (letter != 'f')) {
            clrscr();
            cin.clear();
            cin.ignore(10000000, '\n');
            Board(board);
            Color(1); cout << "\nChoose only between the letters a, b, c, d, e or f: " ;
        }
        //Saber se tem sementes
        else if (board[int(letter) - 97] == 0) {
            clrscr();
            cin.clear();
            cin.ignore(10000000, '\n');
            Board(board);
            Color(1); cout << "\nChoose a house that has seeds: ";
        }
        //Saber se as casas são válidas
        else if ((board[6] == 0) && (board[7] == 0) && (board[8] == 0) && (board[9] == 0) && (board[10] == 0) && (board[11] == 0)) {
            if ((int(letter) - 97 == 0 && board[0] <= 5 && board[0] > 0) || (int(letter) - 97 == 1 && board[1] <= 4 && board[1] > 0) || (int(letter) - 97 == 2 && board[2] <= 3 && board[2] > 0) || (int(letter) - 97 == 3 && board[3] <= 2 && board[3] > 0) || (int(letter) - 97 == 4 && board[4] <= 1 && board[4] > 0)) {
                clrscr();
                cin.clear();
                cin.ignore(10000000, '\n');
                Board(board);
                Color(1); cout << "\nThat's an illegal move. Be carefull! Introduce another letter: ";
            }
            else if ((letter == 'a') || (letter == 'b') || (letter == 'c') || (letter == 'd') || (letter == 'e') || (letter == 'f')) {
                rightletter = true;
            }
        }
        else if ((letter == 'a') || (letter == 'b') || (letter == 'c') || (letter == 'd') || (letter == 'e') || (letter == 'f')) {
            rightletter = true;
        }
    }
    int startposition = int(letter) - 97;
    int seeds = board[startposition];
    //Adicionar as sementes
    for (int i = startposition + 1; seeds > 0; i++) {
        int a = (i % 12);
        if (a != startposition) {
            board[a] += 1;
            seeds--;
        }
    }
    int lastposition;
    if (seeds >= 12) {
        lastposition = startposition + 1;
    }
    else if (seeds < 12) {
        lastposition = (startposition + board[startposition]) % 12;
    }
    if ((lastposition == 6) || (lastposition == 7) || (lastposition == 8) || (lastposition == 9) || (lastposition == 10) || (lastposition == 11)) {
        if (board[lastposition] == 2) {
            scoreplayer1 += 2;
            board[lastposition] = 0;
            for (int i = lastposition - 1; i > 5; i--) {
                if (board[i] == 2) {
                    board[i] = 0;
                    scoreplayer1 += 2;
                }
                else if (board[i] == 3) {
                    board[i] = 0;
                    scoreplayer1 += 3;
                }
                else {
                    break;
                }
            }
            clrscr();
            Color(1);  cout << "\nYOU SCORED!!!!\n" << endl << "Press any key to continue...";
            _getch();
            Board(board);
        }
        else if (board[lastposition] == 3) {
            board[lastposition] = 0;
            scoreplayer1 += 3;
            for (int i = lastposition - 1; i > 5; i--) {
                if (board[i] == 2) {
                    board[i] = 0;
                    scoreplayer1 += 2;
                }
                else if (board[i] == 3) {
                    board[i] = 0;
                    scoreplayer1 += 3;
                }
                else {
                    break;
                }
            }
            clrscr();
            Color(1);  cout << "\nYOU SCORED!!!!\n" << endl << "Press any key to continue...";
            _getch();
            Board(board);
        }
    }
    turnNum = 2;
    board[startposition] = 0;
    clrscr();
    Board(board);
    return 0;
}

int Player2(bool Validoperation) {
    bool rightletter = false;
    char word;
    Color(5); cout << "\nPlayer two (magenta side): ";
    while (rightletter == false) {
        Color(11); cin >> word;
        word = tolower(word);
        if (cin.peek() != '\n' || (word != 'g') && (word != 'h') && (word != 'i') && (word != 'j') && (word != 'k') && (word != 'l')) {
            clrscr();
            cin.clear();
            cin.ignore(10000000, '\n');
            Board(board);
            Color(5); cout << "\nChoose only between the letters g, h, i, j, k or l: ";
        }
        else if (board[int(word) - 97] == 0) {
            clrscr();
            cin.clear();
            cin.ignore(10000000, '\n');
            Board(board);
            Color(5); cout << "\nChoose a house that has seeds: ";
        }
        else if ((board[0] == 0) && (board[1] == 0) && (board[2] == 0) && (board[3] == 0) && (board[4] == 0) && (board[5] == 0)) {
            if ((int(word) - 97 == 6 && board[6] <= 5 && board[6] > 0) || (int(word) - 97 == 7 && board[7] <= 4 && board[7] > 0) || (int(word) - 97 == 8 && board[8] <= 3 && board[8] > 0) || (int(word) - 97 == 9 && board[9] <= 2 && board[9] > 0) || (int(word) - 97 == 10 && board[10] <= 1 && board[10] > 0)) {
                clrscr();
                cin.clear();
                cin.ignore(10000000, '\n');
                Board(board);
                Color(5); cout << "\nThat's an illegal move. Be carefull! Introduce another letter: ";
            }
            else if ((word == 'g') || (word == 'h') || (word == 'i') || (word == 'j') || (word == 'k') || (word == 'l')) {
                rightletter = true;
            }
        }
        else if ((word == 'g') || (word == 'h') || (word == 'i') || (word == 'j') || (word == 'k') || (word == 'l')) {
            rightletter = true;
        }
    }
    int startposition = int(word) - 97;
    int seeds = board[startposition];
    for (int i = startposition + 1; seeds > 0; i++) {
        int a = (i % 12);
        if (a != startposition) {
            board[a] += 1;
            seeds--;
        }
    }
    int lastposition;
    if (seeds >= 12) {
        lastposition = startposition + 1;
    }
    else if (seeds < 12) {
        lastposition = (startposition + board[startposition]) % 12;
    }
    if ((lastposition == 0) || (lastposition == 1) || (lastposition == 2) || (lastposition == 3) || (lastposition == 4) || (lastposition == 5)) {
        if (board[lastposition] == 2) {
            board[lastposition] = 0;
            scoreplayer2 += 2;
            for (int i = lastposition - 1; i > -1; i--) {
                if (board[i] == 2) {
                    board[i] = 0;
                    scoreplayer2 += 2;
                }
                else if (board[i] == 3) {
                    board[i] = 0;
                    scoreplayer2 += 3;
                }
                else {
                    break;
                }
            }
            clrscr();
            Color(5);  cout << "\nYOU SCORED!!!!\n" << endl << "Press any key to continue...";
            _getch();
            Board(board);
        }
        else if (board[lastposition] == 3) {
            board[lastposition] = 0;
            scoreplayer2 += 3;
            for (int i = lastposition - 1; i > -1; i--) {
                if (board[i] == 2) {
                    board[i] = 0;
                    scoreplayer2 += 2;
                }
                else if (board[i] == 3) {
                    board[i] = 0;
                    scoreplayer2 += 3;
                }
                else {
                    break;
                }
            }
            clrscr();
            Color(5);  cout << "\nYOU SCORED!!!!\n" << endl << "Press any key to continue...";
            _getch();
            Board(board);
        }

    }
    turnNum = 1;
    board[startposition] = 0;
    clrscr();
    Board(board);
    return 0;
}

int main() {
    bool Validoperation = false;
    Playagain(Validoperation);
    while (playing == true) {
        while ((scoreplayer2 <= 24) && (scoreplayer1 <= 24)) {
            if (((board[6] == 0) && (board[7] == 0) && (board[8] == 0) && (board[9] == 0) && (board[10] == 0) && (board[11] == 0)) || ((board[0] == 0) && (board[1] == 0) && (board[2] == 0) && (board[3] == 0) && (board[4] == 0) && (board[5] == 0))) {
                Impossible(Validoperation);
            }
            if (turnNum == 1) {
                Player1(Validoperation);
            }
            else if (turnNum == 2) {
                Player2(Validoperation);
            }
        }
        Winner(Validoperation);
    }
    return 0;
}
