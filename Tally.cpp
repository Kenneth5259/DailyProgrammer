/*
Daily Programmer Challenge #361 Tally Program

Description:
5 Friends (let's call them a, b, c, d and e) are playing a game and 
need to keep track of the scores. Each time someone scores a point, 
the letter of his name is typed in lowercase. If someone loses a point, 
the letter of his name is typed in uppercase. Give the resulting score from highest to lowest.
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int playerIndex(char c); 
int main()
{	
	vector<char> players = { 'a', 'b', 'c', 'd', 'e' }; 
	vector<int> score = { 0, 0, 0, 0, 0 };				
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		char c = input[i];
		
		if (int(c) >= 65 && int(c) <= 69) //ASCII Decimal range for capital Characters
			score[playerIndex(c)] -= 1;
		else if (int(c) >= 97 && int(c) <= 101) //ASCII Decimal range for lowercase Characters
			score[playerIndex(c)] += 1;
		else
			cout << "Invalid Character at index: " << i << endl;
	}
	for (int i = 0; i < 4; i++)
		cout << players[i] << ":" << score[i] << ", ";
	cout << players[4] << ":" << score[4] << endl;
	cin >> input;
    return 0;
}
int playerIndex(char c) {
	c = tolower(c);
	switch (c) {
		case 'a':
			return 0;
		case 'b':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'e':
			return 4;
		default:
			return -1;
	}
}

