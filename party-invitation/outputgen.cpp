#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "../brownie.h"

using namespace std;
const string PREF_INPUT = "test/input/input";
const string PREF_OUTPUT = "test/output/output";

int n, m;
vector<vector<int>> adj;
 
unordered_map<int, bool> colored;

void cleanGlobal() {
    adj.clear();
    colored.clear();
}

void dfs(int x, int& totalNum, int& trueNum, bool color) {
    if (color) 
        trueNum++;
    totalNum++;

    colored[x] = color;
    for(const int& v : adj[x]) 
        if (!colored.count(v)) 
            dfs(v, totalNum, trueNum, !color);
}

void solution(const string& inpfile, const string& outfile) {
    ifstream inp(inpfile);
    ofstream out(outfile);
    inp >> n >> m;
    adj = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < m; i++) {
        int u, v;
        inp >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int result = 0;

    for(int i = 0; i < n; i++) {
        if (!colored.count(i)) {
            int totalNum = 0;
            int trueNum  = 0;
            dfs(i, totalNum, trueNum, true);

            result += max(trueNum, totalNum - trueNum);
        }
    }

    out << result;
    inp.close();
    out.close();
}

int main() {
    for(int i = 0; i <= 15; i++) {
        cleanGlobal();
        string inpfile = PREF_INPUT + formatNumber(i, 2) + ".txt";
        string outfile = PREF_OUTPUT + formatNumber(i, 2) + ".txt";
        solution(inpfile, outfile);
    }
    return 0;
}