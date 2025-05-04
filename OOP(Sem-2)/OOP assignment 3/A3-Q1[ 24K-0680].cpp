#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
class Drivers;
class Vehicle;
class Route;
class Transporters;

class Route {
	private:
	    static const float LONG_ROUTE_THRESHOLD;
	    char startPositions[20];
	    char endPositions[20];
	    float distanceCovered;
	    bool isLongRoute;
	public:
	    Route() : distanceCovered(0), isLongRoute(false) {}
	    Route(const char* start, const char* end, float dist) {
	        strcpy(startPositions, start);
	        strcpy(endPositions, end);
	        distanceCovered = dist;
	        isLongRoute = (distanceCovered > LONG_ROUTE_THRESHOLD);
	    }
	    
    	void enterRoutes() {
	        cout << "Enter start position: ";
	        cin  >> startPositions;
	        cout << "Enter end position: ";
	        cin  >> endPositions;
	        cout << "Distance covered(km): ";
	        cin  >> distanceCovered;
	        isLongRoute = (distanceCovered > LONG_ROUTE_THRESHOLD);
	    }
	    
	    void save(ostream& out) {
	        out.write(startPositions, sizeof(startPositions));
	        out.write(endPositions,   sizeof(endPositions));
	        out.write((char*)&distanceCovered, sizeof(distanceCovered));
	        out.write((char*)&isLongRoute,      sizeof(isLongRoute));
	    }
	    
	    void load(istream& in) {
	        in.read(startPositions, sizeof(startPositions));
	        in.read(endPositions,   sizeof(endPositions));
	        in.read((char*)&distanceCovered, sizeof(distanceCovered));
	        in.read((char*)&isLongRoute,      sizeof(isLongRoute));
	    }
	    
	    char* getStart()    { return startPositions; }
	    char* getEnd()      { return endPositions; }
	    float getDistance() { return distanceCovered; }
	    bool  longRoute()   { return isLongRoute; }
	    void operator=(const Route& temp) {
	        strcpy(startPositions, temp.startPositions);
	        strcpy(endPositions,   temp.endPositions);
	        distanceCovered = temp.distanceCovered;
	        isLongRoute     = temp.isLongRoute;
	    }
	    
	    void Info() {
	        cout << "Vehicle: route "<< startPositions << " to " << endPositions << " (" << distanceCovered << " km)" << (isLongRoute ? " [LONG]" : "")<< "\n";
	    }
};
const float Route::LONG_ROUTE_THRESHOLD = 50.0f;

class Vehicle {
	private:
	    char name[15];
	    Route obj;
	    bool airConditioned;
	    int studentSeats;
	    int facultySeats;
	    int studentBooked;
	    int facultyBooked;
	public:
	    Vehicle(): obj(), studentSeats(0), facultySeats(0), studentBooked(0), facultyBooked(0), airConditioned(false) {}
	    Vehicle(const char* vehName, bool airCond, const Route& r): obj(r), studentBooked(0), facultyBooked(0), airConditioned(airCond)
	    {
	        strcpy(name, vehName);
	        if (strcmp(name, "Coaster")==0) {
	            studentSeats = 25;
	            facultySeats = 7;
	        } else if (strcmp(name, "Bus")==0) {
	            studentSeats = 40;
	            facultySeats = 12;
	        } else {
	            studentSeats = facultySeats = 0;
	        }
	    }
	    
	    void save(ostream& out) {
	        out.write(name, sizeof(name));
	        out.write((char*)&airConditioned, sizeof(airConditioned));
	        out.write((char*)&studentSeats, sizeof(studentSeats));
	        out.write((char*)&facultySeats, sizeof(facultySeats));
	        out.write((char*)&studentBooked, sizeof(studentBooked));
	        out.write((char*)&facultyBooked, sizeof(facultyBooked));
	        obj.save(out);
	    }
	    
	    void load(istream& in) {
	        in.read(name, sizeof(name));
	        in.read((char*)&airConditioned, sizeof(airConditioned));
	        in.read((char*)&studentSeats, sizeof(studentSeats));
	        in.read((char*)&facultySeats, sizeof(facultySeats));
	        in.read((char*)&studentBooked, sizeof(studentBooked));
	        in.read((char*)&facultyBooked, sizeof(facultyBooked));
	        obj.load(in);
	    }
	    
