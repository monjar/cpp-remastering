#include<iostream>
#include<thread>
class Singleton
{

protected:
    Singleton()
    {
    }

    static Singleton* singleton_;

    int value_;

public:

  
    Singleton(Singleton &other) = delete;
   
    void operator=(const Singleton &) = delete;
  

    static Singleton *GetInstance();

    void setValue(int value){
        value_ = value;
    }
    void increaseAndPrint()
    {
        value_++;
        std::cout<< value_ << std::endl;
    }

    int value() const{
        return value_;
    } 
};

Singleton* Singleton::singleton_= nullptr;

Singleton *Singleton::GetInstance()
{
   
    if(singleton_==nullptr){
        singleton_ = new Singleton();
    }
    return singleton_;
}



