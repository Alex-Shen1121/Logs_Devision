2018192010:Problem1234:�𰸴���
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
class Group
{
public:
    virtual int add(int x, int y)=0;

    virtual int sub(int x, int y)=0;
    ~Group(){}
};
class A:public Group
{
protected:
    int a,b;
public:
    A(){}
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        return x-y;
    }
    ~A(){}
};
class B:public Group
{
public:
    B(){}
    int add(int x, int y)
    {
        return x+y;
    }
    int sub(int x, int y)
    {
        int res[10];
        int k=0;
        while(x>0)
        {
            res[k] = ((10+x%10)-y%10)%10;
            k++;
            x /=10;
            y /=10;
        }
        int m=0;
        for(int i=0;i<=k;i++)
            m = m+pow(10,i)*res[i]+0.5;
        return m;
    }
    ~B(){}
};
class C:public Group
{
public:
    C(){}
    ~C(){}
    int add(int x, int y)
    {
        int res[10]={0};
        int k=0;
        if(y>x)
        {
            int temp;
            temp = x;
            x = y;
            y = temp;
        }
        while(x>0)
        {
            res[k] = (x%10+y%10)%10;
            cout << res[k] << endl;
            cout << "x=" << x << endl;
            cout << "y=" << y << endl;
            x /=10;
            y /=10;
            k++;
        }
        int m=0;
        for(int i=0;i<k;i++)
        {
            m = m+pow(10,i)*res[i]+0.5;
            cout << "m=" << m <<endl;
        }
        return m;
    }
    int sub(int x, int y)
    {
        int res[10];
        int k=0;
        while(x>0)
        {
            res[k] = ((10+x%10)-y%10)%10;
            k++;
            x /=10;
            y /=10;
        }
        int m=0;
        for(int i=0;i<=k;i++)
            m = m+pow(10,i)*res[i]+0.5;
        return m;
    }
};
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        Group *p;
        int type;
        int x,y;
        char c;
        cin >> type >> x >> c >> y;
        switch(type)
        {
        case 1:p = new A;break;
        case 2:p = new B;break;
        case 3:p = new C;break;
        }
        if(c == '+')
            cout << p->add(x,y);
        else
            cout << p->sub(x,y);
        cout << endl;
        delete p;
    }
    return 0;
}

