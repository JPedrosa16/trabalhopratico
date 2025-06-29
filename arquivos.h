// Arquivo: arquivos.h
#ifndef ARQUIVOS_H
#define ARQUIVOS_H
#include "entidades.h"

void salvarDados(const Local locais[], int totalLocais,
                 const Veiculo veiculos[], int totalVeiculos,
                 const Pedido pedidos[], int totalPedidos);

void restaurarDados(Local locais[], int &totalLocais,
                    Veiculo veiculos[], int &totalVeiculos,
                    Pedido pedidos[], int &totalPedidos);
#endif
