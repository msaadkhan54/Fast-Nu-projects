// Online C compiler to run C program online
#include <stdio.h>
struct bank{
  int acc_num;
  char name[20];
  int balance;
};
int main() {
    int i;
   struct bank customer[2];
   for(i=0;i<2;i++)
      {
          scanf("%d %s %d", &customer[i].acc_num, &customer[i].name, &customer[i].balance);
      }
     for(i=0;i<2;i++)
        {
            printf("%d\n%s\n%d\n",customer[i].acc_num, customer[i].name, customer[i].balance);
        }
    return 0;
}
