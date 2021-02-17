#pragma once
#include "Board.h"
#include "Useful.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

class Board {
public:
    Board(); //defines the number of columns and lines
    void setWord(); //write the word to add to the board
    void setPosition(); //write the orientation of the word
    void setOrientation(); //write the position of the word
    int getLines(); //returns the number of lines
    int getColumns(); //returns the number of columns
    string getWord(); //returns the word to be added
    vector<string> getVecWords(); //returns the vector that contains all the words
    vector<char> getVecOrientations(); //returns the vector that contains all the orientations
    vector<string> getVecPositions(); //returns the vector that contains all the positions
    vector <vector<char>> getBoard(); //returns the 2D vector that contains all the words in the right positions
    bool validateWords(string wordToCheck); //check if the word is in the dictionary
    void addToVectores(); //add the information about the word added to it's corresponding vectors
    bool validateposition(); //check if the position insert is available
    void updateBoard(); //update the board to be easier to visualize it
    void clearVec(); //clear vectors if the user wnats to stop the program;

private:
    int lines, columns;
    vector <vector<char>> board;
    string position;
    string word;
    char orientation;
    vector<string> vecWords;
    vector<char> vecOrientations;
    vector<string> vecPositions;
};