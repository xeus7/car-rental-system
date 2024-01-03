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
#include "Utilities.h"


using namespace std;
const int MAXCARS = 100;


class Utilities;

class Car
{
	Utilities* U;  // Pointer to Utilities object

public:
	Car();  // Constructor
	void setUtilities(Utilities* u);
	int rate(int hour, int j);
	void customerData();
	int carCount();
	int custCount();
	int countUser();
	int countAvail();
	void displayCar();
	void dispAvailCar();
	void existingCust();
	void newCustData();
	void newCarData();
	void availCar();
	void resetAvail();
	void newUserPass();
	void showCarData();
	void showAvailCar();
	void carData();
	void admin();
	void user();
	void menu();
	void delCar();
	void tNc();

};

