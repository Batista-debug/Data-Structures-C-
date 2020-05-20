#include <iostream>
using namespace std;

int main(){
	
	int *pInt = new int;
	
	double *pDouble = new double;
	
	*pInt = 3;
	
	*pDouble = 5.0;
	
	
	cout << "\n Value is stored at pInt = " << *pInt << ": memory address " << pInt << endl;
	cout << "\n Value is stored at pInt = " << *pDouble << ": memory address " << pDouble << endl;
	
	
	cout << "\n Value started at pInt = " << *pInt << ": memory address = " << pInt << endl;
	cout << "\n Value started at double = " << *pDouble << ": location = " << pDouble << endl;
	
	cout << "\n Size of pInt = " << sizeof(pInt);
	cout << "\n Size of *pInt = " << sizeof(*pInt) << endl;
	
	delete pInt;
	delete pDouble;
	
	return 0;
}
