#include<stdio.h>

int main()
{
    float speed, time, distance;
    printf("put the values of average speed and the time you drove: ");
    scanf("%f%f", &speed, &time);

    // the rendiment of the car is 12 km/l 
    distance = speed * time;

    printf("your fuel spent was %.3f", distance / 12);
    return 0;
}
