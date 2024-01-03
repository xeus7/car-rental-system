#include "Utilities.h"




Utilities::Utilities() : C(nullptr) {}

void Utilities::setCar(Car* c)
{
	C = c;
}

void Utilities::fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

const std::string Utilities::currentDateTime()
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	char buf[80];
	snprintf(
		buf, sizeof(buf),
		"%d/%02d/%02d %02d:%02d:%02d",
		st.wYear, st.wMonth, st.wDay,
		st.wHour, st.wMinute, st.wSecond
	);

	return std::string(buf);
}

const std::string Utilities::Date()
{
	return currentDateTime();  // Reusing the currentDateTime function
}

void Utilities::time()
{
	int i = 0;

	while (i < 5)
	{
		Boarder();
		gotoxy(20, 20);
		std::cout << "\n\n\n\n\n\t  |\t\t\t\tDATE: " << currentDateTime() << std::endl;
		Sleep(900);
		system("cls");
		i++;
	}

	C->menu();
}


void Utilities::date()
{
	std::cout << "\n\t  |\t\t\t\t\t\tDATE: " << Date() << std::endl;
}

void Utilities::readUserPass()
{
	ifstream ifs;
	ifs.open("UserPass.txt");

	int i = 0;
	while (!ifs.eof())
	{
		ifs >> userPass[i].ID;
		ifs.ignore();
		ifs.getline(userPass[i].passWord, 20);
		i++;
	}
	ifs.close();
}

void Utilities::password()
{
	Boarder();

	C->countUser();
	string password;

	gotoxy(40, 20);
	cout << "\n\n\n\n\t  |\t\t\tPASSWORD: ";

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

	for (int i = 0; i < C->countUser(); i++)
	{
		if (password.compare(userPass[i].passWord) == 0)
		{
			system("cls");
			load_CHECK();
			C->admin();
		}
	}


	if (password == "a")
	{
		system("cls");
		load_CHECK();
		C->admin();
	}

	else
		cout << "\n\t  |\t\t\tWrong Password.. Call Administrator";
	cout << "\n\t  |\t\t\tReturning to Main MenU->." << endl;
	cout << "\n\t  |\t\t\t";
	Sleep(1000);
	cout << "\n\t  |\t\t\tPress Enter to Continue.";
	cout << "\n\t  |\t\t\t";
	_getch();
	C->menu();
}

void Utilities::gotoxy(int x, int y)
{

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Utilities::load()
{
	Boarder();

	int timer = 5 + rand() % 20;
	int row = 0, col = 0, r = 0, c = 0, q = 0;
	gotoxy(65, 34);
	cout << "BOOTING UP...";
	gotoxy(60, 36);
	for (r = 1; r <= timer; r++)
	{
		for (q = 0; q <= 100000000; q++);//to display the character slowly
		printf("%c", 177);
	}
	Sleep(100);
	system("cls");
}

void Utilities::load_CHECK()
{
	Boarder();
	int timer = rand() % 5 + 1;
	int row = 0, col = 0, r = 0, c = 0, q = 0;
	gotoxy(65, 34);
	printf("LOG IN...");
	gotoxy(60, 36);
	for (r = 1; r <= timer; r++)
	{
		for (q = 0; q <= 100000000; q++);//to display the character slowly
		printf("%c", 177);
	}
	Sleep(100);
	system("cls");
}

void Utilities::load_UPDATE()
{
	Boarder();

	int row = 0, col = 0, r = 0, c = 0, q = 0;
	int timer = rand() % 25 + 1;
	gotoxy(65, 34);
	printf("UPDATING DATABASE...");
	gotoxy(60, 36);
	for (r = 1; r <= timer; r++)
	{
		for (q = 0; q <= 100000000; q++);//to display the character slowly
		printf("%c", 177);
	}
	Sleep(100);
	system("cls");
}

void Utilities::load_EXIT()
{
	Boarder();

	int row = 0, col = 0, r = 0, c = 0, q = 0;
	int timer = rand() % 5 + 1;
	gotoxy(65, 34);
	printf("LOGGING OFF...");
	gotoxy(60, 36);
	for (r = 1; r <= timer; r++)
	{
		for (q = 0; q <= 100000000; q++);//to display the character slowly
		printf("%c", 177);
	}
	Sleep(100);
	system("cls");
}

void Utilities::GotoXY(int x, int y)
{

	fflush(stdout);
	b.X = x;
	b.Y = y;
	a = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(a, b);
}

void Utilities::Boarder()
{
	int i = 0;
	system("cls");
	for (i = 10; i < 140; i++)
	{
		GotoXY(i, 10);
		cout << "=";
		GotoXY(i, 58);
		cout << "=";
	}
	for (i = 10; i < 58; i++)
	{
		GotoXY(10, i);
		cout << "|";
		GotoXY(140, i);
		cout << "|";
	}
}

void Utilities::art()
{
	Boarder();
	gotoxy(0, 20);

	ifstream ifs("art.txt");
	string Lines = "";

	if (ifs)
	{
		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}

		cout << Lines;
		date();
	}

	ifs.close();
}

void Utilities::welcome()
{
	Boarder();
	gotoxy(0, 30);
	ifstream ifs("welcome.txt");
	string Lines = "";

	if (ifs)
	{
		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}

		cout << Lines;


	}
	cout << "\n\t  |\t\t\t\t\t\t\t";
	ifs.close();
	Sleep(1000);

}

void Utilities::exitArt()
{

	Boarder();
	gotoxy(0, 30);
	ifstream ifs("exit art.txt");
	string Lines = " ";

	if (ifs)
	{
		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}

		cout << Lines;

	}
	cout << "\n\t  |\t\t\t\t\t\t\t";
	ifs.close();
	Sleep(3000);
	exit(0);
}
