
#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include <string.h>


typedef struct country{
    char* capital;
    int age;
    long int population;
    float averageMaleHeight;
    float averageFemaleHeight;
}Country;

int cmpCountry(void *key, void *item){
    Country* newItem = (Country*) item;
    Country* pKey = (Country*) key;
    
    if (pKey->capital == newItem->capital && 
      pKey->age == newItem->age && pKey->population == newItem->population && 
      pKey->averageMaleHeight == newItem->averageMaleHeight && pKey->averageFemaleHeight == newItem->averageFemaleHeight ){
        return 1;
    }else{
        return 0;
    }
    
}
int main(){
  

     Country* USA;
     USA = (Country*) malloc(sizeof(Country));
     if(USA!=NULL){
       USA->capital = "Washington";
     USA->age = 244;
     USA->population = 325719178;
     USA->averageMaleHeight = 175.3;
     USA->averageFemaleHeight = 161.5;
     
     Colecao* northAmerica =  colCriar(3); 
     colInserir(northAmerica,USA);
     colBuscar(northAmerica,USA,cmpCountry);
     
     }
     

  
     
    return 0;
}

