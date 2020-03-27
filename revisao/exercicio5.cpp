#include <iostream>

using namespace std;

class TipoMatriz {
    public:
        TipoMatriz(int grau) {
            mGrau = grau;
            mMatriz = new double *[mGrau];

            for (int i = 0; i < mGrau; i++) {
                mMatriz[i] = new double[mGrau];
            }

            for (int i = 0; i < mGrau; i++) {
                for (int j = 0; j < mGrau; j++) {
                    mMatriz[i][j] = 0;
                }
            }
        }

        ~TipoMatriz() {
            for (int i = 0; i < mGrau; i++) {
                delete[] mMatriz[i];
            }
            
            delete[] mMatriz;
        }

        void imprimir() {
            for (int i = 0; i < mGrau; i++) {
                for (int j = 0; j < mGrau; j++) {
                    cout << mMatriz[i][j];
                    if (j == mGrau - 1) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                }
            }
        }

        void operator=(const TipoMatriz& outraMatriz) {
            for (int i = 0; i < mGrau; i++) {
                for (int j = 0; j < mGrau; j++) {
                    mMatriz[i][j] = outraMatriz.mMatriz[i][j];
                }
            }
        }

        TipoMatriz operator*(const TipoMatriz& outraMatriz) {
            TipoMatriz matrizResultante(mGrau);
            for (int i = 0; i < mGrau; i++) {
                for (int j = 0; j < mGrau; j++) {
                    for (int k = 0; k < mGrau; k++) {
                        matrizResultante.mMatriz[i][j] = matrizResultante.mMatriz[i][j] + mMatriz[i][k] * outraMatriz.mMatriz[k][j];
                    }
                }
            }
            return matrizResultante;
        }

        void lerMatriz() {
            for (int i = 0; i < mGrau; i++) {
                for (int j = 0; j < mGrau; j++) {
                    cin >> mMatriz[i][j];
                }
            }
        }

    private:
        double** mMatriz;
        int mGrau;
};

int main() {
    TipoMatriz matriz1(4), matriz2(4), matriz3(4);
    matriz1.lerMatriz();
    matriz2.lerMatriz();
    matriz3 = matriz1 * matriz2;
    matriz3.imprimir();
    return 0;
}