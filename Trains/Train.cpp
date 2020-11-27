#include "Train.h"
#include <iostream>
bool isDigit(const size_t& SIZE_, const string& string_) {
	for (size_t i = 0; i < SIZE_; i++)
	{
		if (!isdigit(string_[i]))
		{
		}
		else {
			return true;
		}
	}
	return false;
}
void Train::setNumber(const int& number)
{
	this->number = number;
}

void Train::setName(const string& name)
{
	//не робив перевірку на цифри бо в назві поїдів є цифри
	if (!name.empty())
	{
		if (isDigit(name.length(),name))
		{
			this->name = name;
		}
		
	}
	else {
		cout << "Eneter correct name" << endl;
	}
}

const int Train::getSize() const
{
	return size;
}

const int Train::getNumber() const
{
	return number;
}

const string Train::getName() const
{
	return name;
}

void Train::printArray() const
{
	for (int i = 0; i < size; i++)
	{
		train[i].print();
	}
}

void Train::print()const
{
	cout << "=====================================" << endl;
	cout << "Size: " << size << endl;
	cout << "Number: " << number<<endl;
	cout << "Name: " << name<<endl;
	printArray();
	cout << "=====================================" << endl;
}

void Train::printAll() const
{
	print();
	cout << "Count of cars: " << size << endl;
	cout << "All Passegers: "<<getAllPasseger() << endl;
	cout << "Number of car with Max passegers: " << getMaxPassagers(train,size).getTypeCar();
	cout << "Number of car with Min passegers: " << getMinPassagers(train, size).getTypeCar();
}

Car Train::getMaxPassagers(const Car arr[], const int size) const
{
	Car max;
	max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max.getCountPassengers()<arr[i].getCountPassengers())
		{
			max = arr[i];
		}
	}
	return max;
}

Car Train::getMinPassagers(const Car arr[], const int size) const
{
	Car min;
	min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (min.getCountPassengers() > arr[i].getCountPassengers())
		{
			min = arr[i];
		}
	}
	return min;
}

const int Train::getAllPasseger() const
{
	int summ = 0;
	for (int i = 0; i < size; i++)
	{
		summ += train[i].getCountPassengers();
	}
	return summ;
}

Train::Train()
	:size(0)
{
	number = 0;
	name = "NoName";
}



Train::Train(const int& size_)
	:size(size_)
{
	number = 0;
	name = "NoName";
}

Train::Train(const int& size_, const int& number, const string& name)
	:size(size_)
{
	this->number = number;
	this->name = name;
}

Train::Train(const Train& other)
	:size(other.size)
{
	setName(other.name);
	copyCars(other);
	setNumber(other.number);
}

Train& Train::operator=(const Train& other)
{
	if (this!=&other)
	{
		setName(other.name);
		copyCars(other);
		setNumber(other.number);
	}
	return *this;
}

Train::~Train()
{
	delete[]train;
}

void Train::copyCars(const Train& other)
{
	train = new Car[size];
	for (int i = 0; i < size; i++)
	{
		this->train[i] = other.train[i];
	}
}


