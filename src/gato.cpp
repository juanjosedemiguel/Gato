#include "gato.h"

Gato::Gato(char *nombreJugador1, char *nombreJugador2, TipoDeJuego tipo, double dificultad)
{
    this->nombreJugador1 = nombreJugador1;
    this->nombreJugador2 = nombreJugador2;
    this->turno = jugador1;
    score.jugador1 = 0;
    score.jugador2 = 0;
    juegoNuevo();
    this->tipo = tipo;
    if (tipo == hombreVSAI)
        ai = new AI(dificultad, this->tablero);
}

Gato::~Gato()
{
    if (this->ai != 0) delete this->ai;
}

void Gato::juegoNuevo()
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            tablero[i][j] = 0;
    score.tiros = 0;
}

Coordenada Gato::tirarJugador(Jugador jugador, Coordenada coor)
{
    if (tablero[coor.y][coor.x] == 0) // Checar si es un tiro válido
        tablero[coor.y][coor.x] = (int)jugador;
    else
    {
        // Lanzar una excepción
    }
    return coor;
}

Coordenada Gato::tirarMaquina(){
    if (score.tiros == 0)
        ai->inicie = true;
    return ai->tirar();
}

Estado Gato::calcularEstado()
{
    // Guarda el estado del juego.
    // 0 para 'enCurso', 1 para 'ganoJugador1', 2 para 'ganoJugador2' y
    // 3 para gato.
    Estado edo = enCurso;

    // Arreglos auxiliares para recorrer la matriz
    int x[] = {0,1,2,0,1,2,0,1,2,0,0,0,1,1,1,2,2,2,0,1,2,0,1,2};
    int y[] = {0,0,0,1,1,1,2,2,2,0,1,2,0,1,2,0,1,2,0,1,2,2,1,0};
    int i = 0;

    // Busca combinaciónes de tiros para ver si alguno ha ganado. de ser así lo
    // guarda en ganador.
    do
    {
        if (tablero[y[i]][x[i]] != 0 && // Checa que la casilla no esté vacía
                tablero[y[i]][x[i]] == tablero[y[i+1]][x[i+1]] &&
                tablero[y[i+1]][x[i+1]] == tablero[y[i+2]][x[i+2]])
        {
            // Guarda el ganador si hay uno
            edo = (tablero[y[i]][x[i]] == 1 ? ganoJugador1 : ganoJugador2);
        }
        else
            i += 3; // Pasar a la siguiente combinación
    } while (edo == 0 && i<24);

    // En caso de un ganador, incrementar el score.
    switch (edo)
    {
    case 0:
        score.tiros++;
        if (score.tiros >= 9)// Si no hay ganador y van 9 tiros, es gato.
            edo = gato;
        break;
    case 1:
        score.jugador1++;
        break;
    case 2:
        score.jugador2++;
        break;
    default:
        break;
    }

    return edo;
}
