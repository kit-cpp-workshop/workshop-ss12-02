int main()
{
	int foo;
	MyType myObj;
	{
		int* pi;
	
		foo = 4;
		
		pi = &foo;
		...
	}
	
	int bar;
	int& bar2 = bar;
	bar = 4;
	bar2 = 4;
	
	double alice = 0;
	double bob = 1;
	
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
