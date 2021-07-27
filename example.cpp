#include "include/bufsize.hpp"
#include <iostream>

int main() noexcept {
    auto x = bufsize::init();

    std::cout << x.rows << ' ' << x.columns << '\n';
}