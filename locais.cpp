// Arquivo: locais.cpp
#include <iostream>
#include <cstring>
#include "locais.h"

// Implementação das funções de CRUD para Locais [cite: 12]
void cadastrarLocal(Local vetorLocais[], int &totalLocais) { /* ...código da resposta anterior... */ }
void listarLocais(const Local vetorLocais[], int totalLocais) { /* ...código da resposta anterior... */ }

// Implementação das funções de atualizar e excluir
int buscarLocalPorNome(const char nomeBusca[], const Local vetorLocais[], int totalLocais) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(vetorLocais[i].nome, nomeBusca) == 0) {
            return i; // Retorna o índice do local encontrado
        }
    }
    return -1; // Retorna -1 se não encontrar
}

void atualizarLocal(Local vetorLocais[], int totalLocais) {
    char nomeBusca[50];
    std::cout << "\nDigite o nome do local que deseja atualizar: ";
    std::cin >> nomeBusca;

    int indice = buscarLocalPorNome(nomeBusca, vetorLocais, totalLocais);

    if (indice != -1) {
        std::cout << "Digite o novo nome: ";
        std::cin >> vetorLocais[indice].nome;
        std::cout << "Digite a nova coordenada X: ";
        std::cin >> vetorLocais[indice].coordenadaX;
        std::cout << "Digite a nova coordenada Y: ";
        std::cin >> vetorLocais[indice].coordenadaY;
        std::cout << "Local atualizado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro: Local nao encontrado." << std::endl;
    }
}

void excluirLocal(Local vetorLocais[], int &totalLocais) {
    char nomeBusca[50];
    std::cout << "\nDigite o nome do local que deseja excluir: ";
    std::cin >> nomeBusca;

    int indice = buscarLocalPorNome(nomeBusca, vetorLocais, totalLocais);

    if (indice != -1) {
        // Para excluir, movemos todos os elementos posteriores uma posição para a esquerda
        for (int i = indice; i < totalLocais - 1; i++) {
            vetorLocais[i] = vetorLocais[i + 1];
        }
        totalLocais--; // Decrementa o total de locais
        std::cout << "Local excluido com sucesso!" << std::endl;
    } else {
        std::cout << "Erro: Local nao encontrado." << std::endl;
    }
}