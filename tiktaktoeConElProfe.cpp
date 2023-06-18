#include <iostream>
#include <vector>
#include<cstdlib>

using namespace std;

//Funciones
void Saludo();
void Instruccions();
char PlayerSymbol();
char Oponent(char Player);
char WinConditions(const vector<char> board);
void PlayMode(char Player, vector<char>& board);
void Winner(vector<char> board);

//Constantes
const int	NUM_SQUARES = 9;
const char	EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const bool NO_ONE = false;

int main()
{
    char Player, Computer, Turn = X;
    vector<char> board(NUM_SQUARES, EMPTY);
    // inicio del juego
    Saludo();
    Player = PlayerSymbol();
    Computer = Oponent(Player);
    cout << "jugaras como: " << Player << "\n La computadora jugara como: " << Computer << "\n";
    Instruccions();
    while (WinConditions(board) == NO_ONE)
    {
        //jugara las X
        if (WinConditions(board) == NO_ONE)
        {
            if (Player == X)
            {
                PlayMode(Player, board);
            }
            else
            {
                PlayMode(Computer, board);
            }
        }
        //jugara las O
        if (WinConditions(board) == NO_ONE)
        {
            if (Player == O)
            {
                PlayMode(Player, board);
            }
            else
            {
                PlayMode(Computer, board);
            }
        }
    }
  

}

void Saludo()
{
cout << "Bienvenido a este reto mortal humano\n";
cout <<	"Te crees lo suficiente para enfrentarme?\n";
}

void Instruccions()
{
    cout << "---------- Bienvenido a TikTakToe ----------\n";
    cout << "Su batalla sera legendaria\n";
}

char PlayerSymbol()
{
    cout << "quieres jugar como las X, y/n\n";
    char answer;
    bool exit = false;
    do
    {
        cin >> answer;
        if (answer=='y')
        {
            return X;
        }
    } while (exit);
    return O;
}

char Oponent(char Player)
{
    if (Player == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

char WinConditions(const vector<char> board)
{
    for (int i = 0; i <= 8; i++)
    {
        if ((i % 3) == 0 && board[i] == X && board[i] == board[i + 1] && board[i] == board[i + 2])
        {         
            return X;
        }
        else if ((i % 3) == 0 && board[i] == O && board[i] == board[i + 1] && board[i] == board[i + 2])
        {          
            return O;
        }
        else if (i == 0 && board[i] == X && board[i] == board[4] && board[i] == board[8])
        {            
            return X;
        }
        else if (i == 0 && board[i] == O && board[i] == board[4] && board[i] == board[8])
        {        
            return O;
        }
        else if (i < 3 && board[i] == X && board[i] == board[i + 3] && board[i] == board[i + 6])
        {          
            return X;
        }
        else if (i < 3 && board[i] == O && board[i] == board[i + 3] && board[i] == board[i + 6])
        {         
            return O;
        }
        else if (i == 2 && board[i] == X && board[i] == board[4] && board[i] == board[6])
        {           
            return X;
        }
        else if (i == 2 && board[i] == O && board[i] == board[4] && board[i] == board[6])
        {             
            return O;
        }
    }
    return NO_ONE;
}

void PlayMode(char Player, vector<char>& board)
{
    int aux;
    cout << "Jugaran las " << Player;
    cout << "\nSelecione una posicion\n";

    for (int i = 0; i < board.size() ; i++)
    {
        if (i == 2 || i == 5 || i == 8)
        {
            if (board[i] == ' ')
            {
                cout << " " << i << "\n";
            }
            else
            {
                cout << " " << board[i] << "\n";

            }
        }
        else
        {
            if (board[i] == ' ')
            {
                cout << " " << i << " |";

            }
            else
            {
                cout << " " << board[i] << " |";
            }
        }
    }

    cin >> aux;
    if (Player == X)
    {
        if (board[aux] != X)
        {
            board[aux] = X;
        }
    }
    else if (Player == O)
    {
        if (board[aux] != O)
        {
            board[aux] = O;
        }
    }
}

void Winner(vector<char> board )
{
    if (WinConditions(board) != NO_ONE)
    {
        if (WinConditions(board) == X)
        {
            cout << " ganaron las X" << "\n";
        }
        else
        {
            cout << " ganaron las O" << "\n";
        }
    }
}
