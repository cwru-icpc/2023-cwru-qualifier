#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Class {
    int a, d, x, y;
    Class(int _a=0, int _d=0, int _x=0, int _y=0): a(_a), d(_d), x(_x), y(_y) {}
};

int n, lim;
vector<Class> classes;
vector<vector<int>> dp;


int manhattan(const Class& c1, const Class& c2) {
    return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

bool bitOn(const int& mask, const int& pos) {
    return (mask >> pos) & 1;
}

int turnOff(const int& mask, const int& pos) {
    return (mask & (~(1 << pos)));
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, d, x, y;
        cin >> a >> d >> x >> y;
        classes.push_back(Class(a, d, x, y));
    }

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

    cout << result;
    return 0;
}