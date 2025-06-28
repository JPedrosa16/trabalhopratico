#include <iostream>
#include <cstring>
#include "locais.h"

void cadastrarLocal(Local vetorLocais[], int &totalLocais) {
    if (totalLocais >= 100) {
        std::cout << "Limite de locais atingido." << std::endl;
        return;
    }

    std::cout << "\nDigite o nome do local: ";
    std::cin >> vetorLocais[totalLocais].nome;
    std::cout << "Digite a coordenada X: ";
    std::cin >> vetorLocais[totalLocais].coordenadaX;
    std::cout << "Digite a coordenada Y: ";
    std::cin >> vetorLocais[totalLocais].coordenadaY;

    totalLocais++;
    std::cout << "Local cadastrado com sucesso!" << std::endl;
}

void listarLocais(const Local vetorLocais[], int totalLocais) {
    std::cout << "\n--- Lista de Locais ---" << std::endl;
    for (int i = 0; i < totalLocais; i++) {
        std::cout << "Nome: " << vetorLocais[i].nome << std::endl;
        std::cout << "Coordenadas: (" << vetorLocais[i].coordenadaX
                  << ", " << vetorLocais[i].coordenadaY << ")" << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

int buscarLocalPorNome(const char nomeBusca[], const Local vetorLocais[], int totalLocais) {
    for (int i = 0; i < totalLocais; i++) {
        if (strcmp(vetorLocais[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1;
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
        for (int i = indice; i < totalLocais - 1; i++) {
            vetorLocais[i] = vetorLocais[i + 1];
        }
        totalLocais--;
        std::cout << "Local excluido com sucesso!" << std::endl;
    } else {
        std::cout << "Erro: Local nao encontrado." << std::endl;
    }
}
