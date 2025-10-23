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
void mostrarTablero(char tablero[3][3]);

// =============================================================
// FUNCION PRINCIPAL
// =============================================================
int main()
{
    string jugador1, jugador2;
    char tablero[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    mostrarInicio();
    limpiarPantalla();
    pedirNombres(jugador1, jugador2);
    elegirTurnoAleatorio(jugador1, jugador2);
    mostrarTablero(tablero);

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
