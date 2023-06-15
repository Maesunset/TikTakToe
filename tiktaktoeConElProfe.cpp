#include <iostream>
#include <vector>

using namespace std;

//Funciones
void Instruccion();
char PlayerSymbol();
char AskYesNo(string question);
char Oponent(char Player);
char Winner(const vector<char>& board);

//Constantes
const int	NUM_SQUARES = 9;
const char	EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const bool NO_ONE = 'N';

int main()
{
    //variables
    char Player = PlayerSymbol(), Computer, Turn = X;
    vector<char> board(NUM_SQUARES, EMPTY);
    Player = PlayerSymbol();
    Computer = Oponent(Player);
    cout << "jugaras como: " << Player << "\n La computadora jugara como: " << Computer << "\n";
    Instruccion();

    board[2] = O;
    board[4] = O;
    board[6] = O;
    Winner(board);
    //while (Winner(board) == NO_ONE)
    //{

    //}
}
void Instruccion()
{
    cout << "---------- Bienvenido a TikTakToe ----------\n";
    cout << "Su batalla sera legendaria\n";
    cout << "Selecione una posicion\n";
    cout << " 0 | 1 | 2 \n";
    cout << " 3 | 4 | 5 \n ";
    cout << " 6 | 7 | 8 \n";
}
char PlayerSymbol()
{
    char Option = AskYesNo("Quieres empezar?");
    if (Option == 'y')
    {
        return X;
    }
    return O;
}
char AskYesNo(string question)
{
    fflush;
    char answer = 'a';
    while (answer != 'y' && answer != 'n')
    {
        cout << "\n" << question << "(y/n)\n";
        cin >> answer;
    }
    return answer;
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
    for (int i = 0; i <= 8 ; i++)
    {
        cout << "\n" << i << "\n";
        if ((i%3) == 0 && board[i] == X && board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            cout << " Ganaron las X\n";
            return X;
        }
        else if ((i % 3) == 0 && board[i] == O && board[i] == board[i + 1] && board[i] == board[i + 2])
        {
            cout << " Ganaron las O\n";
            return O;
        }
        else if (i == 0 && board[i]==X && board[i] == board[4] && board[i] == board[8])
        {
            cout << " Ganaron las X\n";
            return X;
        }
        else if (i == 0 && board[i] == O && board[i] == board[4] && board[i] == board[8])
        {
            cout << " Ganaron las X\n";
            return O ;
        }
        else if ( i < 3 && board[i] == X && board[i] == board[i + 3] && board[i] == board[i + 6])
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
        system("pause");
    }
    cout << " Nadie ha ganado aun \n";
    return NO_ONE;
}