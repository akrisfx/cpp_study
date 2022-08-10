//#define _USE_MATH_DEFINES
//#include<cmath>
//#include <iostream>
#include <format>
#include "HW.h"
#ifdef _USE_MATH_DEFINES 
void ssa();
#endif


//int s = 10;
//void foo() {
//    std::cout << std::format("{}\n", s);
//}


uint64_t operator "" _m(uint64_t min) {
    return min * 60;
}
uint64_t operator "" _s(uint64_t s) {
    return s;
}



enum color : int { red = 0, green, blue };
template<> struct std::formatter<color> : std::formatter<int> {
    auto format(color c, format_context& ctx) {
        return formatter<int>::format((int)c, ctx);
    }
};

//template<> struct std::formatter<color> : std::formatter<const char*> {
//    auto format(color c, format_context& ctx) {
//        return formatter<const char*>::format(color_names[c], ctx);
//    }
//};

struct err {};

std::string s0 = std::format("{}", 42);         // OK, library-provided formatter
//std::string s1 = std::format("{}", "foo");     // error: disabled formatter
std::string s2 = std::format("{}", red);        // OK, user-provided formatter
//std::string s3 = std::format("{}", err{});
//struct err {};

//enum sides : int
//{
//    north = 0,
//    east = 90,
//    south = 180,
//    west = 270
//};
//sides n1 = north;
//sides n2 = west;
//std::cout << n2 << "\n";
//std::cout << std::format("{} {} \n", s0, M_PI);
//auto ss = searchS(1);
//std::cout << std::format("{} {} \n", ss.first, ss.second);


int main()
{
    test_int_double();
    xor_test();
    return 0;
}


