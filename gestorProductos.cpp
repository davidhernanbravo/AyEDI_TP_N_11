#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_PRODUCTOS = 100;

struct tProducto 
    {
        int id;
        double precio;
        int cantidad;
    };

typedef tProducto tLista[MAX_PRODUCTOS];

void cargarProductos(const string &nombreArchivo, tLista &lista, int &numProductos);
void guardarProductos(const string &nombreArchivo, const tLista &lista, int numProductos);
void mostrarProductos(const tLista &lista, int numProductos);
void agregarProducto(tLista &lista, int &numProductos);
void actualizarProducto(tLista &lista, int numProductos);
bool eliminarProducto(tLista &lista, int &numProductos, int idProducto);
int productoMaximoValor(const tLista &lista, int numProductos);

int main() 
    {
        tLista lista;
        int numProductos = 0;
        string nombreArchivo = "productos.txt";

        cargarProductos(nombreArchivo, lista, numProductos);

        int opcion;
        do 
            {
                cout << endl << "MENU" << endl;
                cout << "1. Mostrar productos" << endl;
                cout << "2. Agregar producto" << endl;
                cout << "3. Actualizar producto" << endl;
                cout << "4. Eliminar producto" << endl;
                cout << "5. Buscar y eliminar producto de mayor valor" << endl;
                cout << "0. Salir" << endl;
                cout << "Seleccione una opcion: ";
                cin >> opcion;

                switch (opcion) 
                    {
                        case 1:
                            mostrarProductos(lista, numProductos);
                            break;

                        case 2:
                            agregarProducto(lista, numProductos);
                            guardarProductos(nombreArchivo, lista, numProductos);
                            break;

                        case 3:
                            actualizarProducto(lista, numProductos);
                            guardarProductos(nombreArchivo, lista, numProductos);
                            break;
                        case 4: 
                            {
                                int id;

                                cout << "Ingrese el ID del producto a eliminar: ";
                                cin >> id;

                                if (eliminarProducto(lista, numProductos, id)) 
                                    {
                                        cout << "Producto eliminado." << endl;
                                        guardarProductos(nombreArchivo, lista, numProductos);

                                    } else 
                                        {
                                            cout << "Producto no encontrado." << endl;
                                        }
                                break;

                            }
                        case 5: 
                            {
                                int idMax = productoMaximoValor(lista, numProductos);

                                cout << "Producto con mayor valor (ID: " << idMax << ") sera eliminado." << endl;

                                if (eliminarProducto(lista, numProductos, idMax)) 
                                    {
                                        guardarProductos(nombreArchivo, lista, numProductos);
                                    }

                                break;
                            }
                        case 0:
                            cout << "Saliendo del programa." << endl;
                            break;

                        default:
                            cout << "Le pifiaste feo man." << endl;
                    }
                    
            } while (opcion != 0);

        return 0;
    }

void cargarProductos(const string &nombreArchivo, tLista &lista, int &numProductos) 
    {
        ifstream archivo(nombreArchivo);

        if (!archivo)
            {
                cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
                
                return;
            }

        numProductos = 0;
        while (archivo >> lista[numProductos].id >> lista[numProductos].precio >> lista[numProductos].cantidad) 
            {
                numProductos++;
                if (numProductos >= MAX_PRODUCTOS) break;
            }

        archivo.close();
    }

void guardarProductos(const string &nombreArchivo, const tLista &lista, int numProductos) 
    {
        ofstream archivo(nombreArchivo);

        if (!archivo) 
            {
                cerr << "No se pudo abrir el archivo para escritura." << endl;
                return;
            }

        for (int i = 0; i < numProductos; i++) 
            {
                archivo << lista[i].id << " " << lista[i].precio << " " << lista[i].cantidad << endl;
            }

        archivo.close();
    }

void mostrarProductos(const tLista &lista, int numProductos) 
    {
        cout << endl << "Productos:" << endl;
        cout << setw(10) << "ID" << setw(10) << "Precio" << setw(10) << "Cantidad" << endl;
        
        for (int i = 0; i < numProductos; i++) 
            {
                cout << setw(10) << lista[i].id << setw(10) << lista[i].precio << setw(10) << lista[i].cantidad << endl;
            }
    }

void agregarProducto(tLista &lista, int &numProductos) 
    {
        if (numProductos >= MAX_PRODUCTOS) 
            {
                cout << "No se pueden agregar mas productos." << endl;
                return;
            }

        cout << "Ingrese ID, precio y cantidad del producto: ";
        cin >> lista[numProductos].id >> lista[numProductos].precio >> lista[numProductos].cantidad;
        
        numProductos++;
    }

void actualizarProducto(tLista &lista, int numProductos) 
    {
        int id;

        cout << "Ingrese el ID del producto a actualizar: ";
        cin >> id;

        for (int i = 0; i < numProductos; i++) 
            {
                if (lista[i].id == id) 
                    {
                        cout << "Ingrese nuevo precio y cantidad: ";
                        cin >> lista[i].precio >> lista[i].cantidad;
                        cout << "Producto actualizado." << endl;
                        return;
                    }
            }

        cout << "Producto no encontrado." << endl;
    }

bool eliminarProducto(tLista &lista, int &numProductos, int idProducto) 
    {
        for (int i = 0; i < numProductos; i++) 
            {
                if (lista[i].id == idProducto) 
                    {
                        for (int j = i; j < numProductos - 1; j++) 
                            {
                                lista[j] = lista[j + 1];
                            }

                        numProductos--;
                        return true;
                    }
            }
            
        return false;
    }

// Función para encontrar el producto con mayor valor
int productoMaximoValor(const tLista &lista, int numProductos) 
    {
        int indiceMax = 0;
        double valorMax = lista[0].precio * lista[0].cantidad;

        for (int i = 1; i < numProductos; i++) 
            {
                double valorActual = lista[i].precio * lista[i].cantidad;

                if (valorActual > valorMax) 
                    {
                        valorMax = valorActual;
                        indiceMax = i;
                    }
            }

        cout << "ID del producto con mayor valor: " << lista[indiceMax].id << endl;
        
        return lista[indiceMax].id;
    }