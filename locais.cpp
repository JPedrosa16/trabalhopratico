// Arquivo: locais.cpp
#include <iostream>
#include <cstring>
#include "locais.h"

[cite_start]// Implementação da operação para criar um Local [cite: 12]
void cadastrarLocal(Local vetorLocais[], int &totalLocais) {
    if (totalLocais >= 100) { // Limite arbitrário para o vetor
        std::cout << "Erro: Nao ha mais espaco para cadastrar locais." << std::endl;
        return;
    }

    std::cout << "\n--- Cadastro de Novo Local ---" << std::endl;
    std::cout << "Digite o nome do local: ";
    std::cin >> vetorLocais[totalLocais].nome;

    std::cout << "Digite a coordenada X: ";
    std::cin >> vetorLocais[totalLocais].coordenadaX;

    std::cout << "Digite a coordenada Y: ";
    std::cin >> vetorLocais[totalLocais].coordenadaY;

    totalLocais++;
    std::cout << "Local cadastrado com sucesso!" << std::endl;
}

[cite_start]// Implementação da operação para listar Locais [cite: 12]
void listarLocais(const Local vetorLocais[], int totalLocais) {
    std::cout << "\n--- Lista de Locais Cadastrados ---" << std::endl;
    if (totalLocais == 0) {
        std::cout << "Nenhum local cadastrado." << std::endl;
        return;
    }

    for (int i = 0; i < totalLocais; i++) {
        std::cout << "Local " << i + 1 << ":" << std::endl;
        std::cout << "  Nome: " << vetorLocais[i].nome << std::endl;
        std::cout << "  Coordenadas: (" << vetorLocais[i].coordenadaX << ", " << vetorLocais[i].coordenadaY << ")" << std::endl;
    }
}

// ESTA É A ÚNICA IMPLEMENTAÇÃO DA FUNÇÃO NO PROJETO INTEIRO.
// Ela serve de apoio para as operações de atualizar e excluir.
int buscarLocalPorNome(const char nomeBusca[], const Local vetorLocais[], int totalLocais) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(vetorLocais[i].nome, nomeBusca) == 0) {
            return i; // Retorna o índice do local encontrado
        }
    }
    return -1; // Retorna -1 se não encontrar
}

[cite_start]// Implementação da operação para atualizar um Local [cite: 12]
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

[cite_start]// Implementação da operação para excluir um Local [cite: 12]
void excluirLocal(Local vetorLocais[], int &totalLocais) {
    char nomeBusca[50];
    std::cout << "\nDigite o nome do local que deseja excluir: ";
    std::cin >> nomeBusca;

    int indice = buscarLocalPorNome(nomeBusca, vetorLocais, totalLocais);

    if (indice != -1) {
        for (int i = indice; i < totalLocais - 1; i++) {
            vetorLocais[i] = vetorLocais[i + 1];
        }
        totalLocais--;
        std::cout << "Local excluido com sucesso!" << std::endl;
    } else {
        std::cout << "Erro: Local nao encontrado." << std::endl;
    }
}