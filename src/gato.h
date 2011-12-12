#ifndef GATO_H
#define GATO_H

#include "ai.h"
#include <string>

struct Score
{
    int jugador1;
    int jugador2;
    int tiros;
};

enum TipoDeJuego {hombreVSHombre, hombreVSAI};
enum Turno {jugador1, jugador2};
enum Estado {enCurso, ganoJugador1, ganoJugador2, gato};
enum Jugador {uno = 1, dos = 2};

class Gato
{
public:
    Gato(char *nombreJugador1, char *nombreJugador2, TipoDeJuego tipo, double dificultad);
    ~Gato();

    Coordenada tirarJugador(Jugador jugador, Coordenada coor);
    Coordenada tirarMaquina();
    Estado calcularEstado();

private:
    std::string nombreJugador1;
    std::string nombreJugador2;
    Turno turno;
    int tablero[3][3];
    Score score;
    TipoDeJuego tipo;
    AI *ai;

    void juegoNuevo();
};

#endif // GATO_H
