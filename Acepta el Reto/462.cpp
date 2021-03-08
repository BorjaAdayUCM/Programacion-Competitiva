#include <iostream>
#include <iomanip>


using namespace std;

int main() {
	long long int numCasos, veces, horas, minutos, segundos, diasFinal, horasFinal, minutosFinal, segundosFinal, segundosTotal;
	cin >> numCasos;
	while (numCasos != 0) {
		cin >> veces >> horas; cin.ignore(); cin >> minutos; cin.ignore(); cin >> segundos;
		segundosTotal = veces * (horas * 3600 + minutos * 60 + segundos);
		diasFinal = segundosTotal / 86400;
		horasFinal = (segundosTotal - diasFinal * 86400) / 3600;
		minutosFinal = (segundosTotal - (diasFinal * 86400) - (horasFinal * 3600)) / 60;
		segundosFinal = (segundosTotal - (diasFinal * 86400) - (horasFinal * 3600) - (minutosFinal * 60));
		cout << diasFinal << " " << setfill('0') << setw(2) << horasFinal << ":" << setfill('0') << setw(2) << minutosFinal << ":" << setfill('0') << setw(2) << segundosFinal << '\n';
		numCasos--;
	}
	return 0;
}