	    void bookStudent() {
	        if (studentBooked < studentSeats)
	            ++studentBooked;
	        else
	            throw "No student seats left!";
	    }
	    
	    void bookFaculty() {
	        if (facultyBooked < facultySeats)
	            ++facultyBooked;
	        else
	            throw "No faculty seats left!";
	    }
	    
	    int seatsLeftFor(const char* role) const {
	        return strcmp(role, "student")==0
	            ? studentSeats - studentBooked
	            : facultySeats - facultyBooked;
	    }
	    
	    bool getAirCond() const    { return airConditioned; }
	    const char* getName() const{ return name; }
	    char* getLocation()        { return obj.getStart(); }
	    
	    void operator=(const Vehicle& temp) {
	        strcpy(name, temp.name);
	        airConditioned = temp.airConditioned;
	        studentSeats  = temp.studentSeats;
	        facultySeats  = temp.facultySeats;
	        studentBooked = temp.studentBooked;
	        facultyBooked = temp.facultyBooked;
	        obj           = temp.obj;
	    }
	    
	    void Info() {
	        cout << "Type: " << name<< " | AC: " << (airConditioned ? "Yes" : "No") << "\n"<< "Seats left  for Students: "
			 << (studentSeats - studentBooked)<< " Faculty: "    << (facultySeats - facultyBooked) << "\n";
	        obj.Info();
	    }
};

class Drivers {
	    char name[20];
	    bool license;
	public:
	    Vehicle obj;
	    Drivers(): obj() {}
	    Drivers(const char* driverName, bool licenseValid, const Vehicle& v): obj(v)
	    {
	        strcpy(name, driverName);
	        license = licenseValid;
	    }
	    
	    void save(ostream& out) {
	        out.write(name, sizeof(name));
	        out.write((char*)&license, sizeof(license));
	        obj.save(out);
	    }
	    
	    void load(istream& in) {
	        in.read(name, sizeof(name));
	        in.read((char*)&license, sizeof(license));
	        obj.load(in);
	    }
	    
	    char* getName()        { return name; }
	    bool  getLicense()     { return license; }
	    char* getLocation()    { return obj.getLocation(); }
	    void operator=(const Drivers& temp) {
	        strcpy(name, temp.name);
	        license = temp.license;
	        obj     = temp.obj;
	    }
	    
	    void Info() {
	        cout << "Driver: " << name<< (license ? " (licensed)\n" : " (unlicensed)\n");
	        obj.Info();
	    }
};

class Transporters {
    int numberOfDrivers;
	public:
	    Drivers *temp;
	    Transporters(int a) {
	        numberOfDrivers = a;
	        temp = new Drivers[numberOfDrivers];
	    }
	    ~Transporters() {
	        delete[] temp;
	    }
	    
	    void saveData() {
	        ofstream file("Transport.dat", ios::binary | ios::app);
	        for (int i = 0; i < numberOfDrivers; ++i){
	            temp[i].save(file);
	        }
	        file.close();
	    }
};

class Clients {
	protected:
	    char name[25];
	    char status[10];
	    int  id;
	    char homeLocation[20];
	    float feePayment;
	    bool  feeStatus;
	public:
	    Drivers d1;
	    bool booked;
	    char* getName()     { return name; }
	    char* getStatus()   { return status; }
	    char* getLocation() { return homeLocation; }
	    int   getId()       { return id; }
	    float getFee()      { return feePayment; }
	    bool  getFeestat()  { return feeStatus; }
	    void  setFee(float f)    { feePayment += f; }
	    void  setFeestat()       { feeStatus = true; }
	    
	    void saveData() {
	        ofstream file("Clients.dat", ios::binary | ios::app);
	        file.write((char*)this, sizeof(*this));
	        file.close();
	    }
	    
	    void getData() {
	        cout << name
	             << " | ID: " << id
	             << " | Loc: " << homeLocation
	             << " | " << status
	             << " | Paid: " << feePayment
	             << " | Status: " << (feeStatus ? "paid" : "due") << "\n";
	    }
};

