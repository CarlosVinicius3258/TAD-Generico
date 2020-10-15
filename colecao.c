#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#define FALSE 0
#define TRUE 1

typedef struct _colecao_ {
    int numItens;
    int maxItens;
    void* *itens;
}Colecao;

//OPERAÇÃO: Cria Colecao ok
Colecao* colCriar(int maxItens){
    if (maxItens > 0){
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
    }else{
        free(c);    
    }
    
    }
    return NULL;
    
} 

//OPERAÇÃO: Inserir Item na coleção ok
int colInserir(Colecao* c, void* item){
    if (c != NULL){
      if(c->numItens < c->maxItens){
        if(item!=NULL){
          c->itens[c->numItens] = item;
          printf("inseriu\n");
          c->numItens++;

          return 0;
        }
        
      }
       
    }
    return 1;
}

//OPERAÇÃO: Destruir coleção ok
int colDestruir(Colecao* c){

    if (c == NULL || c->itens == NULL || c->numItens!=0){
        return FALSE;
    }
    free(c->itens);
    free(c);
    return TRUE;
}

//OPERAÇÃO: Buscar elemento na coleção off
void* colBuscar(Colecao* c, void* key, int (*cmp)(void*, void*) ){
    printf("entrou em buscar\n");
    int i = 0;
    if (c!=NULL){
      printf("AAAAAAA\n");
      if(c->itens!= NULL){
        printf("BBBBBB\n");
        if(c->numItens > 0 ){
          printf("CCCCCCC\n");
          while(cmp(c->itens[i], key) != TRUE){
            i++;
            printf("comparou");
          }
          if(cmp(c->itens[i], key) == TRUE){
            printf("buscou\n");
            return c->itens[i];
          }
        }
          
      }
        
    }
    return NULL;  
}

//OPERAÇÃO: Retirar elemento da coleção off

void* colRetirar(Colecao* c, void* key, int(*cmp)(void*, void*)){
    printf("\nEntrou em retirar");
    int i = 0;
    void* aux;
    if(c != NULL)
    { 
      printf("\nif 1\n");
      if(c->itens != NULL)
      {
        printf("if 2 \n");
        if(c->numItens > 0)
        {
          printf("if 3\n");
          while(cmp(c->itens[i], key) != TRUE)
          {
               printf("Entrei no while\n");
              i++;
          }
          if (cmp(c->itens[i], key) == TRUE)
          {
              aux = c->itens[i];
              while(i < c->numItens)
              {
                  c->itens[i] = c->itens[i+1];
                  i++;
              }
              c->numItens--;
              printf("deu certo");
              return aux;
          }
        }
      }
    }
    return NULL;
}