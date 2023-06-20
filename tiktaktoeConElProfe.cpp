#include <iostream>
#include <vector>
#include<cstdlib>

using namespace std;

//Funciones
void Saludo();
void Instruccions();
char PlayerSymbol();
char Oponent(char Player);
void ShowBoard(const vector<char> board);
char WinConditions(const vector<char> board);
void PlayMode(char Player, char computer, vector<char>& board);
void Winner(vector<char> board,char Player);
void IA(char computer, char Player ,vector<char>& board);
bool IAFIll(char Search, char fill, vector<char>& board);

//Constantes
const int	NUM_SQUARES = 9;
const char	EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const bool NO_ONE = false;
const char EMP = 'E';

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
    system("pause");
    system("cls");
    while (WinConditions(board) == NO_ONE)
    {
        //jugara las X
        if (WinConditions(board) == NO_ONE)
        {
            if (Player == X)
            {
                PlayMode(Player, Computer, board);
            }
            else
            {
                ShowBoard(board);
                cout << "es mi turno, es hora de humillarte\nPondre mi X aqui:";
                IA(Computer, Player ,board);
            }
        }
        //jugara las O
        if (WinConditions(board) == NO_ONE)
        {
            if (Player == O)
            {
                PlayMode(Player, Computer, board);
            }
            else
            {
                ShowBoard(board);
                cout << "es mi turno, es hora de humillarte\nPondre mi O aqui:";
                IA(Computer, Player, board);
            }
        }
    }
    system("pause");
    system("cls");
    ShowBoard(board);
    Winner(board, Player);
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
    char answer;
    bool exit = true;
    do
    {
        cout << "quieres jugar como las X, y/n\n";
        cin >> answer;
        if (answer == 'y'||answer == 'n')
        {
            if (answer=='y')
            {
                return X;
                exit = false;
            }
            else
            {
                return O;
                exit = false;
            }
            exit = true;
        }
    } while (exit);
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

void ShowBoard(const vector<char> board)
{
    for (int i = 0; i < board.size(); i++)
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
}

char WinConditions(const vector<char> board)
{
    int emp=0;
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
        if (board[i] != EMPTY)
        {
            emp++;
        }
    }
    if (emp==8)
    {
        return EMP;
    }
    else
    {
        return NO_ONE;
    }
}

void PlayMode(char Player, char Computer , vector<char>& board)
{
    int aux;
    bool exit = true;
    do
    {
        cout << "Jugaran las " << Player;
        cout << "\nSelecione una posicion\n";
        ShowBoard(board);
        cin >> aux;
        if (board[aux] != Computer)
        {
            if (Player == X)
            {
                if (board[aux] != X)
                {
                    board[aux] = X;
                    exit = false;
                }
            }
            else if (Player == O)
            {
                if (board[aux] != O)
                {
                    board[aux] = O;
                    exit = false;
                }
            }
        }
    } while (exit);
}

void Winner(vector<char> board,char Player )
{
    if (WinConditions(board) != NO_ONE)
    {
        if (WinConditions(board) == X)
        {
            if (Player == X)
            {
                cout << " ganaron las X\n";
                cout << " Parece que me has derrotado, acepto que haz sido mejor rival que yo\n";
            }
            else
            {
                cout << " ganaron las O \n";
                cout << " esperaba mas de ti escoria humana \n";
                cout << " ahora arderas en el infierno por ser un simple perdedor \n";
            }
        }
        else if(WinConditions(board)== O)
        {
            if (Player == O)
            {
                cout << " ganaron las O\n";
                cout << " Parece que me has derrotado, acepto que haz sido mejor rival que yo\n";
            }
            else
            {
                cout << " ganaron las X \n";
                cout << " esperaba mas de ti escoria humana \n";
                cout << " ahora arderas en el infierno por ser un simple perdedor \n";
            }
        }
        else
        {
            cout << "esto es un empate\n";
            cout << "un digno rival que me desafia, pero la proxima vez te ganare...\n";
        }
    }
}

void IA(char computer, char Player, vector<char>& board)
{
    //variables necesarias
    bool exit = true;
    bool IAMove = true;

    // verificar si la computadora va a ganar
    if (IAMove)
    {
        IAMove = IAFIll(computer, computer, board);
    }

    // verificar si el player va a ganar 
    if (IAMove)
    {
        IAMove = IAFIll(Player, computer, board);
    }

    // pone en un lugar aleatorio si nada de lo anterior sucede
    if (IAMove)
    {
        do
        {
            srand((unsigned) time(NULL));
            int random = (rand() % 7) + 1;
            if (board[random] == EMPTY)
            {
                board[random] = computer;
                exit = false;
                IAMove = false;
            }
        } while (exit);
    }

}

