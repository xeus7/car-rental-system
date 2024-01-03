#include "Car.h"


Car::Car() : U(nullptr) {}

void Car::setUtilities(Utilities* u)
{
	U = u;
}


int Car::rate(int hour, int j)
{
	int hour_24, hour_12, hour_1;
	int total = 0, total_24 = 0, total_12 = 0, total_1 = 0;

	// Calculate the number of whole days, 12-hour periods, and remaining hours
	hour_24 = hour / 24;
	hour_12 = (hour - hour_24 * 24) / 12;
	hour_1 = (hour - hour_24 * 24 - hour_12 * 12) / 1;

	// Calculate cost for each time period
	total_24 = hour_24 * rent[j].rate_per_day;
	total_12 = hour_12 * rent[j].rate_per_half;
	total_1 = hour_1 * rent[j].rate_per_hour;

	// Calculate the total cost
	total = total_24 + total_12 + total_1;

	return total;
}

void Car::customerData()
{
	ifstream ifs;
	ifs.open("Customer.txt");
	int custNum = 0;

	while (!ifs.eof())
	{
		ifs >> cust[custNum].id;
		ifs.ignore();
		getline(ifs,cust[custNum].name, ';');
		ifs.getline(cust[custNum].phone, 15, ';');
		ifs.getline(cust[custNum].ic, 15, ';');
		ifs.getline(cust[custNum].address, 1500);
		custNum++;
	}

	ifs.close();
}

int Car::carCount()
{
	int numOfCar = 0;
	ifstream ifs("car rental.txt");

	string word;
	while (getline(ifs, word))
	{
		if (!word.empty())
			numOfCar++;
	}

	ifs.close();

	return numOfCar;
}

