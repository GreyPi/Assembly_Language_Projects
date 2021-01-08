// Project 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Gregory Pierot

#include <iostream>
using namespace std;

void enterArea();
void displayT();
void displayR();

float a, b, c, h;
float l, w;
float half = 0.5, two = 2;
float areaT, areaR, perT, perR;

void enterQuad();
void displayQuad();

float negone = -1, four = 4;
float x1, x2, b2;

int main()
{
    _asm
    {
        // Q1
        call enterArea;
        fld half;
        fld c;
        fld h;
        fmul;
        fmul;
        fstp areaT;
        fld a;
        fld b;
        fld c;
        fadd;
        fadd;
        fstp perT;
        call displayT;
        fld l;
        fld w;
        fmul;
        fstp areaR;
        fld two;
        fld l;
        fld w;
        fadd;
        fmul;
        fstp perR;
        call displayR;

        // Q2
        // X1
        call enterQuad;
        fld b;
        fld b2;
        fmul;
        fld four;
        fld a;
        fld c;
        fmul;
        fmul;
        fsub;
        fsqrt;
        fld negone;
        fld b;
        fmul;
        fadd;
        fld a;
        fld two;
        fmul;
        fdiv;
        fstp x1;
        // X2
        fld b;
        fld negone;
        fmul;
        fld b;
        fld b2;
        fmul;
        fld four;
        fld a;
        fld c;
        fmul;
        fmul;
        fsub;
        fsqrt;
        fsub;
        fld a;
        fld two;
        fmul;
        fdiv;
        fstp x2;
        call displayQuad;

    }
    
    return 0;
}

void displayT()
{
    cout << "Triangle" << endl
        << "\tArea...." << areaT << endl
        << "\tPerimeter...." << perT << endl;
}

void displayR()
{
    cout << "Rectangle" << endl
        << "\tArea...." << areaR << endl
        << "\tPerimeter...." << perR << endl << endl;
}

void enterArea()
{
    cout << "Enter the values of a, b, c, and h for the triangle: ";
    cin >> a >> b >> c >> h;
    cout << "Enter the length and the width of the rectangle: ";
    cin >> l >> w;
    cout << endl << endl;
}

void enterQuad()
{
    cout << "To see the two real roots of ax^2 + bx + c = 0, "
        << "enter the a, b, and c values: ";
    cin >> a >> b >> c;
    b2 = b;
}

void displayQuad()
{
    cout << endl << "X1 = " << x1 << "\t" << "X2 = " << x2;
}