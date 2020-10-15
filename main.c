
#include <stdio.h>
#include <stdlib.h>
#include "Colecao.h"
#include <string.h>


typedef struct country{
    char* capital;
    int age;
    long int population;
    float averageMaleHeight;
    float averageFemaleHeight;
}Country;

int cmpCountry(void *item, void *key){

    Country *pItem = (Country *)item;

    char *pkey = (char *)key;
    return strcmp(pkey, pItem->capital);
    
}

int main(){
  

     Country* USA;
     Country* Canada;
     USA->capital = "Washington";
     USA->age = 244;
     Canada->age = 25;
     USA->population = 325719178;
     USA->averageMaleHeight = 175.3;
     USA->averageFemaleHeight = 161.5;
     
     Colecao* northAmerica =  colCriar(3); 
     colInserir(northAmerica, (void*)USA);
     colBuscar(northAmerica, (void*) "Washington", (void*)cmpCountry);
     int a = colDestruir(northAmerica);
     printf("%d", a);

  
     
    return 0;
}

