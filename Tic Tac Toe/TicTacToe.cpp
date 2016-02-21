//By Hardeep Singh
// TIC - TAC -TOE

#include <iostream>
#include <string>
using namespace std;
class TTT
{
private:
	char board[3][3];
public:
	TTT();
	void printTable();
	void setTable();
	void mPlayer(char, char);
	bool winnerCheck(char, bool);
	bool draw(bool);
};
int main()
{
	char aPlayer = 'O';
	char playerChoice;
	bool finish = false;
	bool endGame = false;
	TTT game;
	game.setTable();
	do
	{
		// assign player a character
		if (aPlayer == 'X')
		{
			aPlayer = 'O';
		}
		else
		{
			aPlayer = 'X';
		}
		//print table
		game.printTable();
		cout << "Player " << aPlayer << " turn: ";
		cin >> playerChoice;

		game.mPlayer(playerChoice, aPlayer);
		endGame = game.winnerCheck(aPlayer, endGame);
		if (endGame == true)
		{
			cout << "Congratulations! Player " << aPlayer << " won!\n";
			break;
		}
		endGame = game.draw(endGame);
		if (endGame == true)
		{
			int option;
			cout << "(1) Quit \n";
			cout << "(2) Start a New Game \n";
			cout << "What would you like to do: ";
			cin >> option;
			switch (option)
			{
			case 1: cout << "GoodBye!\n";
						break;
				case 2: game.setTable();
						endGame = false;
				default: cout << "Invalid choice. \n";
					     break;
			}
		}
	} while (!finish);
}
TTT::TTT()
{}
void TTT::setTable()
{
	int n = 1; //to make it char.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '0' + n;
			n++;
		}
	}
}
void TTT::printTable()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j < 2)
				cout << board[i][j] << "  |  ";
			else
				cout << board[i][j] << "\n" ;
		}
	}
}
void TTT::mPlayer(char playerChoice, char aPlayer)
{
	bool invalidMove = true;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == playerChoice)
				board[i][j] = aPlayer;
				invalidMove = false;
		}
	}
	if (invalidMove == true)
		cout << "Invalid Move \n";
}
bool TTT::winnerCheck(char aPlayer, bool endGame)
{
	for (int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			endGame = true;
		
	for (int i = 0; i < 3; i++)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			endGame = true;
	//Diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
			endGame = true;

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
			endGame = true;
	
	return endGame;
}
bool TTT::draw(bool endGame)
{
	int n = 1;
	int counter = 0; //keep track how many spots are full.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '0' + n)
				counter++;
			n++;
		}
	}
	if (counter < 1)
	{
		cout << "Game Over, no winner.\n";
		endGame = true;
	}
	return endGame;
}