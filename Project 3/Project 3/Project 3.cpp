// Project 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void DisplayStore();
void askCustomers();
void askDrinks();
void askTypeD();
void askTypeS();
void askSand();
void readCustomers(short numc);
void readDrinks(short numd);
void readSand(short nums);
void readTypeD(char ch);
void readTypeS(short numi);
void 

int main()
{
    std::cout << "Hello World!\n";

    short numC, numS, numD, numI;
    char d;

   
}

void DisplayStore()
{
    cout << "------ 7-11 Convenient Store ------" << endl;
    cout << "Drinks" << endl << "  Soda(S)... $2" << endl;
    cout << "  Water(W)... $1" << endl << "Sandwhiches" << endl;
    cout << "  10 inches... $3" << endl << "  12 inches... $5" << endl << endl;
}

void askCustomers()
{
    cout << "Enter the number of customers: ";
}

void readCustomers(short numc)
{
    cin >> numc;
}

void askDrinks()
{
    cout << "How many drinks? ";
}

void readDrinks(short numd)
{
    cin >> numd;
}

void askTypeD()
{
    cout << "What kind of drink (S=Soda, W=Water)? ";
}

void readTypeD(char ch)
{
    cin >> ch;
}

void askSand()
{
    cout << "How many Sandwhiches? ";
}

void askTypeS()
{
    cout << "What size of sandwhich (10/12 inches)? ";
}

void readTypeS(short numi)
{
    cin >> numi;
}