#include<iostream>
using namespace std;

class base
{
public:
	base()

	{
		cout<<"Default constructor from base class\n";
	}
		base(int x)
	{
		cout<<"Parameterised constructor from base class\n";
	}
};
class Derived:public base
{
	public:
		Derived()

	{
		cout<<"Default constructor from Derived class\n";
	}
	Derived(int x)
	{
		cout<<"Parameterised constructor from Derived class\n";
	}
		
};
int main()
{
	Derived d1;   //object of derived class
	Derived d2(9);   //if pass paremer too .it can call paremetrised cons. of base class
	//Derived class can't see the paremetrised constructor of base class.
	return 0;
}

//output for clr understanding

//Default constructor from base class
//Default constructor from Derived class
//Default constructor from base class
//Parameterised constructor from Derived class(not base class)
