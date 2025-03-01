#include<iostream>
#include<string>
using namespace std;

class Users{
	public:
	string name;
	int age;
	string licenseType;
	long int contactInfo;
	int userId;
		void updateInfo();
		void registerInfo();
};

class Vehicle{
	public:
	string model;
	float rentalPrice;
	string eligibility;
		void display();
		void check(Users &u);
};

class Rental{
	Vehicle *v1;
	int num;
	public:
		Rental(){
			cout<<"The number of vehicle: ";
			cin>>num;
			v1=new Vehicle[num];
		}
	void iniatilize();
	void rent(Users &u);
	void modifyDetail();
		
		~Rental(){
			delete[] v1;
		}
};



void Users::updateInfo(){
	cout<<"Enter name: ";
	getline(cin,name);
	cout<<"Enter Age: ";
	cin>>age;
	cout<<"Enter License Type(e.g., Learner, Intermediate, Full): ";
	cin>>licenseType;
	cout<<"Enter Contact number: ";
	cin>>contactInfo;
	cout<<"Enter user Id: ";
	cin>>userId;
}

void Vehicle::check(Users &u){
	if(u.licenseType==eligibility){
		cout<<"The per day rent of car model "<<model<<" is "<<rentalPrice<<endl;
	}
	else{
		cout<<"You are not eligile for car model "<<model<<endl;
	}
}
void Vehicle::display(){
	cout<<"The model is "<<model<<endl;
	cout<<"The per day rent is "<<rentalPrice<<endl;
	cout<<"The eligibility criteria is "<<eligibility<<endl<<endl;
}
void Users::registerInfo(){
	cin.ignore();
	cout<<"                   ---------------USER INFORMATION------------"<<endl;
	cout<<"Enter name: ";
	getline(cin,name);
	cout<<"Enter Age: ";
	cin>>age;
	cout<<"Enter License Type(e.g., Learner, Intermediate, Full): ";
	cin>>licenseType;
	cout<<"Enter Contact number: ";
	cin>>contactInfo;
	cout<<"Enter user Id: ";
	cin>>userId;
}

void Rental::modifyDetail(){
	string name;
	for(int i=0;i<num;i++){
		cout<<i+1<<":"<<v1[i].model<<endl;
	}
	cout<<"Enter name of vehicle to modify details: ";
	getline(cin,name);
	for(int i=0;i<num;i++){
		if(name==v1[i].model){
			cout<<"              --------------------FOR CAR "<<v1[i].model<<"-----------------------"<<endl;
			cout<<"Enter rental price: ";
			cin>>v1[i].rentalPrice;
			cout<<"Enter Eligibility criteria(e.g., Learner, Intermediate, Full): ";
			cin>>v1[i].eligibility;
		}
	}
}

void Rental::rent(Users &u){
	int choice;
	cout<<"    Vehicle list: "<<endl;
	for(int i=0;i<num;i++){
		cout<<i+1<<":"<<v1[i].model<<endl;
	}
	cout<<endl<<"Enter the car number to rent: ";
	cin>>choice;
	for(int i=0;i<num;i++){
		if(choice-1==i){
			v1[i].check(u);
	    }
	}
}

void Rental::iniatilize(){
	cin.ignore();
	for(int i=0;i<num;i++){
		cout<<"Enter model: ";
		getline(cin,v1[i].model);
		cout<<"Enter rental price: ";
		cin>>v1[i].rentalPrice;
		cin.ignore();
		cout<<"Enter eligibility: ";
		cin>>v1[i].eligibility;
		cin.ignore();
	}
}


int main(){
	int choice;
	Rental r1;
	Users u1;
	u1.registerInfo();
	cout<<"        -------------------------------MENU-------------------------------"<<endl;
	cout<<"        1: Iniatialize Vehicle"<<endl;
	cout<<"        2: Modify Detail"<<endl;
	cout<<"        3: Update user information"<<endl;
	cout<<"        4: Rent a car"<<endl;
	cout<<"        5: Exit"<<endl;
	
	do{
		cout<<"        Enter choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				r1.iniatilize();
				break;
			case 2:
				r1.modifyDetail();
				break;
			case 3:
				u1.updateInfo();
				break;
			case 4:
				r1.rent(u1);
				break;
		}
	}while(choice!=5);
}

	

