#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	int numeros[100][100], filas, columnas;

	cout << "Filas: ";
	cin >> filas;
	cout << "Columnas: ";
	cin >> columnas;

	//Aqui se almacenan los datos de la matriz
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {

			if (i == 0 || j == 0 || i == filas -1 || j == columnas -1) {
				cout << " 1";
			}
			
			else 
			{ 

				cout << " 0";
			}

		}
		cout << "\n";
	}


	
	return 0;
}