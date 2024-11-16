#include<stdio.h>
struct student{
	int id;
	char name[20];
	float marks;
};

void print(struct student a){
	printf("%d\n%s\n%.2f", a.id,a.name,a.marks);
}
int main(){
	struct student s1={123,"Saad",86.23};
	print(s1);
}