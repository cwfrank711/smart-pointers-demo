#include <memory>
#include <iostream>

int main() {
    auto a = std::make_shared<int>(100);
    std::shared_ptr<int> b = a; // both share ownership
    std::cout << "use_count after copy: " << a.use_count() << '\n'; // prints 2
    b.reset(); // drop one owner
    std::cout << "use_count after reset: " << a.use_count() << '\n'; // prints 1
    return 0;
}