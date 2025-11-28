#include <iostream>
#include <string>
#include <locale>
#include <windows.h>
#include <iomanip>
#include <limits>
using namespace std;
// =============================================================
// CONSTANTES Y ESTRUCTURAS GLOBALES
const int MAXIMO_INVENTARIO = 100; // Maximo numero de productos en el inventario

struct Producto // Estructura para almacenar la informacion de cada producto
{
    int claveProducto;
    string nombreProducto;
    int cantidadDisponible;
    double precioUnitario;
};
// =============================================================
// PROTOTIPOS DE FUNCIONES
void idioma();
int pedirEntero(string mensaje);
double pedirDouble(string mensaje);
int pedirOpcion(int min, int max);
void menuPrincipal(Producto *inv, int &total);
void imprimirInventario(Producto *inv, int total);
void agregarProducto(Producto *inv, int &total);
void eliminarProducto(Producto *inv, int &total);
void actualizarProducto(Producto *inv, int total);
// =============================================================

// =============================================================
// FUNCION PRINCIPAL
int main()
{
    idioma();

    int productosActuales = 10;

    Producto inventario[MAXIMO_INVENTARIO] =
        {
            {417, "Manzanas", 50, 40.00},
            {205, "Platano", 30, 18.50},
            {889, "Naranjas", 20, 20.80},
            {112, "Leche", 15, 29.90},
            {531, "Pan", 25, 5.00},
            {764, "Huevos", 40, 45.00},
            {302, "Queso", 10, 48.75},
            {978, "Arroz", 60, 21.20},
            {156, "Frijoles", 70, 36.50},
            {640, "Azucar", 80, 22.10}};

    menuPrincipal(inventario, productosActuales);
    return 0;
}
// =============================================================

// =============================================================
// DECLARACION DE FUNCIONES

void idioma() // CONFIGURA EL IDIOMA DE LA CONSOLA A ESPAÑOL
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "es_MX.UTF-8");
}

int pedirEntero(string mensaje) // SOLICITA UN ENTERO POSITIVO AL USUARIO
{
    string entrada; // Variable para almacenar la entrada del usuario
    int numero;     // Variable para almacenar el numero convertido

    while (true) // Bucle infinito hasta que se reciba una entrada valida
    {
        cout << mensaje;       // Muestra el mensaje de solicitud al usuario
        getline(cin, entrada); // Lee la entrada del usuario

        if (entrada.empty()) // Verifica si la entrada esta vacia
        {
            cout << "Entrada incorrecta, intenta nuevamente." << endl; // Mensaje de error si la entrada esta vacia
            continue;
        }

        bool valido = true;     // Bandera para verificar si la entrada es valida
        for (char c : entrada)  // Recorre cada caracter en la entrada
            if (!isdigit(c))    // Verifica si el caracter no es un digito
                valido = false; // Marca la entrada como invalida si se encuentra un caracter no digito

        if (!valido) // Si la entrada no es valida
        {
            // Manda un mensaje de error y vuelve al inicio del bucle
            cout << "Entrada incorrecta, intenta nuevamente." << endl;
            continue;
        }

        try // Intenta convertir la entrada a un entero
        {
            numero = stoi(entrada); // Convierte la entrada a entero
            if (numero >= 0)        // Verifica si el numero es positivo
                return numero;      // Retorna el numero si es valido
        }
        catch (...) // Captura cualquier excepcion durante la conversion
        {
        }
        // Mensaje de error si la conversion falla o el numero es negativo
        cout << "Entrada incorrecta, intenta nuevamente." << endl;
    }
}

