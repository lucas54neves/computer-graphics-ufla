#include <iostream>

using namespace std;

// Verifica se o sistema eh possivel e determinado
bool spd(double a1, double b1, double a2, double b2) {
    if ((a1 * b2) - (a2 * b1) != 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    double x1, y1, x2, y2, coordenadaConhecida, coordenadaDesconhecida, a1, b1, a2, b2, det;
    char caractere;

    cin >> x1 >> y1 >> x2 >> y2 >> caractere >> coordenadaConhecida;

    a1 = y2 - y1;
    b1 = x2 - x1;

    if (caractere == 'x') {
        a2 = 1;
        b2 = 0;
        if (spd(a1, b1, a2, b2)) {
            coordenadaDesconhecida = y1 + (coordenadaConhecida - x1) * (y2 - y1) / (x2 - x1);
            cout << coordenadaDesconhecida << endl;
        } else {
            cout << "nenhuma" << endl;
        }
    } else {
        a2 = 0;
        b2 = 1;
        if (spd(a1, b1, a2, b2)) {
            coordenadaDesconhecida = x1 + (coordenadaConhecida - y1) * (x2 - x1) / (y2 - y1);
            cout << coordenadaDesconhecida << endl;
        } else {
            cout << "nenhuma" << endl;
        }
    }
}