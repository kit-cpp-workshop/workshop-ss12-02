#include <iostream>
#include <cstdio>

using namespace std;

class TotesKaetzchen{} up;


void variableLengthArray();
void stackSize();
void recursion(int i);
void ownership();


int main()
{
	int todCode;
	cout << "Welchen Tod soll ich heute sterben?" << endl;
	cin >> todCode;


	switch(todCode)
	{
	case 0:
		variableLengthArray();
	break;

	case 1:
		stackSize();
	break;

	case 2:
		recursion(0);
	break;

	case 3:
		ownership();
	break;

	default:
		cout << "Aha! Ein Spezialist! Dann sterbe ich heute den Tod des ungueltigen Arguments" << endl;
		printf("%u");
	break;
	}


	cout << "Hui, ich lebe noch. Jetzt bin ich aber am Ende.";

	return 0;
}




void variableLengthArray()
{
	cout << "Heute sterbe ich den Tod des dynamisch grossen Speichers." << endl << endl;


	unsigned int size = 0;
	cout << "Wie viel Speicher soll's denn sein?" << endl;
	cin >> size;

	// Gott toetet kleine Kaetzchen!!!!!
	double foobar[size];


	// Leider kompiliert das der gcc (wenn nicht ultra-pedantisch eingestellt),
	// sodass ich die Notbremse ziehe und das Programm Suizid begehen lasse.
	throw up;
}


void stackSize()
{
	cout << "Heute sterbe ich den Tod des endlichen Stacks." << endl << endl;


	double laaaaaargeArray[4000000];


	cout << "Wie, ich lebe noch?" << endl;
}


void recursion(int i)
{
	cout << "Heute sterbe ich den Tod der Rekursion: " << i << endl;


	recursion(i + 1);


	cout << "Wie, ich lebe noch?" << endl;
}


void ownership()
{
	cout << "Heute sterbe ich den Tod des ownership / der automatic storage duration." << endl;


	double* ptr;

	{
		double value = 42.21;
		ptr = &value;
	}


	double result = *ptr;


	cout << "Ich lebe noch? Seltsam.." << endl;


	{
		double newValue = 13.37;
		result = *ptr;
	}


	cout << "Wie, ich lebe noch?" << endl;
}
