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

void limpiarPantalla() // Funcion para limpiar pantalla, ya sea Linux o Windows
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    string jugador1, jugador2;
    int victoriasJ1 = 0, victoriasJ2 = 0;

    bool vsCPU = false;
    int modo;

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

    return 0;
}