int main()
{
	int foo;
	double bar;
	{
		MyType myObj;
	}
	
	return 0;
}

void foo()
{
	int foo;
	double bar;
	int* pi;
	MyType* po;
	
	pi = new int;
	{
		po = new MyType;
	}
	
	double* pd = new double;
	
	delete po;
	po = new MyType;
}
