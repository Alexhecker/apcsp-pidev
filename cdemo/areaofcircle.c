/*
 * C program to find the area of a circle, given the radius
 */
#include <stdio.h>

float b;
float area (float r);
int main(){
for(float r=3.5; r< 12.6;r++){
b = area(r);
printf("Value b - %f\n", b);
}
}

float area(float r)
{
float a;
a = r * r * 3.14;
 
return a;
}

