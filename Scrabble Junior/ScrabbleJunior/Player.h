#pragma once
#include "BoardGame.h"



class Player
{
public:
	Player(vector<char>& pool, int player_id); // constructor creates player and fills his hand

	void turn(vector<char>& pool, const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker); // the turn main function, rules everything connected to the gameplay

	void fill_hand(vector<char>& pool);	// function to swap letters in case there was not possible play

	void skip_turn(vector<char>& pool); // function to fill player's hand

	int get_id();

	int get_score();
private:
	Board board; //board object

	int id; // player id

	vector<char> hand; // player hand

	int score = 0; // player score

};