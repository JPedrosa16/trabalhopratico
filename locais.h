#ifndef LOCAIS_H
#define LOCAIS_H
#include "entidades.h"

void cadastrarLocal(Local vetorLocais[], int &totalLocais);
void listarLocais(const Local vetorLocais[], int totalLocais);
void atualizarLocal(Local vetorLocais[], int totalLocais);
void excluirLocal(Local vetorLocais[], int &totalLocais);
int buscarLocalPorNome(const char nomeBusca[], const Local vetorLocais[], int totalLocais);

#endif
