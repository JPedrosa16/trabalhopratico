// Arquivo: locais.h
#ifndef LOCAIS_H
#define LOCAIS_H

#include "entidades.h"

// Declaração das operações de CRUD para a entidade Local [cite: 12]
void cadastrarLocal(Local vetorLocais[], int &totalLocais);
void listarLocais(const Local vetorLocais[], int totalLocais);
void atualizarLocal(Local vetorLocais[], int totalLocais);
void excluirLocal(Local vetorLocais[], int &totalLocais);

// Declaração da função de busca para que se torne pública para outros módulos.
// Esta é a chave para que 'pedidos.cpp' possa usá-la sem precisar reescrevê-la.
int buscarLocalPorNome(const char nomeBusca[], const Local vetorLocais[], int totalLocais);

#endif