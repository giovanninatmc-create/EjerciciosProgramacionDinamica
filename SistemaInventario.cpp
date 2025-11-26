#include <iostream>
#include <string>
#include <locale>    // Incluido para setlocale
#include <windows.h> // Incluido para Sleep
using namespace std;
// Variables globales
const int registrosInventario = 10;

// Estructuras para productos
struct Producto
{
    string nombreProducto;
    int cantidadDisponible;
    double precioUnitario;
};

Producto inventario[registrosInventario] = {
    {"Laptop", 10, 15000.00},
    {"Smartphone", 25, 8000.00},
    {"Tablet", 15, 6000.00},
    {"Monitor", 8, 4000.00},
    {"Teclado", 30, 500.00},
    {"Mouse", 50, 300.00},
    {"Impresora", 5, 2500.00},
    {"Router", 12, 1200.00},
    {"Disco Duro", 20, 3500.00},
    {"Memoria USB", 40, 700.00}};

// Prototipos de funciones
void idioma();
void iniciarSesion();
void

    int
    main()
{

    idioma(); // Configurar idioma y codificación
    imprimirInventario();
    getchar();
    return 0;
}

void idioma() // Configurar idioma y codificación
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "es_MX.UTF-8");
}

// Imprimir inventario
void imprimirInventario()
{
    system("cls");
    cout << "======================== INVENTARIO DE PRODUCTOS ========================" << endl;
    cout << "Nombre del Producto       | Cantidad Disponible | Precio Unitario (MXN)" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    for (int i = 0; i < registrosInventario; i++)
    {
        cout << inventario[i].nombreProducto << "           | "
             << inventario[i].cantidadDisponible << "                 | $"
             << inventario[i].precioUnitario << endl;
    }
    cout << "=======================================================================\n";
    cout << "Presiona ENTER para volver...";
    cin.get();
}
