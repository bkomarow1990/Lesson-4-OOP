#pragma once
#include <iostream>
#include <time.h>
#include "Car.h"
using namespace std;
class Train
{
public:
	void setNumber(const int& number);
	void setName(const string& name);
	const int getSize()const;
	const int getNumber()const;
	const string getName()const;
	void printArray()const;
	void print()const;
	void printAll()const;
	Car getMaxPassagers(const Car arr[],const int size)const;
	Car getMinPassagers(const Car arr[], const int size)const;
	const int getAllPasseger()const;
	Train();
	Train(const int& size_);
	Train(const int& size_, const int& number, const string& name);
	Train(const Train& other);
	Train& operator= (const Train& other);
	~Train();
private:
	const int size;
	int number;
	string name;
	Car* train = new Car[size];
	void copyCars(const Train& other);
};