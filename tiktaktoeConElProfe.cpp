#include <iostream>
#include <vector>
#include<cstdlib>

using namespace std;

//Funciones
void Instruccions();
char PlayerSymbol();
char Oponent(char Player);
char Winner(const vector<char>& board);

//Constantes
const int	NUM_SQUARES = 9;
const char	EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const bool NO_ONE = false;

int main()
{
    char Player = PlayerSymbol(), Computer, Turn = X;
    vector<char> board(NUM_SQUARES, EMPTY);
    Player = PlayerSymbol();
    Computer = Oponent(Player);
    cout << "jugaras como: " << Player << "\n La computadora jugara como: " << Computer << "\n";

    Instruccions();

    board[2] = O;
    board[4] = O;
    board[6] = O;
    Winner(board);
    //while (Winner(board) == NO_ONE)
    //{

    //}
}
void Instruccions()
{
    cout << "---------- Bienvenido a TikTakToe ----------\n";
    cout << "Su batalla sera legendaria\n";
    cout << "Selecione una posicion\n";
    cout << " 0 | 1 | 2 \n";
    cout << " 3 | 4 | 5 \n";
    cout << " 6 | 7 | 8 \n";
}
char PlayerSymbol()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char answer;
    do
    {
        cout << "Quieres empezar como X? (y/n)\n";
        cin >> answer;
        if (answer == 'y')
        {
            return X;
        }
    } while (answer=='n'||answer=='y');
    return O;
}
char Oponent(char Player)
{
    if (Player == 'X')
    {
        return O;
    }
    else
    {
        return X;
    }
}
char Winner(const vector<char>& board)
{
    int aux = 0;
    for (int i = 0; i <= 8; i++)
    {
        cout << "\n" << i << "\n";
        if ((i % 3) == 0 && board[i] == X && board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            cout << " Ganaron las X\n";
            return X;
        }
        else if ((i % 3) == 0 && board[i] == O && board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            cout << " Ganaron las O\n";
            return O;
        }
        else if (i == 0 && board[i] == X && board[i] == board[4] && board[i] == board[8])
        {
            cout << " Ganaron las X\n";
            return X;
        }
        else if (i == 0 && board[i] == O && board[i] == board[4] && board[i] == board[8])
        {
            cout << " Ganaron las X\n";
            return O;
        }
        else if (i < 3 && board[i] == X && board[i] == board[i + 3] && board[i] == board[i + 6])
        {
            cout << " Ganaron las X\n";
            return X;
        }
        else if (i < 3 && board[i] == O && board[i] == board[i + 3] && board[i] == board[i + 6])
        {
            cout << " Ganaron las O\n";
            return O;
        }
        else if (i == 2 && board[i] == X && board[i] == board[4] && board[i] == board[6])
        {
            cout << " Ganaron las X\n";
            return X;
        }
        else if (i == 2 && board[i] == O && board[i] == board[4] && board[i] == board[6])
        {
            cout << " Ganaron las X\n";
            return O;
        }
        else if (board[i] == X || board[i] == O)
        {
            aux++;
        }
        system("pause");
    }
    cout << " Nadie ha ganado aun \n";
    return NO_ONE;
}