#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;

void idioma()
{
    system("chcp 65001 > nul");       // Cambia la codificación de la consola a UTF-8
    setlocale(LC_ALL, "es_MX.UTF-8"); // Configura idioma español (México)
}

void lobby()
{
    idioma();
    system("cls");

    cout << "**********************************************S*N*A*K*E*S*" << endl;
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
    cout << "Presiona cualquier tecla para continuar..." << endl;
    cout << "\n";
    cout << "**********************************************S*N*A*K*E*S*" << endl;
}

int main()
{
    idioma();
    lobby();
    return 0;
}
