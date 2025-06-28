// Arquivo: main.cpp
#include <iostream>
#include "entidades.h"
#include "locais.h"
#include "veiculos.h"

// Função para exibir o menu de opções
void exibirMenu() {
    std::cout << "\n===== Sistema de Logistica (SLEM) =====" << std::endl;
    std::cout << "--- GESTAO DE LOCAIS ---" << std::endl;
    std::cout << "1. Cadastrar Local" << std::endl;
    std::cout << "2. Listar Locais" << std::endl;
    std::cout << "3. Atualizar Local" << std::endl;
    std::cout << "4. Excluir Local" << std::endl;
    std::cout << "--- GESTAO DE VEICULOS ---" << std::endl;
    std::cout << "5. Cadastrar Veiculo" << std::endl;
    std::cout << "6. Listar Veiculos" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "9. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    // Vetores para armazenar os dados em memória 
    Local vetorLocais[100];
    Veiculo vetorVeiculos[50];
    int totalLocais = 0;
    int totalVeiculos = 0;

    int opcao;

    // Loop do menu que continua até o usuário escolher sair [cite: 27]
    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            case 1: cadastrarLocal(vetorLocais, totalLocais); break;
            case 2: listarLocais(vetorLocais, totalLocais); break;
            case 3: atualizarLocal(vetorLocais, totalLocais); break;
            case 4: excluirLocal(vetorLocais, totalLocais); break;
            case 5: cadastrarVeiculo(vetorVeiculos, totalVeiculos, vetorLocais, totalLocais); break;
            case 6: listarVeiculos(vetorVeiculos, totalVeiculos); break;
            // Faltam os casos para atualizar e excluir veículo
            case 9: std::cout << "Saindo do sistema..." << std::endl; break;
            default: std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    } while (opcao != 9);

    return 0;
}