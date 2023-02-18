/**
 * @file demography.c
 * @author Santiago Bocanegra Gutierrez (udunome@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-13
 * Realice un programa que efectúe lo siguiente:
    1.  Suponga que de cada continente, país y pueblo se conoce el nombre y el número de habitantes.
    2.  Muestre las poblaciones de un continente.
    3.  Obtenga el total de habitantes de uno de los continentes.
    4.  Muestre el promedio de la edad de los habitantes por población, país y continente.
    5.  Muestre toda la información por continente, país y población. 
 * @copyright Copyright (c) 2023
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 20

typedef struct 
{
    int age_average;
    int population_vill;
}village;

typedef struct 
{
    char name[MAX_LENGTH];
    int population_ctry;
    village north;
    village south;
}country;

typedef struct
{
    char name[MAX_LENGTH];
    int total_habitants;
    int population_cntnt;
    country countries[5];
}continent;

int i = 1, j = 1;
int random_popu(unsigned int a); // function to get random values for village population
int set_seed(void);
int age_average(unsigned int b);
int global_counter(void);

int main(void)
{
    continent continents[5];
    int seed = set_seed();
    //declare contintents name

    char name_contint[5][MAX_LENGTH] = {"America", "Europa", "Africa", "Asia", "Oceania"};

    for (int i = 0; i < 5; i++) //then they're copied to their respective struct
        strcpy(continents[i].name, name_contint[i]);
    
    //name all countries
    char america_countries[5][MAX_LENGTH] = {"Mexico", "Colombia", "Estados Unidos", "Salvador", "Puerto Rico"};
    char europa_countries[5][MAX_LENGTH] = {"Espana", "Portugal", "Francia", "Rusia", "Italia"};
    char africa_countries[5][MAX_LENGTH] = {"Nigeria", "Sudafrica", "Ghana", "Marruecos", "Senegal"};
    char asia_countries[5][MAX_LENGTH] = {"Japon", "China", "India", "Singapur", "Indonesia"};
    char oceania_countries[5][MAX_LENGTH] = {"Australia", "Nueva Zelanda", "Fiyi", "Tonga", "Tuvalu"};

    //Copy name to their continents
    for (int i = 0; i < 5; i++) //America
        strcpy(continents[0].countries[i].name, america_countries[i]);        
    for (int i = 0; i < 5; i++) //Europe
        strcpy(continents[1].countries[i].name, europa_countries[i]);                
    for (int i = 0; i < 5; i++) //Africa
        strcpy(continents[2].countries[i].name, africa_countries[i]);                
    for (int i = 0; i < 5; i++) //Asia
        strcpy(continents[3].countries[i].name, asia_countries[i]);                
    for (int i = 0; i < 5; i++) //Oceania
        strcpy(continents[4].countries[i].name, oceania_countries[i]);                
    
    //villages age average
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            continents[i].countries[j].north.age_average = age_average(seed);
            continents[i].countries[j].south.age_average = age_average(seed);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Continent %i, country: %i, village north age: %i \n", i, j, continents[i].countries[j].north.age_average);
            printf("Continent %i, country: %i, village south age: %i\n", i, j, continents[i].countries[j].south.age_average);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            continents[i].countries[j].north.population_vill = random_popu(seed);
            continents[i].countries[j].south.population_vill = random_popu(seed);
        }
    }
    //
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Continent %i, country: %i, village north population average: %i \n", i, j, continents[i].countries[j].north.population_vill);
            printf("Continent %i, country: %i, village south population average: %i\n", i, j, continents[i].countries[j].south.population_vill);
        }
        printf("\n");
    }

    
    printf("Mexico age average: %i\n", continents[0].countries[0].north.age_average);

    return 0;
}

int random_popu(unsigned int seed)
{ 
    int random;
    srand(seed + j);
    //Search an intresting value onto that set of random numbers
    for (int i = 0; i < 20; i++)
        random = rand(); 
    //Change j value to obtain different values when function is called
    j++;
    random *= 5;

    return random % 200000;      
}

int age_average(unsigned int seed)
{
    int random;
    srand(seed + i); //Use seed and get random set of values

    for (int i = 0; i < seed; i++)
        random = rand(); // search an intresting value onto that set of random numbers
    i++;

    return (random % 30) + 45;
}

int set_seed(void)
{
    time_t seconds = time(NULL);    //set current seconds (this value is too long because of time(NULL) function)
    seconds %= 32766;
    seconds = (int) seconds;        //convert long int into an int value 
    unsigned int random;

    srand(seconds);
    for (int i = 0; i < 10; i++)
        random = rand();

    return random % 32766;
}
