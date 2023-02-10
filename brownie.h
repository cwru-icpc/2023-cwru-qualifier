#include <iostream>
#include <algorithm>
#include <random>
#include <iomanip>
#include <sstream>
#include <chrono>


// 1 -> 01, 2 -> 02
std::string formatNumber(int number, int buffer) {
    std::stringstream ss;
    ss << std::setw(buffer) << std::setfill('0') << number;
    return ss.str();
}


// Be careful with overflow :)
int randomInt(int L, int R) {
    if (L == R)
        return L;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen (seed);
    int range = R - L + 1;
    return (gen() % range) + L;
}


// Be careful with overflow :)
long randomLong(long L, long R) {
    if (L == R)
        return L;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937_64 gen (seed);
    long range = R - L + 1;
    return (gen() % range) + L;
}