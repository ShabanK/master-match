#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
#include <algorithm>

using namespace std;

// simply moves the cursor to where i want it to be
void gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
// a litte welcome screen i put together... it supposed to be reminiscent of old arcade games
void welcome()
{
	system("color B1");
	for (int j = 0; j < 2000; j++)
	{
		cout << "*";
	}		
	Sleep(100);
	system("cls");
	for (int j = 0; j < 2000; j++)
	{
		cout << "+";
	}
	Sleep(100);
	system("cls");
	for (int j = 0; j < 2000; j++)
	{
		cout << "$";
	}
	Sleep(100);
	system("cls");
	for (int j = 0; j < 2000; j++)
	{
		cout << "%";
	}		
	Sleep(100);
	system("cls");
	Sleep(1000);
	cout << "LOADING.";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(1000);
	string welcoming = "WELCOME TO MASTER MATCH! \\(O.O)/";
	for (int y = 1; y < 10; y++)
	{
		system("cls");
		gotoxy(24, y);
		cout << welcoming << endl;
		Sleep(200);
	}
	Sleep(200);
	cout << endl << setw(60) << "Final Project by Shaban Khawar/BSEF17M505";
	Sleep(200);
	cout << endl << endl << setw(51) << "Press any key to start\n";
	while (true)
	{
		if (_kbhit())
		{
			break;
		}
	}
	system("cls");
}
// makes the user choose between single player and two player... had to use cin.clear and cin.ignore to avoid an infinite loop that occurs when you enter anything other than a number
int game_mode_select()
{
	while (true)
	{
		system("color E6");
		gotoxy(25, 10);
		cout << "Please pick a mode to play in: ";
		gotoxy(26, 12);
		cout << "Enter 1 for Single-Player";
		gotoxy(26, 14);
		cout << "Enter 2 for Two-Player";
		gotoxy(56, 10);
		int c = 0;
		while (true)
		{
			gotoxy(56, 10);
			if (!(cin >> c))
			{
				cin.clear();
				cin.ignore();
				system("cls");
				gotoxy(12, 18);
				cout << "1 or 2 mate... Is it hard too hard to follow instructions?";
				break;
			}
			if ((c == 1) || (c==2))
			{
				return c;
			}
			else
			{
				system("cls");
				gotoxy(12, 18);
				cout << "1 or 2 mate... Is it hard too hard to follow instructions?";
				break;
			}
		}
	}
}
// pretty similar to the function above this one... difficulty determines the number of slots in the combination the player will get... i couldve made the code shorter making the function return 3, 4 or 5 instead of 1, 2 or 3 and then have them translated to 3, 4 and 5, but by the time im writing these comments, its already been done and im not going to bother... "if it ain't broke, dont fix it"
int difficulty()
{
	while (true)
	{
		system("color D6");
		gotoxy(20, 8);
		cout << "Please select your desired difficulty level: ";
		gotoxy(28, 10);
		cout << "Enter 1 for Easy";
		gotoxy(28, 12);
		cout << "Enter 2 for Intermediate";
		gotoxy(28, 14);
		cout << "Enter 3 for Hard";
		gotoxy(65, 8);
		int c = 0;
		while (true)
		{
			if (!(cin >> c))
			{
				cin.clear();
				cin.ignore();
				system("cls");
				gotoxy(12, 18);
				cout << "1, 2 or 3 mate... Is it hard too hard to follow instructions?";
				break;
			}
			if ((c == 1) || (c == 2) || (c==3))
			{
				return c;
			}
			else
			{
				gotoxy(9, 18);
				cout << "1, 2 or 3 mate... Is it hard too hard to follow instructions?";
				gotoxy(65, 8);
				cout << "                ";
				break;
			}
		}
	}
}
// the translation thing mentioned in the earlier comment....
int slots(int x)
{
	if (x == 1)
		return 3;
	else if (x == 2)
		return 4;
	else if (x == 3)
		return 5;
}
// the code generated by the program for single-player... it generates a number from 1 to 7... i associated each number with a color... it also makes sure that a number isnt repeated...
void cpu_code(int &a, int &b, int &c, int &d, int&e, int s)
{
	srand(time(NULL));
	a = rand() % 7 + 1;
	do
	{
		b = rand() % 7 + 1;
	} while (a == b);
	do
	{
		c = rand() % 7 + 1;
	} while ((c == b) || (c == a));
	do
	{
		d = rand() % 7 + 1;
	} while ((d == a) || (d == b) || (d == c));

	do
	{
		e = rand() % 7 + 1;
	} while ((e == a) || (e == b) || (e == c) || (e == d));
}
// the layout of the game for single player... i didnt use system("cls") for this because i thought it would be complicated to not use a static background...
void single_outlay(int s)
{
	system("color 0F");
	cout << "\n\n\n\n";
	for (int i = 15; i >= 1; i--)
	{
		cout << setw(15) << i << "|" << setw(20) << "| - | - |" << endl;
	}
	gotoxy(28, 4);
	cout << "C.C C.P";
	gotoxy(19, 3);
	cout << "SLOTS";
	gotoxy(0, 5);
	cout << "COLORS" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0| FOREGROUND_BLUE );  // a neat function to control background color and text color.... unlike the system color function i used before... because that changes the entire console's BG color and text color once implmented... this only affects the parts ahead of it 
	cout << "BLUE" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN);
	cout << "GREEN" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 3);
	cout << "AQUA" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_RED);
	cout <<  "RED" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 5);
	cout <<  "PURPLE" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 14);
	cout <<  "YELLOW" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 8);
	cout << "GRAY";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 7);
	if (s == 3)
	{
		for (int i = 1; i <= 15; i++)
		{
			gotoxy(16, 4+i);
			cout << "   * * *   ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
		gotoxy(19, 4);
		cout << "1 2 3";
	}
	else if (s == 4)
	{
		for (int i = 1; i <= 15; i++)
		{
			gotoxy(16, 4 + i);
			cout << "  * * * *  ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
		gotoxy(18, 4);
		cout << "1 2 3 4";
	}
	else
	{
		for (int i = 1; i <= 15; i++)
		{
			gotoxy(16, 4 + i);
			cout << " * * * * * ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
		gotoxy(17, 4);
		cout << "1 2 3 4 5";
	}
}
// pretty similar to the single player outlay... pretty much copy-pasted and put at a difference of 34 units
void double_outlay(int s)
{
	system("color 0F");
	cout << "\n\n\n\n";
	for (int i = 15; i >= 1; i--)
	{
		cout << setw(15) << i << "|" << setw(20) << "| - | - |"<< setw(13) << i << "|" << setw(20) << "| - | - |" << endl;
	}
	gotoxy(28, 4);
	cout << "C.C C.P" << setw(34) << "C.C C.P";
	gotoxy(19, 3);
	cout << "SLOTS" << setw(34) << "SLOTS";
	gotoxy(0, 5);
	cout << "COLORS" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_BLUE);
	cout << "BLUE" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN);
	cout << "GREEN" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 3);
	cout << "AQUA" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_RED);
	cout << "RED" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 5);
	cout << "PURPLE" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 14);
	cout << "YELLOW" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 8);
	cout << "GRAY";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 7);
	if (s == 3)
	{
		for (int i = 1; i <= 15; i++)
		{
			gotoxy(16, 4 + i);
			cout << "   * * *   ";
			gotoxy(50, 4 + i);
			cout << "   * * *   ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
	}
	else if (s == 4)
	{
		for (int i = 1; i <= 15; i++)
		{
			gotoxy(16, 4 + i);
			cout << "  * * * *  ";
			gotoxy(50, 4 + i);
			cout << "  * * * *  ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
	}
	else
	{
		for (int i = 1; i <= 15; i++)
		{
			gotoxy(16, 4 + i);
			cout << " * * * * * ";
			gotoxy(50, 4 + i);
			cout << " * * * * * ";
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
	}
}
// an input validator as mentioned in the proposal... i took into account all the possible ways a person might want to refer to the colors
bool input_vld(string a)
{
	if ((a == "RED") || (a == "red") || (a == "R") || (a == "r") || (a == "BLUE") || (a == "blue") || (a == "b") || (a == "B") || (a == "yellow") || (a == "YELLOW") || (a == "Y") || (a == "y") || (a == "aqua") || (a == "a") || (a == "AQUA") || (a == "A") || (a == "purple") || (a == "PURPLE") || (a == "p") || (a == "P") || (a == "gray") || (a == "grey") || (a == "GRAY") || (a == "GREY") || (a == "green") || (a == "GREEN") || (a == "e") || (a == "E") || (a == "exit") || (a == "EXIT"))
		return true;
	else
		return false;
}
// pretty obvious what this does... takes a string input and prints a letter with the correct hue in the spot i want it to...
void slotfill(string a)
{
	if ((a == "R") || (a == "RED"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_RED);
		cout << "R";
	}
	if ((a == "BLUE") || (a == "B"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_BLUE);
		cout << "B";
	}
	if ((a == "AQUA") || (a == "A"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 3);
		cout << "A";
	}
	if ((a == "YELLOW") || (a == "Y"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 14);
		cout << "Y";
	}
	if ((a == "PURPLE") || (a == "P"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 5);
		cout << "P";
	}
	if ((a == "GRAY") || (a == "GREY"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 8);
		cout << "G";
	}
	if ((a == "GREEN"))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN);
		cout << "G";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
}
// since the code is actually dealt with numbers back-end, this takes a string input and converts it into a number
void backendo(string a, int &num)
{
	if ((a == "R") || (a == "RED"))
	{
		num = 4;
	}
	if ((a == "BLUE") || (a == "B"))
	{
		num = 1;
	}
	if ((a == "AQUA") || (a == "A"))
	{
		num = 3;
	}
	if ((a == "YELLOW") || (a == "Y"))
	{
		num = 6;
	}
	if ((a == "PURPLE") || (a == "P"))
	{
		num = 5;
	}
	if ((a == "GRAY") || (a == "GREY"))
	{
		num = 7;
	}
	if ((a == "GREEN"))
	{
		num = 2;
	}
}
// name's pretty self evident
void reverse_backendo(int a)
{
	if (a==4)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_RED);
		cout << "R";
	}
	if (a==1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_BLUE);
		cout << "B";
	}
	if (a==3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 3);
		cout << "A";
	}
	if (a==6)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 14);
		cout << "Y";
	}
	if (a==5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 5);
		cout << "P";
	}
	if (a==7)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 8);
		cout << "G";
	}
	if (a == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | FOREGROUND_GREEN);
		cout << "G";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 15);
}
// the gameplay portion of the single player mode... calls a bunch of the above functions... a lot of gotoxy usage but it works
void singleplayer(int a)
{
	system("cls");
	system("color F3");
	gotoxy(31, 10);
	cout << "Enter your name: ";
	string p1 = "";
	cin.ignore();
	getline(cin, p1);
	while (p1.empty())
	{
		gotoxy(20, 12);
		cout << "Pretty sure you can read... Why not comply?";
		gotoxy(48, 10);
		getline(cin, p1);
	}
	transform(p1.begin(), p1.end(), p1.begin(), ::toupper);
	system("cls");
	int slot[5] = { 0 };
	string attempt[5];
	int backend[5] = { 0 };
	cout << endl;
	single_outlay(a);
	gotoxy(1, 1);
	string filename = p1;
	ofstream file(filename.append(".txt"), ios::app);
	file << "A Single Player Game Played by " << p1 << " apparently..." << endl;
	cpu_code(slot[0], slot[1], slot[2], slot[3], slot[4], a);
	cout << slot[0] << slot[1] << slot[2] << slot[3] << slot[4]<< endl; //uncomment to play with cheats (-_O)... you can find what the numbers mean in the backendo functions
	file << "The generated code was ";
	for (int i = 0; i < a; i++)
	{
		file << slot[i];
	}
	file << endl;
	file << "This translates to : ";
	for (int i = 0; i < a; i++)
	{
		if (slot[i] == 4)
		{
			file << "RED ";
		}
		if (slot[i] == 1)
		{
			file << "BLUE ";
		}
		if (slot[i] == 3)
		{
			file << "AQUA ";
		}
		if (slot[i] == 6)
		{
			file << "YELLOW ";
		}
		if (slot[i] == 5)
		{
			file << "PURPLE ";
		}
		if (slot[i] == 7)
		{
			file << "GREY ";
		}
		if (slot[i] == 2)
		{
			file << "GREEN ";
		}
	}
	file << endl << "Moving on to the gameplay...\n";
	for (int i = 1; i <= 15; i++)
	{
		gotoxy(10, 21);
		cout << "Attempt " << i << ": ";
		file << "Attempt " << i << ": \n";
		int CC = 0, CP = 0;
		for (int j = 1; j <= a; j++)
		{
			gotoxy(23, 21);
			cout << "Take a guess at what color is in slot " << j << ": ";
			getline(cin, attempt[j - 1]);
			while (!input_vld(attempt[j - 1]))
			{
				gotoxy(14, 23);
				cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
				gotoxy(64, 21);
				cout << "                                                                                 ";
				gotoxy(64, 21);
				getline(cin, attempt[j - 1]);
			}
			transform(attempt[j - 1].begin(), attempt[j - 1].end(), attempt[j - 1].begin(), ::toupper);
			if ((attempt[j - 1] == "EXIT") || (attempt[j - 1] == "E"))
			{
				file << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
				exit(0);
			}
			file << attempt[j-1] << " ";
			backendo(attempt[j - 1], backend[j - 1]);
			gotoxy(62, 21);
			cout << "                                                                                                                                                                        ";
			int k = 19 - (a - 3) + 2 * (j - 1);			//came up with formula myself, kinda proud of it...
			int m = 20 - i;
			gotoxy(k,m);
			slotfill(attempt[j - 1]);
		}
		for (int k = 0; k < a; k++)
		{
			if (backend[k] == slot[k])
				CP++;
			for (int m = 0; m < a; m++)
			{
				if (backend[k] == slot[m])
				{
					CC++;
					if (k == 1)
					{
						if ((backend[k] == backend[k - 1]))
						{
							CC--;
						}
					}
					if (k == 2)
					{
						if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]))
						{
							CC--;
						}
					}
					if (k == 3)
					{
						if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]) || (backend[k] == backend[k - 3]))
						{
							CC--;
						}
					}
					if (k == 4)
					{
						if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]) || (backend[k] == backend[k - 3]) || (backend[k] == backend[k - 4]))
							CC--;
					}
					break;
				}
			}
		}
		gotoxy(29, 20 - i);
		cout << CC << " | " << CP;
		file << "\nResults of this attempt: " << endl << "Correct Color: " << CC << endl << "Correct Position: " << CP << endl;
		if (CP == a)
		{
			file << p1 << " guessed it after " << i << " attempts...\n<---------------------- GAME ENDED HERE ---------------------->\n";
			for (int j = 1; j <= a; j++)
			{
				int x = 19 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(slot[j - 1]);
			}
			gotoxy(5, 21);
			cout << "CONGRATULATIONS! YOU GUESSED IT! PRESS ANY BUTTON TO GET YOUR PRIZE!";
			if (_getch())
			{
				break;
			}
		}
		if ((CP != a) && (i == 15))
		{
			file << p1 << " failed to guess the code.. RIP!";
			for (int j = 1; j <= a; j++)
			{
				int x = 19 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(slot[j - 1]);
			}
			gotoxy(5, 21);
			cout << "GAME OVER!!! PRESS ANY BUTTON TO SEE WHAT YOU GET FOR YOUR EFFORT";
			if (_getch())
			{
				break;
			}
		}
	}
	file.close();
	system("cls");
	system("color F0");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\tyeah you're getting nothing...\n\t\t\t    press a button again...";
	_getch();
	
}
//in two player mode... the users will set a code for each other.. or you can just play as both players if u have no friends and set the code for yourself... once done... it acts exactly similar to the cpu_code
void customcode(int &a, int &b, int &c, int &d, int &e, int q, int t, ofstream &file2)
{
	string color = " ";
	gotoxy(44, 22);
	cout << "                    ";
	gotoxy(20, 22);
	cout << "Enter color for slot 1: ";
	getline(cin, color);
	while (!input_vld(color))
	{
		gotoxy(13, 23);
		cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
		gotoxy(44, 22);
		cout << "                                ";
		gotoxy(44, 22);
		getline(cin, color);
	}
	transform(color.begin(), color.end(), color.begin(), ::toupper);
	if ((color == "EXIT") || (color == "E"))
	{
		file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
		exit(0);
	}
	backendo(color, a);
	int k = 19 + t - (q - 3);
	int m = 4;
	gotoxy(k, m);
	reverse_backendo(a);
	gotoxy(13, 23);
	for (int i = 1; i <= 55; i++)
	{
		cout << " ";
	}
	b = a;
	while (b == a)
	{
		gotoxy(44, 22);
		cout << "                    ";
		gotoxy(20, 22);
		cout << "Enter color for slot 2: ";
		getline(cin, color);
		while (!input_vld(color))
		{
			gotoxy(13, 23);
			cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
			gotoxy(44, 22);
			cout << "                             ";
			gotoxy(44, 22);
			getline(cin, color);
		}
		gotoxy(13, 23);
		for (int i = 1; i <= 55; i++)
		{
			cout << " ";
		}
		transform(color.begin(), color.end(), color.begin(), ::toupper);
		if ((color == "EXIT") || (color == "E"))
		{
			file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
			exit(0);
		}
		backendo(color, b);
	}
	k = 19 + t - (q - 3) + 2;
	gotoxy(k, m);
	reverse_backendo(b);
	c = b;
	while ((c == a) || (c==b))
	{
		gotoxy(44, 22);
		cout << "                    ";
		gotoxy(20, 22);
		cout << "Enter color for slot 3: ";
		getline(cin, color);
		while (!input_vld(color))
		{
			gotoxy(13, 23);
			cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
			gotoxy(44, 22);
			cout << "                             ";
			gotoxy(44, 22);
			getline(cin, color);
		}
		gotoxy(13, 23);
		for (int i = 1; i <= 55; i++)
		{
			cout << " ";
		}
		transform(color.begin(), color.end(), color.begin(), ::toupper);
		if ((color == "EXIT") || (color == "E"))
		{
			file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
			exit(0);
		}
		backendo(color, c);
	}
	k = 19 + t - (q - 3) + 4;
	gotoxy(k, m);
	reverse_backendo(c);
	if (q > 3)
	{
		d = c;
		while ((d==c) ||(d == a) || (d == b))
		{
			gotoxy(44, 22);
			cout << "                    ";
			gotoxy(20, 22);
			cout << "Enter color for slot 3: ";
			getline(cin, color);
			while (!input_vld(color))
			{
				gotoxy(13, 23);
				cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
				gotoxy(44, 22);
				cout << "                             ";
				gotoxy(44, 22);
				getline(cin, color);
			}
			gotoxy(13, 23);
			for (int i = 1; i <= 55; i++)
			{
				cout << " ";
			}
			transform(color.begin(), color.end(), color.begin(), ::toupper);
			if ((color == "EXIT") || (color == "E"))
			{
				file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
				exit(0);
			}
			backendo(color, d);
		}
		k = 19 + t - (q - 3) + 6;
		gotoxy(k, m);
		reverse_backendo(d);
	}
	if (q == 5)
	{
		e = d;
		while ((e==d)|| (e==d) || (d == a) || (d == b))
		{
			gotoxy(44, 22);
			cout << "                    ";
			gotoxy(20, 22);
			cout << "Enter color for slot 3: ";
			getline(cin, color);
			while (!input_vld(color))
			{
				gotoxy(13, 23);
				cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
				gotoxy(44, 22);
				cout << "                             ";
				gotoxy(44, 22);
				getline(cin, color);
			}
			gotoxy(13, 23);
			for (int i = 1; i <= 55; i++)
			{
				cout << " ";
			}
			transform(color.begin(), color.end(), color.begin(), ::toupper);
			if ((color == "EXIT") || (color == "E"))
			{
				file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
				exit(0);
			}
			backendo(color, e);
		}
		k = 19 + t - (q - 3) + 8;
		gotoxy(k, m);
		reverse_backendo(e);
	}
	if (q == 3)
	{
		gotoxy(19+t, 4);
		cout << "1 2 3";
	}
	else if (q == 4)
	{
		gotoxy(18+t, 4);
		cout << "1 2 3 4";
	}
	else if (q == 5)
	{
		gotoxy(17+t, 4);
		cout << "1 2 3 4 5";
	}
	gotoxy(0, 21);
	for (int i = 1; i <= 240; i++)
	{
		cout << " ";
	}
}
// the gameplay portion of the two player mode... the actual fun part of the program...
void twoplayer(int a)
{
	system("cls");
	system("color F3");
	gotoxy(26, 10);
	cout << "Player 1, enter your name: ";
	string p1 = " ";
	cin.ignore();
	getline(cin, p1);
	while (p1.empty())
	{
		gotoxy(20, 12);
		cout << "Pretty sure you can read... Why not comply?";
		gotoxy(53, 10);
		getline(cin, p1);
	}
	transform(p1.begin(), p1.end(), p1.begin(), ::toupper);
	system("cls");
	gotoxy(26, 10);
	cout << "Player 2, enter your name: ";
	string p2 = " ";
	getline(cin, p2);
	while (p2.empty())
	{
		gotoxy(20, 12);
		cout << "Pretty sure you can read... Why not comply?";
		gotoxy(53, 10);
		getline(cin, p2);
	}
	transform(p2.begin(), p2.end(), p2.begin(), ::toupper);
	system("cls");
	string filename = p1;
	filename.append(" v ");
	filename.append(p2);
	filename.append(".txt");
	int player_1c[5];
	int player_2c[5];
	string attempt[5];
	int backend[5];
	cout << endl;
	double_outlay(a);
	gotoxy(0, 21);
	ofstream file2(filename, ios::app);
	file2 << "A Two-Player Game Player b/w " << p1 << " and " << p2 << endl;
	cout << " Player 1, look away while Player 2 sets your code. Same colors are not allowed" << endl;
	int t = 0;
	customcode(player_1c[0], player_1c[1], player_1c[2], player_1c[3], player_1c[4], a, t, file2);
	file2 << "The code set for " << p1 << " by " << p2 << " was ";
	for (int r = 0; r < a; r++)
	{
		file2 << player_1c[r] << " ";
	}
	file2 << endl << "This translates to: ";
	for (int i = 0; i < a; i++)
	{
		if (player_1c[i] == 4)
		{
			file2 << "RED ";
		}
		if (player_1c[i] == 1)
		{
			file2 << "BLUE ";
		}
		if (player_1c[i] == 3)
		{
			file2 << "AQUA ";
		}
		if (player_1c[i] == 6)
		{
			file2 << "YELLOW ";
		}
		if (player_1c[i] == 5)
		{
			file2 << "PURPLE ";
		}
		if (player_1c[i] == 7)
		{
			file2 << "GREY ";
		}
		if (player_1c[i] == 2)
		{
			file2 << "GREEN ";
		}
	}
	file2 << endl;
	t = 34;
	gotoxy(0, 21);
	cout << " Player 2, look away while Player 1 sets your code. Same colors are not allowed" << endl;
	customcode(player_2c[0], player_2c[1], player_2c[2], player_2c[3], player_2c[4], a, t, file2);
	file2 << "The code set for " << p2 << " by " << p1 << " was ";
	for (int r = 0; r < a; r++)
	{
		file2 << player_2c[r] << " ";
	}
	file2 << endl << "This translates to: ";
	for (int i = 0; i < a; i++)
	{
		if (player_2c[i] == 4)
		{
			file2 << "RED ";
		}
		if (player_2c[i] == 1)
		{
			file2 << "BLUE ";
		}
		if (player_2c[i] == 3)
		{
			file2 << "AQUA ";
		}
		if (player_2c[i] == 6)
		{
			file2 << "YELLOW ";
		}
		if (player_2c[i] == 5)
		{
			file2 << "PURPLE ";
		}
		if (player_2c[i] == 7)
		{
			file2 << "GREY ";
		}
		if (player_2c[i] == 2)
		{
			file2 << "GREEN ";
		}
	}
	file2 << endl << "Moving on to the gameplay...\n";
	gotoxy(5, 21);
	cout << "Player  : ";
	for (int i = 1; i <= 15; i++)
	{
		gotoxy(15, 21);
		file2 << "Attempt " << i << ": " << endl;
		cout << "Attempt " << i << ": ";
		//player 1's turn
			file2 << p1 << "'s Turn:" << endl;
			int p = 1;
			int CC1 = 0, CP1 = 0;
			gotoxy(12, 21);
			cout << p;
			for (int j = 1; j <= a; j++)
			{
				gotoxy(27, 21);
				cout << "Take a guess at what color is in slot " << j << ": ";
				getline(cin, attempt[j - 1]);
				while (!input_vld(attempt[j - 1]))
				{
					gotoxy(14, 23);
					cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
					gotoxy(68, 21);
					cout << "                                                              ";
					gotoxy(68, 21);
					getline(cin, attempt[j - 1]);
				}
				transform(attempt[j - 1].begin(), attempt[j - 1].end(), attempt[j - 1].begin(), ::toupper);
				if ((attempt[j - 1] == "EXIT") || (attempt[j - 1] == "E"))
				{
					file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
					exit(0);
				}
				file2 << attempt[j-1] << " ";
				backendo(attempt[j - 1], backend[j - 1]);
				gotoxy(66, 21);
				cout << "                                                                                                                                                                        ";
				int k = 19 - (a - 3) + 2 * (j - 1);	
				int m = 20 - i;
				gotoxy(k, m);
				slotfill(attempt[j - 1]);
			}
			for (int k = 0; k < a; k++)
			{
				if (backend[k] == player_1c[k])
					CP1++;
				for (int m = 0; m < a; m++)
				{
					if (backend[k] == player_1c[m])
					{
						CC1++;
						if (k == 1)
						{
							if ((backend[k] == backend[k - 1]))
							{
								CC1--;
							}
						}
						if (k == 2)
						{
							if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]))
							{
								CC1--;
							}
						}
						if (k == 3)
						{
							if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]) || (backend[k] == backend[k - 3]))
							{
								CC1--;
							}
						}
						if (k == 4)
						{
							if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]) || (backend[k] == backend[k - 3]) || (backend[k] == backend[k - 4]))
								CC1--;
						}
						break;
					}
				}
			}
			gotoxy(29, 20 - i);
			cout << CC1 << " | " << CP1;
			file2 << endl << p1 << "'s Results from Attempt " << i << ": " << endl << "Correct Color: " << CC1 << endl << "Correct Position: " << CP1 << endl;
	
		//player 2's turn
			p = 2;
			file2 << p2 << "'s Turn:" << endl;
			int CC2 = 0, CP2 = 0;
			gotoxy(12, 21);
			cout << p;
			gotoxy(23, 21);
			cout << i;
			for (int j = 1; j <= a; j++)
			{
				gotoxy(27, 21);
				cout << "Take a guess at what color is in slot " << j << ": ";
				getline(cin, attempt[j - 1]);
				while (!input_vld(attempt[j - 1]))
				{
					gotoxy(14, 23);
					cout << "INVALID INPUT! PICK ONE OF THE COLORS ON THE LEFT!";
					gotoxy(68, 21);
					cout << "                                                                    ";
					gotoxy(68, 21);
					getline(cin, attempt[j - 1]);
				}
				transform(attempt[j - 1].begin(), attempt[j - 1].end(), attempt[j - 1].begin(), ::toupper);
				if ((attempt[j - 1] == "EXIT") || (attempt[j - 1] == "E"))
				{
					file2 << "<---------------------- GAME WAS ABORTED HERE ---------------------->\n";
					exit(0);
				}
				file2 << attempt[j - 1] << " ";
				backendo(attempt[j - 1], backend[j - 1]);
				gotoxy(66, 21);
				cout << "                                                                                                                                                                        ";
				int k = 19+34 - (a - 3) + 2 * (j - 1);
				int m = 20 - i;
				gotoxy(k, m);
				slotfill(attempt[j - 1]);
			}
			for (int k = 0; k < a; k++)
			{
				if (backend[k] == player_2c[k])
					CP2++;
			for (int m = 0; m < a; m++)
			{
				if (backend[k] == player_2c[m])
				{
						CC2++;
						if (k == 1)
						{
							if ((backend[k] == backend[k - 1]))
							{
								CC2--;
							}
						}
						if (k == 2)
						{
							if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]))
							{
								CC2--;
							}
						}
						if (k == 3)
						{
							if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]) || (backend[k] == backend[k - 3]))
							{
								CC2--;
							}
						}
						if (k == 4)
						{
							if ((backend[k] == backend[k - 1]) || (backend[k] == backend[k - 2]) || (backend[k] == backend[k - 3]) || (backend[k] == backend[k - 4]))
								CC2--;
						}
					break;
				}
			}
		}
		gotoxy(29 + 34, 20 - i);
		cout << CC2 << " | " << CP2;
		file2 << endl << p2 << "'s Results from Attempt " << i << ": " << endl << "Correct Color: " << CC2 << endl << "Correct Position: " << CP2 << endl;
		if ((i == 15) && (CP1 != a) && (CP2 != a))
		{
			file2 << "Both players were unable to guess after 15 attempts... RIP!\n<---------------------- GAME ENDED HERE ---------------------->\n";
			for (int j = 1; j <= a; j++)
			{
				int x = 19 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_1c[j - 1]);
				x = 19 + 34 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_2c[j - 1]);
			}
			gotoxy(0, 21);
			cout << "GAME OVER FOR BOTH OF YOU! PRESS ANY BUTTON TO SEE WHAT YOU GET FOR YOUR EFFORT";
			if (_getch())
			{
				break;
			}
		}
		if ((CP1 == a) && (CP2==a))
		{
			file2 << "Both players guessed it at the attempt "<< i <<  "! CONGRATS!\n<---------------------- GAME ENDED HERE ---------------------->\n";
			for (int j = 1; j <= a; j++)
			{
				int x = 19 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_1c[j - 1]);
				x = 19 + 34 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_2c[j - 1]);
			}
			gotoxy(0, 21);
			cout << " WOW! GOOD JOB BOTH OF YOU... YOU BOTH GET A REWARD!!! PRESS ANY BUTTON FOR IT";
			if (_getch())
			{
				break;
			}
		}
		if (CP1 == a)
		{
			file2 << p1 << " guessed it at attempt " << i << "! " << p2 << " loses...\n<---------------------- GAME ENDED HERE ---------------------->\n";
			for (int j = 1; j <= a; j++)
			{
				int x = 19 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_1c[j - 1]);
				x = 19 + 34 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_2c[j - 1]);
			}
			gotoxy(0, 21);
			cout << "GGWP PLAYER 1... YOU WIN THIS ONE... PRESS ANY BUTTON FOR A REWARD FOR THIS WIN!";
			if (_getch())
			{
				break;
			}
		}
		if (CP2 == a)
		{
			file2 << p2 << " guessed it at attempt " << i << "! " << p1 << " loses...\n<---------------------- GAME ENDED HERE ---------------------->\n";
			for (int j = 1; j <= a; j++)
			{
				int x = 19 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_1c[j - 1]);
				x = 19 + 34 - (a - 3) + 2 * (j - 1);
				gotoxy(x, 4);
				reverse_backendo(player_2c[j - 1]);
			}
			gotoxy(0, 21);
			cout << "GGWP PLAYER 2... YOU WIN THIS ONE... PRESS ANY BUTTON FOR A REWARD FOR THIS WIN!";
			if (_getch())
			{
				break;
			}
		}
	}
	file2.close();
	system("cls");
	system("color F0");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\tyeah you're getting nothing...\n\t\t\t    press a button again...";
	_getch();
}
// i did my best to explain how the game works...
void instructions()
{
	system("cls");
	system("color F0");
	int y = 4;
	int x = 35;
	gotoxy(x, y);
	cout << "How to Play";
	y += 2;
	x = 0;
	gotoxy(x, y);
	cout << " -> In this game, you need to guess the combination set by your opponent";
	y++;
	gotoxy(x, y);
	cout << " -> It can be a combination of 3, 4 or 5 colors, based on the difficulty";
	y++;
	gotoxy(x, y);
	cout << " -> Easy mode has 3, intermediate has 4 and and hard has 5 color combinations";
	y++;
	gotoxy(x, y);
	cout << " -> You will have 15 attempts to crack the code!";
	y++;
	gotoxy(x, y);
	cout << " -> After each wrong guess, you will get two hints: ";
	y++;
	gotoxy(x, y);
	cout << "\t1) The number of correct colors used (CC)";
	y++;
	gotoxy(x, y);
	cout << "\t2) The number of colors in correct positions(CP)";
	y++;
	gotoxy(x, y);
	cout << " -> In single-player mode, you have to figure out the computer-generated code";
	y++;
	gotoxy(x, y);
	cout << "    in 15 attempts to win";
	y++;

	gotoxy(x, y);
	cout << " -> In two-player mode, you can play against a friend";
	y++;
	gotoxy(x, y);
	cout << " -> You can set combinations for each other, and whoever guesses first wins";
	y++;
	gotoxy(x, y);
	cout << " -> IF you both guess at the same attempt, it'll be a tie...";
	y++;
	gotoxy(x, y);
	cout << " -> That's it! GOOD LUCK HAVE FUN!";
	x = 20;
	y += 2;
	gotoxy(x, y);
	cout << "Press any key to return to the main menu\n";
	while (true)
	{
		if (_kbhit())
		{
			break;
		}
	}
}
// a liitle attempt at humor...
void devnotes()
{
	system("cls");
	system("color D5");
	int x = 5;
	int y = 5;
	gotoxy(x, y);
	cout << "Umm... so...";
	y++;
	Sleep(1000);
	gotoxy(x, y);
	cout << "I was going to add some witty things to say about this program...";
	y++;
	Sleep(1000);
	gotoxy(x, y);
	cout << "But honestly..";
	y++;
	Sleep(1500);
	gotoxy(x, y);
	cout << "Theres not really much to it...";
	y++;
	Sleep(1500);
	gotoxy(x, y);
	cout << "I just reused Sleep and gotoxy...";
	y++;
	Sleep(1500);
	gotoxy(x, y);
	cout << "And tried to make everything look pretty with the colors";
	y++;
	Sleep(2000);
	gotoxy(x, y);
	cout << "And I really didn't know what I would write in this portion...";
	y++;
	Sleep(2000);
	gotoxy(x, y);
	cout << "But I had already made this menu entry so I'm not going to waste it";
	y++;
	Sleep(2000);
	gotoxy(x, y);
	cout << "I'll add a joke here...";
	y++;
	Sleep(1500);
	gotoxy(x, y);
	cout << "What's a chef's favorite weapon?";
	y++;
	Sleep(5000);
	gotoxy(x, y);
	cout << "A-salt rifle...";
	y++;
	Sleep(2000);
	gotoxy(x, y);
	cout << "That's... all I got...";
	Sleep(3000);
	y++;
	y++;
	x = 20;
	gotoxy(x, y);
	cout << "Press any key to return to the main menu\n";
	while (true)
	{
		if (_kbhit())
		{
			break;
		}
	}
}
// giving credit to all the people who worked hard on this project
void credits()
{
	system("cls");
	system("color A0");
		int x = 34;
		int y = 5;
		gotoxy(x, y);
		cout << "Programming";
		y++;
		Sleep(500);
		x = 37;
		gotoxy(x, y);
		cout << "Text";
		y++;
		Sleep(500);
		gotoxy(x, y);
		cout << "Idea";
		y++;
		Sleep(500);
		x = 30;
		gotoxy(x, y);
		cout << "Basically everything";
		y++;
		Sleep(500);
		x = 36;
		gotoxy(x, y);
		cout << "Done by";
		y++;
		Sleep(500);
		x = 33;
		gotoxy(x, y);
		cout << "DudeOfNowhere";
		y++;
		Sleep(500);
		x = 37;
		gotoxy(x, y);
		cout << "a.k.a.";
		y++;
		Sleep(500);
		x = 33;
		gotoxy(x, y);
		cout << "Shaban Khawar";
		y++;
		Sleep(500);
		x = 35;
		gotoxy(x, y);
		cout << "BSEF17M505";
		y++;
		Sleep(500);
		y++;
		x = 20;
		gotoxy(x, y);
		cout << "Press any key to return to the main menu\n";
		while (true)
		{
			if (_kbhit())
			{
				break;
			}
		}
}
// calls the difficultly and mode functions... and launches the game...
void gameStarto()
{
	system("cls");
	int mode = game_mode_select();
	system("cls");
	int diff = difficulty();
	system("cls");
	int slot = slots(diff);
	int x = 30;
	int y = 11;
	gotoxy(x, y);
	system("color 34");
	cout << "Initializing Game ";
	Sleep(400);
	cout << ". ";
	Sleep(400);
	cout << ". ";
	Sleep(400);
	cout << ". ";
	if (mode == 1)
		singleplayer(slot);
	else if (mode == 2)
		twoplayer(slot);
	system("cls");

}
// i thought this would look pretty so i tried...
void main_menu()
{
	char updown = ' ';
	int counter = 0;
	string arrow = "<--";
	int x = 47;
	int y = 9;
	bool flag = true;
	while (flag)
	{
		system("cls");
		system("color CF");
		cout << "\n\n\n\n\n\n\n" << setw(45) << "MASTER MATCH" << endl << endl << setw(45) << "NEW GAME" << endl << setw(45) << "INSTRUCTIONS" << endl << setw(45) << "DEV'S NOTES" << endl << setw(45) << "CREDITS" << endl << setw(45) << "QUIT" << endl;
		gotoxy(x, y);
		cout << arrow;
		Sleep(300);
		_getch();
		{
			Sleep(200);
			if (GetAsyncKeyState(VK_UP))
			{
				if (y > 9)
				{
					y--;
				}
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				if (y < 13)
				{
					y++;
				}
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
				counter++;
				if (counter == 2)
				{
					if (y == 9)
					{
						gameStarto();
						system("color CF");
						cout << "\n\n\n\n\n\n\n\n\n\nReturn to main menu or would you like to quit? [Y for menu/N to quit]: ";
						string y_n = " ";
						while (true)
						{
							
							getline(cin, y_n);
							if ((y_n == "n") || (y_n == "N") || (y_n == "no") || (y_n == "NO") || (y_n == "No"))
							{
								flag = false;
								break;
							}
							else if ((y_n == "y") || (y_n == "Y") || (y_n == "yes") || (y_n == "YES") || (y_n == "Yes"))
							{
								flag = true;
								break;
							}
							else
								cout << "Invalid Input! [Y/N] types only: ";
						}
					}
					else if (y == 10)
					{
						instructions();
					}
					else if (y == 11)
					{
						devnotes();

					}
					else if (y == 12)
					{
						credits();
					}
					else if (y == 13)
					{
						system("cls");
						cout << "Are you sure you want to quit? [Y/N]: ";
						string y_n2 = " ";
						while (true)
						{
							getline(cin, y_n2);
							if ((y_n2 == "n") || (y_n2 == "N") || (y_n2 == "no") || (y_n2 == "NO") || (y_n2 == "No"))
							{
								flag = true;
								break;
							}
							else if ((y_n2 == "y") || (y_n2 == "Y") || (y_n2 == "yes") || (y_n2 == "YES") || (y_n2 == "Yes"))
							{
								flag = false;
								break;
							}
							else
								cout << "Invalid Input! [Y/N] types only: ";
						}
					}
					counter = 0;
				}
			}
		}
	}
}
void main()
{
	welcome();
	main_menu();
}