#pragma once
#include <iostream>
using namespace std;

struct car
{
	char plate_num[10];
	char brand[20];
	char model[20];
	float capacity;
	char colour[20];
	float rate_per_hour;
	float rate_per_half;
	float rate_per_day;
	char transmission[6];
};

struct customer
{
	int id;
	string name;
	char phone[15];
	char ic[15];
	char address[1500];
};

struct pass
{
	int ID;
	char passWord[20];

};

extern struct pass userPass[1000];
extern struct car rent[1000];
extern struct car avail[1000];
extern struct customer cust[1000];