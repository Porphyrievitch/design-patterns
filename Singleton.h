#pragma once
#include <iostream>

class Singleton
{
private:
    static Singleton* __instance;

    // 嵌套类 它的唯一工作就是在析构函数中删除Singleton的实例  
    //Gabage Collection
    class GC 
    {
    public:
        ~GC()
        {  
            if (Singleton::__instance)
            {
                delete Singleton::__instance;
                Singleton::__instance = nullptr;
            }
        }
    };

    // 定义一个静态成员，在程序结束时，系统会调用它的析构函数
    static GC gc;

protected:
    Singleton(void);
    ~Singleton(void);

public:
    static Singleton* getInstance();
};

