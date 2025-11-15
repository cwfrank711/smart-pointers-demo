#include <memory>
#include <iostream>

int main() {
    auto p = std::make_unique<int>(42);       // p owns the int
    std::unique_ptr<int> q = std::move(p);    // transfer ownership to q
    std::cout << (p ? "p not null" : "p null") << '\n'; // prints "p null"
    std::cout << "*q = " << *q << '\n';       // prints 42
    return 0;
}
