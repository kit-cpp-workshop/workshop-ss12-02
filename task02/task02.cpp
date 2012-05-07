#include <iostream>

using namespace std;

class Ringpuffer {
public:
	Ringpuffer(unsigned int Size);
	~Ringpuffer();
	double pull();
	bool push(double Data);
	double GetBufferValue(int Index);
private:
	double* Buffer;
	int BufferSize;
	int WritePosition;
	int ReadPosition;
	int nBuffered; // Anzahl der gespeicherten Werte
};

Ringpuffer::Ringpuffer(unsigned int Size):BufferSize(Size) {
	Buffer = new double[BufferSize];
	WritePosition = 0;
	ReadPosition = 0;
	nBuffered = 0;
}

Ringpuffer::~Ringpuffer() {
	delete[] Buffer;
}

bool Ringpuffer::push(double Data) {
	if(nBuffered<BufferSize) {
		Buffer[WritePosition] = Data;
		WritePosition = (WritePosition + 1) % BufferSize;
		nBuffered++;
		return true;
	} else
		return false;
}

double Ringpuffer::pull() {
	double ret = 0;
	if(nBuffered>0) {
		ret = Buffer[ReadPosition];
		ReadPosition = (ReadPosition + 1) % BufferSize;
		nBuffered--;
	} else
		cout << "Empty Buffer, nothing to read." << endl;
	return ret;
}

double Ringpuffer::GetBufferValue(int Index) {
	int i = (ReadPosition + Index) % BufferSize;

	return Buffer[i]; // ohne Check

}

int main() {
	cout << "Buffer size? " << flush;
	int s=1;
	cin >> s;

	Ringpuffer Buffer(s);

	char ctrlInput = 0;
	while(true) {
		cout << "[r]ead, [w]rite, read [b]uffer element or [q]uit? " << flush;
		cin >> ctrlInput;
		switch(ctrlInput) {
		case 'w':
			{
			double in = 0;
			cout << "Input value = " << flush;
			cin >> in;
			if(Buffer.push(in))
				cout << "Value written." << endl;
			else
				cout << "Writing Error. Maybe full buffer?" << endl;
			}
			break;
		case 'r':
			cout << "Buffer value: " << Buffer.pull() << endl;
			break;
		case 'b':
			{
			double in = 0;
			cout << "Buffer index (0=oldest): " << flush;
			cin >> in;
			cout << "Buffer[" << in << "] = " << Buffer.GetBufferValue(in) << endl;
			break;
			}
		case 'q':
			return 0;
		}

	}

	return 0;
}