int Car::custCount()
{
	int numOfCust = 0;
	ifstream ifs("Customer.txt");

	string word;
	while (getline(ifs, word))
	{
		if (!word.empty())
			numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

int Car::countUser()
{
	int numOfCust = 0;
	ifstream ifs("UserPass.txt");

	string word;
	while (getline(ifs, word))
	{
		if (!word.empty())
			numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

int Car::countAvail()
{
	int numOfCust = 0;
	ifstream ifs("available.txt");

	string word;
	while (getline(ifs, word))
	{
		if (!word.empty())
			numOfCust++;
	}

	ifs.close();

	return numOfCust;
}

void Car::displayCar()
{
    int choice;
    cout << "\n\n";
    U->art();
    cout << endl;

    cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
    cout << "\t  |  =======================================================================================================================" << endl;

    for (int i = 0; i < carCount(); i++)
    {
        cout << "\t  |  " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t " << rent[i].model
             << "\t   " << rent[i].capacity << "\t     " << rent[i].colour << "\t  " << rent[i].rate_per_hour
             << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day
             << "\t\t       " << rent[i].transmission << endl;
    }

    cout << "\n\n";
    cout << "\n\t  |\t\t\t\t\t  1. BACK";
    cout << "\n\t  |\t\t\t\t\t  2. MAIN MENU" << endl << "\n\n";
    cout << "\t  |\t\t\t\t\tINPUT :";
    cin >> choice;

    system("cls");

    switch (choice)
    {
    case 1:
        admin();
        break;

    case 2:
        menu();
        break;

    default:
        // Handle invalid input
        break;
    }
}

void Car::dispAvailCar()
{
	cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t  |  =======================================================================================================================" << endl;
	for (int i = 0; i < countAvail(); i++)
	{
		cout << "\t  |   " << avail[i].plate_num << "\t\t" << avail[i].brand << "\t " << avail[i].model << "\t   " << avail[i].capacity << "\t     "
			<< avail[i].colour << "\t  " << avail[i].rate_per_hour << "\t\t    " << avail[i].rate_per_half << "\t\t    " << avail[i].rate_per_day
			<< "\t\t       " << avail[i].transmission << endl;
	}
}

void Car::existingCust()
{


	int tempCust, hour, userID;
	char carSelect[10];
	tempCust = custCount() - 1;
	ofstream log,Cust;
	log.open("Log.txt", fstream::app);
	// Assuming that "name" is a member of the customer structure
	std::string filePath = "CustData\\" + cust[custCount()].name + ".txt";

	// Open the file in output mode, creating it if it doesn't exist
	Cust.open(filePath, std::fstream::app);
	ofstream ofs;
	ofs.open("temp.txt");
	cout << "\n\n\n\n";
	cout << endl;

	cout << "\n\n";
	U->art();
	cout << endl;

	cout << "\n\t  |\t\t\t\tPlease enter user ID : ";
	cin >> userID;

	for (int i = 0; i < custCount(); i++)
	{
		if (userID == cust[i].id)
		{
			cout << "\n\t  |\t\t\t\t\tWELCOME ";
			cout << cust[i].name;
			log << "\nNAME: " << cust[i].name;
			cout << "\t  |\tID ";
			cout << cust[i].id;
			cout << "\n\n";
			log << "\nPHONE: " << cust[i].phone;
			log << "\nID: " << cust[i].ic;
		}
	}


	dispAvailCar();

	cout << "\n\n\t  |\t\t\t\t\tPlease select car";
	cout << "\n\t  |\t\t\t\t\tPlate Number : ";
	cin >> ws;
	cin.getline(carSelect, 10);
	int x = countAvail();
	for (int i = 0; i < countAvail(); i++)
	{
		if (strcmp(carSelect, avail[i].plate_num) != 0)
		{
			ofs << avail[i].plate_num;
			ofs << " ";
			ofs << avail[i].brand;
			ofs << " ";
			ofs << avail[i].model;
			ofs << " ";
			ofs << avail[i].capacity;
			ofs << " ";
			ofs << avail[i].colour;
			ofs << " ";
			ofs << avail[i].rate_per_hour;
			ofs << " ";
			ofs << avail[i].rate_per_half;
			ofs << " ";
			ofs << avail[i].rate_per_day;
			ofs << " ";
			ofs << avail[i].transmission;
			if (i != countAvail())
			{
				ofs << endl;
			}


		}
	}

	ofs.close();
	
	remove("available.txt");
	rename("temp.txt", "available.txt");
	cout << "\t  |\t\t\t\t\tHours of rent : ";
	cin >> hour;
	int j;
	for (int i = 0; i < carCount(); i++)
	{
		if (strcmp(carSelect, rent[i].plate_num) == 0)
		{
			j = i;

			log << "\nCAR: " << rent[i].plate_num;
			log << "\nBRAND: " << rent[i].brand;
			log << "\nMODEL: " << rent[i].model;
			log << "\nHOUR: " << hour;
			log << "\nPAYMENT: " << rate(hour, j);

			Cust << "\nCAR: " << rent[i].plate_num;
			Cust << "\nBRAND: " << rent[i].brand;
			Cust << "\nMODEL: " << rent[i].model;
			Cust << "\nHOUR: " << hour;
			Cust << "\nPAYMENT: " << rate(hour, j);
		}
	}

	cout << "\t  |\t\t\t\tPrice for " << hour << " hours of rent : $ ";
	cout << rate(hour, j);

	log << "\nDATE: " << U->currentDateTime();
	log << "\n==========================================================";
	log.close();

	Sleep(5000);
	system("cls");
	menu();
}

void Car::newCustData()
{
	cout << "\n\n";
	U->art();
	cout << endl;

	availCar();
	ofstream ofs, log, Cust;
	ofs.open("Customer.txt", fstream::app);
	log.open("Log.txt", fstream::app);

	ofs << endl;
	ofstream availTemp;
	availTemp.open("availtemp.txt");
	cout << "\n\n\n\n";
	cout << endl;


	cust[custCount()].id = custCount() + 1001;
	ofs << cust[custCount()].id;
	ofs << ";";


	cout << "\n\n";
	cout << "\n\t  |\t\t\t\t\t  Please enter the data below : " << endl;

	cout << "\n\t  |\t\t\t\t\t  Name : ";
	cin >> ws;
	getline(cin,cust[custCount()].name);
	ofs << cust[custCount()].name << ";";
	log << "\nNAME: " << cust[custCount()].name;

	// Assuming that "name" is a member of the customer structure
	std::string filePath = "CustData\\" + cust[custCount()].name + ".txt";

	// Open the file in output mode, creating it if it doesn't exist
	Cust.open(filePath, std::fstream::out);

	Cust << "\nNAME: " << cust[custCount()].name;

	cout << "\t  |\t\t\t\t\t  Phone Number : ";
	cin.getline(cust[custCount()].phone, 15);
	ofs << cust[custCount()].phone;
	ofs << ";";
	log << "\nPHONE: " << cust[custCount()].phone;
	Cust << "\nPHONE: " << cust[custCount()].phone;


	cout << "\t  |\t\t\t\t\t  IC : ";
	cin.getline(cust[custCount()].ic, 15);
	ofs << cust[custCount()].ic;
	ofs << ";";
	log << "\nID: " << cust[custCount()].ic;
	Cust << "\nID: " << cust[custCount()].ic;

	cout << "\t  |\t\t\t\t\t  Address : ";
	cin.getline(cust[custCount()].address, 1500);
	ofs << cust[custCount()].address;

	ofs.close();


	system("cls");

	int tempCust, hour;
	char carSelect[10];
	tempCust = custCount() - 1;

	cout << "\n\n\n\n";
	U->art();
	cout << endl;

	cout << "\n\t  |\t\t\tWELCOME ";
	cout << cust[tempCust].name;
	cout << "\t  |\tID ";
	cout << cust[tempCust].id;
	cout << "\n\n";

	dispAvailCar();

	cout << "\n\n\t  |\tPlease select car";
	cout << "\n\t  |\tPlate Number : ";
	cin >> ws;
	cin.getline(carSelect, 10);

	int x = countAvail();

	for (int i = 0; i < countAvail(); i++)
	{
		if (strcmp(carSelect, avail[i].plate_num) != 0)
		{
			availTemp << avail[i].plate_num;
			availTemp << " ";
			availTemp << avail[i].brand;
			availTemp << " ";
			availTemp << avail[i].model;
			availTemp << " ";
			availTemp << avail[i].capacity;
			availTemp << " ";
			availTemp << avail[i].colour;
			availTemp << " ";
			availTemp << avail[i].rate_per_hour;
			availTemp << " ";
			availTemp << avail[i].rate_per_half;
			availTemp << " ";
			availTemp << avail[i].rate_per_day;
			availTemp << " ";
			availTemp << avail[i].transmission;
			if (i != countAvail())
			{
				availTemp << endl;
			}


		}
	}
	availTemp.close();
	ofs.close();

	remove("available.txt");
	rename("availtemp.txt", "available.txt");

	cout << "\t  |\tHours of rent : ";
	cin >> hour;
	int j;
	for (int i = 0; i < carCount(); i++)
	{
		if (strcmp(carSelect, rent[i].plate_num) == 0)
		{
			j = i;
			rate(hour, j);
			log << "\nCAR: " << rent[i].plate_num;
			log << "\nBRAND: " << rent[i].brand;
			log << "\nMODEL: " << rent[i].model;
			log << "\nHOUR: " << hour;
			log << "\nPAYMENT: " << rate(hour, j);

			Cust << "\nCAR: " << rent[i].plate_num;
			Cust << "\nBRAND: " << rent[i].brand;
			Cust << "\nMODEL: " << rent[i].model;
			Cust << "\nHOUR: " << hour;
			Cust << "\nPAYMENT: " << rate(hour, j);

		}
	}



	cout << "\n\t  |\tPrice for " << hour << " hours of rent : $ ";
	cout << rate(hour, j);

	log << "\nDATE: " << U->currentDateTime();
	log << "\n==========================================================";
	log.close();
	Cust.close();
	availTemp.close();
	availCar();

	Sleep(5000);
	system("cls");
	menu();
}

void Car::newCarData()
{
	cout << "\n\n";
	U->art();
	cout << endl;

	ofstream ofs;
	ofs.open("car rental.txt", fstream::app);
	ofs << endl;

	int newCar = carCount() + 1;
	cout << "\n\n";
	cout << "\n\t  |\t\t\t\t\t  Please enter the car data below : " << endl;

	cout << "\n\t  |\t\t\t\t\t  Plate Number : ";
	cin >> ws;
	cin.getline(rent[newCar].plate_num, 10);
	ofs << rent[newCar].plate_num;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Brand : ";
	cin.getline(rent[newCar].brand, 20);
	ofs << rent[newCar].brand;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Model : ";
	cin.getline(rent[newCar].model, 20);
	ofs << rent[newCar].model;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Capacity : ";
	cin >> rent[newCar].capacity;
	ofs << rent[newCar].capacity;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Colour : ";
	cin >> ws;
	cin.getline(rent[newCar].colour, 20);
	ofs << rent[newCar].colour;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Rate Per Hour : ";
	cin >> rent[newCar].rate_per_hour;
	ofs << rent[newCar].rate_per_hour;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Rate Per 12 Hour : ";
	cin >> rent[newCar].rate_per_half;
	ofs << rent[newCar].rate_per_half;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Rate Per 24 Hour : ";
	cin >> rent[newCar].rate_per_day;
	ofs << rent[newCar].rate_per_day;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Tranmission (A/M) : ";
	cin >> ws;
	cin.getline(rent[newCar].transmission, 6);
	ofs << rent[newCar].transmission;

	ofs.close();
	system("cls");

	carData();
	admin();
}

void Car::availCar() {


	ifstream ifs;
	ifs.open("available.txt");
	int carNum = 0;

	while (ifs >> ws)
	{
		ifs.getline(avail[carNum].plate_num, 10, ' ');
		ifs.getline(avail[carNum].brand, 20, ' ');
		ifs.getline(avail[carNum].model, 20, ' ');
		ifs >> avail[carNum].capacity;
		ifs.ignore();
		ifs.getline(avail[carNum].colour, 20, ' ');
		ifs >> avail[carNum].rate_per_hour;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_half;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(avail[carNum].transmission, 6);
		carNum++;
		
	}


	ifs.close();
	}

void Car::resetAvail()
{
	U->Boarder();
	ofstream ofs;
	ofs.open("temp2.txt");

	for (int i = 0; i < carCount(); i++)
	{
		ofs << rent[i].plate_num;
		ofs << " ";
		ofs << rent[i].brand;
		ofs << " ";
		ofs << rent[i].model;
		ofs << " ";
		ofs << rent[i].capacity;
		ofs << " ";
		ofs << rent[i].colour;
		ofs << " ";
		ofs << rent[i].rate_per_hour;
		ofs << " ";
		ofs << rent[i].rate_per_half;
		ofs << " ";
		ofs << rent[i].rate_per_day;
		ofs << " ";
		ofs << rent[i].transmission;
		if (i != carCount())
		{
			ofs << endl;
		}


	}




	ofs.close();
	remove("available.txt");
	rename("temp2.txt", "available.txt");

	admin();

}

void Car::newUserPass()
{
	U->Boarder();
	ofstream ofs;
	ofs.open("UserPass.txt", fstream::app);

	userPass[countUser()].ID = countUser() + 1;


	string password;
	char c = ' ';
	U->gotoxy(40, 20);
	cout << "\n\n\n\n\t  |\t\t\tID(DEFAULT): " << userPass[countUser()].ID;
	cout << "\n\t  |\t\t\tADD PASSWORD: ";

	while (c != '\r') //Loop until 'Enter' is pressed
	{
		c = _getch();
		if (c == 0)
		{
			_getch();

		}
		else if (c == '\b')   //If the 'Backspace' key is pressed
		{
			if (password.size() != 0)  //If the password string contains data, erase last character
			{
				cout << "\b \b";
				password.erase(password.size() - 1, 1);
			}
			continue;
		}
		else if (c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
		{
			password += c;
			cout << "*";
		}
		else
			continue;
	}


	strcpy_s(userPass[countUser()].passWord, password.c_str());

	ofs << userPass[countUser()].ID;
	ofs << ";";
	ofs << userPass[countUser()].passWord;
	ofs << endl;

	system("cls");
	admin();

}

void Car::showCarData()
{
		int choice;
		cout << "\n\n";
		U->art();
		cout << endl;

		cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
		cout << "\t  |  =======================================================================================================================" << endl;

		for (int i = 0; i < carCount(); i++)
		{
			cout << "\t  |  " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t " << rent[i].model
				<< "\t   " << rent[i].capacity << "\t     " << rent[i].colour << "\t  " << rent[i].rate_per_hour
				<< "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day
				<< "\t\t       " << rent[i].transmission << endl;
		}

		cout << "\n\n";
		cout << "\n\t  |\t\t\t\t\t  1. BACK";
		cout << "\n\t  |\t\t\t\t\t  2. MAIN MENU" << endl << "\n\n";
		cout << "\t  |\t\t\t\t\tINPUT :";
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
			admin();
			break;

		case 2:
			menu();
			break;

		default:
			// Handle invalid input
			break;
		}
	}


void Car::showAvailCar()
{
	int x;
	cout << "\n\n";
	U->art();
	cout << endl;

	dispAvailCar();


	cout << "\n\n";
	cout << "\n\t  |\t\t\t\t\t  1. BACK";
	cout << "\n\t  |\t\t\t\t\t  2. MAIN MENU" << endl << "\n\n";
	cout << "\t  |\t\t\t\t\tINPUT :";
	cin >> x;

	system("cls");

	if (x == 1)
	{
		admin();
	}

	if (x == 2)
	{
		menu();
	}

}

void Car::carData()
{
	ifstream ifs;
	ifs.open("car rental.txt");
	int carNum = 0;

	while (!ifs.eof())
	{
		ifs.getline(rent[carNum].plate_num, 10, ' ');
		ifs.getline(rent[carNum].brand, 20, ' ');
		ifs.getline(rent[carNum].model, 20, ' ');
		ifs >> rent[carNum].capacity;
		ifs.ignore();
		ifs.getline(rent[carNum].colour, 20, ' ');
		ifs >> rent[carNum].rate_per_hour;
		ifs.ignore();
		ifs >> rent[carNum].rate_per_half;
		ifs.ignore();
		ifs >> rent[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(rent[carNum].transmission, 6);
		carNum++;
		ifs >> ws;
	}


	ifs.close();
}

void Car::admin()
{
	int x;
	cout << "\n\n\n\n";
	U->art();
	cout << endl;

	cout << "\n\t  |\t\t\t\t\t\t\t  1. ADD ADMIN";
	cout << "\n\t  |\t\t\t\t\t\t\t  2. SHOW ALL CARS";
	cout << "\n\t  |\t\t\t\t\t\t\t  3. ADD CAR";
	cout << "\n\t  |\t\t\t\t\t\t\t  4. DELETE CAR";
	cout << "\n\t  |\t\t\t\t\t\t\t  5. RESET AVAILABLE CAR";
	cout << "\n\t  |\t\t\t\t\t\t\t  6. SHOW AVAILABLE CARS";
	cout << "\n\t  |\t\t\t\t\t\t\t  7. LOG OFF" << endl << "\n";
	cout << "\t  |\t\t\t\t\t\t\tINPUT :";
	cin >> x;


	system("cls");

	if (x == 7)
	{
		U->load_EXIT();
		menu();
	}

	else if (x == 6)
	{
		showAvailCar();
		
	}

	else if (x == 2)
	{
		showCarData();
	}

	else if (x == 3)
	{
		newCarData();
	}

	else if (x == 4)
	{
		delCar();
	}
	else if (x == 1)
	{
		newUserPass();
	}
	else if (x == 5)
		system("cls");
	resetAvail();
}

void Car::user()
{

	int x;

	U->art();
	cout << endl;


	cout << "\n\t  |\t\t\t\t\t\t\t  1. NEW";
	cout << "\n\t  |\t\t\t\t\t\t\t  2. EXISTING";
	cout << "\n\t  |\t\t\t\t\t\t\t  3. MAIN MENU" << endl;
	cout << "\n\n\t  |\t\t\t\t\t\t\tINPUT :";
	cin >> x;

	system("cls");
	if (x == 1)
	{
		newCustData();
	}

	else if (x == 2)
	{
		system("cls");
		U->load_UPDATE();
		existingCust();
	}

	else if (x == 3)
	{
		menu();
	}




}

void Car::menu()
{

	int x;
	U->art();

	cout << endl;
	cout << "\n\t  |\t\t\t\t\t\t\t  1. ADMIN";
	cout << "\n\t  |\t\t\t\t\t\t\t  2. USER";
	cout << "\n\t  |\t\t\t\t\t\t\t  3. T%C";
	cout << "\n\t  |\t\t\t\t\t\t\t  4. EXIT" << endl << "\n";
	cout << "\n\t  |\t\t\t\t\t\t\tINPUT :";
	cin >> x;


	system("cls");

	if (x == 2)
	{
		user();
	}

	else if (x == 1)
	{
		U->password();
	}

	if (x == 3)
	{

		tNc();
		_getch();
	}

	if (x == 5)
		U->time();

	else if (x == 4)
	{
		cout << "\n\n\n\n";
		U->exitArt();
		Sleep(1000);
		exit(0);
	}

	else if (x == 6)
	{
		U->fullscreen();
		menu();
	}





}

void Car::delCar()
{
	char plate[10];

	ofstream ofs;
	ofs.open("temp.txt");

	cout << "\n\n\n\n";
	U->art();
	cout << endl;
	displayCar();

	cout << "\n\n";
	cout << "\t  | \t\tEnter the car plate number that are going to be deleted (CAPITAL LETTER W/OUT SPACE): " << endl;
	cout << "\t  |  \t\t\t\t\t\t\t";
	cin >> ws;
	cin.getline(plate, 10);
	int x = carCount();
	for (int i = 0; i < carCount(); i++)
	{
		if (strcmp(plate, rent[i].plate_num) != 0)
		{
			ofs << rent[i].plate_num;
			ofs << " ";
			ofs << rent[i].brand;
			ofs << " ";
			ofs << rent[i].model;
			ofs << " ";
			ofs << rent[i].capacity;
			ofs << " ";
			ofs << rent[i].colour;
			ofs << " ";
			ofs << rent[i].rate_per_hour;
			ofs << " ";
			ofs << rent[i].rate_per_half;
			ofs << " ";
			ofs << rent[i].rate_per_day;
			ofs << " ";
			ofs << rent[i].transmission;
			if (i != carCount())
			{
				ofs << endl;
			}


		}
	}

	ofs.close();

	remove("car rental.txt");
	rename("temp.txt", "car rental.txt");


	system("cls");

	carData();
	admin();
}

void Car::tNc()
{
	U->art();
	cout << endl;
	cout << "\n\t  |\t\t\t1. MINIMUM RENT TIME IS 3 HOURS";
	cout << "\n\t  |\t\t\t2. RISK BY YOUR OWN";
	cout << "\n\t  |\t\t\t3. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
	cout << "\n\t  |\t\t\t4. PREPARE ITEM AS BELOW";
	cout << "\n\t  |\t\t\t     \3COPY OF IC, LICENSE";
	cout << "\n\t  |\t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
	cout << "\n\t  |\t\t\t5. ADDITIONAL CHARGE IF LATE";
	cout << "\n\t  |\t\t\t6. SAFE DRIVE!";
	cout << "\n\n\n\n\t  |\t\t\t                             PRESS ANY KEY TO CONTINUE :)";
	cout << "\n\t  |\t\t\t                                                            ";

	_getch();
	menu();
}
