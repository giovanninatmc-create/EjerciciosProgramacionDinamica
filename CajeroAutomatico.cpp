#include <iostream>
#include <string>    // Incluido para usar std::string
#include <locale>    // Incluido para setlocale
#include <windows.h> // Incluido para Sleep
#include <limits>    // Incluido para numeric_limits
using namespace std;
// Estructura para almacenar los datos de los clientes
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

// Base de datos simulada de clientes
DatosDeClientes BaseDeDatosClientes[8] = {
    {123456, 1500.75, 1234, "Juan", "Carlos", "Perez", "Lopez", "Ahorros"},
    {234567, 2500.00, 2345, "Maria", "Elena", "Gomez", "Ramirez", "Corriente"},
    {345678, 3200.50, 3456, "Luis", "Miguel", "Hernandez", "Sanchez", "Ahorros"},
    {456789, 4100.25, 4567, "Ana", "Isabel", "Torres", "Flores", "Corriente"},
    {567890, 500.00, 5678, "Carlos", "Andres", "Diaz", "Morales", "Ahorros"},
    {678901, 750.80, 6789, "Sofia", "Lucia", "Vargas", "Cruz", "Corriente"},
    {789012, 1200.60, 7890, "Jorge", "Alberto", "Rojas", "Mendoza", "Ahorros"},
    {890123, 3000.90, 8901, "Laura", "Gabriela", "Castro", "Ortiz", "Corriente"}};

// ========================================================================================================
// Prototipos de funciones
void idioma();
void MensajeBienvenidaInicial();                                             // Mensaje de bienvenida
DatosDeClientes *iniciarSesion();                                            // Función para iniciar sesión
DatosDeClientes *buscarClientePorCuenta(int numeroCuenta);                   // Buscar cliente por número de cuenta
int pedirEntradaNumericaValidada(const string &mensaje, int digitosExactos); // Pedir entrada numérica validada en el inicio de sesión
double pedirMontoValidado(string mensaje);                                   // Pedir monto validado para retiros, depósitos y transferencias
void menuPrincipal(DatosDeClientes *cliente);                                // Menú principal después de iniciar sesión
void consultarSaldo(DatosDeClientes *cliente);                               // Consultar saldo de la cuenta
void retirar(DatosDeClientes *cliente);                                      // Retirar dinero de la cuenta
void depositar(DatosDeClientes *cliente);                                    // Depositar dinero en la cuenta
void transferir(DatosDeClientes *cliente);                                   // Transferir dinero a otra cuenta
void MensajeSalida();                                                        // Mensaje de salida

// ========================================================================================================
// Función principal
// Inicia el programa del cajero automático, mostrando el mensaje de bienvenida,
// gestionando el inicio de sesión del cliente y dirigiéndolo al menú principal si el inicio de sesión es exitoso.

int main()
{
    idioma();                   // Configurar idioma y codificación
    MensajeBienvenidaInicial(); // Mostrar mensaje de bienvenida

    DatosDeClientes *clienteActual = iniciarSesion(); // Iniciar sesión y obtener el cliente actual

    if (clienteActual != nullptr) // Si el inicio de sesión fue exitoso
    {
        Sleep(2000);                  // Pausa antes de mostrar el menú principal
        cin.sync();                   // Limpiar el buffer de entrada
        menuPrincipal(clienteActual); // Mostrar el menú principal
    }
    else // Si el inicio de sesión falló
    {
        cout << "Error al iniciar sesión. Saliendo del programa." << endl;
        Sleep(2000); // Pausa antes de salir
    }
    return 0;
}
// ========================================================================================================

// ========================================================================================================
// Definición de funciones

// Configurar idioma y codificación
void idioma()
{
    system("chcp 65001 > nul");       // Cambiar a UTF-8 en Windows
    setlocale(LC_ALL, "es_MX.UTF-8"); // Configurar localización a español de México
}

// Mostrar mensaje de bienvenida inicial
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
    cout << "Iniciando sistema espera por favor ..." << endl;
    Sleep(5000); // Pausa para que el usuario lea el mensaje
}

