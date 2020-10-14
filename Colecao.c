#include <stdio.h>
#include <stdlib.h>
#include "Colecao.h"


struct _colecao_ {
    int numItens;
    int maxItens;
    void* itens;
};

//OPERAÇÃO: Cria Colecao
Colecao* colCriar(int maxItens){
    if (maxItens <= 0){
        return NULL;
    }
    Colecao* c;
    c = (Colecao*) malloc (sizeof(Colecao));
    if(c != NULL){
        c->itens = (void**) malloc(sizeof(void*) * maxItens);
        if(c->itens == NULL){
            free(c);
            return NULL;
        }
        c->maxItens = maxItens;
        c->numItens = 0;
        return c;
    }
    free(c);
    return NULL;
} 

//OPERAÇÃO: Inserir Item na coleção
void colInserir(Colecao* c, void* item){
    if (c == NULL || c->numItens >= c->maxItens || item==NULL){
       return NULL;
    }
    c->itens[c->numItens] = item;
    c->numItens++; 
}

//OPERAÇÃO: Destruir coleção
void colDestruir(Colecao* c){

    if (c == NULL || c->itens == NULL || c->numItens!=0){
        return NULL;
    }
    free(c->itens);
    free(c);
    
}

//OPERAÇÃO: Buscar elemento na coleção
void* colBuscar(Colecao* c, void* key, int (*cmp)(void*, void*) ){
    int i = 0;
    if (c !=NULL || c->itens!= NULL || c->numItens > 0 ){
        while(cmp(c->itens[i], key) != 0){
            i++;
        }
        if(cmp(c->itens[i], key) == 0){
            return c->itens[i];
        }
    }
    return NULL;  
}

//OPERAÇÃO: Retirar elemento da coleção

void* colRetirar(Colecao* c, void* key, int(*cmp)(void*, void*)){
    int i = 0;
    void* aux;
    if(c != NULL || c->itens != NULL || c->numItens > 0){
        while(cmp(c->itens[i], key) != 0){
            i++;
        }
        if (cmp(c->itens[i], key) == 0){
            aux = c->itens[i];
            while(i < c->numItens){
                c->itens[i] = c->itens[i+1];
                i++;
            }
            c->numItens--;
            return aux;
        }

    }
    return NULL;
}