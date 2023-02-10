#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../brownie.h"

using namespace std;

struct Class {
    int a, d, x, y;
    Class(int _a=0, int _d=0, int _x=0, int _y=0): a(_a), d(_d), x(_x), y(_y) {}
};

int n;
vector<Class> classes;

// Backtrack global
vector<int> selected;
unordered_set<int> available;

// Sol global
int lim;
vector<vector<int>> dp;

void generateTestcase() {
    /*
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
    */

   n = randomInt(1, 10);
   classes.clear();
   for(int i = 0; i < n; i++) {
        int a = randomInt(1, 1000000);
        int b = randomInt(1, a / 80 + 1);
        int x = randomInt(1, 50);
        int y = randomInt(1, 50);
        classes.push_back(Class(a, b, x, y));
   }
}

int manhattan(const Class& c1, const Class& c2) {
    return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

int evaluateSelected(const vector<int>& selected) {
    if (selected.size() == 0)
        return 0;
    int totalValue = classes[selected[0]].a;
    for(int i = 1; i < selected.size(); i++)
        totalValue += (classes[selected[i]].a - classes[selected[i]].d * manhattan(classes[selected[i]], classes[selected[i - 1]]));
    
    return totalValue;
}

void backtrack(int pos, int& result) {
    result = max(result, evaluateSelected(selected));

    if (pos == n) 
        return;

    for(int i = 0; i < n; i++) {
        if (available.count(i)) {
            available.erase(i);
            selected.push_back(i);
            backtrack(pos + 1, result);
            available.insert(i);
            selected.pop_back();
        }
    }
}

int solBacktrack() {
    selected.clear();
    available.clear();
    for(int i = 0; i < n; i++)
        available.insert(i);

    int result = 0;
    backtrack(0, result);

    return result;
}

bool bitOn(const int& mask, const int& pos) {
    return (mask >> pos) & 1;
}

int turnOff(const int& mask, const int& pos) {
    return (mask & (~(1 << pos)));
}

int solDp() {
    lim = (1 << n);
    dp = vector<vector<int>>(lim, vector<int>(n, INT_MIN));
    for(int i = 0; i < n; i++)
        dp[0][i] = 0;

    int result = 0;
    for(int mask = 1; mask < lim; mask++) {
        for(int i = 0; i < n; i++) {
            if (bitOn(mask, i)) {
                int maskp = turnOff(mask, i);
                if (maskp == 0) 
                    dp[mask][i] = classes[i].a;

                for(int j = 0; j < n; j++)
                    if (bitOn(maskp, j)) 
                        dp[mask][i] = max(dp[mask][i], 
                                            dp[maskp][j] + classes[i].a - classes[i].d * manhattan(classes[i], classes[j]));
            }
            result = max(result, dp[mask][i]);
        }
    }

    return result;
}

int main() {
    while (true) {
        cout << "1. Generating testcases..." << endl;
        generateTestcase();
        cout << "    n = " << n << endl;
        cout << "2. Running the actual solution..." << endl;
        int resultDp = solDp();
        cout << "3. Running the backtrack..." << endl;
        int resultBacktrack = solBacktrack();

        if (resultBacktrack == resultDp) {
            cout << "Success!" << endl;
        } else {
            cout << "Wrong!" << ' ' << resultBacktrack << ' ' << resultDp << endl;
            break;
        }

        cout << endl << endl;
    }
}