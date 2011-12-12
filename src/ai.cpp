#include "ai.h"
#include<cstdlib>

AI::AI(double dificultad, int tablero[3][3])
{
    this->dificultad = dificultad;
    this->tablero = tablero;
    this->inicie = false;
}

AI::~AI()
{
    delete tablero;
}

Coordenada AI::tirar()
{
    Coordenada coor;
    coor.x = -1;
    coor.y = -1;

    if (!defender(coor)) // Si no es necesario defender una posición
        atacar(coor);

    tablero[coor.y][coor.x] = 2;
    return coor;
}

// Esta función devuelve un valor booleano semi-aleatorio en donde la
// la probabilidad de que sea verdadero es directamente proporcional a la
// dificultad de la AI que es un valor entre '0' y '1'.
bool AI::bRand()
{
    return ((rand() % 100 + 1) <= (this->dificultad * 100));
}

bool AI::defender(Coordenada &coor)
{
    // Arreglos y variables auxiliares para rrecorres la matriz.
    int x[] = {0,2,1,1,0,2,0,2,0,2,0,2,0,0,2,2};
    int y[] = {1,1,0,2,0,2,2,0,0,0,2,2,0,2,0,2};
    int cy[] = {1,0,1,0,1,0,1,0,0,0,2,0,1,0,1};
    int cx[] = {1,0,1,0,1,0,1,0,1,0,1,0,0,0,2};
    bool res = false;
    int i = 0;

    // Iterar por los arreglos auxiliares checando en donde falta sólo un punto
    // para hacer linea y tirar ahí. Así se blokean los ataques del enemigo y
    // se completan las lineas a favor de la AI. (ADVERTENCIA: si en el mismo
    // tiro puede elegir entre ganar o blokear al enemigo, debería de ganar
    // pero no lo hace, va a escoger la que quede antes en el orden el el que
    // está recorriendo la matríz).
    do
    {
        if (tablero[cy[i]][cx[i]] > 0)
        {
            if (tablero[y[i]][x[i]] == tablero[cy[i]][cx[i]] &&
                    tablero[cy[i]][cx[i]] != tablero[y[i+1]][x[i+1]])
            {
                coor.x = x[i+1];
                coor.y = y[i+1];
                res = true;
            }
            else if (tablero[y[i]][x[i]] != tablero[cy[i]][cx[i]] &&
                     tablero[cy[i]][cx[i]] == tablero[y[i+1]][x[i+1]])
            {
                coor.x = x[i];
                coor.y = y[i];
                res = true;
            }
        }
        else if (tablero[y[i]][x[i]] == tablero[y[i+1]][x[i+1]])
        {
            coor.x = cx[i];
            coor.y = cy[i];
            res = true;
        }

        i += 2;
    } while (coor.x < 0 && !res);

    return res;
}

void AI::atacar(Coordenada &coor)
{
    // Aquí va el algoritmo super cool para ganar siempre. Mientras lo invento
    // use el código anterior.
    if (inicie)
    {

    }
    else
    {

    }
    // Esta parte debe de mejorarse con un algoritmo kick-ass para ganar en gato
    // Declaración e inicialización de variables
    int y = -1;
    int x = -1;
    int i, j;

    i = 0;

    // Iterar por la matriz
    while (y == -1)
    {
        j = 0;
        while (x == -1)
        {
            if (tablero[i][j] == 0)
            {
                // Si estoy en una posición válida marcarla
                y = i;
                x = j;
            }
            j++;
        }
        i++;
    }
    // Tirar en la posición que marque como válida
    coor.y = y;
    coor.x = x;
}
