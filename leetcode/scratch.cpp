#include <iostream>
#include <string>

struct map {
    int x;
    std::string s;
};


void f(int *p){
    std::cout << *p << std::endl;
}

int main() {
    int *p,c;
    c = 5;
    p = &c;
    f(p);
    // std::cout << *p << std::endl;
}
