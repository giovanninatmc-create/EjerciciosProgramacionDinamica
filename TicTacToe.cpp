#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

// =============================================================
// PROTOTIPOS
// Nos sirve para inicializar las funciones en cualquier momento
// =============================================================
void mostrarInicio();
void pedirNombres(string &jugador1, string &jugador2, bool vsCPU);
int elegirTurnoAleatorio(string jugador1, string jugador2);
void limpiarPantalla();
int jugar(string jugador1, string jugador2, int turno, bool vsCPU);
void mostrarTablero(char tablero[3][3]);
bool hayGanador(char tablero[3][3]);
bool tableroLleno(char tablero[3][3]);
void mostrarResultadosFinales(string jugador1, string jugador2, int v1, int v2);

// =============================================================
// FUNCION PRINCIPAL
// =============================================================
int main()
{
    string jugador1, jugador2;
    int victoriasJ1 = 0, victoriasJ2 = 0;
    char opcion;
    bool volverMenu = true;
    bool vsCPU = false;
    int modo;

    do
    {
        mostrarInicio();
#ifdef _WIN32
        getch();
#else
        cin.get();
#endif

        limpiarPantalla();

        // SELECCION DE MODO DE JUEGO
        // Pide al usuario seleccionar el modo de juego y lo lee la variable modo
        cout << "==============================================================" << endl;
        cout << "Elige modo de juego:" << endl;
        cout << "1. Jugador vs Jugador" << endl;
        cout << "2. Jugador vs CPU" << endl;
        cout << "==============================================================" << endl;
        cout << "Opcion: ";
        cin >> modo;
        cin.ignore();

        if (modo == 2) // Valida el modo de juego con una variable bool
            vsCPU = true;
        else
            vsCPU = false;

        pedirNombres(jugador1, jugador2, vsCPU); // Llama la funcion pedir nombres

        victoriasJ1 = 0; // Inicializamos las variables de victorias en 0
        victoriasJ2 = 0;

        char jugarOtraVez; // Declaramos una variable para la funcion de jugarOtraVez
        do
        {
            limpiarPantalla();
            int turno = elegirTurnoAleatorio(jugador1, jugador2);    // Llamamos a la funcion para que la compu decida quien inicia primero
            int resultado = jugar(jugador1, jugador2, turno, vsCPU); // Inicia la partida llamando a la funcion jugar

            if (resultado == 1) // La variable resultado incrementa en 1 las victorias dependiendo que jugardor gana
                victoriasJ1++;
            else if (resultado == 2)
                victoriasJ2++;

            // ESta parte del codigo muestra el marcador actual entre los jugadores
            cout << endl;
            cout << "=================================" << endl;
            cout << " MARCADOR ACTUAL" << endl;
            cout << "=================================" << endl;
            cout << jugador1 << ": " << victoriasJ1 << " victoria(s)" << endl;
            cout << jugador2 << ": " << victoriasJ2 << " victoria(s)" << endl;
            cout << "=================================" << endl;

            // Preguntamos al usuario si quiere jugar otra vez
            cout << "\nQuieres jugar otra vez? (S/N): ";
            cin >> jugarOtraVez;
            cin.ignore();

        } while (toupper(jugarOtraVez) == 'S');

        limpiarPantalla();
        mostrarResultadosFinales(jugador1, jugador2, victoriasJ1, victoriasJ2); // Llamamos a una funcion para mostrar el resultado final del juego

        cout << "\nQuieres volver al menu principal? (S/N): "; // Preguntamos si queremos volver al menu principal o cerrar el juego
        cin >> opcion;
        cin.ignore();

        if (toupper(opcion) == 'N') // no diferenciar entre mayuscula y minuscula
        {
            volverMenu = false;
            limpiarPantalla();
            cout << "==============================================================" << endl; // Si elegimos cerrar el juego sale un mensaje de agradecimiento
            cout << "   Gracias por jugar Tic Tac Toe  - Nos vemos la proxima      " << endl;
            cout << "==============================================================" << endl;
            cout << "Presiona una tecla para salir...";
#ifdef _WIN32
            getch();
#else
            cin.get();
#endif
        }

    } while (volverMenu);

    return 0;
}

