#include <iostream>
#include <string>

struct map {
    int x;
    std::string s;
};


int main() {
    map m = {1,"lol"};
    // int x_tie;
    // std::string s_tie;
    auto[x_tie, s_tie] = m;
    std::cout << x_tie << " " << s_tie << "\n";
    return 0;
}
