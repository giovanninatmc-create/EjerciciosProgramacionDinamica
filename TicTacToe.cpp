// PROMACACION DINAMICA
// MINI PROYECTO 1 - JUEGO DE TIC TAC TOE
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Procedimiento para mostrar las reglas
void reglas()
{
    system("cls");
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
    getch();
}

void pedirNombres(string &jugador1, string &jugador2)
{
    cout << "==============================================================" << endl;
    cout << "NOMBRE DE LOS JUGADORES" << endl;
    cout << "--------------------------------------------------------------" << endl;

    cout << "Ingresa el nombre del jugador 1: ";
    getline(cin, jugador1);

    cout << "Ingresa el nombre del jugador 2: ";
    getline(cin, jugador2);

    cout << "==============================================================" << endl;
}

int main()
{
    string jugador1, jugador2;
    reglas();
    system("cls");
    pedirNombres(jugador1, jugador2);

    cout << "Jugador 1: " << jugador1 << endl;
    cout << "Jugador 2: " << jugador2 << endl;
}
