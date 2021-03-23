#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -1

class Queue
{
private:
    int *base;
    int front; // 头指针,若队列不空,指向队列头元素
    int rear;  // 尾指针,若队列不空,指向队列尾元素的下一个位置
    int num;

public:
    Queue(int n);
    ~Queue();
    bool IsEmpty();
    bool IsFull();
    void Push(int e);
    int Pop(int &e);
};

Queue::Queue(int n)
{
    num = n;
    base = new int[n];
    if (!base)
        exit(OVERFLOW);
    front = rear = 0;
    cout << "构造函数使用完毕" << endl;
}

Queue::~Queue()
{
    if (base)
        delete[] base;
    base = NULL;
    front = rear = 0;
    cout << endl
         << "析构函数使用完毕" << endl;
}

bool Queue::IsEmpty()
{
    if (front == rear)
        return true;
    else
        return false;
}

bool Queue::IsFull()
{
    if ((rear + 1) % num == front)
        return true;
    else
        return false;
}

void Queue::Push(int e)
{
    if ((rear + 1) % num == front)
        return;
    base[rear] = e;
    rear = (rear + 1) % num;
}

int Queue::Pop(int &e)
{
    if (front == rear)
        return ERROR;
    e = base[front];
    front = (front + 1) % num;
    return e;
}

int main(void)
{
    Queue p(10);
    return 0;
}