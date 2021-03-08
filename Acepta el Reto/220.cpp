#include <iostream>

using namespace std;

//EL NUMERO QUE HACE SUMAR MAS AL CONTRARIO
bool partida(int & sumaTotal, int numJugado, int & turno)
{
	if (sumaTotal >= 31) return turno % 2 == 0;
	int numeroAJugar = 0;
	if (numJugado == 9) {
		if (sumaTotal + 8 < 31 && sumaTotal + 8 + 2 >= 31) numeroAJugar = 8;
		else if (sumaTotal + 6 < 31 && sumaTotal + 6 + 3 >= 31) numeroAJugar = 6;
		else if (sumaTotal + 7 < 31 && sumaTotal + 7 + 1 >= 31) numeroAJugar = 7;
		else numeroAJugar = 3;
	}
	else if (numJugado == 8) {
		if (sumaTotal + 9 < 31 && sumaTotal + 9 + 3 >= 31) numeroAJugar = 9;
		else if (sumaTotal + 7 < 31 && sumaTotal + 7 + 1 >= 31) numeroAJugar = 7;
		else if (sumaTotal + 5 < 31 && sumaTotal + 5 + 2 >= 31) numeroAJugar = 5;
		else numeroAJugar = 2;
	}
	else if (numJugado == 7) {
		if (sumaTotal + 9 < 31 && sumaTotal + 9 + 3 >= 31) numeroAJugar = 9;
		else if (sumaTotal + 8 < 31 && sumaTotal + 8 + 2 >= 31) numeroAJugar = 8;
		else if (sumaTotal + 4 < 31 && sumaTotal + 4 + 1 >= 31) numeroAJugar = 4;
		else numeroAJugar = 1;
	}
	else if (numJugado == 6) {
		if (sumaTotal + 9 < 31 && sumaTotal + 9 + 3 >= 31) numeroAJugar = 9;
		else if (sumaTotal + 5 < 31 && sumaTotal + 5 + 2 >= 31) numeroAJugar = 5;
		else if (sumaTotal + 4 < 31 && sumaTotal + 4 + 1 >= 31) numeroAJugar = 4;
		else numeroAJugar = 3;
	}
	else if (numJugado == 5) {
		if (sumaTotal + 8 < 31 && sumaTotal + 8 + 2 >= 31) numeroAJugar = 8;
		else if (sumaTotal + 6 < 31 && sumaTotal + 6 + 3 >= 31) numeroAJugar = 6;
		else if (sumaTotal + 4 < 31 && sumaTotal + 4 + 1 >= 31) numeroAJugar = 4;
		else numeroAJugar = 2;
	}
	else if (numJugado == 4) {
		if (sumaTotal + 6 < 31 && sumaTotal + 6 + 3 >= 31) numeroAJugar = 6;
		else if (sumaTotal + 7 < 31 && sumaTotal + 7 + 1 >= 31) numeroAJugar = 7;
		else if (sumaTotal + 5 < 31 && sumaTotal + 5 + 2 >= 31) numeroAJugar = 5;
		else numeroAJugar = 1;
	}
	else if (numJugado == 3) {
		if (sumaTotal + 9 < 31 && sumaTotal + 9 + 3 >= 31) numeroAJugar = 9;
		else if (sumaTotal + 6 < 31 && sumaTotal + 6 + 3 >= 31) numeroAJugar = 6;
		else if (sumaTotal + 2 < 31 && sumaTotal + 2 + 1 >= 31) numeroAJugar = 2;
		else numeroAJugar = 1;
	}
	else if (numJugado == 2) {
		if (sumaTotal + 8 < 31 && sumaTotal + 8 + 2 >= 31) numeroAJugar = 8;
		else if (sumaTotal + 5 < 31 && sumaTotal + 5 + 2 >= 31) numeroAJugar = 5;
		else if (sumaTotal + 3 < 31 && sumaTotal + 3 + 1 >= 31) numeroAJugar = 3;
		else numeroAJugar = 1;
	}
	else if (numJugado == 1) {
		if (sumaTotal + 7 < 31 && sumaTotal + 7 + 1 >= 31) numeroAJugar = 7;
		else if (sumaTotal + 4 < 31 && sumaTotal + 4 + 1 >= 31) numeroAJugar = 4;
		else if (sumaTotal + 3 < 31 && sumaTotal + 3 + 1 >= 31) numeroAJugar = 3;
		else numeroAJugar = 2;
	}
	sumaTotal += numeroAJugar;
	turno += 1;
	partida(sumaTotal, numeroAJugar, turno);
	return turno % 2 == 0;
}

bool resuelve() {
	int sumaTotal, numJugado;
	cin >> sumaTotal >> numJugado;
	int turno = 0;
	return partida(sumaTotal, numJugado, turno);
}

int main() {
	int numCasos;
	cin >> numCasos;
	while (numCasos > 0) {
		if (resuelve()) cout << "GANA\n";
		else cout << "PIERDE\n";
		numCasos--;
	}
}