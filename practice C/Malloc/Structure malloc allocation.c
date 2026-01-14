#include<stdio.h>
 #include <stdlib.h>
 struct student
 {
 char name[20]; float marks; int batch; char city; int roll_num;
 };
 int main()
 {
   struct student *ptr;   int i,n;
   printf("Enter the number of students: ");
   scanf("%d", &n);
   ptr = (struct student *) malloc(n * sizeof(struct student));
   for(i=0; i<n; i++)
     {
  printf("Enter your name :");     scanf("%s", ptr[i].name);
  printf("Enter your marks:");     scanf("%f", &ptr[i].marks);                 
  printf("Enter your batch:");     scanf("%d", &ptr[i].batch);
//  printf("Enter your name :");     scanf("%s", (ptr+i)->name);
//  printf("Enter your marks:");     scanf("%f", &(ptr+i)->marks);                 
//  printf("Enter your batch:");     scanf("%d", &(ptr+i)->batch);
     }
   free(ptr); // deallocating the memory
   return 0;}
