#include<iostream>
using namespace std;
class HomeAssistant;
class EnergyMonitor;
class SmartDevice{
	string deviceName;
	int powerUsage;
	bool status;
	public:
		SmartDevice(string n,int u,bool s=false):deviceName(n),powerUsage(u),status(s){
		}
		friend HomeAssistant;
		friend EnergyMonitor;
};

class HomeAssistant{
	int consumption;
	public:
		HomeAssistant():consumption(0){}
		void updateStatus(SmartDevice &s){
			
			consumption+=s.powerUsage;
			
			int input;
			cout<<"Enter '1' to onn and '0' to off: ";
			cin>>input;
			if(input==1){
				s.status=true;
			}
			else if(input==0){
				s.status=false;
			}
		}
		friend EnergyMonitor;
};
class EnergyMonitor{
	public:
		void totalConsumption(SmartDevice s1,HomeAssistant h1){
			cout<<"The device name is '"<<s1.deviceName<<"' and consumption is "<<h1.consumption<<endl;
		}
};
int main(){
	SmartDevice s1("LED light",43);
	HomeAssistant h1;
	h1.updateStatus(s1);
	EnergyMonitor e1;
	e1.totalConsumption(s1,h1);
}