double pedirDouble(string mensaje) // SOLICITA UN NUMERO DECIMAL POSITIVO AL USUARIO
{
    string entrada; // Variable para almacenar la entrada del usuario
    double numero;  // Variable para almacenar el numero convertido

    while (true) // Bucle infinito hasta que se reciba una entrada valida
    {
        cout << mensaje;       // Muestra el mensaje de solicitud al usuario
        getline(cin, entrada); // Lee la entrada del usuario

        if (entrada.empty()) // Verifica si la entrada esta vacia
        {
            cout << "Entrada incorrecta, intenta nuevamente." << endl; // Mensaje de error si la entrada esta vacia
            continue;                                                  // Vuelve al inicio del bucle
        }

        bool valido = true; // Bandera para verificar si la entrada es valida
        int puntos = 0;     // Contador de puntos decimales en la entrada

        for (char c : entrada) // Recorre cada caracter en la entrada
        {
            if (c == '.')         // Verifica si el caracter es un punto decimal
                puntos++;         // Incrementa el contador de puntos decimales
            else if (!isdigit(c)) // Verifica si el caracter no es un digito
                valido = false;   // Marca la entrada como invalida si se encuentra un caracter no digito
        }

        if (!valido || puntos > 1) // Si la entrada no es valida o tiene mas de un punto decimal
        {
            cout << "Entrada incorrecta, intenta nuevamente." << endl; // Mensaje de error
            continue;                                                  // Vuelve al inicio del bucle
        }

        try
        {
            numero = stod(entrada); // Convierte la entrada a double
            if (numero >= 0)        // Verifica si el numero es positivo
                return numero;      // Retorna el numero si es valido
        }
        catch (...) // Captura cualquier excepcion durante la conversion
        {
        }
        // Mensaje de error si la conversion falla o el numero es negativo
        cout << "Entrada incorrecta, intenta nuevamente." << endl;
    }
}

int pedirOpcion(int min, int max) // SOLICITA UNA OPCION ENTRE MIN Y MAX AL USUARIO
{
    string entrada; // Variable para almacenar la entrada del usuario
    int numero;     // Variable para almacenar el numero convertido

    while (true) // Bucle infinito hasta que se reciba una entrada valida
    {
        getline(cin, entrada); // Lee la entrada del usuario

        if (entrada.empty()) // Verifica si la entrada esta vacia
        {
            cout << "Entrada incorrecta, intenta nuevamente." << endl; // Mensaje de error si la entrada esta vacia
            continue;                                                  // Vuelve al inicio del bucle
        }

        bool valido = true;     // Bandera para verificar si la entrada es valida
        for (char c : entrada)  // Recorre cada caracter en la entrada
            if (!isdigit(c))    // Verifica si el caracter no es un digito
                valido = false; // Marca la entrada como invalida si se encuentra un caracter no digito

        if (!valido) // Si la entrada no es valida
        {            // Manda un mensaje de error y vuelve al inicio del bucle
            cout << "Entrada incorrecta, intenta nuevamente." << endl;
            continue;
        }

        try // Intenta convertir la entrada a un entero
        {
            numero = stoi(entrada);             // Convierte la entrada a entero
            if (numero >= min && numero <= max) // Verifica si el numero esta dentro del rango permitido
                return numero;                  // Retorna el numero si es valido
        }
        catch (...) // Captura cualquier excepcion durante la conversion
        {
        }
        // Mensaje de error si la conversion falla o el numero esta fuera del rango
        cout << "Entrada incorrecta, intenta nuevamente." << endl;
    }
}

void menuPrincipal(Producto *inv, int &total) // MUESTRA EL MENU PRINCIPAL Y MANEJA LAS OPCIONES
{
    int opcionMenu; // Variable para almacenar la opcion seleccionada por el usuario

    do // Bucle principal del menu
    {
        system("cls");
        cout << "=======================================================================" << endl;
        cout << "                           MENU PRINCIPAL                              " << endl;
        cout << "=======================================================================" << endl;
        cout << "1. Ver inventario de productos." << endl;
        cout << "2. Agregar un nuevo producto." << endl;
        cout << "3. Eliminar un producto." << endl;
        cout << "4. Actualizar datos de producto." << endl;
        cout << "5. Salir del sistema" << endl;
        cout << "=======================================================================" << endl;
        cout << "Selecciona una opción (1-5): ";

        opcionMenu = pedirOpcion(1, 5); // Solicita una opcion valida al usuario con la funcion pedirOpcion

        switch (opcionMenu) // Maneja las diferentes opciones del menu
        {
        case 1: // Opcion para ver el inventario
            imprimirInventario(inv, total);
            break;

        case 2: // Opcion para agregar un nuevo producto
            agregarProducto(inv, total);
            break;

        case 3: // Opcion para eliminar un producto
            eliminarProducto(inv, total);
            break;

        case 4: // Opcion para actualizar los datos de un producto
            actualizarProducto(inv, total);
            break;

        case 5: // Opcion para salir del sistema
            cout << "Presiona ENTER para salir..." << endl;
            cin.get();
            break;

        default: // Opcion invalida (no deberia ocurrir por la validacion previa)
            cout << "Opcion invalida." << endl;
            cout << "Presiona ENTER para continuar..." << endl;
            cin.get();
            break;
        }

    } while (opcionMenu != 5); // Repite el menu hasta que el usuario elija salir
}

