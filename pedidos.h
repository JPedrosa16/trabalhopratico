// Arquivo: pedidos.h
#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "entidades.h"

// Declarações das funções de gestão de pedidos
void cadastrarPedido(Pedido vetorPedidos[], int &totalPedidos, const Local vetorLocais[], int totalLocais);
void listarPedidos(const Pedido vetorPedidos[], int totalPedidos);
// As funções de atualizar e excluir seguiriam a mesma lógica.

#endif