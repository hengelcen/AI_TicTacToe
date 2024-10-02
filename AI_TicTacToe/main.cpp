#include <iostream>
#include <vector>
#include <string>

using namespace std;
enum player {
	x,
	o
};
class ultimeTicTacToe {

public:

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
				if(i%9 == 0 || (i+1)%9 == 0)cout << (char)219u;
				else cout << (char)223u;
				if ((i + 1) % 9 == 0) cout << " ";
			}
			cout << endl;
			for (int i = 1; i <= 3; i++) {
				for (int c = 0; c < 3; c++) {
					cout << (char)219u;
					for (int j = 0; j < 3; j++) {
						cout << " ";
						cout << board[((b - 1) * 3 + c)][ (i-1)*3 + j];
						if (j == 2) cout << " ";
					}
					cout << (char)219u  << " ";
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

void main() {
	ultimeTicTacToe game;
	game.addMove(x, 9, 9);
	game.printBoard();

}