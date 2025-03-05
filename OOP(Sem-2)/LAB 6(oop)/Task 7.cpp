#include <iostream>
using namespace std;
class Device {
protected:
    string deviceName;
    string powerStatus;

public:
    Device(string name) : deviceName(name), powerStatus("OFF") {}

    virtual void turnOn() = 0;  
    virtual void turnOff() {
        powerStatus = "OFF";
        cout << deviceName << " is now " << powerStatus << "." << endl;
    }
};

class SmartLight : virtual public Device {
public:
    SmartLight(string name) : Device(name) {}

    void turnOn() override {
        powerStatus = "ON";
        cout << deviceName << " is " << powerStatus << " with adjustable brightness." << endl;
    }
};

class SmartFan : virtual public Device {
public:
    SmartFan(string name) : Device(name) {}

    void turnOn() override {
        powerStatus = "ON";
        cout << deviceName << " is " << powerStatus << " at medium speed." << endl;
    }
};
class SmartRoom : public SmartLight, public SmartFan {
public:
    SmartRoom(string lightName, string fanName) 
        : SmartLight(lightName), SmartFan(fanName), Device("Smart Room") {}

    void turnOn() override {
        SmartLight::turnOn();  
        SmartFan::turnOn();    
        cout << "Smart Room is now fully activated!" << endl;
    }

    void deactivateRoom() {
        SmartLight::turnOff();
        SmartFan::turnOff();
    }
};

int main() {
    SmartRoom room("Smart Light", "Smart Fan");
    room.turnOn();
    room.deactivateRoom();

    return 0;
}

