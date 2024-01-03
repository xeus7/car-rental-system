#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Car.h"
#include "Utilities.h"


struct pass userPass[1000];
struct car rent[1000];
struct car avail[1000];
struct customer cust[1000];


int main()
{
	Car C;  // Instantiate Car
	Utilities U;  // Instantiate Utilities

	// Set pointers to each other
	C.setUtilities(&U);
	U.setCar(&C);

	U.fullscreen();
	U.welcome();
	U.load();
	U.Boarder();
	U.readUserPass();
	
	C.availCar();
	C.customerData();
	C.carData();
	C.menu();


}
