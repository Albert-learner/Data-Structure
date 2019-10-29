#include <iostream>
#include <fstream>
using namespace std;

#define MAX_TERMS 100

typedef struct
{
	float coef;
	int expon;
}Polynomial;

Polynomial terms[MAX_TERMS];
Polynomial result[MAX_TERMS];
int avail = 0;

char COMPARE(int x, int y)
{
	if (x > y)
		return 1;
	else if (x < y)
		return -1;
	else
		return 0;
}

void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS)
	{
		cout << "too many elements...";
		exit(1);
	}
	

	result[avail].coef = coefficient;
	result[avail].expon = exponent;
	avail++;
}

void padd(int starta, int finisha, int startb, int finishb)
{
	float coefficient;


	while (starta <= finisha && startb <= finishb)
	{
		switch (COMPARE(terms[starta].expon, terms[startb].expon))
		{
		case -1:
			attach(terms[startb].coef, terms[startb].expon);
			startb++;
			break;
		case 0:
			coefficient = terms[starta].coef + terms[startb].coef;
			if (coefficient)
			{
				attach(coefficient, terms[starta].expon);
			}
			starta++; startb++;
			break;
		case 1:
			attach(terms[starta].coef, terms[starta].expon);
			starta++;
			break;
		default:
			break;
		}
	}
	for (; starta <= finisha; starta++)
	{
		attach(terms[starta].coef, terms[starta].expon);
	}

	for (; startb <= finishb; startb++)
	{
		attach(terms[startb].coef, terms[startb].expon);
	}
}

int main()
{
	ifstream fin;
	fin.open("lab02_1.txt");

	if (fin.fail())
	{
		cout << "File open failed" << "\n";
		exit(1);
	}

	int counta, countb, i, *stard = 0, *finishd = 0;
	fin >> counta;
	for (i = 0; i < counta; i++)
	{
		fin >> terms[i].coef;
		fin >> terms[i].expon;
	}

	fin >> countb;
	for (i; i < counta + countb; i++)
	{
		fin >> terms[i].coef;
		fin >> terms[i].expon;
	}

	padd(0, counta - 1, counta, counta + countb - 1);

	for (int i = 0; i < avail; i++)
	{
		cout << result[i].coef << ' ' << result[i].expon << "\n";
	}
	return 0;
}