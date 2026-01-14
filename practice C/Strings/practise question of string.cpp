#include <stdio.h>
int main()
{ int i;
 char language[5][10] = {
 {'J','a','v','a','\0'}, {'P','y','t','h','o','n','\0'},
 {'C','+','+','\0'}, {'H','T','M','L','\0'},
 {'S','Q','L','\0'} };

 for(i=0; i<5; i++)
 printf("%s\n", language[i]);
 return 0;
}
