#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double raio, angulo, anguloAtual, x, y, quantidade;

    cin >> raio >> quantidade;

    angulo = (M_PI * 2) / quantidade;

    for (int i = 0; i < quantidade; i++) {
        if (i == 0) {
            cout << fixed << setprecision(2) << raio << " " << 0 << endl;
        } else {
            anguloAtual = angulo * i;
            x = cos(anguloAtual) * raio;
            y = sin(anguloAtual) * raio;
            cout << fixed << setprecision(2) << x << " " << y << endl;
        }
    }

    return 0;
}