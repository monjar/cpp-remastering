#include <stdio.h>
#include <iostream>

// Base class
class Animal
{
protected:
    int height;

public:
    Animal(Animal &copy)
    {
        this->height = copy.height;
    }
    Animal(int height)
    {
        this->height = height;
    }
    virtual void animalSound()
    {
        std::cout << "The animal makes a sound \n";
    }
    virtual void printHeight()
    {
        std::cout << height << "\n";
    }
};

// Derived class
class Pig : public Animal
{
public:
    Pig(int height) : Animal(height)
    {
    }
    void animalSound() override
    {
        std::cout << "The pig says: wee wee \n";
    }
};

// Derived class
class Dog : public Animal
{

public:
    Dog(int height) : Animal(height)
    {
    }
    void animalSound() override
    {
        std::cout << "The dog says: bow wow \n";
    }
};

int main()
{

    Dog dog1(7);
    Dog dog2(dog1);
    dog2.animalSound();
    dog2.printHeight();
    return 0;
}
