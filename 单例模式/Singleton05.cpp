/*
** FileName     : SingletonPatternDemo5
** Author       : Jelly Young
** Date         : 2013/11/20
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton *GetInstance()
    {
        return m_Instance;
    }

    int GetTest()
    {
        return m_Test;
    }

private:
    Singleton(){ m_Test = 10; }
    static Singleton *m_Instance;
    int m_Test;

    // This is important
    class GC
    {
    public :
        ~GC()
        {
            // We can destory all the resouce here, eg:db connector, file handle and so on
            if (m_Instance != NULL )
            {
                cout<< "Here is the test" <<endl;
                delete m_Instance;
                m_Instance = NULL ;
            }
        }
    };
    static GC gc;
};

Singleton *Singleton ::m_Instance = new Singleton();
Singleton ::GC Singleton ::gc;

int main(int argc , char *argv [])
{
    Singleton *singletonObj = Singleton ::GetInstance();
    cout<<singletonObj->GetTest()<<endl;

    return 0;
}

const char *p;
// 错误: static_cast不能转换有底层const的类型
char* pc = static_cast<char*>(p); 

const char *p;
// 正确: 但是通过pc写值是未定义的行为
char* pc = const_cast<char*>(p); 

dynamic_cast<type*>(e)
dynamic_cast<type&>(e)
dynamic_cast<type&&>(e)

Sales_data
operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs; // 复合赋值运算符
    return sum;
}
typedef char* pstring;
// cstr是指向char的常量指针
const pstring cstr = 0;
// ps是一个指针，它的对象是指向char的常量指针
const pstring* ps;

using SI = Sales_item;

#ifdef __cplusplus
    extern "C" {
#endif
/* ... */
#ifdef __cplusplus
    }
#endif

char* strcpy(char* destination, const char* source)
{
    assert(destination!=NULL && source!=NULL);

    if (destination==source)
        return destination;
    
    char *p = destination;
    while(*p++ = *source++)
        ;
    return destination;
}

    void Qsort(int A[], int Left, int Right)
    {
        int i, j;
        int Pivot;

        if( Left <= Right )
        {
            Pivot = A[Right];
            i = Left ; j = Right-1;
            for( ; ; )
            {
                while( A[ i ] < Pivot ){ ++i; }
                while( A[ j ] > Pivot ){ --j; }
                if( i < j )
                    Swap( &A[ i ], &A[ j ] );
                else
                    break;
            }
            Swap(&A[i], &A[Right]);  /* Restore pivot */

            Qsort(A, Left, i-1);
            Qsort(A, i+1, Right);
        }
    }

for (int i = 0; i < n; ++i)
{
    for (int j = i+1; j < n; ++j)
    {
        if (array[i] > array[j])
            swap(&array[i], &array[j]);
    }
}