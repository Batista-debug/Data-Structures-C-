#include <iostream>
using namespace std;

int main()
{
	
	int num = 3;
	
	int* pNum;
	
	pNum = &num;
	
	cout << num << endl;
	
	cout << &num << endl;
	
	cout << pNum << endl;
	
	return 0;
}
