#ifndef AI_H
#define AI_H

struct Coordenada
{
    int x;
    int y;
};

class AI
{
public:
    AI(double dificultad, int tablero[3][3]);
    ~AI();

    bool inicie;
    Coordenada tirar();

private:
    double dificultad; // 0.0 <= dificultad <= 1.0
    int (*tablero)[3];
    bool bRand();
    bool defender(Coordenada &coor);
    void atacar(Coordenada &coor);
};

#endif // AI_H
