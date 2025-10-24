#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32
#include <conio.h>
#endif
using namespace std;

// =============================================================
// PROTOTIPOS
// =============================================================
void mostrarInicio();
void pedirNombres(string &jugador1, string &jugador2);
int elegirTurnoAleatorio(string jugador1, string jugador2);
void limpiarPantalla();
int jugar(string jugador1, string jugador2, int turno);
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

    do
    {
        mostrarInicio();
#ifdef _WIN32
        getch();
#else
        cin.get();
#endif

        limpiarPantalla();
        pedirNombres(jugador1, jugador2);

        victoriasJ1 = 0;
        victoriasJ2 = 0;

        char jugarOtraVez;
        do
        {
            limpiarPantalla();
            int turno = elegirTurnoAleatorio(jugador1, jugador2);
            int resultado = jugar(jugador1, jugador2, turno);

            if (resultado == 1)
                victoriasJ1++;
            else if (resultado == 2)
                victoriasJ2++;

            cout << endl;
            cout << "=================================" << endl;
            cout << " MARCADOR ACTUAL" << endl;
            cout << "=================================" << endl;
            cout << jugador1 << ": " << victoriasJ1 << " victoria(s)" << endl;
            cout << jugador2 << ": " << victoriasJ2 << " victoria(s)" << endl;
            cout << "=================================" << endl;

            cout << "\nQuieres jugar otra vez? (S/N): ";
            cin >> jugarOtraVez;
            cin.ignore();

        } while (toupper(jugarOtraVez) == 'S');

        limpiarPantalla();
        mostrarResultadosFinales(jugador1, jugador2, victoriasJ1, victoriasJ2);

        cout << "\nQuieres volver al menu principal? (S/N): ";
        cin >> opcion;
        cin.ignore();

        if (toupper(opcion) == 'N')
        {
            volverMenu = false;
            limpiarPantalla();
            cout << "==============================================================" << endl;
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
void mostrarInicio()
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
void pedirNombres(string &jugador1, string &jugador2)
{
    cout << "==============================================================" << endl;
    cout << "NOMBRE DE LOS JUGADORES" << endl;
    cout << "==============================================================" << endl;
    cout << "Ingresa el nombre del jugador 1: ";
    getline(cin, jugador1);
    cout << "Ingresa el nombre del jugador 2: ";
    getline(cin, jugador2);
    cout << "==============================================================" << endl;
}

int elegirTurnoAleatorio(string jugador1, string jugador2)
{
    srand(time(0));
    int turno = rand() % 2; // 0 o 1
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
// Devuelve: 1 si gana jugador1, 2 si gana jugador2, 0 si hay empate
// =============================================================
int jugar(string jugador1, string jugador2, int turno)
{
    char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char marca;
    int casilla;
    bool ganador = false;

    do
    {
        limpiarPantalla();
        mostrarTablero(tablero);

        // Determinar jugador actual
        if (turno % 2 == 0)
        {
            cout << jugador1 << " (X), elige una casilla: ";
            marca = 'X';
        }
        else
        {
            cout << jugador2 << " (O), elige una casilla: ";
            marca = 'O';
        }

        cin >> casilla;

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
        turno++;

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
