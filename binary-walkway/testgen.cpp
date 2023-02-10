#include <iostream>
#include <algorithm>
#include <fstream>
#include "../brownie.h"

using namespace std;
const string PREF_INPUT = "test/input";
const string PREF_OUTPUT = "test/output";

int testId;


void solution(string inpfile, string outfile) {
    ifstream inp(inpfile);
    ofstream out(outfile);
    int n;
    inp >> n;
    string result = "";
    for(int i = 0; i < n; i++) {
        string path;
        inp >> path;
        result.push_back(((path[i] - '0' + 1) & 1) + '0');
    }
    out << result;
    inp.close();
    out.close();
}


void testgenSmall(const int& lim) {
    for(int i = 0; i < lim; i++) {
        string inpfile = PREF_INPUT + formatNumber(i + testId, 2) + ".txt";
        string outfile = PREF_OUTPUT + formatNumber(i + testId, 2) + ".txt";
        ofstream inp(inpfile);
        int n = randomInt(1, 10);
        inp << n << endl;
        for(int j = 0; j < n; j++) {
            string result = "";
            for(int num = 0; num < n; num++) 
                result.push_back((randomInt(0, 1000) % 2) + '0');
            inp << result << endl;
        }
        inp.close();

        solution(inpfile, outfile);
    }

    testId += lim;
}

void testgenBig(const int& lim) {
    for(int i = 0; i < lim; i++) {
        string inpfile = PREF_INPUT + formatNumber(i + testId, 2) + ".txt";
        string outfile = PREF_OUTPUT + formatNumber(i + testId, 2) + ".txt";
        ofstream inp(inpfile);
        int n = randomInt(1, 20);
        inp << n << endl;
        for(int j = 0; j < n; j++) {
            string result = "";
            for(int num = 0; num < n; num++) 
                result.push_back((randomInt(0, 1000) % 2) + '0');
            inp << result << endl;
        }
        inp.close();

        solution(inpfile, outfile);
    }
    
    testId += lim;
}

int main() {
    testId = 0;
    testgenSmall(10);
    testgenBig(10);
    return 0;
}