// Arquivo: rotas.cpp
#include <iostream>
#include <cmath> // Para sqrt e pow
#include <cfloat> // Para DBL_MAX (representar infinito)
#include <cstring>
#include "rotas.h"

// Função para calcular a distância Euclidiana entre dois locais [cite: 19]
double calcularDistancia(Local p1, Local p2) {
    return sqrt(pow(p2.coordenadaX - p1.coordenadaX, 2) + pow(p2.coordenadaY - p1.coordenadaY, 2));
}

// Função para encontrar o veículo disponível mais próximo da origem do pedido 
int encontrarVeiculoMaisProximo(Local origem, const Veiculo vetorVeiculos[], int totalVeiculos) {
    int indiceMelhorVeiculo = -1;
    double menorDistancia = DBL_MAX; // Inicia com uma distância "infinita"

    for (int i = 0; i < totalVeiculos; i++) {
        // Verifica se o veículo está "disponível" [cite: 13, 18]
        if (strcmp(vetorVeiculos[i].status, "disponivel") == 0) {
            double d = calcularDistancia(vetorVeiculos[i].localAtual, origem);
            if (d < menorDistancia) {
                menorDistancia = d;
                indiceMelhorVeiculo = i;
            }
        }
    }
    return indiceMelhorVeiculo;
}

void calcularExibirRota(const Pedido vetorPedidos[], int totalPedidos, Veiculo vetorVeiculos[], int totalVeiculos) {
    int idPedido;
    std::cout << "\nDigite o ID do pedido para calcular a rota: ";
    std::cin >> idPedido;

    int indicePedido = -1;
    for (int i = 0; i < totalPedidos; i++) {
        if (vetorPedidos[i].id == idPedido) {
            indicePedido = i;
            break;
        }
    }

    if (indicePedido == -1) {
        std::cout << "Erro: Pedido nao encontrado." << std::endl;
        return;
    }

    const Pedido& pedidoAtual = vetorPedidos[indicePedido];
    int indiceVeiculo = encontrarVeiculoMaisProximo(pedidoAtual.origem, vetorVeiculos, totalVeiculos);

    if (indiceVeiculo == -1) {
        std::cout << "Nenhum veiculo disponivel encontrado para atender ao pedido." << std::endl;
        return;
    }

    Veiculo& veiculoSelecionado = vetorVeiculos[indiceVeiculo];

    // Calcula a distância total
    double distVeiculoOrigem = calcularDistancia(veiculoSelecionado.localAtual, pedidoAtual.origem);
    double distOrigemDestino = calcularDistancia(pedidoAtual.origem, pedidoAtual.destino);
    double distanciaTotal = distVeiculoOrigem + distOrigemDestino;

    // Exibe a rota calculada 
    std::cout << "\n--- Rota de Entrega Calculada ---" << std::endl;
    std::cout << "Veiculo Selecionado: " << veiculoSelecionado.placa << " (" << veiculoSelecionado.modelo << ")" << std::endl;
    std::cout << "Local de Origem do Pedido: " << pedidoAtual.origem.nome << std::endl;
    std::cout << "Local de Destino do Pedido: " << pedidoAtual.destino.nome << std::endl;
    std::cout << "Distancia Total Percorrida: " << distanciaTotal << " unidades" << std::endl;

    // Simulação da entrega e atualização de status 
    std::cout << "\nSimulando entrega..." << std::endl;
    strcpy(veiculoSelecionado.status, "ocupado");
    std::cout << "Status do veiculo " << veiculoSelecionado.placa << " atualizado para OCUPADO." << std::endl;

    // ... simulação ...
    
    std::cout << "Entrega finalizada!" << std::endl;
    strcpy(veiculoSelecionado.status, "disponivel");
    veiculoSelecionado.localAtual = pedidoAtual.destino;
    std::cout << "Status do veiculo " << veiculoSelecionado.placa << " atualizado para DISPONIVEL." << std::endl;
    std::cout << "Localizacao atual do veiculo atualizada para " << veiculoSelecionado.localAtual.nome << "." << std::endl;
}