int main()
{
	int foo;
	MyType myObj;
//	{
	int* pi;

	foo = 4;
	
	pi = &foo;
//	...
//	}
	
	int  bar;
	int& bar2 = bar;
	bar  = 4;
	bar2 = 4;
	
	double alice = 0;
	double bob   = 1;
	
	compute(alice, bob);
	
	bool b;
	bool* pb = &b;
	
	MyType* pMyObj = &myObj;
	
	MyType& rMyObj = myObj;
	MyType myOtherObj;
	pMyObj = &myOtherObj;
}

void compute(double& p0, double& p1)
{
	p0 = 42.0;
	p1 = 21.0;
}

// damn it!
	int content = *pi;
	*pi = 42;
	
double  myArr[3];
myArr[1] = 13.37;

double* pFirstElem  =    myArr;
double* pFirstElem2 = &( myArr[0] );

double* pElem       = &( myArr[2] );
double* pElem2      = &( myArr[0] ) + 2;

double* pElem3      =    pFirstElem[2];
double* pElem4      =    pFirstElem + 2;
