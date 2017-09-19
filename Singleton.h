#pragma once
#include <iostream>

class Singleton
{
private:
    static Singleton* __instance;

    // Ƕ���� ����Ψһ��������������������ɾ��Singleton��ʵ��  
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

    // ����һ����̬��Ա���ڳ������ʱ��ϵͳ�����������������
    static GC gc;

protected:
    Singleton(void);
    ~Singleton(void);

public:
    static Singleton* getInstance();
};

