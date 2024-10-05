#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <queue>

using namespace std;
enum player {
	x,
	o
};
struct moves {
	int move;
	int depth;
};
struct moveNum {
	int move;
	int depth;
	int moveSpace;
};

class ultimeTicTacToe {

public:
	int bestMove(player playerL, int boardNumber) {
		int bestScore = -numeric_limits<double>::infinity(); 
		vector<moveNum> listMoves;
		int move = 0;
		for (int i = 0; i < 3; i++) {
			for (int b = 0; b < 3; b++) {
				if (board[boardNumber - 1][i * 3 + b] == '_') {
					board[boardNumber - 1][i * 3 + b] = 'X';
					moves score = minimax(boardNumber, 0, false);
					listMoves.push_back({ score.move, score.depth, i * 3 + b });
					board[boardNumber - 1][i * 3 + b] = '_'; 
				}
			}
		}

		return move;
	}

	int checkWinner(int currentBoard) {
		auto currB = board[currentBoard - 1];

		
		for (int i = 0; i < 3; i++) {
			if (currB[i * 3] == currB[i * 3 + 1] && currB[i * 3 + 1] == currB[i * 3 + 2] && currB[i * 3] != '_') {
				return (currB[i * 3] == 'X') ? 1 : -1;
			}
		}

		for (int i = 0; i < 3; i++) {
			if (currB[i] == currB[i + 3] && currB[i + 3] == currB[i + 6] && currB[i] != '_') {
				return (currB[i] == 'X') ? 1 : -1;
			}
		}

		if (currB[0] == currB[4] && currB[4] == currB[8] && currB[0] != '_') {
			return (currB[0] == 'X') ? 1 : -1;
		}
		if (currB[2] == currB[4] && currB[4] == currB[6] && currB[2] != '_') {
			return (currB[2] == 'X') ? 1 : -1;
		}

		for (int i = 0; i < 9; i++) {
			if (currB[i] == '_') {
				return -2; 
			}
		}
		return 0;
	}


	moves minimax(int boardNum, int depth, bool isMaximizing) {
		char result = checkWinner(boardNum);
		if (result != -2) {
			return moves{ result, depth };
		}
		auto& currBoard = board[boardNum - 1]; 

		if (isMaximizing) {
			int bestScore = numeric_limits<int>::min();
			for (int i = 0; i < 9; i++) {
				if (currBoard[i] == '_') {
					currBoard[i] = 'X';
					moves score = minimax(boardNum, depth + 1, false);
					depth = depth + 1;
					currBoard[i] = '_'; 
					bestScore = max(score.move, bestScore);
				}
			}
			return moves{ bestScore, depth };
		}
		else {
			int bestScore = numeric_limits<int>::max();
			for (int i = 0; i < 9; i++) {
				if (currBoard[i] == '_') {
					currBoard[i] = 'O'; 
					moves score = minimax(boardNum, depth + 1, true);
					depth = depth + 1;

					currBoard[i] = '_';
					bestScore = min(score.move, bestScore);
				}
			}
			return moves{ bestScore, depth };
		}
	}

	ultimeTicTacToe() {
		for (int i = 0; i < 9; i++) {
			vector<char> tempVector(9);
			for (int j = 0; j < 9; j++)
				tempVector[j] = '_';
			board.push_back(tempVector);
		}
	}
	void addMove(int playerNum, int boardNum, int space) {
		board[boardNum - 1][space] = playerNum == 0 ? 'X' : 'O';
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
	player chosenPlayer;
	player AIPlayer;
	int move;
	int choosePlayer;
	int currentTable = 5;
	int AIMove;
	int currentBoard;
	cout << "Choose a player:" << endl << "1. X" << endl << "2. O" << endl;
	cin >> choosePlayer;
	if (choosePlayer == 1) {
		AIPlayer = o; 
		chosenPlayer = x;
	}
	else {
		AIPlayer = x;
		chosenPlayer = o;
	}
	int bMove;

	if (AIPlayer == x) {
		bMove = game.bestMove(AIPlayer, 5);
		game.addMove(AIPlayer, 5, bMove);
		system("CLS");
		game.printBoard();
	}
	cout << "enter move:";
	cin >> move;
	while (true) {
		game.addMove(chosenPlayer, 5, move - 1);
		bMove = game.bestMove(AIPlayer, 5);
		game.addMove(AIPlayer, 5, bMove);
		system("CLS");
		game.printBoard();
		cout << "enter move:";
		cin >> move;
	}

	return 0;
}
