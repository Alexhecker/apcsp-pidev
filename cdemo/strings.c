#include <stdio.h>
#include <string.h>

int main()
{

  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char str2[27];
  char str3[53];
  char a ='a';


  for (int i = 0; i < 26; i++)
  {
	str2[i] = a;
	a++;
  }
  str2[26] = 0;
  printf("str1 = %s; str2 = %s\n", str1, str2);


  if (strcmp(str1, str2) == 0)
	printf("Strings identical.\n");
  else
	printf("Strings different.\n");
  printf("%s \n %s \n", str1, str1);


  for (int i = 0; i < 26; i++)
  {
	str2[i] = a - 58;
	a ++;
  }
  printf("\nstr1 = %s; str2 = %s\n", str1, str2);

  if (strcmp(str1, str2) == 0)
  	printf("Strings identical.\n");
  else
	printf("Strings different.\n");

  strcpy(str3, str1);
  strcat(str3, str2);
  printf("\nstr1 = %s \nstr2 = %s \nstr3 = %s\n", str1, str2, str3);

}
