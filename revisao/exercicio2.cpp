/*
    Entradas (sistema de coordenadas vermelho da figura):
    A largura da janela (uma linha com um número inteiro);
    A altura da janela (uma linha com um número inteiro);
    A coordenada X do mouse (uma linha com um número inteiro);
    A coordenada Y do mouse (uma linha com um número inteiro).

    Saídas (sistema de coordenas azul da figura):
    A coordenada X do mouse convertida para o sistema de coordenadas dos dados (número real);
    A coordenada Y do mouse convertida para o sistema de coordenadas dos dados (número real).
*/

#include <iostream>

using namespace std;

int main() {
    double largura_da_janela, altura_da_janela, x_mouse, y_mouse, x_convertido,
        y_convertido, largura_meio, altura_meio;
    
    cin >> largura_da_janela >> altura_da_janela >> x_mouse >> y_mouse;

    largura_meio = largura_da_janela / 2.0;
    altura_meio = altura_da_janela / 2.0;

    x_convertido = (double) (x_mouse - largura_meio) / largura_meio;
    y_convertido = ((double) (y_mouse - altura_meio) / altura_meio) * (-1);

    cout << x_convertido << endl;
    cout << y_convertido << endl;

    return 0;
}
