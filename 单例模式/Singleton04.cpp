#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton *GetInstance()
    {
        static Singleton m_Instance;
        return &m_Instance;
    }

    int GetTest()
    {
        return m_Test++;
    }

private:
    Singleton(){ m_Test = 10; };
    int m_Test;
};

int main(int argc , char *argv [])
{
    Singleton *singletonObj = Singleton ::GetInstance();
    cout<<singletonObj->GetTest()<<endl;

    singletonObj = Singleton ::GetInstance();
    cout<<singletonObj->GetTest()<<endl;
}

template <class T, class Alloc = alloc> 
class vector {
    ...
protected:
    iterator start;           // 表示目前使用空间的头
    iterator finish;          // 表示目前使用空间的尾
    iterator end_of_storage;  // 表示目前可用空间的尾
    ...
}

int select(int nfds, fd_set *readfds, fd_set *writefds, 
    fd_set *exceptfds, struct timeval *timeout);

int pselect(int nfds, fd_set *readfds, fd_set *writefds, 
    fd_set *exceptfds, const struct timespec *timeout, 
    const sigset_t *sigmask);

int poll(struct pollfd *fds, nfds_t nfds, int timeout);
int ppoll(struct pollfd *fds, nfds_t nfds, 
    const struct timespec *tmo_p, const sigset_t *sigmask);

int epoll_create(int size)；//创建一个epoll的句柄，size用来告诉内核这个监听的数目一共有多大
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)；
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);

inline template<typename T, class U> calu(const T&, const U&);
 
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

// 原始的，最通用的版本
template<class T> struct remove_reference {
    typedef T type;
};
// 部分特例化版本，将用于左值引用和右值引用
template<class T> struct remove_reference<T&>
{ typedef T type; }
template<class T> struct remove_reference<T&&>
{ typedef T type; }

class iostream : public istream, public ostream { }
class istream : public virtual base_ios { }
class ostream : virtual public base_ios { }

typedef basic_string<char> string;、
sizeof(string)
int a = 1; printf("%s", a);

ListNode* ReverseList(ListNode* pHead)
{
    // ListNode* pReversedHead = NULL;
    ListNode* pNode = NULL;     // 当前遍历到的结点
    ListNode* pPrev = pHead;    // pNode在原链表中的前一个结点，在
                                // 下面的while循环中pPrev前面的所
                                // 有结点都已正确翻转
    while (pNode != NULL)
    {
        ListNode* pNext = pNode->m_pNext;
        // if (pNext == NULL)
        //     pReversedHead = pNode;
        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }
    return pPrev; // 返回翻转后的链表的头结点指针
    // return pReversedHead;
}
