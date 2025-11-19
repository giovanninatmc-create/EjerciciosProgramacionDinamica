#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
using namespace std;

// Prototipos
void idioma();
void bienvenida();
void validarCuenta();
void menuPrincipal();

// Struct
struct clientes
{
    int numeroCuenta;
    double saldoActual;
    int NIP;
    string nombreCliente;
    string apellidoPaternoCliente;
    string apellidoMaternoCliente;
    string tipoCuenta;
};

// Base de datos
clientes carteraClientes[4] = {
    {123456, 1500.75, 1234, "Juan", "Pérez", "Gómez", "Ahorros"},
    {654321, 2500.00, 4321, "María", "López", "Hernández", "Corriente"},
    {112233, 500.50, 1111, "Carlos", "Ramírez", "Santos", "Ahorros"},
    {332211, 3000.20, 2222, "Ana", "Torres", "Vega", "Corriente"}};

int main()
{
    idioma();
    bienvenida();
    validarCuenta();
    return 0;
}

void idioma()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "es_MX.UTF-8");
}

void bienvenida()
{
    system("cls");
    cout << "*     BIENVENIDO AL BANCO DEL MALESTAR     *" << endl;
}

void validarCuenta()
{
    int cuentaIngresada;
    int nipIngresado;
    bool cuentaValida = false;
    int posCliente = -1;

    while (!cuentaValida)
    {
        cout << "Por favor, ingrese su número de cuenta: ";
        cin >> cuentaIngresada;

        // Buscar cuenta por busqueda secuencial
        for (int i = 0; i < 4; i++)
        {
            if (carteraClientes[i].numeroCuenta == cuentaIngresada)
            {
                cuentaValida = true;
                posCliente = i;
                break;
            }
        }

        if (!cuentaValida)
        {
            cout << "La cuenta no existe. Intente de nuevo.\n\n";
        }
    }

    // Cuenta encontrada
    cout << "Cuenta válida. Hola, " << carteraClientes[posCliente].nombreCliente << "!" << endl;

    cout << "Ingresa tu NIP: ";
    cin >> nipIngresado;

    if (nipIngresado == carteraClientes[posCliente].NIP)
    {
        cout << "NIP correcto. Acceso concedido.\n";
        menuPrincipal();
    }
    else
    {
        cout << "NIP incorrecto. Acceso denegado.\n";
    }
}

void menuPrincipal()
{
    system("cls");
    cout << "===== MENU PRINCIPAL =====" << endl;
}
