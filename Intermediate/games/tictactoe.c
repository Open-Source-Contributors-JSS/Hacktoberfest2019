#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int isInputValid(int, int, int);
int isBoardFull(char [N][N]);
void createInitialBoard(char [N][N]);
void readUserMove(int *, int *);
void printCurrentBoard(char[N][N]);
int getComputerMove(char [N][N], int *, int *, int, int);
int gameWon(char [N][N], char);
int computerPlaysToWin(char [N][N], int * , int * );
void computerPlaysRandom(int * , int * , int , int );
void sumAllDimensions(char [N][N], int [N], int [N], int *, int *);
int memberOf(int , int [N]);
int computerPlaysToBlock(char [N][N], int * , int * );

int main(){

    int userRow, userCol, computerRow, computerCol;
    int taken;
    char board[N][N];
    char winner = 'N';

    srand(time(NULL));

    printf("This tic-tac-toe board is of size %d by %d\n", N, N);

    printf("Player symbol: X \n Computer symbol: O\n\n");

    printf("Here is the board - spaces are indicated by a ?\n");

    createInitialBoard(board);          // create a 3 X 3 board with '?' in each cell

    while ((winner != 'Y') && !(isBoardFull(board))) // while there is no winner and the board is not full
    {
        taken = 0;

        while (!(taken))                  // loop used to accept valid row and col values from the user
        {
            readUserMove(&userRow, &userCol);                  //get user's move
            printf("You chose row %d and column %d \n", userRow, userCol);

            while (!isInputValid(userRow, 1, N) || !isInputValid(userCol, 1, N))     // validate user's move
            {
                printf("That's is an invalid row or column number - try again\n");
                readUserMove(&userRow, &userCol);
                printf("You chose row %d and column %d \n", userRow, userCol);
            }

            if (board[userRow-1][userCol-1] == '?')           // if cell is unoccupied
            {
                board[userRow-1][userCol-1] = 'X';          // store an X there
                taken = 1;
            }
            else
            {
                taken = 0;                                  // otherwise inform the user to enter values again
                printf("That spot is taken - please try another one\n");
            }

        } //end of while (!taken)

        if (gameWon(board, 'X'))   // check if the user wins - game will end if the user does win
        {
            printf("Congrats - you won against the computer :)\n");
            winner = 'Y';
        }

        else  if (!(isBoardFull(board)))            //check if the board is already full
        {
            taken = 0;

            while (!(taken))
            {
                getComputerMove(board, &computerRow, &computerCol, userRow-1, userCol-1); // get computer's row and col

                if (board[computerRow][computerCol] == '?')         // check if the cell is unoccupied
                {
                    board[computerRow][computerCol] = 'O';
                    taken = 1;

                }
                else
                {
                    taken = 0;      //That spot is taken - computer - try another one
                }
            }

            printf("Computer chose row %d and column %d \n", computerRow+1, computerCol+1);

            if (gameWon(board, 'O'))               // check if the computer wins - game must end if it does
            {
                printf("Oh the computer won this time :(( think hard next time\n");
                winner = 'Y';
            }
        }

        printCurrentBoard(board);

        printf("\nPress enter to continue \n");
        getchar();

    } //end of while

    if (winner != 'Y')
        printf("Game was a tie - no winner!\n\n");

    return 0;
}

int isInputValid(int entered, int minimum, int maximum) {
    /*
     * This function checks if the value passed through is within the min and max values, and return true or false
     */
    if (entered >= minimum && entered <= maximum) {
        return 1;
    } else { return 0; }
}

int isBoardFull(char board[N][N]) {
    /*
     * This function loops through the board, and if there are no '?'s, then the board is full. return true or false based on that
     */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '?') {
                return 0;
            }
        }
    }
    return 1;
}

void createInitialBoard(char board[N][N]) {
    /*
     * This function takes an empty 2d array and fills it will '?', then prints the board
     */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '?';
        }
    }
    printCurrentBoard(board);
    printf("\n");
}

void readUserMove(int *userRow, int *userCol) {
    /*
     * This function gets the users row and column choices and sets the pointers equal to the inputted answers
     */
    printf("Your move - enter numbers between 1 and %d\n\n", N);
    printf("Enter row number: ");
    scanf("%d", userRow);
    printf("Enter column number: ");
    scanf("%d", userCol);
}

void printCurrentBoard(char board[N][N]) {
    /*
     * This function prints the board on the screen and formats it properly
     */
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", board[i][j]);
            if (j < N - 1) {
                printf(" | "); //put vertical lines between the columns, but not on the outside
            } else {
                printf("\n");
            }
        }
        if (i < N - 1) {
            printf("----------"); //Print horizontal lines between the rows
            for (int x = 0; x < (N-3); x++) {
                printf("----");
            }
            printf("\n");
        }
    }
}

int  getComputerMove(char board[N][N], int *computerRow, int *computerCol, int userRow, int userCol){
    /*
     *This function determines computer's move in terms of row (computerRow) and column (computerCol)
     *and outputs them to main. The computer first tries to find a winning spot for itself; if it doesn't
     *find one, then it calls function computerPlaysRandom in its attempt to place its symbol in
     *the same row or column as the user (userRow, userCol)
     */

    int winningSpot = 0;
    int blocked = 0;

    winningSpot = computerPlaysToWin(board, computerRow, computerCol);

    if (!winningSpot) {            // if computer doesnt find a winning spot, then it plays to block the user
        blocked = computerPlaysToBlock(board, computerRow, computerCol);
        if (blocked == 0) {
            int counter = 0;
            do {
                counter += 1;
                computerPlaysRandom(computerRow, computerCol, userRow, userCol);
            } while (board[*computerRow][*computerCol] != '?' && counter < 300); //if the counter reaches 300, chances are, all available spots for the computer to take using the algorithm are taken
            if (counter == 300) {
                while (board[*computerRow][*computerCol] == '?') {
                    computerPlaysRandom(computerRow, computerCol, 1, 1); //choose a spot randomly until it works because the board isnt empty
                }
            }
        }
    }
    return winningSpot;
}