// Pedir entrada numérica validada en el inicio de sesión
int pedirEntradaNumericaValidada(const string &mensaje, int digitosExactos) //
{
    string entrada; // Variable para almacenar la entrada del usuario

    while (true) // Bucle infinito hasta que se reciba una entrada válida
    {
        cout << mensaje;       // Mostrar el mensaje al usuario
        getline(cin, entrada); // Leer la entrada del usuario (toda la línea)

        if (entrada.length() != digitosExactos) // Verificar si la longitud es correcta usando length()
            continue;                           // Si no es correcta, continuar al siguiente ciclo del bucle (bool soloDigitos = true;)

        bool soloDigitos = true; // Variable para verificar si todos los caracteres son dígitos
        for (char c : entrada)   // Recorrer cada carácter en la entrada
        {
            if (!isdigit(c)) // Verificar si el carácter no es un dígito
            {
                soloDigitos = false; // Marcar como falso si se encuentra un carácter no numérico
                break;               // Salir del bucle for
            }
        }

        if (!soloDigitos) // Si no todos los caracteres son dígitos
            continue;     // Continuar al siguiente ciclo del bucle (try)

        try // Intentar convertir la entrada a un número entero
        {
            int numero = stoi(entrada); // Convertir la cadena a entero
            if (numero >= 0)            // Verificar si el número es no negativo
                return numero;          // Retornar el número válido
        }
        catch (...) // Capturar cualquier excepción durante la conversión
        {
        }
    }
}

// Pedir monto validado para retiros, depósitos y transferencias
double pedirMontoValidado(string mensaje)
{
    string entrada; // Variable para almacenar la entrada del usuario

    while (true) // Bucle infinito hasta que se reciba una entrada válida
    {
        cout << mensaje;       // Mostrar el mensaje al usuario
        getline(cin, entrada); // Leer la entrada del usuario (toda la línea)

        if (entrada.empty()) // Verificar si la entrada está vacía
            continue;        // Continuar al siguiente ciclo del bucle

        bool formatoCorrecto = true; // Variable para verificar el formato correcto
        int puntos = 0;              // Contador de puntos decimales

        for (char c : entrada) // Recorrer cada carácter en la entrada
        {
            if (c == '.') // Verificar si el carácter es un punto decimal
            {
                puntos++;       // Incrementar el contador de puntos
                if (puntos > 1) // Si hay más de un punto, el formato es incorrecto
                {
                    formatoCorrecto = false; // Marcar como falso
                    break;                   // Salir del bucle for
                }
            }
            else if (!isdigit(c)) // Verificar si el carácter no es un dígito
            {
                formatoCorrecto = false; // Marcar como falso si se encuentra un carácter no numérico
                break;                   // Salir del bucle for
            }
        }

        if (!formatoCorrecto) // Si el formato no es correcto
            continue;         // Continuar al siguiente ciclo del bucle

        try // Intentar convertir la entrada a un número decimal
        {
            double monto = stod(entrada); // Convertir la cadena a double
            if (monto > 0)                // Verificar si el monto es positivo
                return monto;             // Retornar el monto válido
        }
        catch (...) // Capturar cualquier excepción durante la conversión
        {
        }
    }
}

// Buscar cliente por número de cuenta (busqueda lineal)
DatosDeClientes *buscarClientePorCuenta(int numeroCuenta)
{
    for (int i = 0; i < 8; i++) // Recorrer la base de datos de clientes
    {
        if (BaseDeDatosClientes[i].numeroCuenta == numeroCuenta) // Verificar si el número de cuenta coincide
            return &BaseDeDatosClientes[i];                      // Retornar la dirección del cliente encontrado
    }
    return nullptr; // Retornar nullptr si no se encuentra el cliente
}

