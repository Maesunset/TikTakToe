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
void PlayMode(char Player, vector<char>& board);
void Winner(vector<char> board,char Player);
void IA(char computer, char Player ,vector<char>& board);

//Constantes
const int	NUM_SQUARES = 9;
const char	EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const bool NO_ONE = false;
const char EMP = 'EMP';

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
                PlayMode(Player, board);
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
                PlayMode(Player, board);
            }
            else
            {
                ShowBoard(board);
                cout << "es mi turno, es hora de humillarte\nPondre mi O aqui:";
                IA(Computer, Player, board);
            }
        }
    }
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

void PlayMode(char Player, vector<char>& board)
{
    int aux;
    cout << "Jugaran las " << Player;
    cout << "\nSelecione una posicion\n";
    ShowBoard(board);
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
    {//Revision de forma horizontal
        //del 0 al 2
        if (board[0] == computer && board[1] == computer && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
        else if (board[1] == computer && board[2] == computer && board[0] == EMPTY && IAMove)
        {
            cout << 0 << endl;
            board[0] = computer;
            IAMove = false;
        }
        else if (board[0] == computer && board[2] == computer && board[1] == EMPTY && IAMove)
        {
            cout << 1 << endl;
            board[1] = computer;
            IAMove = false;
        }
        // del 3 al 5
        else if (board[3] == computer && board[4] == computer && board[5] == EMPTY && IAMove)
        {
            cout << 5 << endl;
            board[5] = computer;
            IAMove = false;
        }
        else if (board[4] == computer && board[5] == computer && board[3] == EMPTY && IAMove)
        {
            cout << 3 << endl;
            board[3] = computer;
            IAMove = false;
        }
        else if (board[3] == computer && board[5] == computer && board[4] == EMPTY && IAMove)
        {
            cout << 4 << endl;
            board[4] = computer;
            IAMove = false;
        }        // del 3 al 5
        //del 6 al 8
        else if (board[6] == computer && board[7] == computer && board[8] == EMPTY && IAMove)
        {
            cout << 8 << endl;
            board[8] = computer;
            IAMove = false;
        }
        else if (board[7] == computer && board[8] == computer && board[6] == EMPTY && IAMove)
        {
            cout << 6 << endl;
            board[6] = computer;
            IAMove = false;
        }
        else if (board[6] == computer && board[8] == computer && board[7] == EMPTY && IAMove)
        {
            cout << 7 << endl;
            board[7] = computer;
            IAMove = false;
        }

        //Revision de forma vertical
        //numeros 0,3,6
        if (board[0] == computer && board[3] == computer && board[6] == EMPTY && IAMove)
        {
            cout << 6 << endl;
            board[6] = computer;
            IAMove = false;
        }
        else if (board[3] == computer && board[6] == computer && board[0] == EMPTY && IAMove)
        {
            cout << 0 << endl;
            board[0] = computer;
            IAMove = false;
        }
        else if (board[0] == computer && board[6] == computer && board[3] == EMPTY && IAMove)
        {
            cout << 3 << endl;
            board[3] = computer;
            IAMove = false;
        }
        //numeros 1,4,7      
        else if (board[1] == computer && board[4] == computer && board[7] == EMPTY && IAMove)
        {
            cout << 7 << endl;
            board[7] = computer;
            IAMove = false;
        }
        else if (board[4] == computer && board[7] == computer && board[1] == EMPTY && IAMove)
        {
            cout << 1 << endl;
            board[1] = computer;
            IAMove = false;
        }
        else if (board[1] == computer && board[7] == computer && board[4] == EMPTY && IAMove)
        {
            cout << 4 << endl;
            board[4] = computer;
            IAMove = false;
        }
        //numeros 2,5,8
        else if (board[2] == computer && board[5] == computer && board[8] == EMPTY && IAMove)
        {
            cout << 8 << endl;
            board[8] = computer;
            IAMove = false;
        }
        else if (board[5] == computer && board[8] == computer && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
        else if (board[2] == computer && board[8] == computer && board[5] == EMPTY && IAMove)
        {
            cout << 5 << endl;
            board[5] = computer;
            IAMove = false;
        }

        //Revision de forma diagonal 
        //0,4,8
        if (board[0] == computer && board[4] == computer && board[8] == EMPTY && IAMove)
        {
            cout << 8 << endl;
            board[8] = computer;
            IAMove = false;
        }
        else if (board[4] == computer && board[8] == computer && board[0] == EMPTY && IAMove)
        {
            cout << 0 << endl;
            board[0] = computer;
            IAMove = false;
        }
        else if (board[0] == computer && board[8] == computer && board[4] == EMPTY && IAMove)
        {
            cout << 5 << endl;
            board[4] = computer;
            IAMove = false;
        }

        //Revision de forma diagonal inversa
        //6,4,1
        if (board[6] == computer && board[4] == computer && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
        else if (board[4] == computer && board[2] == computer && board[6] == EMPTY && IAMove)
        {
            cout << 6 << endl;
            board[6] = computer;
            IAMove = false;
        }
        else if (board[6] == computer && board[4] == computer && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
    }

    // verificar si el player va a ganar 
    if (IAMove)
    {
        //Revision de forma horizontal
        //del 0 al 2
        if (board[0] == Player && board[1] == Player && board[2] == EMPTY && IAMove) 
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }       
        else if (board[1] == Player && board[2] == Player && board[0] == EMPTY && IAMove) 
        {
            cout << 0 << endl;
            board[0] = computer;
            IAMove = false;
        }       
        else if (board[0] == Player && board[2] == Player && board[1] == EMPTY && IAMove) 
        {
            cout << 1 << endl;
            board[1] = computer;
            IAMove = false;
        }   
        // del 3 al 5
        else if (board[3] == Player && board[4] == Player && board[5] == EMPTY && IAMove) 
        {
            cout << 5 << endl;
            board[5] = computer;
            IAMove = false;
        }        
        else if (board[4] == Player && board[5] == Player && board[3] == EMPTY && IAMove) 
        {
            cout << 3 << endl;
            board[3] = computer;
            IAMove = false;
        }        
        else if (board[3] == Player && board[5] == Player && board[4] == EMPTY && IAMove) 
        {
            cout << 4 << endl;
            board[4] = computer;
            IAMove = false;
        }        // del 3 al 5
        //del 6 al 8
        else if (board[6] == Player && board[7] == Player && board[8] == EMPTY && IAMove) 
        {
            cout << 8 << endl;
            board[8] = computer;
            IAMove = false;
        }        
        else if (board[7] == Player && board[8] == Player && board[6] == EMPTY && IAMove) 
        {
            cout << 6 << endl;
            board[6] = computer;
            IAMove = false;
        }        
        else if (board[6] == Player && board[8] == Player && board[7] == EMPTY && IAMove) 
        {
            cout << 7 << endl;
            board[7] = computer;
            IAMove = false;
        }

        //Revision de forma vertical
        //numeros 0,3,6
        if (board[0] == Player && board[3] == Player && board[6] == EMPTY && IAMove)
        {
            cout << 6 << endl;
            board[6] = computer;
            IAMove = false;
        }
        else if (board[3] == Player && board[6] == Player && board[0] == EMPTY && IAMove)
        {
            cout << 0 << endl;
            board[0] = computer;
            IAMove = false;
        }
        else if (board[0] == Player && board[6] == Player && board[3] == EMPTY && IAMove)
        {
            cout << 3 << endl;
            board[3] = computer;
            IAMove = false;
        }
        //numeros 1,4,7      
        else if (board[1] == Player && board[4] == Player && board[7] == EMPTY && IAMove)
        {
            cout << 7 << endl;
            board[7] = computer;
            IAMove = false;
        }
        else if (board[4] == Player && board[7] == Player && board[1] == EMPTY && IAMove)
        {
            cout << 1 << endl;
            board[1] = computer;
            IAMove = false;
        }
        else if (board[1] == Player && board[7] == Player && board[4] == EMPTY && IAMove)
        {
            cout << 4 << endl;
            board[4] = computer;
            IAMove = false;
        }
        //numeros 2,5,8
        else if (board[2] == Player && board[5] == Player && board[8] == EMPTY && IAMove)
        {
            cout << 8 << endl;
            board[8] = computer;
            IAMove = false;
        }
        else if (board[5] == Player && board[8] == Player && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
        else if (board[2] == Player && board[8] == Player && board[5] == EMPTY && IAMove)
        {
            cout << 5 << endl;
            board[5] = computer;
            IAMove = false;
        }
        
        //Revision de forma diagonal 
        //0,4,8
        if (board[0] == Player && board[4] == Player && board[8] == EMPTY && IAMove)
        {
            cout << 8 << endl;
            board[8] = computer;
            IAMove = false;
        }
        else if (board[4] == Player && board[8] == Player && board[0] == EMPTY && IAMove)
        {
            cout << 0 << endl;
            board[0] = computer;
            IAMove = false;
        }
        else if (board[0] == Player && board[8] == Player && board[4] == EMPTY && IAMove)
        {
            cout << 5 << endl;
            board[4] = computer;
            IAMove = false;
        }

        //Revision de forma diagonal inversa
        //6,4,1
        if (board[6] == Player && board[4] == Player && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
        else if (board[4] == Player && board[2] == Player && board[6] == EMPTY && IAMove)
        {
            cout << 6 << endl;
            board[6] = computer;
            IAMove = false;
        }
        else if (board[6] == Player && board[4] == Player && board[2] == EMPTY && IAMove)
        {
            cout << 2 << endl;
            board[2] = computer;
            IAMove = false;
        }
    }

    // pone en un lugar aleatorio si nada de lo anterior sucede
    if (IAMove)
    {
        do
        {
            srand((unsigned)time(NULL));
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
