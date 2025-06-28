// Arquivo: entidades.h
#ifndef ENTIDADES_H
#define ENTIDADES_H

// Definição da struct para Local
struct Local {
    char nome[50];          // Nome (identificador único) [cite: 11]
    int coordenadaX;        // Coordenada X (numérica) [cite: 11]
    int coordenadaY;        // Coordenada Y (numérica) [cite: 11]
};

// Definição da struct para Veículo
struct Veiculo {
    char placa[10];         // Placa (identificador único) [cite: 13]
    char modelo[30];        // Modelo do veículo [cite: 13]
    char status[20];        // Status (disponível ou ocupado) [cite: 13]
    Local localAtual;       // Referência a um Local cadastrado [cite: 13]
};

// Definição da struct para Pedido (será usada no próximo sprint)
struct Pedido {
    int id;                 // Identificador único [cite: 16]
    Local origem;           // Local de origem (referência a um Local) [cite: 16]
    Local destino;          // Destino (referência a um Local) [cite: 16]
    float peso;             // Peso do item (em kg) [cite: 16]
};

#endif