#include <iostream>

using namespace std;

const int MAX_PALABRAS = 50;
const int MAX_LONG_PALABRA = 30;

int main() 
    {
        char frase[256];                       
        char palabras[MAX_PALABRAS][MAX_LONG_PALABRA];
        int numLetras[MAX_PALABRAS];
        int contadorPalabras = 0;

    
        for (int i = 0; i < MAX_PALABRAS; i++) 
            {
                for (int j = 0; j < MAX_LONG_PALABRA; j++) 
                    {
                        palabras[i][j] = '\0';
                    }

                numLetras[i] = 0; 
            }

    
        cout << "Introduce una frase: ";
        cin.getline(frase, 256);

        int indexFrase = 0;
        int indexPalabra = 0;

    
        while (frase[indexFrase] != '\0') 
            {
                
                if (frase[indexFrase] == ' ') 
                    {
                        if (indexPalabra > 0) 
                            { 
                                palabras[contadorPalabras][indexPalabra] = '\0';
                                numLetras[contadorPalabras] = indexPalabra; 
                                contadorPalabras++; 
                                indexPalabra = 0; 
                            }
                    } else 
                        {
                            if (indexPalabra < MAX_LONG_PALABRA - 1) 
                                {
                                    palabras[contadorPalabras][indexPalabra] = frase[indexFrase];
                                    indexPalabra++;
                                }
                        }

                indexFrase++; 
            }

        if (indexPalabra > 0) 
            {
                palabras[contadorPalabras][indexPalabra] = '\0';
                numLetras[contadorPalabras] = indexPalabra;
                contadorPalabras++;
            }

        cout << endl << "Palabras en la frase y su numero de letras:" << endl;

        for (int i = 0; i < contadorPalabras; i++) 
            {
                cout << palabras[i] << " - " << numLetras[i] << " letras" << endl;
            }

        return 0;
    }