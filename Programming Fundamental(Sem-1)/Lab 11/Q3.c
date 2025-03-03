#include<stdio.h>
#include<string.h>
struct Courses{
	int code;
	char courseName[50];
	char instructor[50];
};
struct students{
	int rollNum;
	char name[50];
	struct Courses course[10];
};

int update(int num){
	int rollNum,numCourses,consider=0,i,j,found;
	struct students update;
	FILE *file=fopen("students.dat","rb");
	FILE *ptr=fopen("temp.dat","wb");
	
	printf("Enter the Roll num:");
	scanf("%d",&rollNum);	
		if(file==NULL || ptr==NULL)
	{
	    printf("ERROR");
	    return 0;
	}
	while(fread(&update,sizeof(struct students),1,file))
	{
		if(update.rollNum==rollNum)
		{
			found=1;
		
	    	printf("Enter Student %d\nName:",i+1);
	    	scanf("  %[^\n]s",update.name);
		
	    	printf("Roll number:");
    		scanf("%d", &update.rollNum);
		
    		printf("Number of courses:");
	    	scanf("%d", &numCourses);
    		if(numCourses>consider)
	    	consider=numCourses;
	    	
		for(j=0;j<numCourses;j++)
		{
			printf("Enter cousere %d\nName:",j+1);
			scanf("  %[^\n]s",update.course[j].courseName);
			
			printf("Code:");
			scanf("%d", &update.course[j].code);
			
			printf("Instructor:");
			scanf("  %[^\n]s",update.course[j].instructor);	
		}
		}
		fwrite(&update,sizeof(struct students),1,ptr);
	}
	if(found){
		printf("Updated successfully");
		remove("students.dat");
		rename("temp.dat","students.dat");
	}
	else
	printf("Not updated");
	fclose(ptr);
	fclose(file);
}

int main(){
	int num,numCourses,consider=0,maths=0,physics=0,urdu=0,english=0,history=0,chemistry=0;
	FILE *file=fopen("students.dat","wb");
	if(file==NULL)
	{
	    printf("ERROR");
	    return 0;
	}
	int i,j;
	struct students s1[100];
	printf("Enter number of students:");
	scanf("%d", &num);
	for(i=0;i<num;i++)
	{
		printf("Enter Student %d\nName:",i+1);
		scanf("  %[^\n]s",s1[i].name);
		
		printf("Roll number:");
		scanf("%d", &s1[i].rollNum);
		
		printf("Number of courses:");
		scanf("%d", &numCourses);
		if(numCourses>consider)
		consider=numCourses;
		for(j=0;j<numCourses;j++)
		{
			printf("Enter cousere %d\nName:",j+1);
			scanf("  %[^\n]s",s1[i].course[j].courseName);
			
			printf("Code:");
			scanf("%d", &s1[i].course[j].code);
			
			printf("Instructor:");
			scanf("  %[^\n]s",s1[i].course[j].instructor);	
		}
	}
	for(i=0;i<num;i++)
	{
		fwrite(&s1[i],sizeof(struct students),1,file);
	}
	fclose(file);
	
	file=fopen("students.dat","rb");
		if(file==NULL)	
	{
	    printf("ERROR");
	    return 0;
	}
	i=0;
	struct students temp;
	while(fread(&temp,sizeof(struct students),1,file))
	{
		printf("Student %d\n",i+1);
		for(i=0;i<consider;i++)
		{
			if(strcmp(temp.course[i].courseName,"maths")==0)
			maths++;
			if(strcmp(temp.course[i].courseName,"physics")==0)
			physics++;
			if(strcmp(temp.course[i].courseName,"english")==0)
			english++;
			if(strcmp(temp.course[i].courseName,"urdu")==0)
			urdu++;
			if(strcmp(temp.course[i].courseName,"chemistry")==0)
			chemistry++;
			if(strcmp(temp.course[i].courseName,"history")==0)
			history++;
			printf("%s,",temp.course[i].courseName);
		}
		printf("\n");
		i++;
	}
	if(maths!=0)
	printf("The Students inrolled in Maths %d\n",maths);
	if(physics!=0)
	printf("The Students inrolled in physics %d\n",physics);
	if(chemistry!=0)
	printf("The Students inrolled in Chemistry %d\n",chemistry);
	if(urdu!=0)
	printf("The Students inrolled in Urdu %d\n",urdu);
	if(english!=0)
	printf("The Students inrolled in English %d\n",english);
	if(history!=0)
	printf("The Students inrolled in History %d\n",history);
	fclose(file);
	printf("For updating:\n");
	update(num);
}
