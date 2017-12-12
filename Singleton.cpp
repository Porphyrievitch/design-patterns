#include "Singleton.h"


Singleton::Singleton(void)
{
    std::cout<<"constructor"<<std::endl;
}


Singleton::~Singleton(void)
{
    std::cout<<"destructor"<<std::endl;
}

Singleton* Singleton::getInstance()
{
    //懒汉模式
    if (nullptr == __instance)
    {
        __instance = new Singleton();
    }
    return __instance;
}

Singleton* Singleton::__instance = nullptr;
Singleton::GC Singleton::gc;
