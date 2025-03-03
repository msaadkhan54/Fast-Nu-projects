#include<stdio.h>
#include <stdlib.h>


typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;


typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    Weather *weather; 
} Crop;


typedef struct {
    char equipmentType[50];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[100];
} Equipment;


typedef struct {
    float soilNutrients;
    float pHLevel;
    int pestActivity; 
} Sensor;


typedef struct {
    float gpsLatitude;
    float gpsLongitude;
    float soilHealth;
    float moistureLevel;
    int numCrops;
    int numEquipment;
    int numSensors;
    Crop *crops;       
    Equipment *equipment;
    Sensor *sensors;   
} Field;


typedef struct {
    int numFields;
    Field *fields;     
    float aggregateYieldPrediction;
    float resourceDistribution;
    char emergencyResponsePlan[100];
} RegionalHub;


int main(){
	int i,j;
	RegionalHub hub;
	
	printf("Enter the number of feilds: ");
	scanf("%d",&hub.numFields);
	
	Field f[hub.numFields];
	
	for(i=0;i<hub.numFields;i++){
		printf("Enter gpsLatitude,gpsLongitude,soilHealth and moistureLevel for feild '%d': \n",i+1);
		scanf("%f %f %f %f", &f[i].gpsLatitude,&f[i].gpsLongitude,&f[i].soilHealth,&f[i].moistureLevel);
		
		printf("Enter number of crops in feild %d: ",i+1);
		scanf("%d",&f[i].numCrops);
		f[i].crops=(Crop*)malloc(f[i].numCrops*sizeof(Crop));
		for(j=0;j<f[i].numCrops;j++)
		{
			printf("Crop type: ");
			scanf("%s",f[i].crops[j].cropType);
			
			printf("Growth Stage: ");
			scanf("%s",f[i].crops[j].growthStage);
			
			printf("Expected Yeild: ");
			scanf("%f",&f[i].crops[j].expectedYield);
			
		    f[i].crops[j].weather=(Weather*)malloc(sizeof(Weather));
		    printf("Temprature: ");
		    scanf("%f",&f[i].crops[j].weather[0].temperature);
		    
		    printf("Rainfall: ");
		    scanf("%f",&f[i].crops[j].weather[0].rainfall);
		    
		    printf("Wind speed: ");
		    scanf("%f",&f[i].crops[j].weather[0].windSpeed);
		}
		printf("Enter equipments: ");
		scanf("%d",&f[i].numEquipment);
		f[i].equipment=(Equipment*)malloc(f[i].numEquipment*sizeof(Equipment));
		for(j=0;j<f[i].numEquipment;j++)
		{
			printf("Equipment type: ");
			scanf("%s",f[i].equipment[j].equipmentType);
			
			printf("Operational Status: ");
			scanf("%d",&f[i].equipment[j].operationalStatus);
			
			printf("fuel Level: ");
			scanf("%f",&f[i].equipment[j].fuelLevel);
			
			printf("Activity Schedule: ");
			scanf("%s",f[i].equipment[j].activitySchedule);
		}
		printf("Enter Sensors: ");
		scanf("%d",&f[i].numSensors);
		f[i].sensors=(Sensor*)malloc(f[i].numSensors*sizeof(Sensor));
		for(j=0;j<f[i].numSensors;j++)
		{
			printf("Soiul Nutrients: ");
			scanf("%f",&f[i].sensors[j].soilNutrients);
			
			printf("Ph Level: ");
			scanf("%f",&f[i].sensors[j].pHLevel);
			
			printf("Pest Activity: ");
			scanf("%d",&f[i].sensors[j].pestActivity);
		}
	}
	printf("Enter aggregateYieldPrediction: ");
	scanf("%f",&hub.aggregateYieldPrediction);
	
	printf("Enter resourceDistribution: ");
	scanf("%f",&hub.resourceDistribution);
	
	printf("Enter Emergency response plan: ");
	scanf("  %[^\n]",&hub.emergencyResponsePlan);
	
	for(i=0;i<hub.numFields;i++)
	{
		printf("gpsLatitude:%f\tgpsLongitude:%f\tsoilHealth:%f\tmoistureLevel:%f\n", f[i].gpsLatitude,f[i].gpsLongitude,f[i].soilHealth,f[i].moistureLevel);
		for(j=0;j<f[i].numEquipment;j++)
		{
			printf("cropType:%s\tgrowthStage:%s\texpectedYield:%f\t\nweather:%f\trainfall:%f\twindSpeed:%f\n",f[i].crops[j].cropType,f[i].crops[j].growthStage,f[i].crops[j].expectedYield,f[i].crops[j].weather[0].temperature,f[i].crops[j].weather[0].rainfall,f[i].crops[j].weather[0].windSpeed);	
	    }
	    	for(j=0;j<f[i].numEquipment;j++)
		{
			printf("equipmentType:%s\t",f[i].equipment[j].equipmentType);
			
		    printf("operationalStatus:%d\t",&f[i].equipment[j].operationalStatus);
			
			printf("fuelLevel:%f\t",&f[i].equipment[j].fuelLevel);
			
			printf("activitySchedule:%s\n",f[i].equipment[j].activitySchedule);
		}
		for(j=0;j<f[i].numSensors;j++)
		{
			printf("soilNutrients:%f\t",&f[i].sensors[j].soilNutrients);

			printf("pHLevel:%f\t",&f[i].sensors[j].pHLevel);
			
			printf("pestActivity:%d\n",&f[i].sensors[j].pestActivity);
		}
		for(i=0;i<hub.numFields;i++){
		for (j = 0; j < f[i].numCrops; j++) {
        free(f[i].crops[j].weather);
		free(f[i].crops);   
        free(f[i].equipment); 
        free(f[i].sensors);  
        }
    }

	}

}
