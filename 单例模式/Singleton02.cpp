#include <iostream>
using namespace std;

// 懒汉式单例类 线程安全
class Singleton
{
public:
    static Singleton *GetInstance()
    {
        if (m_Instance == NULL )
        {
            Lock(); // C++没有直接的Lock操作，请使用其它库的Lock，比如Boost，此处仅为了说明
            if (m_Instance == NULL )
            {
                m_Instance = new Singleton ();
            }
            UnLock(); // C++没有直接的Lock操作，请使用其它库的Lock，比如Boost，此处仅为了说明
        }
        return m_Instance;
    }

    static void DestoryInstance()
    {
        if (m_Instance != NULL )
        {
            delete m_Instance;
            m_Instance = NULL ;
        }
    }

    int GetTest()
    {
        return m_Test;
    }

private:
    Singleton(){ m_Test = 0; }
    static Singleton *m_Instance;
    int m_Test;
};

Singleton *Singleton ::m_Instance = NULL;

int main(int argc , char *argv [])
{
    Singleton *singletonObj = Singleton ::GetInstance();
    cout<<singletonObj->GetTest()<<endl;
    Singleton ::DestoryInstance();

    return 0;
}