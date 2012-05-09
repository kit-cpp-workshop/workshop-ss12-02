#include <iostream>

using namespace std;

class Ringpuffer {
public:
	bool push(double newelement);
	double pop();
	double element(int number);
	Ringpuffer(int size);
	~Ringpuffer();

private:
	int NumberOfElements;
	int ElementsInUse;
	double* ptr;
	double* pushptr;
	double* popptr;
	double* lastptr;

};


Ringpuffer::Ringpuffer(int size):NumberOfElements(size) {
	ptr=new double[NumberOfElements];
	pushptr=ptr;
	popptr=ptr;
	ElementsInUse=0;
}

bool Ringpuffer::push(double newelement)
{
	if (ElementsInUse>=NumberOfElements) //Zu viele Elemente
	{
		return 0;
	}

	*pushptr=newelement; //Element schreiben

	if (pushptr==ptr+NumberOfElements-1) //Überprüfen, ob letztes Element
	{
		pushptr=ptr; //Zurück zum 1. Element
	}
	else
	{
		pushptr++; //Weiterspringen falls nicht am Ende
	}



	ElementsInUse++; //Erhöhe Zahl der Elemente
	return 1;
}

double Ringpuffer::pop()
{
	if (ElementsInUse==0)
	{
		return 0;
	}

	double returnvalue=*popptr;

	if (popptr==ptr+NumberOfElements-1) //Überprüfen, ob letztes Element
	{
		popptr=ptr; //Zurück zum 1. Element
	}
	else
	{
		popptr++; //Weiterspringen falls nicht am Ende
	}

	ElementsInUse--; //Senke Zahl der Elemente
	return returnvalue;
}


double Ringpuffer::element(int number)
{
	if ((number<0)||(number>=NumberOfElements))
	{
		return 0;
	}
	return *(ptr+number);
}


Ringpuffer::~Ringpuffer() {
	delete[] ptr;
}


int main()
{
	int size;
	cout << "Bitte Groesse des Puffers angeben: " << flush;
	cin >> size;
	Ringpuffer puffer(size);


	int s=0;
	while (s!=4)
	{
		cout << "push=>1  pop=>2 read=>3 quit=>4 " << flush;
		cin >> s;

		if (s==1) //push
		{
			double add;
			cout << "Zahl eingeben: " << flush;
			cin >> add;
			if (puffer.push(add)==1)
			{
				cout << "Zahl erfolgreich hinzugefuegt" << endl;
			}
			else
			{
				cout << "Zahl konnte nicht hinzugefuegt werden" << endl;
			}
		}

		if (s==2) // pop
		{
			cout << "Die Zahl ist " << puffer.pop() << " und wurde geloescht" << endl;
		}

		if (s==3) //read
		{
			int n;
			cout << "Element eingeben (zwischen 0 und " << size-1 << "): " << flush;
			cin >> n;
			cout << "Der Zahl ist " << puffer.element(n) << endl;
		}

		cout << endl;
	}

	return 0;
}
