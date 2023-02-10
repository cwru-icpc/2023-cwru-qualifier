#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
vector<vector<int>> adj;
 
unordered_map<int, bool> colored;

void dfs(int x, int& totalNum, int& trueNum, bool color) {
    if (color) 
        trueNum++;
    totalNum++;

    colored[x] = color;
    for(const int& v : adj[x]) 
        if (!colored.count(v)) 
            dfs(v, totalNum, trueNum, !color);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>());
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
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

    cout << result;
    return 0;
}