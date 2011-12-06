#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int tablero[3][3];
int score[3];
char player[25];
char ordenador[25];

void imprimir()
{
    cout << "_____" << endl;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
            tablero[i][j]==0 ? printf("@") : tablero[i][j]==1 ? printf("X") : printf("O");
        printf("\n");
    }
}

void juegoNuevo()
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            tablero[i][j] = 0;
    score[0] = 0;
}

bool valido(int y, int x)
{
    // Si la posición que estoy checando esta marcada con 0, entonces es válida
    return (tablero[y][x] == 0);
}

bool validar(int y, int x)
{
    bool res = valido(y, x);
    if (!res)
        cout << "Tiro invalido" << endl;
    return res;
}

void turnoJugador()
{
    // Declaración de variables
    int num, x, y;
    
    // Leo la posicion en donde el jugador quiere tirar
    do
    {
        cout << "Turno del Jugador: " << player << endl;
        cin >> num;
    
        // Le asigno coordenadas 'y' en la matriz
        if (num == 7 || num == 8 || num == 9)
            y = 0;
        else if (num == 4 || num == 5 || num == 6)
            y = 1;
        else if (num == 1 || num == 2 || num == 3)
            y = 2;

        // Le asigno coordenadas 'x' en la matriz
        if (num == 7 || num == 4 || num == 1)
            x = 0;
        else if (num == 8 || num == 5 || num == 2)
            x = 1;
        else if (num == 9 || num == 6 || num == 3)
            x = 2;
        
    // Validar el tiro
    } while (!validar(y,x));
    
    tablero[y][x] = 1;
}

void turnoMaquina()
{
    // Esta parte debe de mejorarse con un algoritmo kick-ass para ganar en gato
    // Declaración e inicialización de variables
    int y = -1;
    int x = -1;
    int i, j;
    
    // Para que paresca una interacción con alguien real
    cout << "Turno del Jugador: " << ordenador << endl;
    
    i = 0;

    // Iterar por la matriz
    while (y == -1)
    {
        j = 0;
        while (x == -1)
        {
            if (valido(i, j))
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
    tablero[y][x] = 2;
}

bool checar()
{
    // Arreglos auxiliares para recorrer la matriz
    int y[] = {0,0,0,1,1,1,2,2,2,0,1,2,0,1,2,0,1,2,0,1,2,2,1,0};
    int x[] = {0,1,2,0,1,2,0,1,2,0,0,0,1,1,1,2,2,2,0,1,2,0,1,2};
    int i = 0;
    // Guarda quien ganó el juego. 1 para jugador, 2 para máquina.
    int ganador = 0;
    
    // Busca combinaciónes de tiros para ver si alguno ha ganado. de ser así lo
    // guarda en ganador.
    do
    {
        if (tablero[y[i]][x[i]] != 0 && // Checa que la casilla no esté vacía
                tablero[y[i]][x[i]] == tablero[y[i+1]][x[i+1]] &&
                tablero[y[i+1]][x[i+1]] == tablero[y[i+2]][x[i+2]])
        {
            ganador = tablero[y[i]][x[i]]; // Guarda el ganador
        }
        else
            i += 3; // Pasar a la siguiente combinación
    } while (ganador==0 && i<24);
    
    // En caso de un ganador, incrementar el score y avisar
    if (ganador!=0)
    {
        if (ganador==1)
        {
            score[1]++;
            cout << "Felicidades! has ganado :D" << endl;
        }
        else
        {
            score[2]++;
            cout << "Gana " << ordenador << "!" << endl;
        }
    }
    else
    {
        score[0]++;
    }
    
    // Devuelve verdadero si hay un ganador y falso en el caso contrario
    return (ganador != 0);
}

bool continuar()
{
    char letra;
    cout << "Presione 'Q' para salir o cualquier otra letra para continuar..." << endl;
    cin >> letra;
    return (letra == 'q' || letra == 'Q');
}

int main2()
{
    bool acabo;
    bool jugador;
    
    score[1] = 0;
    score[2] = 0;
    
    cout << "Nombre del Jugador: ";
    cin >> player;
    cout << "Nombre del Ordenador: ";
    cin >> ordenador;
    
    do
    {
        acabo = false;
        jugador = (score[1] <= score[2]);

        juegoNuevo();

        while (!acabo && score[0]<9)
        {
            jugador ? turnoJugador() : turnoMaquina();
            imprimir();
            acabo = checar();
            jugador = !jugador;
        }
        cout << "Score " << player << ": " << score[1] << " | " << ordenador << ": " << score[2] << endl;

    } while (continuar());
    return 0;
}
