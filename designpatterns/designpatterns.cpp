#include <iostream>
#include <thread>
#include "singleton.cpp"

int main()
{
    Singleton *singletonIns1 = Singleton::GetInstance();
    singletonIns1->setValue(6);
    singletonIns1->increaseAndPrint();

    Singleton *singletonIns2 = Singleton::GetInstance();
    singletonIns2->increaseAndPrint();

    return 0;
}