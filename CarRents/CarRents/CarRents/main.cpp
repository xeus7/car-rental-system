#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>zz
using namespace std;

#include "Car.h"
#include "Utilities.h"

int main()
{
	Car car;  // Instantiate Car
	Utilities utilities;  // Instantiate Utilities

	// Set pointers to each other
	car.setUtilities(&utilities);
	utilities.setCar(&car);

	U.fullscreen();
	U.welcome();
	U.load();
	U.Boarder();
	U.readUserPass();
	C.availCar();
	C.customerData();
	C.carData();
	U.menu();

	
}
