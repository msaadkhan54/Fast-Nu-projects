#include<iostream>
#include<string>
using namespace std;
class Vehicle;
class OperatorControl{
public:
	string meal;
	string action;
    void command(string actio, string packageID){
        cout<<"Command for: "<<actio<<" for package "<<packageID<<"\n";
        action=actio;
    }

    void command(string actio, string packageID, string mealt){
        cout<<"Command for: "<<mealt<<" for package "<<packageID<<" with urgency "<<actio<<"\n";
        action=actio;
        meal=mealt;
    }
    void compareVehicle( Vehicle *v1,Vehicle *v2,Vehicle *v3);
};

class Vehicle{
	int id;
	string status;
	int speed;
	int capacity;
	string efficency;
	public:
		static int totalDeliveries;
		Vehicle(){
			
		}
		Vehicle(int i,int s,int c,string eff,string stat):id(i),status(stat),speed(s),capacity(c),efficency(eff){}
		virtual void deliveryRoute(string action,string mealType){
			cout<<"Difference in route for each vehicle\n";
		}
		virtual void deliveryTime(){
			cout<<"Depend upon distance and vehicle\n";
		}
		friend void OperatorControl::compareVehicle( Vehicle *v1,Vehicle *v2,Vehicle *v3);
		void operator==(const Vehicle &v) const{
			if(speed==v.speed){
				cout<<"Both have same speed\n";
			}
			if(capacity==v.capacity){
				cout<<"Both have same capacity\n";
			}
			if(efficency==v.efficency){
				cout<<"Both have same efficency\n";
			}
		}
};

int Vehicle::totalDeliveries;

class RamzanDrone:public Vehicle{
	public:
		RamzanDrone(int i,int s,int c,string eff,string stat="none"):Vehicle(i,s,c,eff,stat){}
		void deliveryRoute(string action,string mealType="none") {
			int weight;
			cout<<"Enter meal weight in Kg: ";
			cin>>weight;
			if(weight<=5){
				cout<<"Perfect weight\n";
				if(action=="urgent"){
					cout<<"Drone is ready to deliver this urgent meal.Calculating route for high speed delivery\n";
					totalDeliveries++;
					deliveryTime();
				}
				else if(mealType=="iftar" || mealType=="sehri"){
					cout<<"Drone is ready to deliver this iftar/sehri meal.\n***Calculating route for high speed delivery***\n";
					totalDeliveries++;
					deliveryTime();
				}
				
			}
			else{
				cout<<"Over weight\n";
				cout<<"No delivery\n";
			}
		}
		void deliveryTime(){
			int range;
			cout<<"Enter the distance in KM: ";
			cin>>range;
			if(range<=5){
				cout<<"Meal will be delivered in 5 minutes\n";
			}
			else{
				cout<<"Meal will be delivered in 10-15 minutes\n";
			}
		}
};

class RamzanTimeShip:public Vehicle{
	public:
		RamzanTimeShip(int i,int s,int c,string eff,string stat="none"):Vehicle(i,s,c,eff,stat){}
		void deliveryRoute(string action,string mealType="none") {
			if(action=="urgent" && (mealType!="iftar" || mealType!="sehri")){
				cout<<"Ready to deliver.Calculating delivery route\n";
				totalDeliveries++;
				deliveryTime();
			}
			else{
				cout<<"Ignores the delivery\n";
			}
		}
		void deliveryTime(){
			int range;
			cout<<"Enter the distance in KM: ";
			cin>>range;
			if(range<=10){
				cout<<"Meal will be delivered in 10 minutes\n";
			}
			else{
				cout<<"Meal will be delivered in 15 minutes\n";
			}
		}
};

class RamzanHyperPod:public Vehicle{
	public:
		RamzanHyperPod(int i,int s,int c,string eff,string stat="none"):Vehicle(i,s,c,eff,stat){}
		void deliveryRoute(string action="none",string mealType="none") {
			cout<<"It doesnot bother if is urgent or not or it is iftar/sehri\n";
			int weight;
			cout<<"Enter meal weight in Kg: ";
			cin>>weight;
			if(weight>6){
				cout<<"Perfect weight\n";
				cout<<"Ready for delivery.\n***Calculating underground distance***\n";
				deliveryTime();
			}
			else{
				cout<<"Under weight\n";
			}
		}
		void deliveryTime(){
			int range;
			cout<<"Enter the distance in KM: ";
			cin>>range;
			if(range<=20){
				cout<<"Meal will be delivered in 10 minutes\n";
			}
			else{
				cout<<"Meal will be delivered in 20-25 minutes\n";
			}
		} 
};


void OperatorControl:: compareVehicle( Vehicle *v1, Vehicle *v2, Vehicle *v3){
    	int id;
    	cout<<"Check Vehicle with id: "<<v1->id<<endl;
    	v1->deliveryRoute(action,meal);cout<<endl<<endl;
    	
    	cout<<"Check Vehicle with id: "<<v2->id<<endl;
    	v2->deliveryRoute(action,meal);cout<<endl<<endl;
    	
    	cout<<"Check Vehicle with id: "<<v3->id<<endl;
    	v3->deliveryRoute(action,meal);cout<<endl<<endl;
		
		cout<<"Now according to details enter id of vehicle which suits you the most: ";
		cin>>id;
		cout<<"Vehicle "<<id<<" is ready to deliver\n";
	}

int main(){
	
	cout<<"********** Muhammad Saad Khan 24K-0680 **************"<<endl<<endl;
	Vehicle *v1;
	Vehicle *v2;
	Vehicle *v3;
	
	RamzanDrone drone(101,45,3,"Fast");
	RamzanTimeShip timeShip(102,34,3,"Medium");
	RamzanHyperPod hyperPod(103,25,4,"Slow");
	
	OperatorControl control;
	
	v1=&drone;
	v2=&timeShip;
	v3=&hyperPod;
	
	control.command("urgent","204","iftar");
	cout<<"1: Drone"<<endl;
	cout<<"2: Time Ship"<<endl;
	cout<<"3: Hyper Pod"<<endl;
	cout<<"4: Comparing vehicles and then deciding"<<endl;
	cout<<"5: Exit"<<endl;
	int ch;
	do{
		cout<<"Enter choice: ";
		cin>>ch;
		if(ch==1){
			drone.deliveryRoute(control.action,control.meal);
		}
		else if(ch==2){
			timeShip.deliveryRoute(control.action,control.meal);
		}
		else if(ch==3){
			hyperPod.deliveryRoute();
		}
		else if(ch==4){
			control.compareVehicle(v1,v2,v3);
			cout<<endl<<"Comparing vehicle based on capacity,speed and efficency: "<<endl;
			*v1==*v2;cout<<endl;
		}
	}while(ch!=5);
	
	
	control.command("No urgent","206");
		cout<<"1: Drone"<<endl;
	cout<<"2: Time Ship"<<endl;
	cout<<"3: Hyper Pod"<<endl;
	cout<<"4: Comparing vehicles and then deciding"<<endl;
	cout<<"5: Exit"<<endl;
	do{
		cout<<"Enter choice: ";
		cin>>ch;
		if(ch==1){
			drone.deliveryRoute(control.action,control.meal);
		}
		else if(ch==2){
			timeShip.deliveryRoute(control.action,control.meal);
		}
		else if(ch==3){
			hyperPod.deliveryRoute();
		}
		else if(ch==4){
			control.compareVehicle(v1,v2,v3);
			cout<<endl<<"Comparing vehicle based on capacity,speed and efficency: "<<endl;
			*v1==*v2;cout<<endl;
		}
	}while(ch!=5);
}
