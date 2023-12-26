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
#include "Car.h"

#include "structs.h"
using namespace std;

class Car;

class Utilities
{
    Car* C;  // Pointer to Car object 
    char c;
    HANDLE a;
    COORD b;
    COORD coord;

public:
    Utilities();  // Constructor
    void setCar(Car* c);  // Setter for Car object
    void fullscreen();
    const std::string currentDateTime();
    const std::string Date();
    void time();
    void date();
    void readUserPass();
    void password();
    void gotoxy(int x, int y);
    void load();
    void load_CHECK();
    void load_UPDATE();
    void load_EXIT();
    void GotoXY(int x, int y);
    void Boarder();
    void art();
    void welcome();
    void exitArt();

  

private:
   
};
