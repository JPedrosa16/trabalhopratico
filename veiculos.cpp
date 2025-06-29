// Módulo de gestão de veículos.
// Permite cadastrar veículos com base em um local existente e listar os veículos cadastrados.

// Arquivo: veiculos.cpp
#include <iostream>
#include <cstring> // Essencial para usar a função strcpy
#include "veiculos.h"
#include "locais.h"

// Implementação da operação para criar um Veículo
void cadastrarVeiculo(Veiculo vetorVeiculos[], int &totalVeiculos, const Local vetorLocais[], int totalLocais) {
    if (totalVeiculos >= 50) { // Limite arbitrário para o vetor
        std::cout << "Limite de veiculos atingido." << std::endl;
        return;
    }

    Veiculo v; // Cria um veículo temporário para preencher os dados
    std::cout << "\n--- Cadastro de Novo Veiculo ---" << std::endl;
    std::cout << "Digite a placa do veiculo: ";
    std::cin >> v.placa; // Atributo: Placa (identificador único)
    std::cout << "Digite o modelo do veiculo: ";
    std::cin >> v.modelo; // Atributo: modelo

    // ALTERAÇÃO APLICADA AQUI
    // O status é definido como "disponivel" por padrão para garantir a consistência do sistema.
    // Isso remove a necessidade de o usuário digitar o status e evita erros.
    strcpy(v.status, "disponivel"); // Atributo: status

    char nomeLocal[50];
    std::cout << "Digite o nome do local atual do veiculo (deve ser um local ja cadastrado): ";
    std::cin >> nomeLocal;

    // Busca o local informado para garantir que ele existe antes de associá-lo ao veículo
    int indice = buscarLocalPorNome(nomeLocal, vetorLocais, totalLocais);
    if (indice != -1) {
        v.localAtual = vetorLocais[indice]; // Atributo: local atual (referência a um Local)
        vetorVeiculos[totalVeiculos++] = v; // Adiciona o veículo ao vetor principal
        std::cout << "Veiculo cadastrado com sucesso! (Status padrao: disponivel)" << std::endl;
    } else {
        std::cout << "Erro: Local nao encontrado. Veiculo nao cadastrado." << std::endl;
    }
}

// Implementação da operação para listar Veículos
void listarVeiculos(const Veiculo vetorVeiculos[], int totalVeiculos) {
    std::cout << "\n--- Lista de Veiculos Cadastrados ---" << std::endl;
    if (totalVeiculos == 0) {
        std::cout << "Nenhum veiculo cadastrado." << std::endl;
        return;
    }

    for (int i = 0; i < totalVeiculos; i++) {
        std::cout << "Veiculo " << i + 1 << ":" << std::endl;
        std::cout << "  Placa: " << vetorVeiculos[i].placa << std::endl;
        std::cout << "  Modelo: " << vetorVeiculos[i].modelo << std::endl;
        std::cout << "  Status: " << vetorVeiculos[i].status << std::endl;
        std::cout << "  Local Atual: " << vetorVeiculos[i].localAtual.nome << std::endl;
        std::cout << "----------------------------------" << std::endl;
    }
}