void imprimirInventario(Producto *inv, int total) // IMPRIME EL INVENTARIO Y PERMITE ORDENARLO
{
    system("cls");
    // Muestra el inventario de productos
    cout << "=======================================================================" << endl;
    cout << "                         INVENTARIO DE PRODUCTOS                       " << endl;
    cout << "=======================================================================" << endl;
    cout << "Total de productos: " << total << endl // Muestra el total de productos
         << endl;

    cout << left << setw(10) << "Clave" // Muestra los encabezados de las columnas
         << left << setw(20) << "Producto"
         << right << setw(12) << "Cantidad"
         << right << setw(20) << "Precio Unitario" << endl;

    cout << "-----------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2); // Formatea los numeros decimales a 2 decimales

    for (int i = 0; i < total; i++) // Recorre e imprime cada producto en el inventario
    {
        cout << left << setw(10) << inv[i].claveProducto
             << left << setw(20) << inv[i].nombreProducto
             << right << setw(12) << inv[i].cantidadDisponible
             << right << setw(10) << "$"
             << right << setw(10) << inv[i].precioUnitario
             << endl;
    }

    cout << "=======================================================================" << endl;
    cout << "¿Deseas ordenar el inventario? (s/n): "; // Pregunta si el usuario desea ordenar el inventario

    string r;        // Variable para almacenar la respuesta del usuario en r
    getline(cin, r); // Lee la respuesta del usuario

    if (r != "s" && r != "S") // Si la respuesta no es 's' o 'S', regresa al menu principal
    {
        cout << "Presiona ENTER para regresar..." << endl;
        cin.get(); // Espera a que el usuario presione ENTER
        return;
    }

    system("cls");

    cout << "=======================================================================" << endl;
    cout << "                           ORDENAR INVENTARIO                          " << endl;
    cout << "=======================================================================" << endl;
    cout << "1. Precio" << endl;
    cout << "2. Cantidad" << endl;
    cout << "3. Clave" << endl;
    cout << "4. Nombre (A-Z)" << endl;
    cout << "=======================================================================" << endl;
    cout << "Selecciona una opción: ";

    int opcion = pedirOpcion(1, 4); // Solicita una opcion valida al usuario para el criterio de ordenamiento

    if (opcion == 1) // Ordena por precio usando el algoritmo de seleccion
    {
        for (int i = 0; i < total - 1; i++) // Bucle para cada posicion en el arreglo
        {
            int min = i;                                             // Indice del elemento con el valor minimo encontrado
            for (int j = i + 1; j < total; j++)                      // Busca el minimo en el resto del arreglo
                if (inv[j].precioUnitario < inv[min].precioUnitario) // Compara precios
                    min = j;                                         // Actualiza el indice del minimo si se encuentra uno menor

            if (min != i) // Si se encontro un minimo diferente al actual, realiza el intercambio
            {
                Producto temp = inv[i]; // Almacena temporalmente el producto en la posicion i
                inv[i] = inv[min];      // Coloca el producto minimo en la posicion i
                inv[min] = temp;        // Coloca el producto originalmente en i en la posicion del minimo
            }
        }
    }
    else if (opcion == 2) // Ordena por cantidad usando el algoritmo de seleccion
    {
        for (int i = 0; i < total - 1; i++) // Bucle para cada posicion en el arreglo
        {
            int min = i;                                                     // Indice del elemento con el valor minimo encontrado
            for (int j = i + 1; j < total; j++)                              // Busca el minimo en el resto del arreglo
                if (inv[j].cantidadDisponible < inv[min].cantidadDisponible) // Compara cantidades
                    min = j;                                                 // Actualiza el indice del minimo si se encuentra uno menor

            if (min != i) // Si se encontro un minimo diferente al actual, realiza el intercambio
            {
                Producto temp = inv[i]; // Almacena temporalmente el producto en la posicion i
                inv[i] = inv[min];      // Coloca el producto minimo en la posicion i
                inv[min] = temp;        // Coloca el producto originalmente en i en la posicion del minimo
            }
        }
    }
    else if (opcion == 3) // Ordena por clave usando el algoritmo de seleccion
    {
        for (int i = 0; i < total - 1; i++) // Bucle para cada posicion en el arreglo
        {
            int min = i;                                           // Indice del elemento con el valor minimo encontrado
            for (int j = i + 1; j < total; j++)                    // Busca el minimo en el resto del arreglo
                if (inv[j].claveProducto < inv[min].claveProducto) // Compara claves
                    min = j;                                       // Actualiza el indice del minimo si se encuentra uno menor

            if (min != i) // Si se encontro un minimo diferente al actual, realiza el intercambio
            {
                Producto temp = inv[i]; // Almacena temporalmente el producto en la posicion i
                inv[i] = inv[min];      // Coloca el producto minimo en la posicion i
                inv[min] = temp;        // Coloca el producto originalmente en i en la posicion del minimo
            }
        }
    }
    else if (opcion == 4) // Ordena por nombre alfabeticamente usando el algoritmo de seleccion
    {
        for (int i = 0; i < total - 1; i++) // Bucle para cada posicion en el arreglo
        {
            int min = i;                                             // Indice del elemento con el valor minimo encontrado
            for (int j = i + 1; j < total; j++)                      // Busca el minimo en el resto del arreglo
                if (inv[j].nombreProducto < inv[min].nombreProducto) // Compara nombres alfabeticamente
                    min = j;                                         // Actualiza el indice del minimo si se encuentra uno menor

            if (min != i) // Si se encontro un minimo diferente al actual, realiza el intercambio
            {
                Producto temp = inv[i]; // Almacena temporalmente el producto en la posicion i
                inv[i] = inv[min];      // Coloca el producto minimo en la posicion i
                inv[min] = temp;        // Coloca el producto originalmente en i en la posicion del minimo
            }
        }
    }

    system("cls");
    // Muestra el inventario ordenado
    cout << "=======================================================================" << endl;
    cout << "                         INVENTARIO ORDENADO                           " << endl;
    cout << "=======================================================================" << endl;
    cout << "Total de productos: "
         << endl;

    cout << left << setw(10) << "Clave"
         << left << setw(20) << "Producto"
         << right << setw(12) << "Cantidad"
         << right << setw(20) << "Precio Unitario" << endl;

    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < total; i++) // Recorre e imprime cada producto en el inventario
    {
        cout << left << setw(10) << inv[i].claveProducto
             << left << setw(20) << inv[i].nombreProducto
             << right << setw(12) << inv[i].cantidadDisponible
             << right << setw(10) << "$"
             << right << setw(10) << inv[i].precioUnitario
             << endl;
    }

    cout << "=======================================================================" << endl;
    cout << "Presiona ENTER para regresar..." << endl;
    cin.get();
}