// =============================================================
// DEFINICIONES DE FUNCIONES
// =============================================================
void mostrarInicio() // Muestra las reglas del juego
{
    cout << "==============================================================" << endl;
    cout << "|                 ****** BIENVENIDO A ******                 |" << endl;
    cout << "|                     *** TIC TAC TOE ***                    |" << endl;
    cout << "|                       X  |  O  |  X                        |" << endl;
    cout << "|                     -----+-----+-----                      |" << endl;
    cout << "|                       O  |  X  |  O                        |" << endl;
    cout << "|                     -----+-----+-----                      |" << endl;
    cout << "|                       X  |  O  |  X                        |" << endl;
    cout << "==============================================================" << endl;
    cout << "\n";
    cout << "==============================================================" << endl;
    cout << "                   *** REGLAS DEL JUEGO **                    " << endl;
    cout << "==============================================================" << endl;
    cout << "1. Hay dos jugadores: X y O." << endl;
    cout << "2. Se elejira quien comienza la partida, siempre es (X)" << endl;
    cout << "3. Los jugadores se turnan para marcar una casilla en el tablero." << endl;
    cout << "4. No se puede marcar una casilla ya ocupada." << endl;
    cout << "5. Gana quien forme tres en linea (fila, columna o diagonal)." << endl;
    cout << "6. Si se llenan las casillas sin ganador, hay empate." << endl;
    cout << "==============================================================" << endl;
    cout << "Ejemplo de EMPATE:" << endl;
    cout << " X | O | X " << endl;
    cout << "---+---+---" << endl;
    cout << " O | X | O " << endl;
    cout << "---+---+---" << endl;
    cout << " O | X | X " << endl;
    cout << endl;
    cout << "Ejemplo de VICTORIA (Jugador X):" << endl;
    cout << " X | X | X " << endl;
    cout << "---+---+---" << endl;
    cout << " O | O |   " << endl;
    cout << "---+---+---" << endl;
    cout << "   |   |   " << endl;
    cout << "==============================================================" << endl;
    cout << "     Consejo: Piensa tus movimientos y bloquea al rival!      " << endl;
    cout << "                   QUE GANE EL MEJOR!                         " << endl;
    cout << "                          ( UwU )                             " << endl;
    cout << "==============================================================" << endl;
    cout << "Presiona cualquier tecla para continuar..." << endl;
}

void pedirNombres(string &jugador1, string &jugador2, bool vsCPU) // Pide al usuario los nombres de los jugadores
{
    cout << "==============================================================" << endl;
    cout << "NOMBRE DE LOS JUGADORES" << endl;
    cout << "==============================================================" << endl;
    cout << "Ingresa el nombre del jugador 1: "; // Pide por default el numero del jugador 1
    getline(cin, jugador1);

    if (vsCPU)
    {
        jugador2 = "CPU";
        cout << "Modo CPU activado. Te enfrentaras a la computadora." << endl; // Si elegimos CPU aparece ese mensaje
    }
    else
    {
        cout << "Ingresa el nombre del jugador 2: "; // Si elegimos contra otro jugador nos pide su nombre
        getline(cin, jugador2);
    }

    cout << "==============================================================" << endl;
}

int elegirTurnoAleatorio(string jugador1, string jugador2)
{
    srand(time(0));
    int turno = rand() % 2; // 0 o 1, se generan estos dos valores y se elige aleatoriamente quien empieza el juego
    cout << endl;
    cout << "==============================================================" << endl;
    cout << "Que los Dioses del Tic Tac Toe decidan quien empieza..." << endl;
    cout << (turno == 0 ? jugador1 : jugador2) << " empieza la partida." << endl;
    cout << "==============================================================" << endl;
#ifdef _WIN32
    system("pause");
#else
    cout << "Presiona ENTER para continuar...";
    cin.get();
#endif
    return turno;
}