bool IAFIll(char Search, char fill, vector<char>& board)
{
    // Revision de forma horizontal
    //del 0 al 2
    if (board[0] == Search && board[1] == Search && board[2] == EMPTY)
    {
        cout << 2 << endl;
        board[2] = fill;
        return false;
    }
    else if (board[1] == Search && board[2] == Search && board[0] == EMPTY)
    {
        cout << 0 << endl;
        board[0] = fill;
        return false;
    }
    else if (board[0] == Search && board[2] == Search && board[1] == EMPTY)
    {
        cout << 1 << endl;
        board[1] = fill;
        return false;
    }
    // del 3 al 5
    else if (board[3] == Search && board[4] == Search && board[5] == EMPTY)
    {
        cout << 5 << endl;
        board[5] = fill;
        return false;
    }
    else if (board[4] == Search && board[5] == Search && board[3] == EMPTY)
    {
        cout << 3 << endl;
        board[3] = fill;
        return false;
    }
    else if (board[3] == Search && board[5] == Search && board[4] == EMPTY)
    {
        cout << 4 << endl;
        board[4] = fill;
        return false;
    }       
    //del 6 al 8
    else if (board[6] == Search && board[7] == Search && board[8] == EMPTY)
    {
        cout << 8 << endl;
        board[8] = fill;
        return false;
    }
    else if (board[7] == Search && board[8] == Search && board[6] == EMPTY)
    {
        cout << 6 << endl;
        board[6] = fill;
        return false;
    }
    else if (board[6] == Search && board[8] == Search && board[7] == EMPTY)
    {
        cout << 7 << endl;
        board[7] = fill;
        return false;
    }

    //Revision de forma vertical
    //numeros 0,3,6
    if (board[0] == Search && board[3] == Search && board[6] == EMPTY)
    {
        cout << 6 << endl;
        board[6] = fill;
        return false;
    }
    else if (board[3] == Search && board[6] == Search && board[0] == EMPTY)
    {
        cout << 0 << endl;
        board[0] = fill;
        return false;
    }
    else if (board[0] == Search && board[6] == Search && board[3] == EMPTY)
    {
        cout << 3 << endl;
        board[3] = fill;
        return false;
    }
    //numeros 1,4,7      
    else if (board[1] == Search && board[4] == Search && board[7] == EMPTY)
    {
        cout << 7 << endl;
        board[7] = fill;
        return false;
    }
    else if (board[4] == Search && board[7] == Search && board[1] == EMPTY)
    {
        cout << 1 << endl;
        board[1] = fill;
        return false;
    }
    else if (board[1] == Search && board[7] == Search && board[4] == EMPTY)
    {
        cout << 4 << endl;
        board[4] = fill;
        return false;
    }
    //numeros 2,5,8
    else if (board[2] == Search && board[5] == Search && board[8] == EMPTY)
    {
        cout << 8 << endl;
        board[8] = fill;
        return false;
    }
    else if (board[5] == Search && board[8] == Search && board[2] == EMPTY)
    {
        cout << 2 << endl;
        board[2] = fill;
        return false;
    }
    else if (board[2] == Search && board[8] == Search && board[5] == EMPTY)
    {
        cout << 5 << endl;
        board[5] = fill;
        return false;
    }

    //Revision de forma diagonal 
    //0,4,8
    if (board[0] == Search && board[4] == Search && board[8] == EMPTY)
    {
        cout << 8 << endl;
        board[8] = fill;
        return false;
    }
    else if (board[4] == Search && board[8] == Search && board[0] == EMPTY)
    {
        cout << 0 << endl;
        board[0] = fill;
        return false;
    }
    else if (board[0] == Search && board[8] == Search && board[4] == EMPTY)
    {
        cout << 5 << endl;
        board[4] = fill;
        return false;
    }

    //Revision de forma diagonal inversa
    //6,4,1
    if (board[6] == Search && board[4] == Search && board[2] == EMPTY)
    {
        cout << 2 << endl;
        board[2] = fill;
        return false;
    }
    else if (board[4] == Search && board[2] == Search && board[6] == EMPTY)
    {
        cout << 6 << endl;
        board[6] = fill;
        return false;
    }
    else if (board[6] == Search && board[4] == Search && board[2] == EMPTY)
    {
        cout << 2 << endl;
        board[2] = fill;
        return false;
    }
    return true;
}