class Student : public Clients {
	public:
	    Student() {}
	    Student(const char* nm, int i, const char* loc) {
	        strcpy(name, nm);
	        id = i;
	        strcpy(homeLocation, loc);
	        feePayment = 0;
	        feeStatus  = false;
	        strcpy(status, "student");
	        booked = false;
	    }
	    
	    void searchData(int sid) {
	        ifstream file("Clients.dat", ios::binary);
	        Student temp; bool found = false;
	        while (!found && file.read((char*)&temp, sizeof(temp))) {
	            if (temp.id == sid) {
	                found = true;
	                temp.getData();
	            }
	        }
	        cout << (found ? "Found\n" : "Not found\n");
	    }
	    
	    void removeData(int rid) {
	        ifstream file("Clients.dat", ios::binary);
	        ofstream tmp("temp.dat", ios::binary);
	        Student temp; bool found = false;
	        
	        while (file.read((char*)&temp, sizeof(temp))) 
			{
	            if (temp.id != rid) tmp.write((char*)&temp, sizeof(temp));
	            else { found = true; temp.getData(); }
	        }
	        file.close(); tmp.close();
	        remove("Clients.dat");
	        rename("temp.dat", "Clients.dat");
	        cout << (found ? " Removed\n" : " Not found\n");
	    }
};

class Faculty : public Clients {
public:
    Faculty() {}
    Faculty(const char* nm, int i, const char* loc) {
        strcpy(name, nm);
        id = i;
        strcpy(homeLocation, loc);
        feePayment = 0;
        feeStatus  = false;
        strcpy(status, "faculty");
        booked = false;
    }
    
    void searchData(int sid) {
        ifstream file("Clients.dat", ios::binary);
        Faculty temp; bool found = false;
        while (!found && file.read((char*)&temp, sizeof(temp))) {
            if (temp.id == sid) {
                found = true;
                temp.getData();
            }
        }
        cout << (found ? " Found\n" : "Not found\n");
    }
    
    void removeData(int rid) {
        ifstream file("Clients.dat", ios::binary);
        ofstream tmp("temp.dat", ios::binary);
        Faculty temp; bool found = false;
        
        while (file.read((char*)&temp, sizeof(temp)))
		 {
            if (temp.id != rid) tmp.write((char*)&temp, sizeof(temp));
            else { found = true; temp.getData(); }
        }
        
        file.close(); tmp.close();
        remove("Clients.dat");
        rename("temp.dat", "Clients.dat");
        cout << (found ? " Removed\n" : "Not found\n");
    }
};

class Booking {
	public:
		
	    void BookingInfo(Student& s) {
	        ifstream file("Transport.dat", ios::binary);
	        Drivers temp; bool found = false;
	        
	        while (file.peek() != EOF)
			 {
	            temp.load(file);
	            Vehicle& v = temp.obj;
	            if (!found && strcmp(s.getLocation(), temp.getLocation()) == 0 && strcmp(s.getStatus(),   "student") == 0 && temp.getLicense() && v.seatsLeftFor("student") > 0)
	            {
	                found = true;
	                s.d1 = temp;
	                float fare = 30000.0f + (v.getAirCond() ? 2000.0f : 0.0f);
	                s.setFee(fare);
	                cout << "\n"; temp.Info();
	                cout << "Fee Amount: " << s.getFee() << "\n\n";
	            }
	        }
	        file.close();
	        if (!found) cout << " No student seat available\n\n";
	    }
	    
	    void BookingInfo(Faculty& f) {
	        ifstream file("Transport.dat", ios::binary);
	        Drivers temp; bool found = false;
	        while (file.peek() != EOF)
			 {
	            temp.load(file);
	            Vehicle& v = temp.obj;
	            if (!found
	                && strcmp(f.getLocation(), temp.getLocation()) == 0
	                && strcmp(f.getStatus(),   "faculty")      == 0
	                && temp.getLicense()
	                && v.seatsLeftFor("faculty") > 0)
	            {
	                found = true;
	                f.d1 = temp;
	                float fare = 22000.0f
	                          + (v.getAirCond() ? 2000.0f : 0.0f);
	                f.setFee(fare);
	                cout << "\n"; temp.Info();
	                cout << "Fee Amount: " << f.getFee() << "\n\n";
	            }
	        }
	        file.close();
	        if (!found) cout << " No faculty seat available\n\n";
	    }
	    