// Función para iniciar sesión
DatosDeClientes *iniciarSesion()
{
    while (true) // Bucle infinito hasta que el inicio de sesión sea exitoso
    {
        system("cls");
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << ":::::::::::::::::::::::::: INICIAR SESIÓN :::::::::::::::::::::::::::" << endl;

        int numeroCuentaIngresado = pedirEntradaNumericaValidada("Ingresa tu número de cuenta (6 dígitos): ", 6); // Pedir número de cuenta
        DatosDeClientes *cliente = buscarClientePorCuenta(numeroCuentaIngresado);                                 // Buscar cliente por número de cuenta

        if (cliente == nullptr) // Si no se encuentra el cliente
        {
            cout << "\nNúmero de cuenta no encontrado.\nPresiona ENTER para intentar de nuevo..."; // Mensaje de error
            cin.get();                                                                             // Esperar a que el usuario presione ENTER
            continue;
        }

        int NIPIngresado = pedirEntradaNumericaValidada("Ingresa tu NIP (4 dígitos): ", 4); // Pedir NIP

        if (NIPIngresado != cliente->NIP) // Verificar si el NIP es incorrecto
        {
            cout << "\nNIP incorrecto.\nPresiona ENTER para intentar de nuevo..."; // Mensaje de error
            cin.get();                                                             // Esperar a que el usuario presione ENTER
            continue;                                                              // Continuar al siguiente ciclo del bucle
        }
        cout << "-----------------------------------------------" << endl;
        cout << "\nBienvenido, " << cliente->primernombreCliente << "." << endl; // Mensaje de bienvenida
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << "Cargando tus datos, espera..." << endl;
        Sleep(1500);    // Pausa antes de continuar
        return cliente; // Retornar el cliente autenticado
    }
}

// Menú principal después de iniciar sesión
void menuPrincipal(DatosDeClientes *cliente)
{

    while (true) // Bucle infinito para mostrar el menú principal
    {
        system("cls"); // Limpiar la pantalla
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << ":::::::::::::::::::::::::: MENÚ PRINCIPAL :::::::::::::::::::::::::::" << endl;
        cout << "\nCliente: " << cliente->primernombreCliente << " " << cliente->apellidoPaternoCliente << endl; // Mostrar nombre del cliente
        cout << "Tipo de cuenta: " << cliente->tipoCuenta << endl;                                               // Mostrar tipo de cuenta
        cout << "-----------------------------------------------" << endl;
        cout << "\nSelecciona una opción:" << endl; // Mostrar opciones del menú
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Transferencia a otra cuenta" << endl;
        cout << "5. Salir" << endl;
        cout << "================================================= BANCO - G N M C ===" << endl;

        string opcion;        // Variable para almacenar la opción seleccionada
        getline(cin, opcion); // Leer la opción del usuario

        if (opcion == "1")           // Si la opción es 1, consultar saldo
            consultarSaldo(cliente); // Consultar saldo de la cuenta
        else if (opcion == "2")      // Si la opción es 2, retirar dinero
            retirar(cliente);
        else if (opcion == "3") // Si la opción es 3, depositar dinero
            depositar(cliente);
        else if (opcion == "4") // Si la opción es 4, transferir dinero
            transferir(cliente);
        else if (opcion == "5") // Si la opción es 5, salir
        {
            MensajeSalida(); // Mostrar mensaje de salida
            return;          // Salir del menú principal
        }
    }
}

