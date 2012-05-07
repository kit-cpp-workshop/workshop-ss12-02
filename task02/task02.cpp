/*
 * task02.cpp
 *
 *  Created on: 06.05.2012
 *      Author: Steven Weitemeyer & Holger Drees
 */




#include<iostream>

using namespace std;



class Ringspeicher {

public:
	Ringspeicher(long n);
	~Ringspeicher();
	bool push(double Wert);
	double pop();
	double get(long n);

private:
	double* Array;			//Pointer auf Ringspeicher
	double* Speicherfeld;	//Pointer für Speichervorgang
	double* Auslesefeld;	//Pointer für Auslesevorgang
	long Laenge;
	bool Leer;				//Information, ob Ringspeicher komplett Leer
	bool Voll;				//oder komplett voll
};

Ringspeicher::Ringspeicher(long n){
	Laenge = n;
	Leer = true;
	Voll = false;
	Array = new double[n];
	Speicherfeld = Array;
	Auslesefeld = Array;

	//beim Initialisieren alle Elemente auf 0 setzen
	for(int i=0; i<n; i++){
		Array[i] = 0;
	}

}

Ringspeicher::~Ringspeicher(){
	delete[] Array;
}

bool Ringspeicher::push(double Wert){
	if (Voll) {return false;}	//Sicherung gegen Pufferüberlauf
	else{
		*(Speicherfeld) = Wert;
		//gehe eine Speicherstelle vor
		if(Speicherfeld == Array + (Laenge - 1)){
			Speicherfeld = Array ;
		}
		else {
			Speicherfeld = Speicherfeld + 1;
		}
	}
	Leer = false;
	if(Speicherfeld == Auslesefeld){Voll = true;}

	return true;
}

double Ringspeicher::pop(){
	//Sicherung gegen sinnlosen Auslesevorgang
	if(Leer){
		cout << "Fehler: alle Speicherstellen leer/bereits ausgegeben => " << endl ;
		return 0;
	}
	double temp = *(Auslesefeld);

	//gehe eine Auslesestelle vor
	if(Auslesefeld == Array + (Laenge - 1)){
		Auslesefeld = Array ;
	}
	else {
		Auslesefeld = Auslesefeld + 1;
	}
	Voll = false;
	if(Auslesefeld == Speicherfeld){Leer = true;}


	return temp;
}

double Ringspeicher::get(long n){	// Hinweis: "get" kontrolliert nicht, ob Speicherstelle sinnvoll beschrieben
	return Array[n-1];
}



int main() {
	long Groesse;
	cout << "Ringspeichergroesse angeben: " << endl;
	cin >> Groesse;
	Ringspeicher Speicher(Groesse);

	int Befehlswahl=0;
	do {
		cout << "Welcher Befehl? (1 => push | 2 => pop | 3 => get | 0 => Ende): " << endl;
		cin >> Befehlswahl;
		if(Befehlswahl==1){
			double temp;
			cout << "Welchen Wert willst du speichern? "<< endl;
			cin >> temp;
			if(Speicher.push(temp)){
				cout << "Speichervorgang erfolgreich." << endl;
			} else{
				cout << "Speichervorgang abgebrochen." << endl;
			}
		}

		if(Befehlswahl==2){
			cout << Speicher.pop() << endl;
		}

		if(Befehlswahl==3){
			long n;
			cout << "Auslesen des Elements der Nummer" << endl;
			cin >> n;
			cout << Speicher.get(n) << endl;
		}

	} while(Befehlswahl);

	return 0;
}