void limpiarPantalla() // Funcion para limpiar pantalla, ya sea Linux o Windows
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// =============================================================
// FUNCION PRINCIPAL DEL JUEGO
// =============================================================
int jugar(string jugador1, string jugador2, int turno, bool vsCPU)
{
    char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // arreglo para las casillas del tablero
    char marca;
    int casilla;
    bool ganador = false; // inicializamos la variable de ganador como false hasta que se cumpla y sea true

    do
    {
        limpiarPantalla();
        mostrarTablero(tablero); // Mostramos el tablero vacio

        // Determinar jugador actual
        if (turno % 2 == 0)
        {
            cout << jugador1 << " (X), elige una casilla: ";
            marca = 'X';
            cin >> casilla;
        }
        else
        {
            marca = 'O';
            if (vsCPU)
            {
                cout << "Turno de la CPU (O)..." << endl;
#ifdef _WIN32
                Sleep(700);
#else
                usleep(700000);
#endif
                do
                {
                    casilla = rand() % 9 + 1;
                } while (tablero[(casilla - 1) / 3][(casilla - 1) % 3] == 'X' ||
                         tablero[(casilla - 1) / 3][(casilla - 1) % 3] == 'O');
            }
            else
            {
                cout << jugador2 << " (O), elige una casilla: ";
                cin >> casilla;
            }
        }

        // Validar casilla
        if (casilla < 1 || casilla > 9)
        {
            cout << "Casilla no valida. Intenta de nuevo." << endl;
#ifdef _WIN32
            system("pause");
#else
            cout << "Presiona ENTER para continuar...";
            cin.ignore();
            cin.get();
#endif
            continue;
        }

        int fila = (casilla - 1) / 3;
        int col = (casilla - 1) % 3;

        // Si la casilla ya esta ocupada
        if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O')
        {
            cout << "Casilla ocupada. Intenta con otra." << endl;
#ifdef _WIN32
            system("pause");
#else
            cout << "Presiona ENTER para continuar...";
            cin.ignore();
            cin.get();
#endif
            continue;
        }

        // Colocar marca
        tablero[fila][col] = marca;

        // Comprobar ganador
        if (hayGanador(tablero))
        {
            limpiarPantalla();
            mostrarTablero(tablero);
            cout << "=================================" << endl;
            cout << " Felicidades! ";
            if (marca == 'X')
                cout << jugador1;
            else
                cout << jugador2;
            cout << " ha ganado esta partida." << endl;
            cout << "=================================" << endl;
            ganador = true;

#ifdef _WIN32
            system("pause");
#else
            cout << "Presiona ENTER para continuar...";
            cin.ignore();
            cin.get();
#endif

            if (marca == 'X')
                return 1;
            else
                return 2;
        }

        // Cambiar turno
        turno++; // incrementamos el uno siempre en uno, cuando sea par es jugador1, cuando se impar jugador 2

    } while (!tableroLleno(tablero));

    // Si se llena y no hay ganador
    limpiarPantalla();
    mostrarTablero(tablero);
    cout << "=================================" << endl;
    cout << "          Empate!               " << endl;
    cout << "=================================" << endl;
#ifdef _WIN32
    system("pause");
#else
    cout << "Presiona ENTER para continuar...";
    cin.ignore();
    cin.get();
#endif
    return 0;
}

// =============================================================
// MUESTRA EL TABLERO
// =============================================================
void mostrarTablero(char tablero[3][3])
{
    cout << "============ A JUGAR! ============" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << tablero[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---+---+---" << endl;
    }
    cout << "=================================" << endl;
}

// =============================================================
// COMPRUEBA SI HAY GANADOR
// =============================================================
bool hayGanador(char t[3][3])
{
    for (int i = 0; i < 3; i++)
        if (t[i][0] == t[i][1] && t[i][1] == t[i][2])
            return true;

    for (int i = 0; i < 3; i++)
        if (t[0][i] == t[1][i] && t[1][i] == t[2][i])
            return true;

    if (t[0][0] == t[1][1] && t[1][1] == t[2][2])
        return true;
    if (t[0][2] == t[1][1] && t[1][1] == t[2][0])
        return true;

    return false;
}

// =============================================================
// COMPRUEBA SI EL TABLERO ESTA LLENO
// =============================================================
bool tableroLleno(char t[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (t[i][j] != 'X' && t[i][j] != 'O')
                return false;
    return true;
}

// =============================================================
// MUESTRA RESULTADOS FINALES Y GANADOR DEL JUEGO
// =============================================================
void mostrarResultadosFinales(string jugador1, string jugador2, int v1, int v2)
{
    cout << "==============================================================" << endl;
    cout << "                MARCADOR DEL JUEGO" << endl;
    cout << "==============================================================" << endl;
    cout << jugador1 << ": " << v1 << " victoria(s)" << endl;
    cout << jugador2 << ": " << v2 << " victoria(s)" << endl;
    cout << "==============================================================" << endl;

    if (v1 > v2)
        cout << "El ganador indiscutible es: " << jugador1 << endl;
    else if (v2 > v1)
        cout << "El ganador indiscutible es: " << jugador2 << endl;
    else
        cout << "Bien jugado, es un empate." << endl;

    cout << "==============================================================" << endl;
}
