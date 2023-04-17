// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
using namespace std;

// Ваші файли загловки 
//
#include "Lab3Example.h"
int main()
{
    cout << " Lab #3  !\n";

    char ch = '5';
    do {
        system("cls");
        cout << "1 Task1" << endl;
        cout << "2 Task2" << endl;
        cout << "3 Task3" << endl;
        cout << "4 Exit" << endl;
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': mainExample1();   break;
        case '2': mainExample4();   break;
        case '3': mainExample4();   break;
        case '4': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '6');

    return 0;
}

