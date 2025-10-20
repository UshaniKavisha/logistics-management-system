#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIES 30
#define VEHICLE 3

char cities[MAX_CITIES][40];
int cityCount=0;
int distance[MAX_CITIES][MAX_CITIES];
char vehicle[VEHICLE][30]={"Van", "Truck" , "Lorry"};
int capacity[VEHICLE]={1000,5000,10000};
int rate[VEHICLE]={30,40,80};
int avgSpeed[VEHICLE]={60,50,45};
int fuelEfficiency[VEHICLE]={12,6,4};

void addCity();
void renameCity();
void removeCity();
void listCities();

void getDistance();
void enterDistance();
void displayDistance();

void displayVehicle();
int chooseVehicle()


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
    listCities();
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
    listCities();
    if(cityCount==0){
       printf("you didn't add cities yet!\n");
       return;
    }

    printf("Enter the number of city you want to rename: ");
    scanf("%d",&index);

    if(index < 1 || index > cityCount)
    {
        printf("Invalid index!");
        return;
    }

    for(int i= index-1; i<cityCount-1;i++)
    {
        strcpy(cities[i], cities[i + 1]);
    }

    cityCount--;
    printf("City remove successfully! \n");
}

void listCities()
{
    if(cityCount==0){
       printf("you didn't add cities yet!\n");
       return;
    }

    printf("\n You added cities..\n");
    for (int i=0;i<cityCount;i++)
    {
        printf("%d %s\n",i+1,cities[i]);
    }
}


void getDistance()
{
    for(int i=0;i<MAX_CITIES;i++)
    {
        for(int j=0;j<MAX_CITIES;j++)
        {
            {if(i==j)
                distance[i][j]=0;
             else
                distance[i][j]=-1;
        }

    }
}

void enterDistance()
{
    listCities();
    int city1,city2,d;

    if(cityCount<1)
    {
        printf("Add least 2 cities,therefore you cann't give distance...\n ");
        return;
    }


    printf("Enter 1st city: ");
    scanf("%d",&city1);

    printf("Enter 2nd city: ");
    scanf("%d",&city2);

    if(city1<1 || city2<1 || city1>cityCount || city2>cityCount ||city1==city2)
    {
        printf("Invalid city numbers or conn't city numbers are same...\n");
        return;
    }

    printf("Enter distance between %s and %s in km: ",cities[city1-1],cities[city2-1]);
    scanf("%d",&d);

    distance[city1-1][city2-2]=d;
    distance[city2-1][city1-1]=d;

    printf("Distance added successfully....\n");
}

void displayDistance()
{
    if(cityCount<1)
    {
        printf("Add least 2 cities, therefore you cann't give distance...\n ");
        return;
    }

    printf("\n Distance......\n");
    for(int i=0; i<cityCount;i++)
    {
        printf("%s",cities[i]);
    }

    printf("\n");

    for(int i=0; i<cityCount;i++)
    {
        printf("%s",cities[i]);
        for(int j=0;j<cityCount;j++)
        {
            if(distance[i][j]==-1)
                printf("%s","-");
            else
                printf("%d",distance[i][j]);
        }
        printf("\n");
    }
}

void displayVehicle()
{
    printf("Type\tCapacity(kg)\tRate(LKR)\tAvg Speed(km/h)\tFuel Efficiency(km/l)\t");
    printf("- - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - -");

    for (int i=0;i<VEHICLE;i++)
    {
        printf("%s \t %d \t %d \t %d \t %d \t ",vehicle[i],capacity[i],rate[i],avgSpeed[i],fuelEfficiency[i]);

    }

}

int chooseVehicle()
{
    int choice;
    displayVehicle();
    printf("Choose you want vehicle(Enter number (Van:0 ,Truck:1, Lorry:2)): ");
    scanf("%d",&choice);

    if(choice<1 || choice>(VEHICLE-1))
    {
        printf("Invalid choice \n");
        return ;
    }

    return choice;
}
