#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
float b;
float number1;
float number2;
float smaller; 
float larger; 
char input[256], name[256]; 
char input2[256], name2[256];
float getnumber();
float getnumber2();
float area(float area);
int main(){

float one = getnumber();
float two = getnumber2();

if(two>one){
smaller = one; 
larger = two; 
}
else{
smaller = two;
larger = one;
}
for(float r=smaller; r< larger;r++){
b = area(r);
printf("Value b - %f\n", b);
} 
printf("End of Output\n");
}
float area(float area){
  int b =0;
  b = area * area * 3.14; 
  return b;
}

float getnumber(){
int test = 0;
while(test==0){
printf("Give me a number to calculate the area\n");
fgets(input, 256, stdin);
sscanf(input,"%s", name); 
printf("First number is %s\n", name);
 number1 = atof(name);
if(number1!= 0){
test=1;
}
else if(number2==0){
  printf("Input is not a number or is blank, so number is set to 3.5\n");
  number1 = 3.5;
  test = 1;
}
else{
printf("That is not a number! Please input a number!\n");
}
}
return number1; 
}
float getnumber2(){
int test = 0;
while(test==0){
printf("Give me a second number to calculate the area\n");
fgets(input2, 256, stdin);
sscanf(input2,"%s", name2); 
printf("Second number is %s\n", name2);
number2 = atof(name2);
if(number2!=0){
test=1;
}
else if(number2 ==0){
printf("Input is not a number or is blank, so number is set to 12.5\n");
number2 = 12.5;
test = 1;

}
else{
printf("That is not a number! Please input a number!\n");
}
}
return number2; 
}
