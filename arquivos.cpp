// Arquivo: arquivos.cpp
#include <iostream>
#include <fstream>
#include "arquivos.h"

void salvarDados(const Local locais[], int totalLocais,
                 const Veiculo veiculos[], int totalVeiculos,
                 const Pedido pedidos[], int totalPedidos) {
    std::ofstream arqLocais("locais.bin", std::ios::binary);
    if (arqLocais) {
        arqLocais.write(reinterpret_cast<const char*>(&totalLocais), sizeof(int));
        arqLocais.write(reinterpret_cast<const char*>(locais), totalLocais * sizeof(Local));
        arqLocais.close();
    } else {
        std::cout << "Erro ao salvar locais." << std::endl;
    }

    std::ofstream arqVeiculos("veiculos.bin", std::ios::binary);
    if (arqVeiculos) {
        arqVeiculos.write(reinterpret_cast<const char*>(&totalVeiculos), sizeof(int));
        arqVeiculos.write(reinterpret_cast<const char*>(veiculos), totalVeiculos * sizeof(Veiculo));
        arqVeiculos.close();
    } else {
        std::cout << "Erro ao salvar veiculos." << std::endl;
    }

    std::ofstream arqPedidos("pedidos.bin", std::ios::binary);
    if (arqPedidos) {
        arqPedidos.write(reinterpret_cast<const char*>(&totalPedidos), sizeof(int));
        arqPedidos.write(reinterpret_cast<const char*>(pedidos), totalPedidos * sizeof(Pedido));
        arqPedidos.close();
    } else {
        std::cout << "Erro ao salvar pedidos." << std::endl;
    }

    std::cout << "\nBackup realizado com sucesso!" << std::endl;
}

void restaurarDados(Local locais[], int &totalLocais,
                    Veiculo veiculos[], int &totalVeiculos,
                    Pedido pedidos[], int &totalPedidos) {
    std::ifstream arqLocais("locais.bin", std::ios::binary);
    if (arqLocais) {
        arqLocais.read(reinterpret_cast<char*>(&totalLocais), sizeof(int));
        arqLocais.read(reinterpret_cast<char*>(locais), totalLocais * sizeof(Local));
        arqLocais.close();
    }

    std::ifstream arqVeiculos("veiculos.bin", std::ios::binary);
    if (arqVeiculos) {
        arqVeiculos.read(reinterpret_cast<char*>(&totalVeiculos), sizeof(int));
        arqVeiculos.read(reinterpret_cast<char*>(veiculos), totalVeiculos * sizeof(Veiculo));
        arqVeiculos.close();
    }

    std::ifstream arqPedidos("pedidos.bin", std::ios::binary);
    if (arqPedidos) {
        arqPedidos.read(reinterpret_cast<char*>(&totalPedidos), sizeof(int));
        arqPedidos.read(reinterpret_cast<char*>(pedidos), totalPedidos * sizeof(Pedido));
        arqPedidos.close();
    }

    std::cout << "\nDados restaurados com sucesso!" << std::endl;
}