	    void payfee(Clients& c) {
	        cout << "Seats before booking: "<< c.d1.obj.seatsLeftFor(c.getStatus()) << "\n";
	        if (c.d1.obj.seatsLeftFor(c.getStatus()) > 0) {
	            if (!c.getFeestat()) {
	                cout << "Monthly fee Rs " << c.getFee() << " paid\n\n";
	                c.setFeestat();
	            } else throw "Already paid";
	        } else throw "No seats left";
	    }
	    
	    void makeBooking(Clients& c) {
	        if (!c.getFeestat()) throw "Fee not paid";
	        if (strcmp(c.getStatus(), "student")==0)
	            c.d1.obj.bookStudent();
	        else
	            c.d1.obj.bookFaculty();
	        fstream tf("Transport.dat", ios::binary|ios::in|ios::out);
	        Drivers tmp; streampos pos;
	        
	        while (tf.peek() != EOF) {
	            pos = tf.tellg();
	            tmp.load(tf);
	            if (strcmp(tmp.getName(), c.d1.getName()) == 0) {
	                tf.seekp(pos);
	                c.d1.save(tf);
	                break;
	            }
	        }
	        
	        tf.close();
	        fstream cf("Clients.dat", ios::binary|ios::in|ios::out);
	        Clients tmpc;
	        while (cf.read((char*)&tmpc, sizeof(tmpc)))
			 {
	            if (tmpc.getId() == c.getId()) {
	                cf.seekp(-static_cast<int>(sizeof(tmpc)), ios::cur);
	                cf.write((char*)&c, sizeof(c));
	                break;
	            }
	        }
	        cf.close();
	        cout << "Booking confirmed\n\n";
	    }
};

int main() {
	cout<<" <<<< M.Saad Khan 24K-0680 >>>>"<<endl<<endl;
	
    ofstream("Clients.dat", ios::binary|ios::trunc).close();
    ofstream("Transport.dat", ios::binary|ios::trunc).close();

    Transporters transporter(2);
    Route route("Malir","Johar",10.0f);
    Vehicle vStudent("Coaster", true,  route);
    Vehicle vFaculty("Bus",    false, route);
    transporter.temp[0] = Drivers("Jamshed", true,  vStudent);
    transporter.temp[1] = Drivers("Ali",    true,  vFaculty);
    transporter.saveData();

    Student s1("Adnan",   1, "Malir");
    Student s2("Saad",     2, "Malir");
    Faculty f1("DrAhmed", 3, "Malir");
    Faculty f2("Prof Sara", 4, "Malir");
    s1.saveData(); s2.saveData();
    f1.saveData(); f2.saveData();

    Booking booking;

    cout << "\n ----Booking a seat for " << s1.getName() << "---- \n";
    booking.BookingInfo(s1);
    try { 
		booking.payfee(s1);    } 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }
    try { 
		booking.makeBooking(s1);} 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }

    cout << " ----Booking a seat for" << s2.getName() << "----- \n";
    booking.BookingInfo(s2);
    try { 
		booking.payfee(s2);    } 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }
    try { 
		booking.makeBooking(s2);} 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }

    cout << "----Booking a seat for " << f1.getName() << "-----\n";
    booking.BookingInfo(f1);
    try { 
		booking.payfee(f1);    } 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }
    try { 
		booking.makeBooking(f1);} 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }

    cout << "----Booking a seat for " << f2.getName() << "-----\n";
    booking.BookingInfo(f2);
    try { 
		booking.payfee(f2);    } 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }
    try { 
		booking.makeBooking(f2);} 
	catch(const char* e) { 
		cout<<e<<"\n\n"; }

    cout << "----Search & Remove Students----\n";
    s1.searchData(s1.getId());
    s2.searchData(s2.getId());
    s1.removeData(s1.getId());
    s2.removeData(s2.getId());

    cout << "---- Search & Remove Faculty----\n";
    f1.searchData(f1.getId());
    f2.searchData(f2.getId());
    f1.removeData(f1.getId());
    f2.removeData(f2.getId());

    return 0;
}

