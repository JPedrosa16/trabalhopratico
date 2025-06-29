// Arquivo principal do sistema SLEM.
// Responsável por inicializar vetores, exibir o menu principal e controlar o fluxo do programa.
// Todas as operações são chamadas a partir daqui.

// Arquivo: main.cpp
#include <iostream>
#include "entidades.h"
#include "locais.h"
#include "veiculos.h"
#include "pedidos.h" // Incluir novo módulo
#include "rotas.h"   // Incluir novo módulo

void exibirMenu() {
    std::cout << "\n===== Sistema de Logistica (SLEM) =====" << std::endl;
    std::cout << "--- GESTAO DE LOCAIS ---" << std::endl;
    // ... opções 1 a 4 ...
    std::cout << "--- GESTAO DE VEICULOS ---" << std::endl;
    // ... opções 5 e 6 ...
    std::cout << "--- GESTAO DE PEDIDOS ---" << std::endl;
    std::cout << "7. Cadastrar Pedido" << std::endl;
    std::cout << "8. Listar Pedidos" << std::endl;
    std::cout << "--- OPERACOES ---" << std::endl;
    std::cout << "10. Calcular Rota de Entrega" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "99. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    // Vetores
    Local vetorLocais[100];
    Veiculo vetorVeiculos[50];
    Pedido vetorPedidos[200]; // Adicionar vetor de pedidos

    // Contadores
    int totalLocais = 0;
    int totalVeiculos = 0;
    int totalPedidos = 0; // Adicionar contador de pedidos

    int opcao;

    do {
        exibirMenu();
        std::cin >> opcao;

        switch (opcao) {
            // Casos 1 a 6 da Sprint 1...
            
            case 7: cadastrarPedido(vetorPedidos, totalPedidos, vetorLocais, totalLocais); break;
            case 8: listarPedidos(vetorPedidos, totalPedidos); break;
            case 10: calcularExibirRota(vetorPedidos, totalPedidos, vetorVeiculos, totalVeiculos); break;
            
            case 99: std::cout << "Saindo do sistema..." << std::endl; break;
            default: std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    } while (opcao != 99);

    return 0;
}