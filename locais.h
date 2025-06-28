// Arquivo: locais.h
#ifndef LOCAIS_H
#define LOCAIS_H
#include "entidades.h"

// Declaração das funções que serão implementadas em locais.cpp [cite: 31]
void cadastrarLocal(Local vetorLocais[], int &totalLocais);
void listarLocais(const Local vetorLocais[], int totalLocais);
void atualizarLocal(Local vetorLocais[], int totalLocais);
void excluirLocal(Local vetorLocais[], int &totalLocais);

#endif