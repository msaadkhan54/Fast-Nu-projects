#include<iostream>
using namespace std;

class Transport{
		string vehicletype;
		int capacity;
		public:
			Transport(string v,int c):vehicletype(v),capacity(c){}
			void detailBase(){
				cout<<"=== Hybrid Vehicle Details ==="<<endl;
				cout<<"Vehicle type: "<<vehicletype <<endl;
				cout<<"Max capacity: "<<capacity<<" passenger"<<endl;
			}
};

class roadTransport:virtual public Transport{
	public:
		roadTransport(string r,string v,int c):roadtype(r),Transport(v,c){}
		string roadtype;
		void detailRoad(){
			cout<<"Road type: "<<roadtype<<endl;
		}
};
class airTransport:virtual public Transport{
	public:
		int altitude;
		airTransport(int a,string v,int c):altitude(a),Transport(v,c){}
		void detailAir(){
			cout<<"Altitude: "<<altitude<<" feet"<<endl;
		}
};
class hybridVehicle:public roadTransport,public airTransport{
	public:
		hybridVehicle(float f,string r,int a,string v,int c):fuelEfficency(f),roadTransport(r,v,c),
		airTransport(a,v,c),Transport(v,c){}
		float fuelEfficency;
		void detailHybrid(){
			cout<<"Fuel Efficency: "<<fuelEfficency<<"Km/L"<<endl;
		}
		
};

int main(){
	hybridVehicle h1(15.5,"SUV",10000,"Hybrid",5);
	h1.detailBase();
	h1.detailRoad();
	h1.detailAir();
	h1.detailHybrid();
}
