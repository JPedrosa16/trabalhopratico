#ifndef ENTIDADES_H
#define ENTIDADES_H

struct Local {
    char nome[50];
    int coordenadaX;
    int coordenadaY;
};

struct Veiculo {
    char placa[10];
    char modelo[30];
    char status[20];
    Local localAtual;
};

struct Pedido {
    int id;
    Local origem;
    Local destino;
    float peso;
};

#endif