void agregarProducto(Producto *inv, int &total) // AGREGA UN NUEVO PRODUCTO AL INVENTARIO
{
    if (total >= MAXIMO_INVENTARIO) // Verifica si el inventario esta lleno
    {                               // Si el inventario esta lleno, muestra un mensaje y regresa al menu principal
        system("cls");
        cout << "=======================================================================" << endl;
        cout << "                       INVENTARIO COMPLETO                             " << endl;
        cout << "=======================================================================" << endl;
        cout << "Presiona ENTER para continuar..." << endl;
        cin.get();
        return;
    }

    system("cls");
    // Muestra el encabezado para agregar un nuevo producto
    cout << "=======================================================================" << endl;
    cout << "                           AGREGAR PRODUCTO                            " << endl;
    cout << "=======================================================================" << endl;

    cout << "--------------------------- CAPTURA DE DATOS --------------------------" << endl;

    Producto *nuevo = &inv[total]; // Apunta al siguiente espacio disponible en el inventario

    nuevo->claveProducto = pedirEntero("Clave del producto: "); // Solicita la clave del nuevo producto

    for (int i = 0; i < total; i++) // Verifica que la clave no exista ya en el inventario
    {
        if (inv[i].claveProducto == nuevo->claveProducto) // Compara claves
        {
            cout << "La clave ya existe." << endl; // Muestra un mensaje de error si la clave ya existe
            cout << "Presiona ENTER..." << endl;
            cin.get();
            return; // Regresa al menu principal sin agregar el producto
        }
    }

    cout << "Nombre del producto: ";     // Solicita el nombre del nuevo producto
    getline(cin, nuevo->nombreProducto); // Lee el nombre del producto

    nuevo->cantidadDisponible = pedirEntero("Cantidad disponible: "); // Solicita la cantidad disponible del nuevo producto
    nuevo->precioUnitario = pedirDouble("Precio unitario: ");         // Solicita el precio unitario del nuevo producto

    total++; // Incrementa el total de productos en el inventario

    cout << endl                                        // Muestra un mensaje de confirmacion
         << "Producto agregado correctamente." << endl; // Mensaje de exito
    cout << "Presiona ENTER para continuar..." << endl; // Espera a que el usuario presione ENTER
    cin.get();                                          // Lee la entrada del usuario
}

