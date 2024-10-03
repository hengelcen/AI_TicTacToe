#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;
enum player {
	x,
	o
};
class ultimeTicTacToe {

public:
	int bestMove(player playerL, int boardNumber) {
		int bestScore;
			if (playerL == x) {
				bestScore = (numeric_limits<int>::max()) * -1;
			}
			else {
				bestScore = (numeric_limits<int>::max());
			}
			int move = 0;
		for (int i = 0; i < 3; i++) {
			for (int b = 0; b < 3; b++) {
				if (board[boardNumber - 1][i * 3 + b] == '_') {
					board[boardNumber - 1][i * 3 + b] = playerL == o?  'O' : 'X';
					int score = minimax(boardNumber, 0, playerL);
					board[boardNumber - 1][i * 3 + b] = '_';
					if (playerL == o) {
						if (score > bestScore) {
							bestScore = score;
							move = i * 3 + b;
						}
					}
					else {
						if (score > bestScore) {
							bestScore = score;
							move = i * 3 + b;
						}
					}
				}
			}
		}
		return move;
	}

	int checkWinner(int currentBoard) {
		int winner = -2;
		bool tie = true;
		for (int i = 0; i < 3; i++) {
			if ((board[currentBoard - 1][0 + 3 * i] == 'X' && board[currentBoard - 1][1 + 3 * i] == 'X' && board[currentBoard - 1][2 + 3 * i] == 'X') ||
				(board[currentBoard - 1][i] == 'X' && board[currentBoard - 1][3 + i] == 'X' && board[currentBoard - 1][6 + i] == 'X')) winner = 1;

	   		else if ((board[currentBoard - 1][0 + 3 * i] == 'O' && board[currentBoard - 1][1 + 3 * i] == 'O' && board[currentBoard - 1][2 + 3 * i] == 'O') ||
				(board[currentBoard - 1][i] == 'O' && board[currentBoard - 1][3 + i] == 'O' && board[currentBoard - 1][6 + i] == 'O')) winner = -1;
		}
		if (board[currentBoard - 1][0] == 'X' && board[currentBoard - 1][4] == 'X' && board[currentBoard - 1][8] == 'X' ||
			board[currentBoard - 1][2] == 'X' && board[currentBoard - 1][4] == 'X' && board[currentBoard - 1][6] == 'X') winner = 1;
		else if (board[currentBoard - 1][0] == 'O' && board[currentBoard - 1][4] == 'O' && board[currentBoard - 1][8] == 'O' ||
			board[currentBoard - 1][2] == 'O' && board[currentBoard - 1][4] == 'O' && board[currentBoard - 1][6] == 'O') winner = -1;
		for (int i = 0; i < 9; i++) {
			if (board[currentBoard - 1][i] == '_') tie = false;
		}
		if (tie) return 0; //fix
		else return winner;
		/*
		  -1 for O wins,
		  +1 for X wins,
		   0 for tie,
		  -2 for nothing
		*/
	}

	int minimax(int currentBoard, int depth, player playerL) {
		int won = checkWinner(currentBoard);
		if (won != -2) {
			return won;
		}
		if (playerL == x) {
			int bestScore = (numeric_limits<int>::max()) * -1;
			for (int i = 0; i < 3; i++) {
				for (int b = 0; b < 3; b++) {
					if (board[currentBoard - 1][i * 3 + b] == '_') {
						board[currentBoard - 1][i * 3 + b] = 'X';
						int score = minimax(currentBoard, depth + 1, x);
						board[currentBoard - 1][i * 3 + b] = '_';
						bestScore = max(score, bestScore);
					}

				}
			}
			return bestScore;
		}
		else {
			int bestScore = (numeric_limits<int>::max());
			for (int i = 0; i < 3; i++) {
				for (int b = 0; b < 3; b++) {
					if (board[currentBoard - 1][i * 3 + b] == '_') {
						board[currentBoard - 1][i * 3 + b] = 'O';
						int score = minimax(currentBoard, depth + 1, o);
						board[currentBoard - 1][i * 3 + b] = '_';
						bestScore = min(score, bestScore);
					}
				}
			}
			return bestScore;

		}
	}
	/*int chooseRandomMove(int tableNumber) {
		srand((unsigned)time(NULL));
		int randomNumber = rand() % 9;
		auto currentTable = board[tableNumber - 1];
		bool full = true;
		for (int i = 0; i < 9; i++) {
			if (currentTable[i] == '_') full = false;
		}
		if (full) return -1;
		while (currentTable[randomNumber] != '_') {
			randomNumber = rand() % 9;

		}
		return randomNumber + 1;
	}*/
	ultimeTicTacToe() {
		for (int i = 0; i < 9; i++) {
			vector<char> tempVector(9);
			for (int j = 0; j < 9; j++)
				tempVector[j] = '_';
			board.push_back(tempVector);
		}
	}
	void addMove(int playerNum, int boardNum, int space) {
		board[boardNum - 1][space - 1] = playerNum == 0 ? 'X' : 'O';
	}
	void printBoard() {
		for (int b = 1; b <= 3; b++) {
			for (int i = 0; i < 27; i++) {
				if (i % 9 == 0 || (i + 1) % 9 == 0)cout << (char)219u;
				else cout << (char)223u;
				if ((i + 1) % 9 == 0) cout << " ";
			}
			cout << endl;
			for (int i = 1; i <= 3; i++) {
				for (int c = 0; c < 3; c++) {
					cout << (char)219u;
					for (int j = 0; j < 3; j++) {
						cout << " ";
						cout << board[((b - 1) * 3 + c)][(i - 1) * 3 + j];
						if (j == 2) cout << " ";
					}
					cout << (char)219u << " ";
				}
				cout << endl;
			}
			for (int i = 0; i < 27; i++) {
				if (i % 9 == 0 || (i + 1) % 9 == 0)cout << (char)219u;
				else cout << (char)220u;
				if ((i + 1) % 9 == 0) cout << " ";
			}
			cout << endl << endl;
		}
	}
private:
	vector<vector<char>> board;

};

int main() {
	ultimeTicTacToe game;
	game.printBoard();
	int move;
	int currentTable = 5;
	cout << "Select a move from table 5: (You are X)" << endl;
	cin >> move;
	int randomMove;
	while (true) {
		game.addMove(x, currentTable, move);
		currentTable = move;
		randomMove = game.bestMove(o, currentTable);
		game.addMove(o, currentTable, randomMove);
		currentTable = randomMove;
		system("CLS");
		game.printBoard(/*currentTable, move*/);
		cout << "Select a move from table " << currentTable << ": (You are X)" << endl;
		cin >> move;
	}

	return 0;
}