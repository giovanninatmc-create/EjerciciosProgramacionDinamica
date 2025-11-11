#include <iostream>
#include <locale.h> // Para cambiar idioma
#include <cstdlib>  // Para limpiar pantalla
#include <windows.h>
using namespace std;

string NOMBRE_JUGADOR;

void idioma() // Establece el idioma de la consola en español MX
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "es_MX.UTF-8");
}

void lobby() // Pantalla de inicio del juego
{
    idioma();
    system("cls");
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << R"(                            _             )" << endl;
    cout << R"(            ___ _ __   __ _| | _____  ___ )" << endl;
    cout << R"(           / __| '_ \ / _` | |/ / _ \/ __|)" << endl;
    cout << R"(           \__ \ | | | (_| |   <  __/\__ \)" << endl;
    cout << R"(           |___/_| |_|\__,_|_|\_\___||___/)" << endl;
    cout << R"(             _________         _________ )" << endl;
    cout << R"(            /         \       /         \   )" << endl;
    cout << R"(           /  /~~~~~\  \     /  /~~~~~\  \  )" << endl;
    cout << R"(           |  |     |  |     |  |     |  |)" << endl;
    cout << R"(           |  |     |  |     |  |     |  |)" << endl;
    cout << R"(           |  |     |  |     |  |     |  |         /)" << endl;
    cout << R"(           |  |     |  |     |  |     |  |       //)" << endl;
    cout << R"(          (o  o)    \  \_____/  /     \  \_____/ /)" << endl;
    cout << R"(           \__/      \         /       \        /)" << endl;
    cout << R"(            |         ~~~~~~~~~         ~~~~~~~~)" << endl;
    cout << R"(            ^)" << endl;
    cout << "\n";
    cout << "***************** BIENVENIDO A 'SNAKES' *****************" << endl;
    cout << "************ EL CLÁSICO JUEGO DE LA VÍBORITA ************" << endl;
    cout << "\n";
    cout << "******************* REGLAS DEL JUEGO: *******************" << endl;
    cout << "\n";
    cout << "1. Usa las FLECHAS del teclado para mover la serpiente." << endl;
    cout << "2. Come la comida (o) para crecer y sumar puntos." << endl;
    cout << "3. Evita chocar contra las paredes y tu propio cuerpo." << endl;
    cout << "4. Cada vez que comas, la serpiente se alarga y acelera." << endl;
    cout << "5. Si chocas... ¡GAME OVER!" << endl;
    cout << "\n";
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << "Presiona cualquier tecla para continuar..." << endl;
    cin.get();
}

void ingresarNombreJugador()
{
    system("cls");
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << "\n";
    cout << "Antes de comenzar, por favor ingresa tu nombre de jugador: " << endl;
    cout << "> ";
    getline(cin, NOMBRE_JUGADOR);
    cout << "\n ::: Perfecto, " << NOMBRE_JUGADOR << ". ¡Vamos allá! :::" << endl;
    cout << "\n";
    cout << R"(            ____                   ____)" << endl;
    cout << R"(      _,.-'`_ o `;__,        _,.-'`_ o `;__,)" << endl;
    cout << R"(       _.-'` '---'  '         _.-'` '---'  ')" << endl;
    cout << "\n";
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << "Presiona una tecla para comenzar el juego..." << endl;
    cin.get();
}

void animacionInicio()
{
    system("cls");
    cout << "\n\n\n";
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << "            Preparando el terreno de juego..." << endl;
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << "\n\n";

    const string frames[] = {
        R"(            ____)",
        R"(      _,.-'`_ o `;__,)",
        R"(       _.-'` '---'  ')",
    };

    cout << "\n";

    // Animación de la serpiente "avanzando"
    for (int paso = 0; paso <= 25; paso++)
    {
        system("cls");

        cout << "\n\n\n";
        cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
        cout << "            CARGANDO EL JUEGO..." << endl;
        cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
        cout << "\n";

        cout << "   ";

        // Dibuja la barra de carga
        for (int i = 0; i < paso; i++)
            cout << "=";

        cout << "~~o>";
        cout << "\n\n";

        // Dibuja la serpiente moviéndose
        for (auto &linea : frames)
            cout << linea << endl;

        cout << "\n";
        cout << "         " << paso * 4 << "% completado..." << endl;

        Sleep(250); // Controla la velocidad de la animación
    }

    cout << "\n\n";
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    cout << "               ¡Listo! Iniciando partida..." << endl;
    cout << "***...***...***...***...***...***...***...****S*N*A*K*E*S*" << endl;
    Sleep(3000);
    system("cls");
}

void dibujarTablero()
{
    cout << "Aqui deberia ir el tablero, si tuviera uno" << endl;
}

int main()
{
    idioma();
    lobby();
    ingresarNombreJugador();
    animacionInicio();
    dibujarTablero();

    return 0;
}
