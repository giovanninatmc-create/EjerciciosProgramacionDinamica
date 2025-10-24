TIC TAC TOE 

------------------------------------------------------------
INTRODUCCION

Bienvenido al legendario TIC TAC TOE programado en C++
Prepárate para enfrentarte a tus amigos o retar a la CPU en una batalla de tres en línea.
------------------------------------------------------------
MODOS DE JUEGO

Cuando inicies el programa, podrás elegir entre dos modos:

1. Jugador vs Jugador
2. Jugador vs CPU

Modo Jugador vs Jugador:
Dos humanos se enfrentan turno a turno. Cada uno elige su casilla hasta que uno logre tres en línea.

Modo Jugador vs CPU:
La computadora entra al campo de batalla.
No habla, no se queja, pero piensa (bueno... un poco).
Elegirá casillas al azar, así que más vale que no te confíes.

------------------------------------------------------------
REGLAS DEL JUEGO

1. Hay dos jugadores: X y O.
2. Se elejira quien comienza la partida, siempre es (X)
3. Los jugadores se turnan para marcar una casilla en el tablero.
4. No se puede marcar una casilla ya ocupada.
5. Gana quien forme tres en linea (fila, columna o diagonal).
6. Si se llenan las casillas sin ganador, hay empate.

Ejemplo de empate:
 X | O | X
---+---+---
 O | X | O
---+---+---
 O | X | X

Ejemplo de victoria (Jugador X):
 X | X | X
---+---+---
 O | O |
---+---+---
   |   |

Consejo: Piensa tus movimientos y bloquea al rival.
QUE GANE EL MEJOR.

------------------------------------------------------------
EJECUCION

Compilacion:
g++ main.cpp -o TicTacToe

Ejecucion:
./TicTacToe

Compatible con Windows, Linux y macOS.
En Windows, el programa usa system("cls") para limpiar la pantalla.
En Linux/macOS usa system("clear").

------------------------------------------------------------
ESTRUCTURA DEL CODIGO

El codigo esta dividido en funciones modulares para mantener claridad y orden:

mostrarInicio()             Muestra el título y las reglas del juego.
pedirNombres()              Solicita los nombres de los jugadores. Si está activado el modo CPU, el segundo jugador se nombra automáticamente como “CPU”.
elegirTurnoAleatorio()      Usa números aleatorios y el poder de los dioses para decidir quién empieza.
jugar()                     Controla toda la partida: turnos, validaciones, tablero y detección de ganador.
mostrarTablero()            Dibuja el tablero con líneas y separadores.
hayGanador()                Detecta si alguien ha hecho tres en línea.
tableroLleno()              Detecta si ya no quedan movimientos (empate).
mostrarResultadosFinales()  Muestra el marcador total al final del juego.

------------------------------------------------------------
LOGICA DEL TURNO

El turno se alterna entre jugadores usando un contador:

if (turno % 2 == 0)
    marca = 'X';
else
    marca = 'O';

La CPU actúa automáticamente al detectar el modo activado:
casilla = rand() % 9 + 1;

Solo juega en casillas libres.
Parece simple... pero es efectiva.

------------------------------------------------------------
FLUJO DEL JUEGO

MOSTRAR MENU INICIO
       ↓
SELECCIONAR MODO (1 o 2)
       ↓
PEDIR NOMBRES
       ↓
ELEGIR QUIEN EMPIEZA (azar)
       ↓
INICIAR PARTIDA
       ↓
COMPROBAR GANADOR O EMPATE
       ↓
PREGUNTAR SI JUGAR OTRA VEZ
       ↓
MOSTRAR MARCADOR FINAL
       ↓
VOLVER AL MENU O SALIR

------------------------------------------------------------
EJEMPLO DE MARCADOR

=================================
 MARCADOR ACTUAL
=================================
Giovanni: 2 victoria(s)
CPU: 1 victoria(s)
=================================

Y si decides salir:
==============================================================
   Gracias por jugar Tic Tac Toe  - Nos vemos la proxima
==============================================================
Presiona una tecla para salir...

------------------------------------------------------------
AUTOR Y CREDITOS

Desarrollado por: Giovanni Natanael
Lenguaje: C++
Fecha: Octubre 2025
Version: 1.0
Proyecto academico

------------------------------------------------------------
