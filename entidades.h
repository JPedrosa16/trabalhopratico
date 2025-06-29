// Arquivo: entidades.h
#ifndef ENTIDADES_H
#define ENTIDADES_H

// Estrutura para representar um local geográfico
struct Local {
    char nome[50];
    float coordenadaX;
    float coordenadaY;
};

// Estrutura para representar um veículo
struct Veiculo {
    char placa[10];
    char modelo[50];
    char status[20];
    Local localAtual;
};

// Estrutura para representar um pedido de entrega
struct Pedido {
    int id;
    Local origem;
    Local destino;
    float peso;
};

#endif
