#include <iostream>
using namespace std;

class A
{
private:
    int a;
    friend class C;

public:

     class B
    {
    private:
        int b;

    public:
        B(int y)
        {
            b = y;
        }
    };

    A(int x)
    {
        a = x;
    }
};

class C
{
private:
    int c;

public:
    void display(A &t)
    {
        cout << t.a << endl;
    }

    C(int z)
    {
        c = z;
    }
};

int main()
{

    B b1(56);
    A a1(12);
    C c1(34);
}