#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30

char cities[MAX_CITIES][40];
int cityCount=0;

void addCity();
void renameCity();
void removeCity();

int main()
{

    return 0;
}

void addCity()
{
    if(cityCount>=MAX_CITIES)
    {
        printf("you already reached your city limit.\n");
        return;
    }
    char city[40];

    printf("Enter your city name (unique name): ");
    scanf("%s",city);

    for(int i=0;i<cityCount;i++)
    {
        if(strcmp(cities[i],city)==0)
        {printf("you already entered this city!\n");
         return;}
    }

        strcpy(cities[cityCount], city);
        cityCount++;
        printf("you successfully added city!\n");

}


void renameCity()
{
    if(cityCount==0)
    {
        printf("you didn't add cities yet!\n");
        return;
    }
    int index;

    printf("Enter the number of city you want to rename: ");
    scanf("%d",&index);

    if(index < 1 || index > cityCount)
    {
        printf("Invalid index!");
        return;
    }

    char newCity[40];
    printf("Rename city: ");
    scanf("%s",newCity);

    for(int i=0;i<cityCount;i++)
    {
        if(strcmp(cities[i],newCity)==0)
        {printf("you already entered this city!\n");
         return;}
    }
        strcpy(cities[index - 1], newCity);
        printf("you added new name added successfully!");

}


void removeCity()
{

}
