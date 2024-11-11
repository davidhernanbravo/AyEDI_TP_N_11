#include <iostream>
#include <iomanip>

using namespace std;

const int N = 3; // Tamaño de la matriz NxN (puedes cambiar el valor de N).

void leerMatriz(int matriz[N][N]);
void mostrarMatriz(const int matriz[N][N]);
void sumarMatrices(const int matriz1[N][N], const int matriz2[N][N], int resultado[N][N]);
void restarMatrices(const int matriz1[N][N], const int matriz2[N][N], int resultado[N][N]);
void multiplicarMatrices(const int matriz1[N][N], const int matriz2[N][N], int resultado[N][N]);
void transponerMatriz(const int matriz[N][N], int resultado[N][N]);
void puntosSilla(const int matriz[N][N]);

int main() 
    {
        int opcion;
        int matriz1[N][N], matriz2[N][N], resultado[N][N];

        cout << "Operaciones sobre matrices de " << N << "x" << N << ":" << endl;
        cout << "1. Sumar 2 matrices" << endl;
        cout << "2. Restar 2 matrices" << endl;
        cout << "3. Multiplicar 2 matrices" << endl;
        cout << "4. Trasponer una matriz" << endl;
        cout << "5. Mostrar puntos de silla en una matriz" << endl;
        cout << "Seleccione una opcion (1-5): ";
        cin >> opcion;

        switch (opcion) 
        {
            case 1:
                cout << "Introduce los elementos de la primera matriz:" << endl;
                leerMatriz(matriz1);

                cout << "Introduce los elementos de la segunda matriz:" << endl;
                leerMatriz(matriz2);

                sumarMatrices(matriz1, matriz2, resultado);
                cout << "Resultado de la suma:" << endl;
                mostrarMatriz(resultado);

                break;

            case 2:
                cout << "Introduce los elementos de la primera matriz:" << endl;
                leerMatriz(matriz1);

                cout << "Introduce los elementos de la segunda matriz:" << endl;
                leerMatriz(matriz2);

                restarMatrices(matriz1, matriz2, resultado);
                cout << "Resultado de la resta:" << endl;
                mostrarMatriz(resultado);

                break;

            case 3:
                cout << "Introduce los elementos de la primera matriz:" << endl;
                leerMatriz(matriz1);

                cout << "Introduce los elementos de la segunda matriz:" << endl;
                leerMatriz(matriz2);

                multiplicarMatrices(matriz1, matriz2, resultado);
                cout << "Resultado de la multiplicacion:" << endl;
                mostrarMatriz(resultado);

                break;

            case 4:
                cout << "Introduce los elementos de la matriz:" << endl;
                leerMatriz(matriz1);

                transponerMatriz(matriz1, resultado);
                cout << "Resultado de la transposicion:" << endl;
                mostrarMatriz(resultado);

                break;

            case 5:
                cout << "Introduce los elementos de la matriz:" << endl;
                leerMatriz(matriz1);

                cout << "Matriz:" << endl;
                mostrarMatriz(matriz1);
                puntosSilla(matriz1);

                break;

            default:
                cout << "Opcion no valida changoooo..." << endl;

                break;
        }

        return 0;
    }

// Subprograma para leer una matriz desde el teclado.
void leerMatriz(int matriz[N][N]) 
    {
        for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                    {
                        cout << "Elemento [" << i << "][" << j << "]: ";
                        cin >> matriz[i][j];
                    }
            }
    }

// Subprograma para mostrar una matriz en pantalla.
void mostrarMatriz(const int matriz[N][N]) 
    {
        for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                    {
                        cout << setw(5) << matriz[i][j];
                    }
                    
                cout << endl;
            }
    }

// Suma de dos matrices.
void sumarMatrices(const int matriz1[N][N], const int matriz2[N][N], int resultado[N][N]) 
    {
        for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                    {
                        resultado[i][j] = matriz1[i][j] + matriz2[i][j];
                    }
            }
    }

// Resta de dos matrices.
void restarMatrices(const int matriz1[N][N], const int matriz2[N][N], int resultado[N][N]) 
    {
        for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                    {
                        resultado[i][j] = matriz1[i][j] - matriz2[i][j];
                    }
            }
    }

// Multiplicación de dos matrices.
void multiplicarMatrices(const int matriz1[N][N], const int matriz2[N][N], int resultado[N][N]) 
{
    for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
                {
                    resultado[i][j] = 0; // Inicializa el resultado en 0.
                    for (int k = 0; k < N; k++) 
                        {
                            resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                        }
                }
        }
}

// Transposición de una matriz.
void transponerMatriz(const int matriz[N][N], int resultado[N][N]) 
    {
        for (int i = 0; i < N; i++) 
            {
                for (int j = 0; j < N; j++) 
                    {
                        resultado[j][i] = matriz[i][j];
                    }
            }
    }

// Identificación de puntos de silla
void puntosSilla(const int matriz[N][N]) 
{
    bool puntoSillaEncontrado = false;

    for (int i = 0; i < N; i++) 
        {
            // Encuentra el mínimo en la fila
            int minFila = matriz[i][0];
            int colIndex = 0;

            for (int j = 1; j < N; j++) 
                {
                    if (matriz[i][j] < minFila) 
                        {
                            minFila = matriz[i][j];
                            colIndex = j;
                        }
                }

            // Verifica si el mínimo de la fila es el máximo en su columna
            bool esPuntoSilla = true;

            for (int k = 0; k < N; k++) 
                {
                    if (matriz[k][colIndex] > minFila) 
                        {
                            esPuntoSilla = false;

                            break;
                        }
                }

            if (esPuntoSilla) 
                {
                    puntoSillaEncontrado = true;

                    cout << "Punto de silla encontrado en [" << i << "][" << colIndex << "] con valor " << minFila << endl;
                }
        }

    if (!puntoSillaEncontrado) 
        {
            cout << "No se encontraron puntos de silla en la matriz." << endl;
        }
}