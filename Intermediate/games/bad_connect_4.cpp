#include "pch.h"
#include <iostream>
using namespace std;
#define row 6
#define column 7

void init_grid(const char* grid[row][column]) {
	cout << "--------------------"<<endl;
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 6; j++) {
			grid[i][j] = " . ";
			cout << grid[i][j];
		}
		cout<<endl;
	}
}

void player_turn(bool black_turn) {
	if (black_turn == false) {
		cout << "------Red Turn------"<<endl;
	}
	else if(black_turn == true) {
		cout << "-----Black Turn-----" << endl;
	}
}

int col_chooser(bool black_turn, int col) {
	do {
		cout << "Choose Column: ";

		cin >> col;

		if (col > 7 || col < 1) {
			cout << "Please Enter A Column Number Between 1 And 7." << endl;
		}
	} while (col > 7 || col < 1);
	
	return col;
}

void update_grid(const char* grid[row][column], bool black_turn, int col) {
	if (-1 < col && col < 7) {
		for (int i = 5; i >= 0; i--) {
			if (black_turn == false && grid[i][col] == " . ") {
				grid[i][col] = " r ";
				break;
			}
			else if (black_turn == true && grid[i][col] == " . ") {
				grid[i][col] = " b ";
				break;
			}
		}
	}
}

void print_grid(const char* grid[row][column]) {
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= 6; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool next_turn(bool black_turn) {
	if (black_turn == true) {
		return false;
	}
	else if (black_turn == false) {
		return true;
	}
	else {
		return false;
	}
}

bool check_win_verticle(const char* grid[row][column], bool black_turn) {
	if (black_turn == true) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 5; i >= 0; i--) {
				if (grid[i][j] == " b " && grid[i - 1][j] == " b " && grid[i - 2][j] == " b " && grid[i - 3][j] == " b ") {
					cout << "--------------------"<<endl;
					cout << "Verticle Match, Black Wins" << endl;
					return true;
				}
			}

		}
	}
	else if (black_turn == false) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 5; i >= 0; i--) {
				if (grid[i][j] == " r " && grid[i - 1][j] == " r " && grid[i - 2][j] == " r " && grid[i - 3][j] == " r ") {
					cout << "--------------------" << endl;
					cout << "Verticle Match, Red Wins" << endl;
					return true;
				}
			}

		}
	}
		return false;
}

bool check_win_horizontal(const char* grid[row][column], bool black_turn) {
	if (black_turn == true) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 5; i >= 0; i--) {
				if (grid[i][j] == " b " && grid[i][j + 1] == " b " && grid[i][j + 2] == " b " && grid[i][j + 3] == " b ") {
					cout << "--------------------" << endl;
					cout << "Horizontal Match, Black Wins" << endl;
					return true;
				}
			}

		}
	}
	else if (black_turn == false) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 5; i >= 0; i--) {
				if (grid[i][j] == " r " && grid[i][j + 1] == " r " && grid[i][j + 2] == " r " && grid[i][j + 3] == " r ") {
					cout << "--------------------" << endl;
					cout << "Horizontal Match, Red Wins" << endl;
					return true;
				}
			}

		}
	}
	return false;
}

bool check_win_diagonal_up(const char* grid[row][column], bool black_turn) {
	if (black_turn == true) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 5; i >= 0; i--) {
				if (grid[i][j] == " b " && grid[i + 1][j - 1] == " b " && grid[i + 2][j - 2] == " b " && grid[i + 3][j - 3] == " b ") {
					cout << "--------------------" << endl;
					cout << "Diagonal Match, Black Wins" << endl;
					return true;
				}
			}

		}
	}
	else if (black_turn == false) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 5; i >= 0; i--) {
				if (grid[i][j] == " r " && grid[i + 1][j - 1] == " r " && grid[i + 2][j - 2] == " r " && grid[i + 3][j - 3] == " r ") {
					cout << "--------------------" << endl;
					cout << "Diagonal Match, Red Wins" << endl;
					return true;
				}
			}

		}
	}
	return false;
}

bool check_win_diagonal_down(const char* grid[row][column], bool black_turn) {
	if (black_turn == true) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 0; i <= 5; i++) {
				if (grid[i][j] == " b " && grid[i + 1][j + 1] == " b " && grid[i + 2][j + 2] == " b " && grid[i + 3][j + 3] == " b ") {
					cout << "--------------------" << endl;
					cout << "Diagonal Match, Black Wins" << endl;
					return true;
				}
			}

		}
	}
	else if (black_turn == false) {
		for (int j = 0; j <= 6; j++) {
			for (int i = 0; i <= 5; i++) {
				if (grid[i][j] == " r " && grid[i + 1][j + 1] == " r " && grid[i + 2][j + 2] == " r " && grid[i + 3][j + 3] == " r ") {
					cout << "--------------------" << endl;
					cout << "Diagonal Match, Red Wins" << endl;
					return true;
				}
			}

		}
	}
	return false;
}

int main()
{
	bool game_over = false;
	bool black_turn = true;
	const char* grid[row][column];

	init_grid(grid);

	do {
		int col = 0;
		player_turn(black_turn);
		col = col_chooser(black_turn, col);
		system("cls");
		cout << "--------------------"<<endl;
		col--;
		update_grid(grid, black_turn, col);
		print_grid(grid);
		game_over = check_win_verticle(grid, black_turn);
		if (game_over == true) {
			break;
		}
		game_over = check_win_horizontal(grid, black_turn);
		if (game_over == true) {
			break;
		}
		game_over = check_win_diagonal_up(grid, black_turn);
		if (game_over == true) {
			break;
		}
		game_over = check_win_diagonal_down(grid, black_turn);
		black_turn = next_turn(black_turn);
	} while (game_over == false);


	return 0;
}