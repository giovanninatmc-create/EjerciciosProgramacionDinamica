#include <iostream>
#include <cmath>     // Para funciones matemáticas como pow, sqrt
#include <stdexcept> // Para manejo de excepciones
#include <limits>
#include <string>
using namespace std;

double operar(double a, double b) { return a + b; }                             // Suma
double operar(int tipo, double a, double b) { return (tipo == 1) ? a - b : 0; } // Resta
double operar(double a, double b, int tipo) { return (tipo == 2) ? a * b : 0; } // Multiplicación

double dividir(double a, double b) // División
{
    if (b == 0)                                            // Verificar división entre cero
        throw runtime_error("Error: División entre cero"); // Lanzar excepción si b es cero
    return a / b;                                          // Retornar el resultado de la división
}

long long factorial(long long n) // Factorial
{
    if (n < 0)
        throw runtime_error("Error: Factorial negativo"); // Lanzar excepción si n es negativo
    if (n == 0 || n == 1)                                 // Caso base
        return 1;                                         // Retornar 1 para 0! y 1!
    return n * factorial(n - 1);                          // Llamada recursiva para calcular el factorial
}

double potencia(double base, double exponente = 2) // Potencia
{
    return pow(base, exponente); // Retornar la base elevada al exponente
}

double raiz(double numero = 0) // Raíz cuadrada
{
    if (numero < 0)                                            // Verificar si el número es negativo
        throw runtime_error("Error: Raíz de número negativo"); // Lanzar excepción si el número es negativo
    return sqrt(numero);                                       // Retornar la raíz cuadrada del número
}

void limpiar() // Limpiar el buffer de entrada
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void encabezado() // Mostrar el encabezado de la calculadora
{
    cout << endl;
    cout << "=========================================================" << endl;
    cout << "            G N M C   -   C A L C U L A D O R A         " << endl;
    cout << "=========================================================" << endl;
}

void menu() // Mostrar el menú de opciones
{
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicación" << endl;
    cout << "4. División" << endl;
    cout << "5. Factorial" << endl;
    cout << "6. Potencia" << endl;
    cout << "7. Raíz cuadrada" << endl;
    cout << "0. Salir" << endl;
    cout << "=========================================================" << endl;
    cout << "Elige una opción: ";
}

void idioma() // Configura el idioma y la codificación de la consola
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "es_MX.UTF-8");
}

// ===============================================
// FUNCION PRINCIPAL
int main() // Función principal del programa
{
    idioma();              // Configurar idioma
    int opcion;            // Variable para almacenar la opción del usuario
    double a, b;           // Variables para los operandos
    bool continuar = true; // Variable para controlar el bucle principal

    while (continuar) // Bucle principal
    {
        encabezado();  // Mostrar el encabezado
        menu();        // Mostrar el menú de opciones
        cin >> opcion; // Leer la opción del usuario

        if (cin.fail()) // Verificar si la entrada es inválida
        {
            cout << "Entrada incorrecta." << endl; // Mensaje de error
            limpiar();                             // Limpiar el buffer de entrada
            continue;                              // Continuar al siguiente ciclo del bucle
        }

        try // Manejar las operaciones según la opción seleccionada
        {
            switch (opcion)
            {
            case 1: // Suma
                cout << "Número 1: ";
                cin >> a; // Leer primer operando
                cout << "Número 2: ";
                cin >> b;                                      // Leer segundo operando
                cout << "Resultado: " << operar(a, b) << endl; // Mostrar resultado
                break;

            case 2: // Resta
                cout << "Número 1: ";
                cin >> a; // Leer primer operando
                cout << "Número 2: ";
                cin >> b;                                         // Leer segundo operando
                cout << "Resultado: " << operar(1, a, b) << endl; // Mostrar resultado
                break;

            case 3: // Multiplicación
                cout << "Número 1: ";
                cin >> a; // Leer primer operando
                cout << "Número 2: ";
                cin >> b;                                         // Leer segundo operando
                cout << "Resultado: " << operar(a, b, 2) << endl; // Mostrar resultado
                break;

            case 4: // División
                cout << "Número 1: ";
                cin >> a; // Leer primer operando
                cout << "Número 2: ";
                cin >> b; // Leer segundo operando
                cout << "Resultado: " << dividir(a, b) << endl;
                break;

            case 5: // Factorial
                cout << "Ingresa un número entero: ";
                cin >> a;                                                 // Leer el número para calcular el factorial
                cout << "Resultado: " << factorial((long long)a) << endl; // Mostrar resultado
                break;

            case 6: // Potencia
            {
                cout << "Base: ";
                cin >> a;
                limpiar(); // Limpiar el buffer de entrada

                cout << "Exponente (ENTER = 2): ";
                string entrada;        // Variable para leer la entrada del usuario del exponente
                getline(cin, entrada); // Leer la línea completa del exponente

                double exp; // Variable para almacenar el exponente

                if (entrada.empty()) // Si la entrada está vacía, usar el valor por defecto (al cuadrado)
                {
                    exp = 2;                                           // Exponente por defecto
                    cout << "Usando exponente por defecto: 2" << endl; // Notificar al usuario
                }
                else // Si se proporcionó un exponente, convertirlo a double
                {
                    exp = stod(entrada); // Convertir la entrada a double
                }

                cout << "Resultado: " << potencia(a, exp) << endl; // Mostrar resultado
                break;
            }

            case 7: // Raíz cuadrada
                cout << "Número: ";
                cin >> a;                                 // Leer el número para calcular la raíz cuadrada
                cout << "Resultado: " << raiz(a) << endl; // Mostrar resultado
                break;

            case 0:                // Salir
                continuar = false; // Cambiar la variable para salir del bucle
                break;

            default:
                cout << "Opción inválida." << endl; // Mensaje de error para opción inválida
            }
        }
        catch (exception &e) // Capturar excepciones y mostrar el mensaje de error
        {
            cout << e.what() << endl; // Mostrar el mensaje de la excepción
        }

        limpiar();
    }

    cout << endl
         << "Gracias por usar la calculadora GNMC." << endl;
    return 0;
}
