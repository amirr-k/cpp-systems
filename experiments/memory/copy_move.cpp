#include <iostream>
#include <algorithm>

struct Big {
    int* data;

    Big() {
        data = new int[1'000'000];
        std::cout << "constructor\n";
    }

    ~Big() {
        delete[] data;
        std::cout << "destructor\n";
    }

    Big(const Big& other) {
        data = new int[1'000'000];
        std::copy(other.data, other.data + 1'000'000, data);
        std::cout << "copy constructor\n";
    }

    Big(Big&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "move constructor\n";
    }
};

Big make_big() {
    Big b;
    return b;
}

int main() {
    Big a = make_big();
    std::cout << "done\n";
}