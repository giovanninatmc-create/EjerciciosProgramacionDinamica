#include <iostream>  // Incluido para std::cout, std::cin
#include <string>    //  Incluido para usar std::string
#include <locale>    // Incluido para setlocale
#include <windows.h> // Incluido para Sleep
#include <iomanip>   // Incluido para std::setw, std::setprecision
#include <limits>
using namespace std;

// Variables globales
const int MAXIMO_INVENTARIO = 100; // Máximo de productos en el inventario
int productosActuales = 10;        // Número de productos iniciales en el inventario (se ira agregando más productos)

struct Producto // Estructura para almacenar los datos de un producto
{
    int claveProducto;
    string nombreProducto;
    int cantidadDisponible;
    double precioUnitario;
};

Producto inventario[MAXIMO_INVENTARIO] = { // Inventario inicial de diez productos
    {101, "Manzanas", 50, 40.00},
    {102, "Platano", 30, 18.50},
    {103, "Naranjas", 20, 20.80},
    {104, "Leche", 15, 29.90},
    {105, "Pan", 25, 5.00},
    {106, "Huevos", 40, 45.00},
    {107, "Queso", 10, 48.75},
    {108, "Arroz", 60, 21.20},
    {109, "Frijoles", 70, 36.50},
    {110, "Azucar", 80, 22.10}};

// ========================================================================================================
// Prototipos de funciones
void idioma();             // Configurar idioma y codificación
void menuPrincipal();      // Menú principal del sistema de inventario
void imprimirInventario(); // Mostrar el inventario completo

// ========================================================================================================
// Función principal
int main()
{
    idioma();        // Configurar idioma y codificación
    menuPrincipal(); // Mostrar el menú principal del sistema de inventario
    return 0;
}

// ========================================================================================================
// Definición de funciones

void idioma() // Configurar idioma y codificación
{
    system("chcp 65001 > nul");       // Cambiar a UTF-8 en Windows
    setlocale(LC_ALL, "es_MX.UTF-8"); // Configurar localización a español de México
}

void menuPrincipal() // Menú principal del sistema de inventario
{
    int opcionMenu;

    do
    {
        system("cls");
        cout << "========================     MENÚ PRINCIPAL    ========================" << endl;
        cout << "1. Ver inventario de productos." << endl;
        cout << "2. Agregar un nuevo producto." << endl;
        cout << "3. Eliminar un producto." << endl;
        cout << "4. Actualizar datos de producto." << endl;
        cout << "5. Salir del sistema" << endl;
        cout << "=======================================================================" << endl;
        cout << "Selecciona una opción (1-5): ";

        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:
            imprimirInventario();
            break;

        case 5:
            cout << "Presiona Enter para salir del sistema..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;

        default:
            cout << "Opcion invalida: " << opcionMenu << endl;
            cout << "Presiona Enter para reintentar." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (opcionMenu != 5);
}

void imprimirInventario() // Mostrar el inventario completo
{
    system("cls");
    cout << "======================== INVENTARIO DE PRODUCTOS ========================" << endl;
    cout << left << setw(10) << "Clave" //  Encabezados de la tabla
         << left << setw(20) << "Producto"
         << right << setw(12) << "Cantidad"
         << right << setw(20) << "Precio Unitario" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2); // Formatear números decimales a 2 dígitos

    for (int i = 0; i < productosActuales; i++) // Recorrer el inventario y mostrar cada producto
    {                                           // Mostrar datos del producto con formato de tabla
        cout << left << setw(10) << inventario[i].claveProducto
             << left << setw(20) << inventario[i].nombreProducto
             << right << setw(12) << inventario[i].cantidadDisponible
             << right << setw(10) << "$"
             << right << setw(10) << inventario[i].precioUnitario
             << endl;
    }

    cout << "=======================================================================" << endl;
    cout << "Presiona ENTER para regresar al menú principal...";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void agregarProducto()
{
    Producto nuevoProducto;
    system("cls") if (productosActuales >= MAX_INVENTARIO)
    {
        cout << "Inventario lleno, ya no hay espacio para agregar mas productos." << endl;
        cout << "Presiona Enter para regresar al menú principal" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    

}
