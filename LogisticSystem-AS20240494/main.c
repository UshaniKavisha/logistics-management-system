#include <stdio.h>
#include <stdlib.h>
#define MAX_CITIES 30

char cities[MAX_CITIES][40];
int cityCount=0;
void addCity();

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

}
