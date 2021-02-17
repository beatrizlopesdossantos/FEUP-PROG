#include "Player.h"


Player::Player(vector<char>& pool, int player_id) { //constructor creates player and fills his hand
	Player::id = player_id;
	Player::fill_hand(pool);
}

void Player::turn(vector<char>& pool, const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker) { //the turn main function, rules everything connected to the gameplay
	if (hand.size() == 0) {
		cout << "\nPlayer " << id << " your hand is empty, you have to wait for all players to finish the game.\n";
		return;
	}


	for (int a = 1; a <= 2; a++) { // for with the 2 possible plays

		if (board.choices_check(game_board, play_tracker, hand) == false) { // check if player can play by trying all possibilities
			if (a == 1) {
				cout << "\nPlayer " << id << ", you can't play anything.\n";
				if (pool.size() > 0) { 
					
					get_board(game_board, play_tracker);
					Player::skip_turn(pool); // if not and if pool still has letters, player swaps letters
				}

				else cout << "\nThe pool is empty.\n";


				clrscr();
				get_board(game_board, play_tracker);
				return;

			}
			else { // if player can't play the second letter, pass the turn and fill hand
				clrscr();
				cout << "\nPlayer " << id << ", you don't have anymore valid moves available. Turn passed.\n\n";

				get_board(game_board, play_tracker);
				Player::fill_hand(pool);
				return;
			}
		}


		while (true) { //while the play isn't correctly chosen or validated...repeat
			if (a == 2) cout << "\nPlay your second letter: ";


			cout << "\nPlayer number " << id << " hand: ";
			for (int l = 0; l < hand.size(); l++) { // show player hand
				cout << hand[l] << " ";
			}


			board.input(game_board, hand); // ask for play input

			if (board.check_play(game_board, play_tracker, hand) == true) break; // if input is valid breaks the while loop and moves on
		}

		score += board.update_score(game_board, play_tracker); // if score has changed, increments it
		clrscr(); // clear screen
		get_board(game_board, play_tracker); // print updated board		
	}

	Player::fill_hand(pool); // fill hand to 7 again if possible
	cout << "\nPlayer " << id << " has a score of " << score << endl;
	return;
}


void Player::skip_turn(vector<char>& pool) { //function to swap letters in case there was not possible play
	bool flag = 0;
	char swap;
	int max = 2; // maximum of letters to swap


	if (pool.size() == 1) { // case where pool only has 1 letter
		cout << "\nOnly 1 letter left. Choose a letter to swap in the pool\nHere are your letters: ";
		max = 1;
	}
	else cout << "\nChoose 2 letters to swap in the pool\nHere are your letters: ";


	for (int l = 0; l < hand.size(); l++) { // show player hand
		cout << hand[l] << " ";
	}
	cout << endl;



	for (int s = 1; s <= max; s++) { // while player hasn't swapped all possible letters...run

		cout << "\nPick a letter: ";

		while (cin >> swap) { // ask for input until player chooses a valid letter

			if (cin.peek() != '\n') {
				cout << "\nInvalid input. Try again: \n";
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			for (int l = 0; l < hand.size(); l++) {
				swap = toupper(swap);

				if (hand[l] == swap) {
					flag = 1;
					pool.push_back(swap); // put the letter back in the pool
					hand.erase(hand.begin() + l); // erase the letter chosen
					break;
				}
			}

			if (flag == 1) break;
			else cout << "\nYou don't have that letter. Try again: ";
		}
	}

	Player::fill_hand(pool);
	return;
}

void Player::fill_hand(vector<char>& pool) { // function to fill player's hand
	srand((unsigned)time(0));
	int rnd;
	char draft;

	if (hand.size() == 7) return;

	if (pool.size() == 0) { // pool empty
		cout << "\nThe pool is already empty, so you won't recieve any new letters.\n";
		return;
	}

	while (true) {
		if (pool.size() == 0) { // pool empty
			cout << "\nThe pool is already empty, so you won't recieve any new letters.\n";
			return;
		}
		else {
			rnd = rand() % pool.size();
			draft = pool[rnd]; // // take a piece randomly 

			hand.push_back(draft); // add it to the hand
			pool.erase(pool.begin() + rnd); // take it off the pool

			if (hand.size() == 7) break; // when hand is full, break and return
		}
	}
	return;
}


int Player::get_id() {
	return id;
}

int Player::get_score() {
	return score;
}