void eliminarProducto(Producto *inv, int &total) // ELIMINA UN PRODUCTO DEL INVENTARIO
{
    system("cls");
    // Muestra el encabezado para eliminar un producto
    cout << "=======================================================================" << endl;
    cout << "                           ELIMINAR PRODUCTO                           " << endl;
    cout << "=======================================================================" << endl;

    if (total == 0) // Verifica si el inventario esta vacio
    {               // Si el inventario esta vacio, muestra un mensaje y regresa al menu principal
        cout << "No hay productos para eliminar." << endl;
        cout << "Presiona ENTER para continuar..." << endl;
        cin.get();
        return; // Regresa al menu principal
    }
    // Solicita la clave del producto a eliminar
    cout << "------------------------------ BUSQUEDA -------------------------------" << endl;

    int clave = pedirEntero("Ingresa la clave del producto a eliminar: "); // Lee la clave del producto

    int indice = -1; // Variable para almacenar el indice del producto a eliminar

    for (int i = 0; i < total; i++) // Busca el producto en el inventario
    {
        if (inv[i].claveProducto == clave) // Compara claves
        {
            indice = i; // Almacena el indice del producto encontrado
            break;      // Sale del bucle si se encuentra el producto
        }
    }

    if (indice == -1) // Si no se encontro el producto, muestra un mensaje y regresa al menu principal
    {
        cout << "Producto no encontrado." << endl;
        cout << "Presiona ENTER para continuar..." << endl;
        cin.get();
        return; // Regresa al menu principal
    }
    // Muestra los detalles del producto encontrado
    cout << endl
         << "Producto encontrado:" << endl;
    cout << "Clave: " << inv[indice].claveProducto << endl;
    cout << "Nombre: " << inv[indice].nombreProducto << endl;
    cout << "Cantidad: " << inv[indice].cantidadDisponible << endl;
    cout << "Precio: $" << inv[indice].precioUnitario << endl;

    cout << endl
         << "---------------------------- CONFIRMACION -----------------------------" << endl;
    cout << "¿Eliminar producto? (s/n): "; // Pregunta si el usuario desea eliminar el producto

    string op;        // Variable para almacenar la respuesta del usuario
    getline(cin, op); // Lee la respuesta del usuario

    if (op != "s" && op != "S") // Si la respuesta no es 's' o 'S', cancela la eliminacion y regresa al menu principal
    {
        cout << "Operación cancelada." << endl; // Muestra un mensaje de cancelacion
        cout << "Presiona ENTER para continuar..." << endl;
        cin.get();
        return;
    }

    for (int i = indice; i < total - 1; i++) // Desplaza los productos posteriores para llenar el espacio del producto eliminado
        inv[i] = inv[i + 1];                 // Copia el producto siguiente al actual

    total--; // Decrementa el total de productos en el inventario

    // Muestra un mensaje de confirmacion

    cout << endl
         << "Producto eliminado." << endl;
    cout << "Presiona ENTER para continuar..." << endl;
    cin.get();
}

