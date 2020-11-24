#include "Car.h"
#include <time.h>
#include <ctime>
#include <windows.h>
void Car::setTypeCar(const int& type_car) 
{
	if (type_car <= 3 && type_car >= 0)
	{
		this->type_car = Type_cars(type_car);
	}
}

void Car::setCountPassengers(const size_t& count_passengers) 
{
	this->count_passengers = count_passengers;
}

void Car::input()
{
	int type_car_;
	size_t count_passengers_;
	cout << "Enter type of car: " << endl;
	cout << "1 - SEAT, 2 - COMPACT, 3 - SLEEPING" << endl; 
	cin >> type_car_;
	setTypeCar(type_car_);
	cout << "Enter count passengers: " << endl;
	cin >> count_passengers_;
	setCountPassengers(count_passengers_);
}

void Car::print()
{
	cout << "Type car: " << getTypeCar() << endl;
	cout << "Count Passenger: " << count_passengers << endl;
}

const string Car::getTypeCar() const
{
	static string types[]{ "SEAT","COMPACT","SLEEPING" };
	return types[(int)type_car];
}

const size_t Car::getCountPassengers() const
{
	return count_passengers;
}

void Car::randomValuesCar()
{
	setTypeCar(rand() % 3);
	setCountPassengers((rand() % 20)+ 1);
	//type_car = (Type_cars)(rand() % ((int)Type_cars::SLEEPING + 1));
	//count_passengers = rand() % (maxPlaces[(int)type_car + 1] + 1);
}

Car::Car()
{
	type_car = (Type_cars)(rand() % ((int)Type_cars::SLEEPING + 1));
	count_passengers = rand() % ((int)(maxPlaces[(int)type_car + 1] + 2));
}

Car::Car(const int& type_car, const size_t& count_passengers)
{
	setTypeCar(type_car);
	setCountPassengers(count_passengers);
}

Car::Car(const Car& other)
{
	type_car = other.type_car;
	count_passengers = other.count_passengers;
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		type_car = other.type_car;
		count_passengers = other.count_passengers;
	}
	return *this;
}

Car::~Car()
{
}
const size_t Car::maxPlaces[]{ 56,22,16 };
