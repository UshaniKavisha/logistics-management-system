#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_CITIES 30
#define VEHICLE 3
#define FUEL_PRICE 310.0
#define MAX_DELIVERIES 50

char cities[MAX_CITIES][40];
int cityCount=0;
int distance[MAX_CITIES][MAX_CITIES];
char vehicle[VEHICLE][30]={"Van", "Truck" , "Lorry"};
int capacity[VEHICLE]={1000,5000,10000};
int rate[VEHICLE]={30,40,80};
int avgSpeed[VEHICLE]={60,50,45};
int fuelEfficiency[VEHICLE]={12,6,4};

typedef struct {
    int sourceCity;
    int destinationCity;
    float weight;
    int vehicalType;
    float distance;
    float deliveryCost;
    float fuelCost;
    float operationalCost;
    float profit;
    float customerCharge;
    float deliveryTime;
} DeliveryRecord;

DeliveryRecord deliveries[MAX_DELIVERIES];
int deliveryCount = 0;

void addCity();
void renameCity();
void removeCity();
void listCities();

void getDistance();
void enterDistance();
void displayDistance();

void displayVehicle();
int chooseVehicle();
void deliveryRequestHandling();
void findingTheLeastCostRoute(int startIndex, int endIndex);
void performanceReport();


int main()
{
    int choice;
    getDistance();

    do
    {
        printf("\n------------------------------------------------------\n");
        printf("LOGISTIC MANAGEMENT SYSTEM\n");
        printf("-------------------------------------------------------\n");
        printf("1.Add a new city\n");
        printf("2.Rename a city\n");
        printf("3.Remove a city\n");
        printf("4.List all cities\n");
        printf("5.Enter distance\n");
        printf("6.Display distance table\n");
        printf("7.Display vehicle details\n");
        printf("8.Handle a delivery request\n");
        printf("9.Find least cost route(limited to 4 cities only)\n");
        printf("0.Exit.............\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                addCity();
                break;
            case 2:
                renameCity();
                break;
            case 3:
                removeCity();
                break;
            case 4:
                listCities();
                break;
            case 5:
                enterDistance();
                break;
            case 6:
                displayDistance();
                break;
            case 7:
                displayVehicle();
                break;
            case 8:
                deliveryRequestHandling();
                break;
            case 9:
                {
                    int start, end;
                    listCities();

                    printf("Enter start city number: ");
                    scanf("%d",&start);
                    printf("Enter end city number: ");
                    scanf("%d",&end);
                    findingTheLeastCostRoute(start -1,end -1);
                }
                break;
            case 0:
                printf("Exiting the program....\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

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

    printf("Enter your city name (unique name,also no spaces): ");
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
    if(cityCount==0){
       printf("you didn't add cities yet!\n");
       return;
    }

    int index;
    listCities();

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
            if(i==j)
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

    if(cityCount<2)
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

    distance[city1-1][city2-1]=d;
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
    printf("Type\tCapacity(kg)\tRate(LKR)\tAvg Speed(km/h)\tFuel Efficiency(km/l)\t\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - -\n");

    for (int i=0;i<VEHICLE;i++)
    {
        printf("%s \t %d \t %d \t %d \t %d \t \n",vehicle[i],capacity[i],rate[i],avgSpeed[i],fuelEfficiency[i]);

    }

}

int chooseVehicle()
{
    int choice;
    displayVehicle();
    printf("Choose you want vehicle(Enter number (Van:0 ,Truck:1, Lorry:2)): ");
    scanf("%d",&choice);

    if(choice<0 || choice>=VEHICLE)
    {
        printf("Invalid choice \n");
        return -1;
    }

    return choice;
}

void deliveryRequestHandling()
{
    listCities();
    if(cityCount<2)
    {
        printf("Add least 2 cities and their distance, therefore we cann't implement this...");
        return;
    }

    int sourceCity,destinationCity;

    printf("Enter source city number: ");
    scanf("%d",&sourceCity);

    printf("Enter destination city number: ");
    scanf("%d",&destinationCity);

    if(sourceCity<1 || sourceCity==destinationCity || sourceCity>cityCount || destinationCity<1 || destinationCity>cityCount)
    {
        printf("Invalid city numbers or conn't city numbers are same...\n");
        return;
    }

    float weight;
    printf("Enter weight(kg):  ");
    scanf("%f",&weight);

    if(distance[sourceCity-1][destinationCity-1]==-1)
    {
        printf("Between two cities distance not entered yet...\n");
    }

    int vehicalType=chooseVehicle();
    if(vehicalType==-1)return;

    if(weight>capacity[vehicalType])
    {
        printf("You entered weight exceeds vehicle capacity!\n");
        return;
    }

    float D = distance[sourceCity-1][destinationCity-1];
    float R = rate[vehicalType];
    float S = avgSpeed[vehicalType];
    float E = fuelEfficiency[vehicalType];
    float F = FUEL_PRICE;

    float deliveryCost = D*R*(1+(weight/10000.0));
    float deliveryTime=D/S;
    float fuelConsumption=D/E;
    float fuelCost=fuelConsumption*F;
    float totalOperationalCost=deliveryCost+fuelCost;
    float profit=deliveryCost*0.25;
    float customerCharge=totalOperationalCost+profit;

    if(deliveryCount<MAX_DELIVERIES)
    {
        deliveries[deliveryCount].sourceCity=sourceCity-1;
        deliveries[deliveryCount].destinationCity=destinationCity-1;
        deliveries[deliveryCount].weight=weight;
        deliveries[deliveryCount].vehicalType=vehicalType;
        deliveries[deliveryCount].distance=D;
        deliveries[deliveryCount].deliveryCost=deliveryCost;
        deliveries[deliveryCount].fuelCost=fuelCost;
        deliveries[deliveryCount].operationalCost=totalOperationalCost;
        deliveries[deliveryCount].profit=profit;
        deliveries[deliveryCount].customerCharge=customerCharge;
        deliveries[deliveryCount].deliveryTime=deliveryTime;
        deliveryCount++;
    }
    else
    {
        printf("You reached maximum delivery.....\n");
    }

    printf("\n----------------------------------------------------------\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("----------------------------------------------------------\n");
    printf("From: %s\n",cities[sourceCity-1]);
    printf("To: %s\n",cities[destinationCity-1]);
    printf("Minimum Distance: %.2f km\n",D);
    printf("Vehicle: %s\n",vehicle[vehicalType]);
    printf("Weight: %.2f kg\n",weight);
    printf("---------------------------------------------------------\n");
    printf("Base Cost: %.2f LKR\n",deliveryCost);
    printf("Fuel Used: %.2f L\n",fuelConsumption);
    printf("Fuel Cost: %.2f LKR\n",fuelCost);
    printf("Operational Cost: %.2f LKR\n",totalOperationalCost);
    printf("Profit: %.2f LKR\n",profit);
    printf("Customer Charge: %.2f LKR\n",customerCharge);
    printf("Estimated Time: %.2f hours\n",deliveryTime);
    printf("\n----------------------------------------------------------\n");
}

void findingTheLeastCostRoute(int startIndex, int endIndex)
{
    if(cityCount>4)
    {
        printf("Route search limited to 4 cities only.\n");
        return;
    }

    int citiesToVisit[4];
    for(int i=0,j=0;i<cityCount;i++)
    {
       if(i!=startIndex && i!=endIndex)citiesToVisit[j++] = i;
    }

    int minDistance = INT_MAX;
    int bestRoute[4];

    for(int i=0;i<cityCount-2;i++)
    {
         for(int j=0;j<cityCount-2;j++)
         {
             if(i==j)continue;
            int totalDist=distance[startIndex][citiesToVisit[i]]+distance[citiesToVisit[i]][citiesToVisit[j]]+distance[citiesToVisit[j]][endIndex];
            if(totalDist<minDistance)
            {
                minDistance=totalDist;
                bestRoute[0]=startIndex;
                bestRoute[1]=citiesToVisit[i];
                bestRoute[2]=citiesToVisit[j];
                bestRoute[3]=endIndex;
            }
         }
    }

    printf("The Least-Cost Route(Least-Distance): ");
    for(int i=0;i<cityCount;i++)
    {
        printf("%s to ",cities[bestRoute[i]]);
    }
    printf("\nMinimum Distance: %d km\n",minDistance);

}


void performanceReport()
{
    if (deliveryCount == 0)
    {
        printf("\nNo deliveries have been completed yet....\n");
        return;
    }

    float totalDistance=0,totalTime=0,totalRevenue=0,totalProfit=0;
    float longestDistance=0,shortestDistance=1e9;

    for (int i=0;i<deliveryCount;i++)
    {
        totalDistance+=deliveries[i].distance;
        totalTime+=deliveries[i].deliveryTime;
        totalRevenue+=deliveries[i].customerCharge;
        totalProfit+=deliveries[i].profit;

        if (deliveries[i].distance>longestDistance)
            longestDistance=deliveries[i].distance;
        if (deliveries[i].distance<shortestDistance)
            shortestDistance=deliveries[i].distance;
    }
    float avgTime=totalTime/deliveryCount;

    printf("\n---------------------------------------------------\n");
    printf("PERFORMANCE REPORT\n");
    printf("------------------------------------------------------\n");
    printf("Total Deliveries Completed : %d\n",deliveryCount);
    printf("-----------------------------------------------------\n");
    printf("Total Distance Covered      : %.2f km\n",totalDistance);
    printf("Average Delivery Time       : %.2f hours\n",avgTime);
    printf("-----------------------------------------------------\n");
    printf("Total Revenue               : %.2f LKR\n",totalRevenue);
    printf("Total Profit                : %.2f LKR\n",totalProfit);
    printf("-----------------------------------------------------\n");
    printf("Longest Route Distance      : %.2f km\n",longestDistance);
    printf("Shortest Route Distance     : %.2f km\n",shortestDistance);
    printf("-----------------------------------------------------\n");
}
