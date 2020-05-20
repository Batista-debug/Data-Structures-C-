#include <iostream>
//Exercicios Ponteiro C++

using namespace std;

    void passByRef(int &num1);

    int main()
    {

        int num = 3;
        cout << "In main()" << endl;
        cout << "Value of num is " << num << endl;

        passByRef(num);

        cout << "Back in main and the value of num is  " << num << endl;


        return 0;
    }

    void passByRef(int &num1)
    {
        cout << "In passByRef()" << endl;
        cout << "Value of num1 is " << num1 << endl;

        num1++;

        cout << "num1 is now " << num1 << endl;
    }
