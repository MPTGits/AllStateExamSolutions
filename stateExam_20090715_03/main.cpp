#include <iostream>

using namespace std;

class A {
    public:
         A()     { cout << "A::A()\n"; g();      }
         void operator=(const A&)     { cout << "A::=\n";     }
         void f()     { cout << "A::f()\n";       g();     }
         virtual void g ()      { cout << "A::g()\n";     }
         virtual ~A()     { cout << "A::~\n";     } };

 class B : public A {
     public:
         B() { cout << "B::B()\n";     }
         void f()     { cout << "B::f()\n";     }
         void g()     { cout << "B::g()\n";     }
         ~B()     { cout << "B::~\n";     } };

int main()
{
    cout << "1:\n";
    B* bp = new B;
    cout << "2:\n";
    A* bp_a = bp;
    bp_a->f();
    cout << "3:\n";
    bp_a->g();
    cout << "4:\n";
    A a;
    a = *bp;
    cout << "5:\n";
    B b;
    b = *bp;
    cout << "6:\n";
    delete bp_a;
    cout << "7:\n";
    return 0;
}
