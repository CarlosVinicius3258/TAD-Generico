#include <stdio.h>
#include <stdlib.h>
#include "Colecao.h"

typedef struct country{
    char* capital;
    int age;
    long int population;
    float averageMaleHeight;
    float averageFemaleHeight;
}Country;

int main(){
     Country* USA;
     USA.capital = "Washington";
     USA.age = 244;
     USA.population = 325719178;
     USA.averageMaleHeight = 175.3;
     USA.averageFemaleHeight = 161.5;
     Colecao* northAmerica =  colCriar(3); 
     colInserir(northAmerica, USA);
     printf("%d", USA.age);
    return 0;
}