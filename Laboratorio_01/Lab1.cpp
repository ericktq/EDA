#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

double calcularDistanciaEuclidiana(const vector<double>& punto1, const vector<double>& punto2) {
    double distancia = 0.0;
    for (int i = 0; i < punto1.size(); ++i) {
        double diferencia = punto1[i] - punto2[i];
        distancia += diferencia * diferencia;
    }
    return sqrt(distancia);
}

int main() {
    srand(time(0));
    vector<int> dimensiones = {10, 50, 100, 500, 1000, 2000, 5000};
    for (int d : dimensiones) {
        cout << "-------------------" << endl;
        cout << "Dimensionalidad: " << d << endl;
        vector<vector<double>> puntos(100, vector<double>(d));
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < d; ++j) {
                puntos[i][j] = static_cast<double>(rand()) / RAND_MAX; // entre 0 y 1
            }
        }

        int numPuntos = puntos.size();
        int numDistancias = (numPuntos * (numPuntos - 1)) / 2; 
        //cout << "Número de distancias a calcular: " << numDistancias << endl;

        ofstream archivo("distancias_dim" + to_string(d) + ".txt");
        if (!archivo.is_open()) {
            cerr << "Error al abrir el archivo para escritura." << endl;
            return 1;
        }

        for (int i = 0; i < numPuntos; ++i) {
            for (int j = i + 1; j < numPuntos; ++j) {
                double distancia = calcularDistanciaEuclidiana(puntos[i], puntos[j]);
                archivo << "Distancia entre P" << i << " y P" << j << ": " << distancia << endl;
            }
        }
        archivo.close(); 
        cout << "Distancias guardadas en 'distancias_dim" << d << ".txt'" << endl;

    }
    return 0;
}