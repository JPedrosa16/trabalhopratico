// Arquivo: pedidos.cpp
#include <iostream>
#include <cstring>
#include "pedidos.h"

// Função auxiliar para buscar um local pelo nome (já criada em locais.cpp, mas necessária aqui)
// Para evitar duplicar código, o ideal seria ter um arquivo "utils.h"
// Mas, por simplicidade, podemos reescrevê-la ou chamá-la se a estrutura permitir.
int buscarLocalPorNome(const char nomeBusca[], const Local vetorLocais[], int totalLocais) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(vetorLocais[i].nome, nomeBusca) == 0) return i;
    }
    return -1;
}

// Implementação das funções de CRUD para Pedidos
void cadastrarPedido(Pedido vetorPedidos[], int &totalPedidos, const Local vetorLocais[], int totalLocais) {
    if (totalPedidos >= 200) { // Limite máximo de 200 pedidos
        std::cout << "Erro: Nao ha mais espaco para cadastrar pedidos." << std::endl;
        return;
    }

    Pedido novoPedido;
    novoPedido.id = totalPedidos + 1; // ID sequencial simples

    char nomeOrigem[50], nomeDestino[50];
    
    std::cout << "\n--- Cadastro de Novo Pedido ---" << std::endl;
    std::cout << "Digite o nome do local de ORIGEM: ";
    std::cin >> nomeOrigem;
    int indiceOrigem = buscarLocalPorNome(nomeOrigem, vetorLocais, totalLocais);

    if (indiceOrigem == -1) {
        std::cout << "Erro: Local de origem nao encontrado." << std::endl;
        return;
    }
    novoPedido.origem = vetorLocais[indiceOrigem];

    std::cout << "Digite o nome do local de DESTINO: ";
    std::cin >> nomeDestino;
    int indiceDestino = buscarLocalPorNome(nomeDestino, vetorLocais, totalLocais);

    if (indiceDestino == -1) {
        std::cout << "Erro: Local de destino nao encontrado." << std::endl;
        return;
    }
    novoPedido.destino = vetorLocais[indiceDestino];

    std::cout << "Digite o peso do item (kg): ";
    std::cin >> novoPedido.peso;

    vetorPedidos[totalPedidos] = novoPedido;
    totalPedidos++;
    std::cout << "Pedido cadastrado com sucesso! (ID: " << novoPedido.id << ")" << std::endl;
}

void listarPedidos(const Pedido vetorPedidos[], int totalPedidos) {
    std::cout << "\n--- Lista de Pedidos Cadastrados ---" << std::endl;
    if (totalPedidos == 0) {
        std::cout << "Nenhum pedido cadastrado." << std::endl;
        return;
    }

    for (int i = 0; i < totalPedidos; i++) {
        std::cout << "Pedido ID: " << vetorPedidos[i].id << std::endl;
        std::cout << "  Origem: " << vetorPedidos[i].origem.nome << " (" << vetorPedidos[i].origem.coordenadaX << "," << vetorPedidos[i].origem.coordenadaY << ")" << std::endl;
        std::cout << "  Destino: " << vetorPedidos[i].destino.nome << " (" << vetorPedidos[i].destino.coordenadaX << "," << vetorPedidos[i].destino.coordenadaY << ")" << std::endl;
        std::cout << "  Peso: " << vetorPedidos[i].peso << " kg" << std::endl;
    }
}