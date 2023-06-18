#include<iostream>
using namespace std;
template <class A>
class B
{
public:
    template <class T>
    void Test(T t)
    {
        cout<< t;
    }
};
int test2main()
{
    B<int> b;
    b.Test("wuwen");
    b.Test("hello");
    return 0;
}