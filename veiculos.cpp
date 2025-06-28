#include <iostream>
#include <cstring>
#include "veiculos.h"
#include "locais.h"

void cadastrarVeiculo(Veiculo vetorVeiculos[], int &totalVeiculos, const Local vetorLocais[], int totalLocais) {
    if (totalVeiculos >= 50) {
        std::cout << "Limite de veiculos atingido." << std::endl;
        return;
    }

    Veiculo v;
    std::cout << "\nDigite a placa do veiculo: ";
    std::cin >> v.placa;
    std::cout << "Digite o modelo do veiculo: ";
    std::cin >> v.modelo;
    std::cout << "Digite o status do veiculo (disponivel/ocupado): ";
    std::cin >> v.status;

    char nomeLocal[50];
    std::cout << "Digite o nome do local atual do veiculo: ";
    std::cin >> nomeLocal;

    int indice = buscarLocalPorNome(nomeLocal, vetorLocais, totalLocais);
    if (indice != -1) {
        v.localAtual = vetorLocais[indice];
        vetorVeiculos[totalVeiculos++] = v;
        std::cout << "Veiculo cadastrado com sucesso!" << std::endl;
    } else {
        std::cout << "Erro: Local nao encontrado. Veiculo nao cadastrado." << std::endl;
    }
}

void listarVeiculos(const Veiculo vetorVeiculos[], int totalVeiculos) {
    std::cout << "\n--- Lista de Veiculos ---\n";
    for (int i = 0; i < totalVeiculos; i++) {
        std::cout << "Placa: " << vetorVeiculos[i].placa << std::endl;
        std::cout << "Modelo: " << vetorVeiculos[i].modelo << std::endl;
        std::cout << "Status: " << vetorVeiculos[i].status << std::endl;
        std::cout << "Local: " << vetorVeiculos[i].localAtual.nome << " ("
                  << vetorVeiculos[i].localAtual.coordenadaX << ", "
                  << vetorVeiculos[i].localAtual.coordenadaY << ")" << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}