int gameWon(char board[N][N], char symbol) {
    /*
     * This function checks if the game was won for the given symbol. It checks horizontal, vertical, and diagonal lines. If there is a win, it returns true, otherwise it returns false
     */
    int amt = 0;
    int sumR[N];
    for (int i = 0; i < N; i++) {sumR[i] = 0;} //fill the array with zeros
    int sumC[N];
    for (int i = 0; i < N; i++) {sumC[i] = 0;} //fill the array with zeros
    int sumLD = 0;
    int sumRD = 0;

    sumAllDimensions(board, sumR, sumC, &sumLD, &sumRD);

    if (symbol == 'O') {amt = (N + 1) * N;} //set the amounts that the rows or columns should be equal to
    else {amt = N;}

    if (memberOf(amt, sumR)) { //check if the amount is withing the array, because if it is, that means a win was achieved
        return 1;
    }

    if (memberOf(amt, sumC)) { //same here
        return 1;
    }

    if (sumLD == amt || sumRD == amt) { //check if the diagonals are wins
        return 1;
    }

    return 0;
}

int computerPlaysToWin(char board[N][N], int *cRow, int *cCol) {
    /*
     * This function creates a copy of the board, and loops through each empty spot on the board and checks if it would be a win if the computer placed an 'O' there
     */
    char boardClone[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            boardClone[i][j] = board[i][j]; //create a clone list and make it equal to the current board
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (boardClone[i][j] == '?') { //if the spot is empty
                boardClone[i][j] = 'O';
                if (gameWon(boardClone, 'O')) { //check if the game would be won
                    *cRow = i; //if the game would be won, set the row and col for the computer
                    *cCol = j;
                    return 1; //return true
                } else {
                    boardClone[i][j] = '?'; //else, reset the clone board, otherwise it could create fake wins by eventually setting every empty value to O
                }
            }
        }
    }
    return 0;
}

void computerPlaysRandom(int *cRow, int *cCol, int uRow, int uCol) {///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    *cRow = uRow; //sets the computers column and row to the same as the computer so it doesnt have to switch later
    *cCol = uCol;
    int colRow = rand() % 3;
    if (colRow == 0) {
        *cCol = rand() % 3; //change the computer col, but the row will stay the same as the players due to above code
    } else if (colRow == 1) {
        *cRow = rand() % 3; //change the computer row, but col will remain
    } else {
        if (rand() % 2 == 0) { //right diagonal changes
            int ranval = rand() % 3;
            *cRow = ranval;
            *cCol = ranval;
        } else { //left diagonal changes
            int ranval = rand() % 3;
            *cRow = ranval;
            *cCol = N-ranval;
        }
    }
}

void sumAllDimensions(char board[N][N], int sumR[N], int sumC[N], int *sumLD, int *sumRD) {
    /*
     * This function creates a sum of every row, column, and diagonal, making O's equal to the size of the board plus one (so its size can be customizable), and X's to 1.
     * It sets the values passed through to these values
     */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { //sum of each row
            if (board[i][j] == 'O') {sumR[i] += (N + 1);}
            else if (board[i][j] == 'X') {sumR[i] += 1;}
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { //sum of each column
            if (board[j][i] == 'O') {sumC[i] += (N + 1);}
            else if (board[j][i] == 'X') {sumC[i] += 1;}
        }
    }
    for (int i = 0; i < N; i++) {
        if (board[i][i] == 'O') {*sumLD += (N + 1);} //sum the left diagonal
        else if (board[i][i] == 'X') {*sumLD += 1;}
    }
    for (int i = 0; i < N; i++) {
        if (board[i][N-i-1] == 'O') {*sumRD += (N + 1);} //sum the right diagonal
        else if (board[i][N-i-1] == 'X') {*sumRD += 1;}
    }
}

int memberOf(int aNum, int someArray[N]) {
    /*
     * This function checks if a given number is in it
     */
    for (int i = 0; i < N; i++) {
        if (someArray[i] == aNum) {
            return 1;
        }
    }
    return 0;
}

int computerPlaysToBlock(char board[N][N], int *cRow, int *cCol) {
    /*
     * This function creates a clone of the board, and loops through it. It checks every empty value and sets them one at a time to 'X' to see if the player would win on one of those moves.
     * If the player could win during the next move, the computer places an 'O' there.
     */
    char boardClone[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            boardClone[i][j] = board[i][j]; //create a board clone
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (boardClone[i][j] == '?') { //if the spot is empty
                boardClone[i][j] = 'X'; //set the current spot to X so it can be tested
                if (gameWon(boardClone, 'X')) { //if the player would win with the current board
                    *cRow = i;
                    *cCol = j;
                    return 1;
                } else {
                    boardClone[i][j] = '?'; //else, reset the board to prevent fake wins
                }
            }
        }
    }
    return 0;
}
