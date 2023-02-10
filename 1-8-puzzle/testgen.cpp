#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include "../brownie.h"
using namespace std;

queue<string> q1;
queue<string> q2;
unordered_map<string, int> state_map1;
unordered_map<string, int> state_map2;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<string> records[40];
vector<string> unrecorded;

string infile(int x) {
    return "test/input/input" + formatNumber(x, 2) + ".txt";
}

string outfile(int x) {
    return "test/output/output" + formatNumber(x, 2) + ".txt";
}

void print_state(int id, string s) {

    cout << id << " " << s << "\n";

    int x = state_map1[s];

    ofstream out(outfile(id));
    ofstream inp(infile(id));
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            inp << s[i * 3 + j] << " ";
        }
        if(i < 2) inp << "\n";
    }
    out << x;
    out.close();
    inp.close();
    return ;
}

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
    
    string start1 = "123456780";
    string start2 = "123456870";

    q1.push(start1);
    q2.push(start2);

    state_map1[start1] = 0;
    state_map2[start2] = 0;

    int max_dist = 0;

    while(!q1.empty()) {
        string top = q1.front();
        q1.pop();
        int dist = state_map1[top];
        records[dist].push_back(top);
        vector<string> v_state = next_state(top);
        for(string state: v_state) {
            if(state_map1.find(state) == state_map1.end()) {
                state_map1[state] = dist + 1;
                max_dist = max(max_dist, dist + 1);
                q1.push(state);
            }
        }
    }

    while(!q2.empty()) {
        string top = q2.front();
        q2.pop();
        int dist = state_map2[top];
        unrecorded.push_back(top);
        vector<string> v_state = next_state(top);
        for(string state: v_state) {
            if(state_map2.find(state) == state_map2.end()) {
                state_map2[state] = dist + 1;
                q2.push(state);
            }
        }
    }

    cout << max_dist; // 31

    cout << "wtf";

    print_state(0, "123456780");
    print_state(1, "123456708");
    
    // small test: 3
    for(int i = 2; i < 5; i++) {
        int x = randomInt(2, 6);
        int id = randomInt(0, records[x].size() - 1);
        string state = records[x][id];
        print_state(i, state);
    }

    // medium test: 5
    for(int i = 5; i < 10; i++) {
        int x = randomInt(7, 25);
        int id = randomInt(0, records[x].size() - 1);
        string state = records[x][id];
        print_state(i, state);
    }

    // max test: 5
    for(int i = 10; i < 15; i++) {
        int x = randomInt(26, 31);
        int id = randomInt(0, records[x].size() - 1);
        string state = records[x][id];
        print_state(i, state);
    }

    // null test: 5
    for(int i = 15; i < 20; i++) {
        int id = randomInt(0, unrecorded.size() - 1);
        string s = unrecorded[id];
        ofstream out(outfile(i));
        ofstream inp(infile(i));
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                inp << s[i * 3 + j] << " ";
            }
            if(i < 2) inp << "\n";
        }
        out << -1;
        out.close();
        inp.close();
    }

    return 0;
}