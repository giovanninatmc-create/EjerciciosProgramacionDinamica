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
void mostrarTablero(char tablero[6][7]);
bool hayGanador(char tablero[6][7]);
bool tableroLleno(char tablero[6][7]);
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

            if (resultado == 1) // La variable resultado incrementa en 1 las victorias dependiendo que jugador gana
                victoriasJ1++;
            else if (resultado == 2)
                victoriasJ2++;

            // Esta parte del codigo muestra el marcador actual entre los jugadores
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
            cout << "   Gracias por jugar Conecta 4 - Nos vemos la proxima         " << endl;
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
    cout << "|                       *** CONECTA 4 ***                    |" << endl;
    cout << "|                | 1 | 2 | 3 | 4 | 5 | 6 | 7 |               |" << endl;
    cout << "|                |---+---+---+---+---+---+---|               |" << endl;
    cout << "|                | O | X | O | X |   |   |   |               |" << endl;
    cout << "|                | X | O | X | O |   |   |   |               |" << endl;
    cout << "|                | O | X | O | X |   |   |   |               |" << endl;
    cout << "|                | X | O | X | O |   |   |   |               |" << endl;
    cout << "==============================================================" << endl;
    cout << "\n";
    cout << "==============================================================" << endl;
    cout << "                   *** REGLAS DEL JUEGO ***                   " << endl;
    cout << "==============================================================" << endl;
    cout << "1. Hay dos jugadores: X y O." << endl;
    cout << "2. El jugador (X) siempre comienza la partida." << endl;
    cout << "3. Los jugadores se turnan para dejar su ficha en una columna." << endl;
    cout << "4. La ficha caerá hasta la posición más baja disponible en esa columna." << endl;
    cout << "5. No se puede colocar una ficha en una columna llena." << endl;
    cout << "6. Gana el jugador que conecte cuatro fichas seguidas en línea" << endl;
    cout << "   (ya sea horizontal, vertical o diagonal)." << endl;
    cout << "7. Si el tablero se llena sin ganador, el juego termina en EMPATE." << endl;
    cout << "==============================================================" << endl;
    cout << "Ejemplo de VICTORIA (Jugador X):" << endl;
    cout << "|   |   |   |   |   |   |   |" << endl;
    cout << "|   |   |   |   |   |   |   |" << endl;
    cout << "|   |   | X | O | O |   |   |" << endl;
    cout << "|   |   | X | X | O |   |   |" << endl;
    cout << "|   |   | X | O | X |   |   |" << endl;
    cout << "|   |   | X | O | O |   |   |" << endl;
    cout << "==============================================================" << endl;
    cout << "     Consejo: Planea tus movimientos y bloquea al rival!      " << endl;
    cout << "                   ¡QUE GANE EL MEJOR!                        " << endl;
    cout << "                         ( > w < )                            " << endl;
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
    int turno = rand() % 2; // 0 o 1
    cout << endl;
    cout << "==============================================================" << endl;
    cout << "Que los Dioses del Conecta 4 decidan quien empieza..." << endl;
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

void limpiarPantalla()
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
    char tablero[6][7]; // NUEVO TAMAÑO DEL TABLERO
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            tablero[i][j] = ' ';

    char marca;
    int columna;
    bool ganador = false;

    do
    {
        limpiarPantalla();
        mostrarTablero(tablero);

        if (turno % 2 == 0)
        {
            cout << jugador1 << " (X), elige una COLUMNA (1-7): ";
            marca = 'X';
            cin >> columna;
        }
        else
        {
            marca = 'O';
            if (vsCPU)
            {
                cout << "Turno de la CPU (O)..." << endl;
#ifdef _WIN32
                Sleep(600);
#else
                usleep(600000);
#endif
                do
                {
                    columna = rand() % 7 + 1;
                } while (tablero[0][columna - 1] != ' ');
            }
            else
            {
                cout << jugador2 << " (O), elige una COLUMNA (1-7): ";
                cin >> columna;
            }
        }

        if (columna < 1 || columna > 7)
        {
            cout << "Columna no valida. Intenta de nuevo." << endl;
#ifdef _WIN32
            system("pause");
#else
            cout << "Presiona ENTER para continuar...";
            cin.ignore();
            cin.get();
#endif
            continue;
        }

        int col = columna - 1;
        if (tablero[0][col] != ' ')
        {
            cout << "Esa columna esta llena. Elige otra." << endl;
#ifdef _WIN32
            system("pause");
#else
            cout << "Presiona ENTER para continuar...";
            cin.ignore();
            cin.get();
#endif
            continue;
        }

        for (int fila = 5; fila >= 0; fila--)
        {
            if (tablero[fila][col] == ' ')
            {
                tablero[fila][col] = marca;
                break;
            }
        }

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
#ifdef _WIN32
            system("pause");
#else
            cout << "Presiona ENTER para continuar...";
            cin.ignore();
            cin.get();
#endif
            return (marca == 'X') ? 1 : 2;
        }

        turno++;

    } while (!tableroLleno(tablero));

    limpiarPantalla();
    mostrarTablero(tablero);
    cout << "=================================" << endl;
    cout << "              EMPATE!            " << endl;
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
void mostrarTablero(char tablero[6][7])
{
    cout << "============ A JUGAR! ============" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << " ";
        for (int j = 0; j < 7; j++)
        {
            cout << tablero[i][j];
            if (j < 6)
                cout << " | ";
        }
        cout << endl;
        if (i < 5)
            cout << "---+---+---+---+---+---+---" << endl;
    }
    cout << "=================================" << endl;
}

// =============================================================
// COMPRUEBA SI HAY GANADOR
// =============================================================
bool hayGanador(char t[6][7])
{
    // Horizontal
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (t[i][j] != ' ' && t[i][j] == t[i][j + 1] && t[i][j] == t[i][j + 2] && t[i][j] == t[i][j + 3])
                return true;

    // Vertical
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 7; j++)
            if (t[i][j] != ' ' && t[i][j] == t[i + 1][j] && t[i][j] == t[i + 2][j] && t[i][j] == t[i + 3][j])
                return true;

    // Diagonal ↘
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            if (t[i][j] != ' ' && t[i][j] == t[i + 1][j + 1] && t[i][j] == t[i + 2][j + 2] && t[i][j] == t[i + 3][j + 3])
                return true;

    // Diagonal ↙
    for (int i = 3; i < 6; i++)
        for (int j = 0; j < 4; j++)
            if (t[i][j] != ' ' && t[i][j] == t[i - 1][j + 1] && t[i][j] == t[i - 2][j + 2] && t[i][j] == t[i - 3][j + 3])
                return true;

    return false;
}

// =============================================================
// COMPRUEBA SI EL TABLERO ESTA LLENO
// =============================================================
bool tableroLleno(char t[6][7])
{
    for (int j = 0; j < 7; j++)
        if (t[0][j] == ' ')
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
