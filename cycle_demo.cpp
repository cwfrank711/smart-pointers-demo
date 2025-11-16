#include <memory>
#include <iostream>

struct B;
struct A {
    std::shared_ptr<B> bptr;
    ~A(){ std::cout << "A destroyed\n"; }
};
struct B {
    std::weak_ptr<A> aptr; // weak here breaks cycle
    ~B(){ std::cout << "B destroyed\n"; }
};

int main() {
    {
        auto a = std::make_shared<A>();
        auto b = std::make_shared<B>();
        a->bptr = b;    // A holds shared_ptr to B
        b->aptr = a;    // B holds weak_ptr to A
    } // both A and B destroyed here
    return 0;
}