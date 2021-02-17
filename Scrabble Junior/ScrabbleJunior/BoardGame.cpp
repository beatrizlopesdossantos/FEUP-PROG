#include "BoardGame.h"



void get_board(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker) { // function to print the board
	vector<char> alpha_upper = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };
	vector<char> alpha_lower = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't' };

	// print board

	cout << "  ";
	Color(blue);
	for (int q = 0; q < game_board[0].size(); q++) {
		cout << alpha_lower[q] << " "; // lower alphabet line
	}
	cout << endl;


	for (int m = 0; m < game_board.size(); m++) {

		Color(blue);
		cout << alpha_upper[m] << " "; // upper alphabet column

		for (int n = 0; n < game_board[0].size(); n++) {

			Color(play_tracker[m][n]); // changing the color acording to the state of the tile
			cout << game_board[m][n] << " ";
		}
		cout << endl;

		Color(white);
	}
}

void Board::input(const vector< vector<char> >& game_board, vector<char>& hand) { // function torecieve input
	bool flag = 0;
	char str_line;
	char str_column;

	cout << "\n\nPick a letter from your hand: ";

	while (cin >> letter) { // ask for input until player chooses a letter in the hand


		if (cin.peek() != '\n') {
			cout << "\nInvalid input. Try again: \n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}


		letter = toupper(letter); // capitalize letter

		for (int l = 0; l < hand.size(); l++) {

			if (hand[l] == letter) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) break;
		cout << "\nInvalid input. Try again: ";
	}

	cin.clear();
	cin.ignore(1000, '\n');



	cout << "\nChoose the line you want to play (Capital letters only): ";

	while (cin >> str_line) { // input line
		line = int(str_line) - 65;

		if (cin.peek() != '\n') {
			cout << "\nInvalid input. Try again: \n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (!(line >= 0 && line < game_board.size())) {
			cout << "\nInvalid input. Try again.";
			Board::input(game_board, hand); //if not valid, start over
			return;
		}
		else break;
	}

	cin.clear();
	cin.ignore(1000, '\n');



	cout << "\nChoose the column you want to play (non-Capital letters only): ";

	while (cin >> str_column) {// input column
		column = int(str_column) - 97;

		if (cin.peek() != '\n') {
			cout << "\nInvalid input. Try again: \n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (!(column >= 0 && column < game_board[0].size())) {
			cout << "\nInvalid input. Try again.";
			Board::input(game_board, hand); //if not valid, start over
			return;
		}
		else break;
	}
	return;
}


bool Board::choices_check(const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker, vector<char>& hand) { //checks if player can play and how many times
	tester = true; // if true, doesn't write when the play is not valid(test purposes)

	for (line = 0; line < game_board.size(); line++) {

		for (column = 0; column < game_board[0].size(); column++) {

			for (int piece = 0; piece < hand.size(); piece++) { // loop covering all possible plays, for x line, y column and z piece				
				letter = hand[piece];

				if (Board::check_play(game_board, play_tracker, hand) == 1) { // if there is a possible play, turn off tester version and return true

					tester = false;
					return true;
				}
			}
		}
	}
	tester = false;
	return false;
}

bool Board::check_play(const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker, vector<char>& hand) { // function to check whether a play is possible
	if (game_board[line][column] != letter) { // check if the square has the same letter as the chosen one(1st check)
		if (tester == false) cout << "\nThat position doesn't match with the letter chosen.\n";
		return false;
	}

	else {
		if (play_tracker[line][column] != white) { // check if the square has already been played (2nd check)
			if (tester == false) cout << "\nThat position is already occupied.\n";
			return false;
		}

		else {
			if (Board::vertical_check(game_board, play_tracker) || Board::horizontal_check(game_board, play_tracker) == true) { // check if the letter is the first not played being written in the word, either to the left or upwards (final check - if it's the first then...)

				if (tester == false) {
					play_tracker[line][column] = yellow; // mark the letter has played

					for (int tile = 0; tile < hand.size(); tile++) { // erase the letter from the hand
						if (hand[tile] == letter) {

							hand.erase(hand.begin() + tile);
							break;
						}
					}
				}
				return true;
			}

			else { // if it isn't the first then...
				if (tester == false) cout << "\nYou must write the words by letter order.\n";
				return false;
			}
		}
	}
}


bool Board::one_word_vert(const vector< vector<char> >& game_board) { //function to disable all 1 lettered "words" vertically
	if (line == 0) {
		if (game_board[line + 1][column] == '-') return true; // first line case
	}

	else {
		if (line == game_board.size() - 1) {
			if (game_board[line - 1][column] == '-')return true; // last line case
		}

		else {
			if (game_board[line + 1][column] == '-' && game_board[line - 1][column] == '-') return true; //other cases		
		}
	}
	return false;
}

bool Board::one_word_horiz(const vector< vector<char> >& game_board) { //function to disable all 1 lettered "words" horizontally
	if (column == 0) {
		if (game_board[line][column + 1] == '-') return true; // first column case

	}

	else {
		if (column == game_board[0].size() - 1) {
			if (game_board[line][column - 1] == '-')return true; // last column case
		}

		else {
			if (game_board[line][column + 1] == '-' && game_board[line][column - 1] == '-') return true; //other cases
		}
	}
	return false;
}


bool Board::vertical_check(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker) { // function to check if the letter is the first not played vertically
	if (Board::one_word_vert(game_board) == true) return false; // palavra com 1 letra

	for (int up = line - 1; up >= 0; up--) {

		if (game_board[up][column] == '-') return true; // word as been all checked, return true

		if (play_tracker[up][column] == white) return false; // it's not the first letter not played
	}
	return true; // word as been all checked, return true
}

bool Board::horizontal_check(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker) { // function to check if the letter is the first not played horizontally
	if (Board::one_word_horiz(game_board) == true) return false; // 1 lettered words case

	for (int left = column - 1; left >= 0; left--) {

		if (game_board[line][left] == '-') return true; // word as been all checked, return true

		if (play_tracker[line][left] == white) return false; // it's not the first letter not played
	}
	return true; // word as been all checked, return true
}


bool Board::check_vert_end(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker) { // check if the word is to be scored vertically
	int h = line;

	if (Board::one_word_vert(game_board) == true) return false; // if it's a one word case, doesn't count as finished

	while (h >= 0 && game_board[h][column] != '-') { // up from the tile check

		if (play_tracker[h][column] == white) 	return false; // if the word has not been finished, false
		h--;
	}


	h = line + 1; // iterator goes to the original place again, to check other side


	while (h <= game_board.size() - 1 && game_board[h][column] != '-') { //down from the tile check

		if (play_tracker[h][column] == white) return false; // if the word has not been finished, false
		h++;
	}


	return true; // score it
}

bool Board::check_horiz_end(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker) { // check if the word is to be scored horizontally
	int v = column;

	if (Board::one_word_horiz(game_board) == true) return false; // if it's a one word case, doesn't count as finished

	while (v >= 0 && game_board[line][v] != '-') { // left from the tile check

		if (play_tracker[line][v] == white) return false; // if the word has not been finished, false
		v--;
	}


	v = column + 1; // iterator goes to the original place again, to check other side


	while (v <= game_board[0].size() - 1 && game_board[line][v] != '-') { // right from the tile check

		if (play_tracker[line][v] == white) return false; // if the word has not been finished, false
		v++;
	}


	return true; // score it
}

int Board::update_score(const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker) { // function to update score
	int h = line;
	int v = column;
	int score = 0;

	if (Board::check_vert_end(game_board, play_tracker) == true) { // check if there any word was scored vertically
		while (h >= 0 && game_board[h][column] != '-') { // up from the played tile
			play_tracker[h][column] = green; // mark the letters has scored
			h--;
		}
		h = line + 1; // iterator goes to the original place again, to check other side

		while (h <= game_board.size() - 1 && game_board[h][column] != '-') { // down from the played tile
			play_tracker[h][column] = green; // mark the letters has scored
			h++;
		}

		score += 1;
	}

	if (Board::check_horiz_end(game_board, play_tracker) == true) { // check if there any word was scored horizontally
		while (v >= 0 && game_board[line][v] != '-') { // left from the played tile
			play_tracker[line][v] = green; // mark the letters has scored
			v--;
		}
		v = column + 1; // iterator goes to the original place again, to check other side

		while (v <= game_board[0].size() - 1 && game_board[line][v] != '-') { // right from the played tile
			play_tracker[line][v] = green; // mark the letters has scored
			v++;
		}

		score += 1;
	}

	return score;
}