void actualizarProducto(Producto *inv, int total) // ACTUALIZA LOS DATOS DE UN PRODUCTO EN EL INVENTARIO
{
    system("cls");
    // Muestra el encabezado para actualizar un producto
    cout << "=======================================================================" << endl;
    cout << "                           ACTUALIZAR PRODUCTO                         " << endl;
    cout << "=======================================================================" << endl;

    if (total == 0) // Verifica si el inventario esta vacio
    {
        cout << "No hay productos para actualizar." << endl;
        cout << "Presiona ENTER para continuar..." << endl;
        cin.get();
        return; // Regresa al menu principal
    }

    cout << "------------------------------ BUSQUEDA -------------------------------" << endl;

    int clave = pedirEntero("Ingresa la clave del producto a actualizar: "); // Solicita la clave del producto a actualizar

    int indice = -1; // Variable para almacenar el indice del producto a actualizar

    // Busca el producto en el inventario

    for (int i = 0; i < total; i++) // Recorre el inventario
    {
        if (inv[i].claveProducto == clave) // Compara claves
        {
            indice = i; // Almacena el indice del producto encontrado
            break;
        }
    }

    if (indice == -1) // Si no se encontro el producto, muestra un mensaje y regresa al menu principal
    {
        cout << "Producto no encontrado." << endl;
        cout << "Presiona ENTER para continuar..." << endl;
        cin.get();
        return; // Regresa al menu principal
    }

    Producto *p = &inv[indice]; // Apunta al producto encontrado
    int opcion = 0;             // Variable para almacenar la opcion seleccionada por el usuario

    // Muestra los detalles del producto encontrado

    do
    {
        system("cls");

        cout << "=======================================================================" << endl;
        cout << "                           ACTUALIZAR PRODUCTO                         " << endl;
        cout << "=======================================================================" << endl;

        cout << "---------------------------- DATOS ACTUALES ---------------------------" << endl;

        cout << "1. Nombre actual: " << p->nombreProducto << endl;
        cout << "2. Cantidad actual: " << p->cantidadDisponible << endl;
        cout << "3. Precio actual: $" << p->precioUnitario << endl;
        cout << "4. Salir" << endl;

        cout << "---------------------------- SELECCIONAR ------------------------------" << endl;
        cout << "Selecciona el dato a actualizar: ";

        opcion = pedirOpcion(1, 4); // Solicita una opcion valida al usuario para el dato a actualizar

        // Maneja la actualizacion segun la opcion seleccionada

        switch (opcion) // Actualiza el dato seleccionado
        {
        case 1: // Actualiza el nombre del producto
        {
            cout << "---------------------------- NUEVO VALOR ------------------------------" << endl;
            string n;                 // Variable para almacenar el nuevo nombre
            cout << "Nuevo nombre: "; // Solicita el nuevo nombre al usuario
            getline(cin, n);          // lee el nuevo nombre
            p->nombreProducto = n;    // Actualiza el nombre del producto
            cout << "Nombre actualizado." << endl;
            cout << "Presiona ENTER..." << endl;
            cin.get();
            break;
        }

        case 2: // Actualiza la cantidad disponible del producto
        {
            cout << "---------------------------- NUEVO VALOR ------------------------------" << endl;
            int c = pedirEntero("Nueva cantidad: "); // Solicita la nueva cantidad al usuario
            p->cantidadDisponible = c;               // Actualiza la cantidad del producto
            cout << "Cantidad actualizada." << endl;
            cout << "Presiona ENTER..." << endl;
            cin.get();
            break;
        }

        case 3: // Actualiza el precio unitario del producto
        {
            cout << "---------------------------- NUEVO VALOR ------------------------------" << endl;
            double pr = pedirDouble("Nuevo precio: "); // Solicita el nuevo precio al usuario
            p->precioUnitario = pr;                    // Actualiza el precio del producto
            cout << "Precio actualizado." << endl;
            cout << "Presiona ENTER..." << endl;
            cin.get();
            break;
        }

        case 4: // Sale de la actualizacion
            break;
        }

    } while (opcion != 4); // Repite hasta que el usuario elija salir
}
// =============================================================