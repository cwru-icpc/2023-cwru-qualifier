#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include "../brownie.h"

using namespace std;
const string PREF_INPUT = "test/input/input";
const string PREF_OUTPUT = "test/output/output";

int testId;

void testSmall(const int& lim) {
    for(int i = 0; i < lim; i++) {
        string inpfile = PREF_INPUT + formatNumber(i + testId, 2) + ".txt";
        ofstream inp(inpfile);
        int n = randomInt(1, 5);
        inp << n << endl;

        for(int j = 0; j < n; j++) {
            int a = randomInt(1, 50);
            int b = randomInt(1, a / 2 + 1);
            int x = randomInt(1, 7);
            int y = randomInt(1, 7);
            inp << a << ' ' << b << ' ' << x << ' ' << y << endl;
        }
        inp.close();
    }
    
    testId += lim;
}

void testMedium(const int& lim) {
    for(int i = 0; i < lim; i++) {
        string inpfile = PREF_INPUT + formatNumber(i + testId, 2) + ".txt";
        ofstream inp(inpfile);
        int n = randomInt(6, 15);
        inp << n << endl;

        for(int j = 0; j < n; j++) {
            int a = randomInt(1, 5000);
            int b = randomInt(1, a / 20 + 1);
            int x = randomInt(1, 50);
            int y = randomInt(1, 50);
            inp << a << ' ' << b << ' ' << x << ' ' << y << endl;
        }
        inp.close();
    }

    testId += lim;
}

void testBig(const int& lim) {
    for(int i = 0; i < lim; i++) {
        string inpfile = PREF_INPUT + formatNumber(i + testId, 2) + ".txt";
        ofstream inp(inpfile);
        int n = randomInt(16, 20);
        inp << n << endl;

        for(int j = 0; j < n; j++) {
            int a = randomInt(1, 1000000);
            int b = randomInt(1, a / 80 + 1);
            int x = randomInt(1, 50);
            int y = randomInt(1, 50);
            inp << a << ' ' << b << ' ' << x << ' ' << y << endl;
        }
        inp.close();
    }

    testId += lim;
}

int main() {
    testId = 0;
    testSmall(5);
    testMedium(5);
    testBig(5);
}