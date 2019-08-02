
// An example of enumeration usage for function flags


#include <iostream>
#include <bitset>

struct Options {
    enum FLAGS { F1=1, F2=2, F3=4, F4=8 };
    
    Options() = default;
    Options(FLAGS f) : bs_(f) {}

    friend Options operator|(Options o1, Options o2);
    friend std::ostream& operator<<(std::ostream&, Options const& obj);
    private:
    std::bitset<4> bs_;
};

inline Options operator|(Options o1, Options o2) {
    Options result;
    result.bs_= o1.bs_ | o2.bs_;
    return result;
}
inline Options operator|(Options::FLAGS f1, Options::FLAGS f2) {
    return Options(f1) | Options(f2);
}
std::ostream& operator<<(std::ostream& os, Options const& obj) {
    os << obj.bs_;
    return os;
}

using namespace std;

int main() {
    auto fl1 = Options::FLAGS::F1 | Options::FLAGS::F2;
    cout << fl1 << endl;
    cout << (Options::FLAGS::F1 | Options::FLAGS::F4) << endl;
    auto fl3 = fl1 | Options::FLAGS::F4;
    cout << fl3 << endl;
    auto fl4 = fl3 | Options::FLAGS::F2;
    cout << fl4 << endl;

}

