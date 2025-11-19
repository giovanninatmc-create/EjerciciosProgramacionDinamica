#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <limits>
using namespace std;

struct DatosDeClientes
{
    int numeroCuenta;
    double saldoActual;
    int NIP;
    string PrimernombreCliente;
    string segundoNombreCliente;
    string apellidoPaternoCliente;
    string apellidoMaternoCliente;
    string tipoCuenta;
};

DatosDeClientes BaseDeDatosClientes[8] = {
    {123456, 1500.75, 1234, "Juan", "Carlos", "Perez", "Lopez", "Ahorros"},
    {234567, 2500.00, 2345, "Maria", "Elena", "Gomez", "Ramirez", "Corriente"},
    {345678, 3200.50, 3456, "Luis", "Miguel", "Hernandez", "Sanchez", "Ahorros"},
    {456789, 4100.25, 4567, "Ana", "Isabel", "Torres", "Flores", "Corriente"},
    {567890, 500.00, 5678, "Carlos", "Andres", "Diaz", "Morales", "Ahorros"},
    {678901, 750.80, 6789, "Sofia", "Lucia", "Vargas", "Cruz", "Corriente"},
    {789012, 1200.60, 7890, "Jorge", "Alberto", "Rojas", "Mendoza", "Ahorros"},
    {890123, 3000.90, 8901, "Laura", "Gabriela", "Castro", "Ortiz", "Corriente"}};

void idioma();
void MensajeBienvenidaInicial();
DatosDeClientes *iniciarSesion();
DatosDeClientes *buscarClientePorCuenta(int numeroCuenta);
int pedirEntradaNumericaValidada(string mensaje, int digitosExactos);

int main()
{
    idioma();
    MensajeBienvenidaInicial();

    DatosDeClientes *clienteActual = iniciarSesion();

    if (clienteActual != nullptr)
    {
        cout << clienteActual->PrimernombreCliente
             << ", has iniciado sesión correctamente." << endl;
    }
    else
    {
        cout << "No se pudo iniciar sesión." << endl;
    }

    return 0;
}

void idioma()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "es_MX.UTF-8");
}

void MensajeBienvenidaInicial()
{
    system("cls");
    cout << "======================================================================" << endl;
    cout << " " << endl;
    cout << "█████▄ ▄████▄ ███  ██ ▄█████ ▄████▄    ▄████  ███  ██ ██▄  ▄██ ▄█████ " << endl;
    cout << "██▄▄██ ██▄▄██ ██ ▀▄██ ██     ██  ██   ██  ▄▄▄ ██ ▀▄██ ██ ▀▀ ██ ██     " << endl;
    cout << "██▄▄█▀ ██  ██ ██   ██ ▀█████ ▀████▀    ▀███▀  ██   ██ ██    ██ ▀█████ " << endl;
    cout << " " << endl;
    cout << "::::::::::::::::::::::TU DINERO SIEMPRE SEGURO::::::::::::::::::::::::" << endl;
    cout << " " << endl;
    cout << "======================================================================" << endl;
    cout << "Presiona enter para continuar ..." << endl;
}

int pedirEntradaNumericaValidada(string mensaje, int digitosExactos)
{
    string entrada;
    int numero = 0;

    while (true)
    {
        cout << mensaje;
        getline(cin, entrada);

        if (entrada.length() != digitosExactos)
            continue;

        bool soloDigitos = true;
        for (char c : entrada)
        {
            if (!isdigit(c))
            {
                soloDigitos = false;
                break;
            }
        }

        if (!soloDigitos)
            continue;

        try
        {
            numero = stoi(entrada);
            if (numero < 0)
                continue;
        }
        catch (...)
        {
            continue;
        }

        return numero;
    }
}

DatosDeClientes *buscarClientePorCuenta(int numeroCuenta)
{
    for (int i = 0; i < 8; i++)
    {
        if (BaseDeDatosClientes[i].numeroCuenta == numeroCuenta)
        {
            return &BaseDeDatosClientes[i];
        }
    }
    return nullptr;
}

DatosDeClientes *iniciarSesion()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true)
    {
        system("cls");

        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << ":::::::::::::::::::::::::: INICIAR SESIÓN :::::::::::::::::::::::::::" << endl;

        int numeroCuentaIngresado = pedirEntradaNumericaValidada("Ingresa tu número de cuenta (6 dígitos): ", 6);

        DatosDeClientes *clientePorIngresar = buscarClientePorCuenta(numeroCuentaIngresado);

        if (clientePorIngresar == nullptr)
        {
            cout << "\nNúmero de cuenta no encontrado." << endl;
            cout << "Presiona ENTER para volver a intentarlo...";
            cin.get();
            continue;
        }

        int NIPIngresado = pedirEntradaNumericaValidada("Ingresa tu NIP (4 dígitos): ", 4);

        if (NIPIngresado != clientePorIngresar->NIP)
        {
            cout << "\nNIP incorrecto." << endl;
            cout << "Presiona ENTER para volver a intentarlo...";
            cin.get();
            continue;
        }

        cout << "\nInicio de sesión exitoso. Bienvenido, " << clientePorIngresar->PrimernombreCliente << "." << endl;
        cout << "================================================= BANCO - G N M C ===" << endl;

        return clientePorIngresar;
    }
}
