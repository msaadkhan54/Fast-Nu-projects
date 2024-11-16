#include<stdio.h>
#include<math.h>
int main(){
	int r;
	printf("Enter the radius of circle for the calculation of the area\n");
	scanf("%d", &r);
	float area=M_PI*r*r;
	printf("The Area of the circle is %.2f",area);
}
