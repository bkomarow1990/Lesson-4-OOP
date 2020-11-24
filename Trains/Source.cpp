#include <iostream>
#include <time.h>
#include <ctime>
#include "Car.h"
#include "Train.h"
using namespace std;
int main() {
	srand(time(NULL));
	Train t1(5);
	Train t2(4);
	t1.print();
	t2.print();
	Train t3(3,5,"Train 3");
	t3.print();
	return 0;
}