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
    string primernombreCliente;
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
int pedirEntradaNumericaValidada(const string &mensaje, int digitosExactos);
double pedirMontoValidado(string mensaje);
void menuPrincipal(DatosDeClientes *cliente);
void consultarSaldo(DatosDeClientes *cliente);
void retirar(DatosDeClientes *cliente);
void depositar(DatosDeClientes *cliente);
void transferir(DatosDeClientes *cliente);

int main()
{
    idioma();
    MensajeBienvenidaInicial();
    cin.get();

    DatosDeClientes *clienteActual = iniciarSesion();

    if (clienteActual != nullptr)
    {
        Sleep(2000);
        menuPrincipal(clienteActual);
    }
    else
    {
        Sleep(2000);
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
    cout << "Presiona ENTER para continuar..." << endl;
}

int pedirEntradaNumericaValidada(const string &mensaje, int digitosExactos)
{
    string entrada;

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
            int numero = stoi(entrada);
            if (numero >= 0)
                return numero;
        }
        catch (...)
        {
        }
    }
}

double pedirMontoValidado(string mensaje)
{
    string entrada;

    while (true)
    {
        cout << mensaje;
        getline(cin, entrada);

        if (entrada.empty())
            continue;

        bool formatoCorrecto = true;
        int puntos = 0;

        for (char c : entrada)
        {
            if (c == '.')
            {
                puntos++;
                if (puntos > 1)
                {
                    formatoCorrecto = false;
                    break;
                }
            }
            else if (!isdigit(c))
            {
                formatoCorrecto = false;
                break;
            }
        }

        if (!formatoCorrecto)
            continue;

        try
        {
            double monto = stod(entrada);
            if (monto > 0)
                return monto;
        }
        catch (...)
        {
        }
    }
}

DatosDeClientes *buscarClientePorCuenta(int numeroCuenta)
{
    for (int i = 0; i < 8; i++)
    {
        if (BaseDeDatosClientes[i].numeroCuenta == numeroCuenta)
            return &BaseDeDatosClientes[i];
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
        DatosDeClientes *cliente = buscarClientePorCuenta(numeroCuentaIngresado);

        if (cliente == nullptr)
        {
            cout << "\nNúmero de cuenta no encontrado.\nPresiona ENTER para intentar de nuevo...";
            cin.get();
            continue;
        }

        int NIPIngresado = pedirEntradaNumericaValidada("Ingresa tu NIP (4 dígitos): ", 4);

        if (NIPIngresado != cliente->NIP)
        {
            cout << "\nNIP incorrecto.\nPresiona ENTER para intentar de nuevo...";
            cin.get();
            continue;
        }

        cout << "\nBienvenido, " << cliente->primernombreCliente << "." << endl;
        Sleep(1500);
        return cliente;
    }
}

void menuPrincipal(DatosDeClientes *cliente)
{
    while (true)
    {
        system("cls");
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << ":::::::::::::::::::::::::: MENÚ PRINCIPAL :::::::::::::::::::::::::::" << endl;
        cout << "\nCliente: " << cliente->primernombreCliente << " " << cliente->apellidoPaternoCliente << endl;
        cout << "Tipo de cuenta: " << cliente->tipoCuenta << endl;
        cout << "\nSelecciona una opción:" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Transferencia a otra cuenta" << endl;
        cout << "5. Salir" << endl;
        cout << "================================================= BANCO - G N M C ===" << endl;

        string opcion;
        getline(cin, opcion);

        if (opcion == "1")
            consultarSaldo(cliente);
        else if (opcion == "2")
            retirar(cliente);
        else if (opcion == "3")
            depositar(cliente);
        else if (opcion == "4")
            transferir(cliente);
        else if (opcion == "5")
            return;
    }
}

void consultarSaldo(DatosDeClientes *cliente)
{
    system("cls");
    cout << "========================= CONSULTA DE SALDO =========================" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl;
    cout << "=====================================================================" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

void retirar(DatosDeClientes *cliente)
{
    system("cls");
    cout << "=========================== RETIRO DE EFECTIVO =======================" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl;

    double monto = pedirMontoValidado("Monto a retirar: ");

    if (monto > cliente->saldoActual)
    {
        cout << "Fondos insuficientes.\nPresiona ENTER...";
        cin.get();
        return;
    }

    cliente->saldoActual -= monto;

    cout << "Retiro exitoso.\nNuevo saldo: $" << cliente->saldoActual << endl;
    cout << "=====================================================================" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

void depositar(DatosDeClientes *cliente)
{
    system("cls");
    cout << "============================ DEPÓSITO ==============================" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl;

    double monto = pedirMontoValidado("Monto a depositar: ");

    cliente->saldoActual += monto;

    cout << "Depósito exitoso.\nNuevo saldo: $" << cliente->saldoActual << endl;
    cout << "=====================================================================" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

void transferir(DatosDeClientes *cliente)
{
    system("cls");
    cout << "========================== TRANSFERENCIA ============================" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl;

    int cuentaDestino = pedirEntradaNumericaValidada("Ingresa la cuenta destino (6 dígitos): ", 6);

    DatosDeClientes *destino = buscarClientePorCuenta(cuentaDestino);

    if (destino == nullptr)
    {
        cout << "La cuenta destino no existe.\nPresiona ENTER...";
        cin.get();
        return;
    }

    if (destino->numeroCuenta == cliente->numeroCuenta)
    {
        cout << "No puedes transferirte a ti mismo.\nPresiona ENTER...";
        cin.get();
        return;
    }

    double monto = pedirMontoValidado("Monto a transferir: ");

    if (monto > cliente->saldoActual)
    {
        cout << "Fondos insuficientes.\nPresiona ENTER...";
        cin.get();
        return;
    }

    system("cls");
    cout << "======================= CONFIRMAR TRANSFERENCIA =====================" << endl;
    cout << "Cuenta origen:  " << cliente->numeroCuenta << endl;
    cout << "Cuenta destino: " << destino->numeroCuenta << " (" << destino->primernombreCliente << ")" << endl;
    cout << "Monto: $" << monto << endl;
    cout << "=====================================================================" << endl;
    cout << "¿Confirmar transferencia? (s/n): ";

    string confirm;
    getline(cin, confirm);

    if (confirm != "s" && confirm != "S")
    {
        cout << "Transferencia cancelada.\nPresiona ENTER...";
        cin.get();
        return;
    }

    cliente->saldoActual -= monto;
    destino->saldoActual += monto;

    cout << "Transferencia realizada con éxito." << endl;
    cout << "Nuevo saldo: $" << cliente->saldoActual << endl;
    cout << "=====================================================================" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}
