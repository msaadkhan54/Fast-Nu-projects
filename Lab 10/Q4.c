#include<stdio.h>
struct movie{
	char name[20];
	char genre[20];
	char director[20];
	int rel_year;
	float rating;
};

void display(struct movie a[],int count){
	int i;
	for(i=0;i<count;i++){
		if(a[i].rel_year==0){
			continue;
		}
		printf("Title=%s, Genre=%s, Director=%s, Release Date=%d, Rating=%.1f\n\n",a[i].name,a[i].genre,a[i].director,a[i].rel_year,a[i].rating);
	}
}

void search(struct movie bio[],int count){
	char movie[20];
	int flag=0,i;
	printf("Enter the Movie Name.\n");
	scanf("%s",movie);
	for(i=0;i<count;i++){
		if(strcmp(bio[i].name,movie)==0){
			flag=1;break;
		}
	}
	if(flag){
		printf("The movie '%s'is available\n",bio[i].name);
	}
}

int add(struct movie a[],int count){
	int i;
	for(i=0;i<count;i++){
	if(a[i].rel_year==0){
	    printf("Enter Title\n");
		scanf("  %[^\n]s", a[i].name);
		
		printf("Enter the Genre\n");
	    scanf("  %[^\n]s",a[i].genre);
		
		printf("Enter the Director\n");
		 scanf("  %[^\n]s",a[i].director);
		
		printf("Enter the Release Year\n");
		scanf("%d", &a[i].rel_year);
		
		printf("Enter Rating\n");
		scanf("%f", &a[i].rating);
		printf("Movie added Successfully\n\n\n");
		
		break;}
    }
    return;
}

int main(){
	struct movie bio[5]={{"Titanic","Real_story","David",2001,4.1},
	                     {"3 Idiot","Fiction","Saad",2023,4.6},
	                     {"Josh","Non-Fiction","Fatima",2006,3.6},
	                     {"Big Hero","Fiction","Yousuf",2012,4.0},
	                     {"","","",0,0.0}
	};
	int ch;
	int count=sizeof(bio)/sizeof(bio[0]);
	printf("1:Display\n2:Add Movie\n3:Search Movie\n4:Exit\n");

	printf("Enter number 1-4! anyone:");
	scanf("%d", &ch);
	
	switch(ch){
		case 1:
			display(bio,count);
			break;
		case 2:
		    add(bio,count);
		    display(bio,count);
			break;
		case 3:
		    search(bio,count);
			break;
		case 4:
			printf("Program has ended\n");
			break;
		default:
		    printf("Invalid input\n");	
	    }
}
