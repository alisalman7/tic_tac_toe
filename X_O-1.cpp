#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3]={'1', '2','3', '4', '5', '6','7', '8', '9'};

const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

        cout << "\nWould you like to play again? (Y/N): ";
        cin >> response;
        response = toupper(response);
    } while (response == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    cout<<"\n\n <|>'Tic Tac Toe Game'<|> \n"<<endl;
          cout<<" YOUx Vs COMPUTERy \n\n"<<endl;
          cout<<"   |   |   "<<endl;
          cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
          cout<<"___|___|___"<<endl;
          cout<<"   |   |   "<<endl;
          cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
          cout<<"___|___|___"<<endl;
          cout<<"   |   |   "<<endl;
          cout<<" "<< board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
          cout<<"   |   |   "<<endl;
}

int checkFreeSpaces()
{
    int freeSpaces = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                freeSpaces++;
            }
        }
    }

    return freeSpaces;
}

void playerMove()
{
    int x, y;

    do
    {
        cout << "Enter row #(1-3): ";
        cin >> x;
        x--;
        cout << "Enter column #(1-3): ";
        cin >> y;
        y--;

        if (x < 0 || x >= 3 || y < 0 || y >= 3)
        {
            cout << "Invalid move! Try again." << endl;
        }
        else if (board[x][y] != ' ')
        {
            cout << "Invalid move! Cell already occupied. Try again." << endl;
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (true);
}

void computerMove()
{
    srand(time(NULL));
    int x, y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}

char checkWinner()
{
    //check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }
    //check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }
    }
    //check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        cout << "You Win!" << endl;
    }
    else if (winner == COMPUTER)
    {
        cout << "You Lose!" << endl;
    }
    else
    {
        cout << "It's a Tie!" << endl;
    }
}
