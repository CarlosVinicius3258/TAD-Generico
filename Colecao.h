
#ifndef __COLECAO_H
#define __COLECAO_H

typedef struct _colecao_ Colecao;

//Cria uma coleção
//Pre-condicao: max_items > 0
//Pos-condicao: retorna um ponteiro para uma novo
//TAD Colecao void* vazio*/
Colecao* colCriar(int maxItems);

//Adiciona um item na coleção
//Pre-condicao : (c é um TAD Colecao criado por uma chamada a colCriar e (o TAD Colecao nao esta cheio) e (item != NULL)
//Pos-condicao: item foi adicionado ao TAD c
int colInserir(Colecao* c, void* item);

//Retira um item da coleção
//Pre-condicao: c é um coleção criada por uma chamada a colCriar existe pelo menos um item na colecao
//Pos-condicao: item foi retirado da colecao
void* colRetirar(Colecao* c, void* key, int (*cmp)(const void*, const void*));

//Encontra um item na coleção
//Pre-condicao: (c é um TAD Colecao criado por uma chamada a colCriar) e (key != NULL)
//Pos-condicao: retorna um item identificado por key se ele existir no TAD c, ou return NULL caso contrátrio
void* colBuscar(Colecao* c, void* key, int (*cmp)(const void*, const void*));

//Destrói uma coleção
//Pre-condicao: (c é um TAD Colecao criado por uma chamada a colCriar)
//Pos-condicao: a memoria usada pelo TAD foi liberada
void colDestruir(Colecao* c);

#endif /* __COLECAO_H */