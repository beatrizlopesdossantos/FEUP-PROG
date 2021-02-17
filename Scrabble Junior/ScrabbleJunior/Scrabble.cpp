#include "Player.h"
#include "BoardGame.h"
#include "UsefulGame.h"


void reader(string& size_x, string& size_y, vector<string>& position, vector<string>& orientation, vector<string>& word_list, string name) { // function to read the file and organize the information
    ifstream data;
    data.open(name + ".txt"); // open text file

    if (!data.is_open()) {
        string path2;

        cout << "\nError, try to write the path again: ";

        cin.clear();
        cin.ignore(1000, '\n');

        cin >> path2;
        reader(size_x, size_y, position, orientation, word_list, path2); // if not open, tries again
        return;
    }

    int i = 0;
    char word[21]; // max word_length

    while (!data.eof()) { // while file doesn't end

        data >> word;
        if (i < 3) {
            if (i == 0) size_x = word; // store board length
            if (i == 2) size_y = word; // store board width
        }
        else {
            if (i % 3 == 0)  position.push_back(word); // stores the start position
            if (i % 3 == 1)  orientation.push_back(word); // stores the orientation 
            if (i % 3 == 2) word_list.push_back(word); // stores the word              
        }
        i++;
    }
    return;
}

vector<char> str_char(string word) { // function to transform a string word in a char vector
    vector<char> letters(word.begin(), word.end());
    return letters;
}

void word_placer(vector< vector<char> >& game_board, const vector<string>& position, const vector<string>& orientation, const vector<string>& word_list) { // function to construct the board with the given words
    int word_start_x;
    int word_start_y;

    vector<char> word_start;
    vector<char> characters;

    for (int i = 0; i < word_list.size(); i++) {

        characters = str_char(word_list[i]);
        word_start = str_char(position[i]);

        word_start_x = int(word_start[0]) - 65; // word start x index
        word_start_y = int(word_start[1]) - 97; // word start y index

        if (orientation[i] == "H") {
            for (int letter = 0; letter < word_list[i].length(); letter++) {
                game_board[word_start_x][word_start_y + letter] = characters[letter]; // position xy = letter p
            }
        }

        if (orientation[i] == "V") {
            for (int letter = 0; letter < word_list[i].length(); letter++) {
                game_board[word_start_x + letter][word_start_y] = characters[letter]; // position xy = letter p
            }
        }
    }
    return;
}

void pool_filler(const vector< vector<char> >& game_board, vector<char>& pool) { // pool filling function
    for (int x = 0; x < game_board.size(); x++) {
        for (int y = 0; y < game_board[0].size(); y++) {
            if (game_board[x][y] != '-') pool.push_back(game_board[x][y]); // adding to the pool all board tiles with letters
        }
    }
    return;
}

bool game_end(vector<Player>& order, int max_score) {
    vector<int> scores(order.size(), 0); // all players combined score
    int total_score = 0;
    vector <int> winner_score_list;
    vector <int> winner_id_list;
    int winner_score = 0;
    int winner_id = 0;

    for (int c = 0; c < order.size(); c++) {

        scores[c] = order[c].get_score(); // store current score
        total_score += scores[c]; // add to maximum        
    }

    if (total_score == max_score) { // if all points have been conceeded

        cout << "\n\nThe game is over! Press any key to see the winner.";
        (void)_getch(); clrscr();

        for (int d = 0; d < order.size(); d++) {
            if (scores[d] >= winner_score) { // if it is the best score so far...

                if (scores[d] > winner_score) {
                    winner_score_list.clear(); // clean winner vectors
                    winner_id_list.clear();
                }

                winner_score = scores[d]; // mark best score and id
                winner_id = d + 1;

                winner_score_list.push_back(winner_score); // score best score and id
                winner_id_list.push_back(winner_id);
            }

        }
        if (winner_score_list.size() == 1) {
            cout << "\nPlayer " << winner_id << " won with a score of " << winner_score << endl;
            return true;
        }
        if (winner_score_list.size() == 2) {
            cout << "\nPlayer " << winner_id_list[0] << " and " << winner_id_list[1] << " drawn with a score of " << winner_score << endl;
            return true;
        }
        if (winner_score_list.size() == 3) {
            cout << "\nPlayer " << winner_id_list[0] << ", " << winner_id_list[1] << " and " << winner_id_list[2] << " drawn with a score of " << winner_score << endl;
            return true;
        }
        if (winner_score_list.size() == 4) {
            cout << "\nPlayer " << winner_id_list[0] << ", " << winner_id_list[1] << ", " << winner_id_list[2] << " and " << winner_id_list[3] << " drawn with a score of " << winner_score << endl;
            return true;
        }
    }


    return false;
}

