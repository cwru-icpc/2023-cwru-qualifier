#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

queue<string> q;
unordered_map<string, int> state_map;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<char> > decode(string s) {
    vector<vector<char> > results;
    for(int i = 0; i < 3; i++) {
        vector<char> row;
        for(int j = 0; j < 3; j++) {
            row.push_back(s[i * 3 + j]);
        }
        results.push_back(row);
    }
    return results;
}

string encode(vector<vector<char> > v) {
    string res = "";
    for(vector<char> v2: v) {
        for(char a: v2) {
            res.push_back(a);
        }
    }
    return res;
}

vector<string> next_state(string curState) {
    vector<string> res;
    vector<vector<char> > v = decode(curState);
    int x = 0, y = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[i][j] == '0') {
                x = i;
                y = j;
            }
        }
    }

    for(int o = 0; o < 4; o++) {
        if(x + dir[o][0] >= 0 && x + dir[o][0] < 3 
        && y + dir[o][1] >= 0 && y + dir[o][1] < 3) {
            vector<vector<char> > v2 = v;
            swap(v2[x + dir[o][0]][y + dir[o][1]], v2[x][y]);
            res.push_back(encode(v2));
        }
    }

    return res;

}

int main() {
    
    string target = "123456780";

    string start = "";

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            char a;
            cin >> a;
            start.push_back(a);
        }
    }

    state_map[start] = 0;
    q.push(start);
    while(!q.empty()) {
        string top = q.front();
        q.pop();
        // cout << top << "\n";
        int dist = state_map[top];
        if(top == target) {
            cout << dist;
            return 0;
        }
        vector<string> v_state = next_state(top);
        for(string state: v_state) {
            if(state_map.find(state) == state_map.end()) {
                state_map[state] = dist + 1;
                q.push(state);
            }
        }
    }
    cout << -1;

    return 0;
}