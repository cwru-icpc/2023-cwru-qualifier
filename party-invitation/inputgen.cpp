#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <set>
#include "../brownie.h"

using namespace std;
const string PREF_INPUT = "test/input/input";


int testId;

bool generateGraph(const string& inpfile, int n, int m) {
    unordered_map<int, bool> coloredVertex;
    set<pair<int, int>> edges;

    ofstream inp(inpfile);
    auto start = chrono::high_resolution_clock::now();
    inp << n << ' ' << m << endl;
    for(int i = 0; i < m; i++) {
        while (true) {
            auto current = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(current - start);
            if (duration.count() > 15) {
                inp.close();
                return false;
            }

            int u = randomInt(1, n);
            int v = randomInt(1, n);
            if (u == v || (coloredVertex.count(u) && coloredVertex.count(v) && coloredVertex[u] == coloredVertex[v])) {
                continue;
            }
            if (!coloredVertex.count(u) && !coloredVertex.count(v)) {
                coloredVertex[u] = true;
                coloredVertex[v] = false;
            }
            else if (!coloredVertex.count(u)) {
                coloredVertex[u] = !coloredVertex[v];
            }
            else {
                coloredVertex[v] = !coloredVertex[u];
            }

            if (!edges.count({min(u, v), max(u, v)})) {
                inp << u << ' ' << v << endl;
                edges.insert({min(u, v), max(u, v)});
                break;
            }
        }
    }
    
    inp.close();
    return true;
}

void testDummy(const int& lim) {
    for(int num = 0; num < lim; num++) {
        string inpfile = PREF_INPUT + formatNumber(num + testId, 2) + ".txt";
        int n = randomInt(2, 8);
        int m = randomInt(0, n * n / 4);
        bool result = generateGraph(inpfile, n, m);
        if (!result) {
            num--;
            continue;
        }
    }
    testId += lim;
}

void testNormal(const int& lim) {
    for(int num = 0; num < lim; num++) {
        string inpfile = PREF_INPUT + formatNumber(num + testId, 2) + ".txt";
        int n = randomInt(10, 500);
        int m = min(randomLong(0, n * n / 4), 5000L);
        bool result = generateGraph(inpfile, n, m);
        if (!result) {
            num--;
            continue;
        }
    }
    testId += lim;
}

void testBig(const int& lim) {
    for(int num = 0; num < lim; num++) {
        string inpfile = PREF_INPUT + formatNumber(num + testId, 2) + ".txt";
        int n = randomInt(80000, 100000);
        int m = min(randomLong(0, 1L * n * n / 4), 100000L);
        bool result = generateGraph(inpfile, n, m);
        if (!result) {
            num--;
            continue;
        }
    }
    testId += lim;
}

int main() {
    testId = 0;
    testDummy(4);
    testNormal(5);
    testBig(5);
    return 0;
}