// Consultar saldo de la cuenta
void consultarSaldo(DatosDeClientes *cliente)
{
    system("cls");
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << ":::::::::::::::::::::::::: CONSULTA DE SALDO ::::::::::::::::::::::::" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl; // Mostrar saldo actual
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

// Retirar dinero de la cuenta
void retirar(DatosDeClientes *cliente)
{
    system("cls");
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << "::::::::::::::::::::::::: RETIRO DE EFECTIVO ::::::::::::::::::::::::" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl; // Mostrar saldo actual

    double monto = pedirMontoValidado("Monto a retirar: "); // Pedir monto a retirar

    if (monto > cliente->saldoActual) // Verificar si hay fondos suficientes
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Fondos insuficientes." << endl; // Mensaje de error
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << "Presiona ENTER para volver...";
        cin.get();
        return;
    }

    cliente->saldoActual -= monto; // Restar el monto retirado del saldo actual
    cout << "-----------------------------------------------" << endl;
    cout << "Retiro exitoso.\nNuevo saldo: $" << cliente->saldoActual << endl; // Mostrar nuevo saldo
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

// Depositar dinero en la cuenta
void depositar(DatosDeClientes *cliente)
{
    system("cls");
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << ":::::::::::::::::::::::: DEPÓSITO DE EFECTIVO :::::::::::::::::::::::" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl; // Mostrar saldo actual

    double monto = pedirMontoValidado("Monto a depositar: "); // Pedir monto a depositar

    cliente->saldoActual += monto; // Sumar el monto depositado al saldo actual
    cout << "-----------------------------------------------" << endl;
    cout << "Depósito exitoso.\nNuevo saldo: $" << cliente->saldoActual << endl; // Mostrar nuevo saldo
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

// Transferir dinero a otra cuenta
void transferir(DatosDeClientes *cliente)
{
    system("cls");
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << "::::::::::::::::::::::: TRANSFERENCIA A CUENTAS :::::::::::::::::::::" << endl;
    cout << "Saldo actual: $" << cliente->saldoActual << endl; // Mostrar saldo actual

    int cuentaDestino = pedirEntradaNumericaValidada("Ingresa la cuenta destino (6 dígitos): ", 6); // Pedir cuenta destino

    DatosDeClientes *destino = buscarClientePorCuenta(cuentaDestino); // Buscar cliente por número de cuenta destino

    if (destino == nullptr) // Si no se encuentra la cuenta destino
    {
        cout << "-----------------------------------------------" << endl;
        cout << "La cuenta destino no existe." << endl; // Mensaje de error
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << "Presiona ENTER para volver...";
        cin.get();
        return;
    }

    if (destino->numeroCuenta == cliente->numeroCuenta) // Verificar si la cuenta destino es la misma que la de origen
    {
        cout << "-----------------------------------------------" << endl;
        cout << "No puedes transferirte a ti mismo." << endl; // Mensaje de error
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << "Presiona ENTER para volver..." << endl;
        cin.get();
        return;
    }

    double monto = pedirMontoValidado("Monto a transferir: "); // Pedir monto a transferir

    if (monto > cliente->saldoActual) // Verificar si hay fondos suficientes
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Fondos insuficientes." << endl; // Mensaje de error
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << "Presiona ENTER para volver...";
        cin.get();
        return;
    }
    cout << "-----------------------------------------------" << endl;
    cout << "::::::::::::::::::::::: CONFIRMAR TRANSFERENCIA :::::::::::::::::::::" << endl;
    cout << "Cuenta origen:  " << cliente->numeroCuenta << endl;                                                // Mostrar cuenta origen
    cout << "Cuenta destino: " << destino->numeroCuenta << " (" << destino->primernombreCliente << ")" << endl; // Mostrar cuenta destino
    cout << "Monto: $" << monto << endl;                                                                        // Mostrar monto a transferir
    cout << "¿Confirmar transferencia? (s/n): ";                                                                // Pedir confirmación

    string confirm;        // Variable para almacenar la confirmación
    getline(cin, confirm); // Leer la confirmación del usuario

    if (confirm != "s" && confirm != "S") // Si la confirmación no es 's' o 'S'
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Transferencia cancelada." << endl; // Mensaje de cancelación
        cout << "================================================= BANCO - G N M C ===" << endl;
        cout << "Presiona ENTER para volver...";
        cin.get();
        return;
    }

    cliente->saldoActual -= monto; // Restar el monto transferido del saldo actual
    destino->saldoActual += monto; // Sumar el monto transferido al saldo de la cuenta destino

    cout << "-----------------------------------------------" << endl;
    cout << "Transferencia realizada con éxito." << endl;     // Mensaje de éxito
    cout << "Nuevo saldo: $" << cliente->saldoActual << endl; // Mostrar nuevo saldo
    cout << "================================================= BANCO - G N M C ===" << endl;
    cout << "Presiona ENTER para volver...";
    cin.get();
}

void MensajeSalida()
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
    cout << "¡Gracias por tu preferencia!. Saliendo del sistema ..." << endl;
    Sleep(5000); // Pausa para que el usuario lea el mensaje
}

// ========================================================================================================
