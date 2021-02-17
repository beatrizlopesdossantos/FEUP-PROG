#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <climits>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <cctype>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include "BoardGame.h"
#define _USE_MATH_DEFINES
using namespace std;

const int green = 10;
const int blue = 11;
const int yellow = 14;
const int white = 15;

void clrscr(void); //clear screen

void get_board(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker); // function to print the board

void Color(int value); // function to change color



class Board
{
public:

	void input(const vector< vector<char> >& game_board, vector<char>& hand); // function torecieve input

	bool check_play(const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker, vector<char>& hand); // checks if player can play and how many times

	bool choices_check(const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker, vector<char>& hand); // function to check whether a play is possible

	bool one_word_vert(const vector< vector<char> >& game_board); // function to disable all 1 lettered "words" horizontally vertically

	bool one_word_horiz(const vector< vector<char> >& game_board); // function to disable all 1 lettered "words" horizontally

	bool vertical_check(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker); // function to check if the letter is the first not played vertically

	bool horizontal_check(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker); // function to check if the letter is the first not played horizontally

	bool check_vert_end(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker); // check if the word is to be scored vertically

	bool check_horiz_end(const vector< vector<char> >& game_board, const vector< vector<int> >& play_tracker);// check if the word is to be scored horizontally

	int update_score(const vector< vector<char> >& game_board, vector< vector<int> >& play_tracker); // function to update score

private:
	bool tester = true; // true == machine valid plays checker / false == human valid play checker 

	char letter = ' '; // letter input holder
	int line = 0; // line input holder
	int column = 0; // column input holder
};