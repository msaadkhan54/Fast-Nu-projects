#include <stdio.h>
 struct student
 {
 char name[20]; float marks; int batch; char city; int roll_num;
 };
 void getStudentData(struct student *ptr) { 
     
printf("Enter your name :");     scanf("%s", (ptr)->name);
  printf("Enter your marks:");     scanf("%f", &(ptr)->marks);                 
  printf("Enter your batch:");     scanf("%d", &(ptr)->batch);
  printf("Enter your city:");      scanf(" %c",&(ptr )->city);
  printf("Enter your roll_num:");  scanf("%d", &(ptr )->roll_num);
 }
 int main()
 {
 	int i;
  struct student student1[2];
  //ptr=&student1;  
 for( i=0;i<2;i++)
  getStudentData(&student1[i]);
  for( i=0;i<2;i++){
  printf("\nYour data is\nName : %s \nMarks : %f\nBatch :  %d\nCity:%c\nRoll Number :%d", student1[i].name, student1[i].marks,   student1[i].batch,student1[i].city,student1[i].roll_num);  }
  return 0;
 }
