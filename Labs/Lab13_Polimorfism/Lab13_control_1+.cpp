#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Vehicle
{
public:
	static int vehicleCount;
	Vehicle() { vehicleCount++; };
	virtual ~Vehicle() { cout << "Vehicle destructor" << endl; }; // virtual destructor for right sequence of destructors calls. Without it only Vehicle destructor will be called for case: Vehicle* v = new Car(); delete v;

	virtual void move(string& beh) = 0; // pure virtual function, whithout implementation. Like abstract method in C#.
	virtual string type() = 0;

	void serialize() // the method is not virtual, it has implementation in base class. Inheritors use it as usual.
	{
		fstream file("vehicle.txt", ios::app); // open file only for append
		if (file.is_open())
		{
			string beh;
			move(beh); // calling virtual method of inheritor
			file << type() << " ; " << beh << endl; // calling virtual method of inheritor
			file.close();
		}
		
	}
private:	
	
};

int Vehicle::vehicleCount = 0; // static member initialization

class Car : public virtual Vehicle // virtual inheritance (rombus inheritance) to avoid duplicate Vehicle base class in AmphibiousVehicle.
	//Without virtual inheritance, AmphibiousVehicle would have two Vehicle base class subobjects: one from Car and one from Boat. And they both would have their own Vehicle part.
	//That's meeans the constructor and destructor of Vehicle would be called twice for AmphibiousVehicle object creation and destruction. Fields of Vehicle would be duplicated in AmphibiousVehicle object and will have different memory addresses.
{
public: 
	Car() {};
	~Car() override { cout << "Car destructor" << endl; };
	void move(string& beh) override
	{
		beh = "Car is driving on the road.";
		cout << beh << endl;
	}
	string type() override
	{
		return string("Car: ") + typeid(*this).name();
	}
};

class Boat : public virtual Vehicle // virtual inheritance (rombus inheritance) to avoid duplicate Vehicle base class in AmphibiousVehicle 
{
	public:
	Boat() {};
	~Boat() override { cout << "Boat destructor" << endl; };
	void move(string& beh) override
	{
		beh = "Boat is sailing on the water.";
		cout << beh << endl;
	}
	string type() override
	{
		return string("Boat: ") + typeid(*this).name();
	}
};

class Plane : public Vehicle
{
	public:
	Plane() {};
	~Plane() override { cout << "Plane destructor" << endl; };
	void move(string& beh) override
	{
		beh = "Plane is flying in the sky.";
		cout << beh  << endl;
	}
	string type() override
	{
		return string("Plane: ") + typeid(*this).name();
	}
};

class AmphibiousVehicle : public Car, public Boat
{
	public:
	AmphibiousVehicle() {};
	~AmphibiousVehicle() override { cout << "AmphibiousVehicle destructor" << endl; };
	void move(string& beh) override
	{
		beh = "AmphibiousVehicle is driving on the road and sailing on the water.";
		cout << beh << endl;
	}
	string type() override
	{
		return string("AmphibiousVehicle: ") + typeid(*this).name();
	}
};





int main()
{
	vector<Vehicle*> vehicles;
	vehicles.push_back(new Car());
	vehicles.push_back(new Boat());
	vehicles.push_back(new Plane());
	vehicles.push_back(new AmphibiousVehicle());
	cout << "Vehicle count: " << Vehicle::vehicleCount << endl; // without creating objects accessing static member requires class name prefix (className::staticMemberName)
	for (Vehicle* v : vehicles)
	{
		cout << v->type() << ": ";
		v->serialize();
	}
	for (Vehicle* v : vehicles)
	{
		delete v; // calling destructors in right order
	}

	
	return 0;
}