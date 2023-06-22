#pragma once
#include<iostream>

using namespace std;

void Parte2Examen();

void Parte2Examen()
{
	// variables;
	const int MATRIZ[3][4] = { {2, 3, 1, 4}
							  ,{9, 8, 7, 9}
							  ,{3, 2, 1, 5} };
	int sum = 0, sub = 0, answer;

	// inicio programa
	cout << "empieza apartado del examen\n";
	cout << "su matriz es:\n";
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <=3; j++) 
		{
			cout << MATRIZ[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if ((MATRIZ[i][j]%2) == 0)
			{
				cout << "el numero " << MATRIZ[i][j] << " es par\n";
				sum += MATRIZ[i][j];
				cout << "su indice es: " << i << j << "\n";
				sub += ((i * 10) + j);
			}
		}
	}
	//mostrar resultados
	cout << "La summa de todos los pares es: " << sum<<"\n";
	cout << "La suma de su indice es: " << sub << "\n";
	answer = sum - sub;
	cout << " el resultado de restar la suma de los pares menos el total de indices es: " << answer << "\n";

	// acabar programa
	cout << "acaba el apartado 2 del examen\n";
	system("pause");
	system("cls");
}