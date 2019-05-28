
#include <stdio.h>
int arrayAdd(int arr[], int n, int s);
int arr[100];
int main()
{


//size_t s = sizeof(arr)/sizeof(arr[0]);
//int i;

for(int i  = 0; i < 100; i++)
{
        arr[i] = i * i;
        printf("Area of %d is %d\n", i, arr[i]);
}

//printf("1st and 3rd vals: %d, %d\n", arr[0], arr[2]);

//printf("Or %d, %d\n", *arr, *(arr+2));
arrayAdd( arr, 5, 100);

for(int i=0; i<100;i++){
  printf("New Area of %d is %d\n", i, arr[i]);
}
}

int arrayAdd(int arr[], int n, int s){


for(int i = 0; i < s; i++)
{
arr[i] = arr[i] + n;
}
return 0;
}