void Rules() {
    cout << "This game is constituted by a board and a pool of 28 or more letters, depending on how much words the board has\nand each player has 7 tiles.\n\nHow to play?\n\nOn your turn, you have to play two of your tiles (if possible) to cover the letters of the board and then,\nautomatically, you will receive as much letters as you played.\nPlay the letter by the order of the word, for example, if you play in the second letter of a word but the first\nisn't ocuppied, you won't be able to make that move.\nIf you don't have tiles to play, the pool opens and you have to switch two of your words, but you won't be able to\nmake a move until next turn.\nYou score one point if you put the last letter of a word.\nIf the aren't no more tiles in the pool your turn will be passed.\nAfter the game ends, the player who completed more words wins.\n\nGood luck ;)";
    (void) _getch();  clrscr();
}

bool menu() { //output of the menu
    int command;
    Color(yellow); cout << endl << setw(70) << "SCRABBLE JUNIOR GAME" << endl;
    Color(blue); cout << endl << setw(68) << "_______________\n" << setw(52) << "|" << setw(16) << "|" << endl << setw(56) << "| 1. ";
    Color(white); cout << "Play Game ";
    Color(blue); cout << " | \n" << setw(56) << " | 2. ";
    Color(white); cout << "Rules ";
    Color(blue); cout << setw(8) << " | \n" << setw(56) << " | 3. ";
    Color(white); cout << "Quit ";
    Color(blue); cout << setw(8) << " | " << endl << setw(70) << " |_______________| \n" << endl << endl;
    Color(white); cout << setw(75) << "Enter the number you want : ";

    while (true) { //if cin not correct
        cin >> command;
        if (cin.peek() != '\n' || cin.fail() || (command != 1 && command != 2 && command != 3)) {
            clrscr();
            Color(yellow); cout << endl << setw(70) << "SCRABBLE JUNIOR GAME" << endl;
            Color(blue); cout << endl << setw(68) << "_______________\n" << setw(52) << "|" << setw(16) << "|" << endl << setw(56) << "| 1. ";
            Color(white); cout << "Play Game ";
            Color(blue); cout << " | \n" << setw(56) << " | 2. ";
            Color(white); cout << "Rules ";
            Color(blue); cout << setw(8) << " | \n" << setw(56) << " | 3. ";
            Color(white); cout << "Quit ";
            Color(blue); cout << setw(8) << " | " << endl << setw(70) << " |_______________| \n" << endl;
            cin.clear();
            cin.ignore(10000000, '\n');
            Color(white); cout << endl << setw(77) << "Choose only between 1, 2 and 3: ";
        }
        else {
            break;
        }
    }
    switch (command) {
    case 1: //play the game
        clrscr();
        return true;
        break;
    case 2: //rules
        clrscr();
        Rules();
        menu();
        break;
    case 3: //exit
        clrscr();
        return false;
        break;
    }
}

int main()
{
    while (menu() == true) {
        Color(white);
        vector<string> position;
        vector<string> orientation;
        vector<string> word_list;

        vector<Player> order;

        string name;
        int player_number;

        string str_size_x;
        string str_size_y;
        int size_x;
        int size_y;

        vector<char> pool;

        int round = 0; // iterator to decide who's playing



        cout << "Which gameboard do you want to use? (Insert the name of the file - no extension needed): ";
        cin >> name;
        reader(str_size_x, str_size_y, position, orientation, word_list, name); // getting file name, reading it, and storing it


        size_x = stoi(str_size_x); // str x to int
        size_y = stoi(str_size_y); // str y to int


        vector< vector<char> > game_board(size_x, vector<char>(size_y, '-')); // create board with "-" in all tiles
        vector< vector<int> > play_tracker(size_x, vector<int>(size_y, 15)); // create board to check whether a letter was already played or scored using integers


        word_placer(game_board, position, orientation, word_list); // put the words on the board
        pool_filler(game_board, pool); // create the pool with all the letters that can be played



        cout << "\nHow many players are playing? (2-4): ";

        while (true) {
            cin >> player_number;
            if (cin.peek() != '\n' || player_number < 2 || player_number > 4) {
                cout << "\nThe input is not correct. Try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else break;
        }

        clrscr();

        get_board(game_board, play_tracker);



        //creating players according to their number 
        Player player1(pool, 1);
        order.push_back(player1);
        Player player2(pool, 2);
        order.push_back(player2);
        if (player_number >= 3) {
            Player player3(pool, 3);
            order.push_back(player3);
        } if (player_number == 4) {
            Player player4(pool, 4);
            order.push_back(player4);
        }


        while (true) {
            order[round % order.size()].turn(pool, game_board, play_tracker); // player x turn begins
            round++;

            if (game_end(order, word_list.size()) == true) break;

        }
        cout << "\n\n\nPress any key to continue...";
        (void)_getch(); clrscr();

    }
    cout << "\n\n\n Thanks for playing!!!\n\n\n\n";

    return 0;
}