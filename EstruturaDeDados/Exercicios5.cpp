#include <iostream>
using namespace std;

void passByValue(int);
void passByRef(int &);

int main(){
	
	int num = 3;
	
	int &refNums = num;
	
	cout << "\n Num Contains " << num << endl;
	cout << "\n refNum contains " << refNums << endl;
	
	refNums++;
	
	cout << "\n Num Contains " << num << endl;
	cout << "\n refNum Contains " << refNums << endl;
	
	num++;
	
	cout << "\n Num contains " << num << endl;
	cout << "\n refNum Contains " << refNums << endl;
	
	cout << "\n refNum is located at " << &refNums << " and num is located at " << &num << endl;
	
	return 0;
}
