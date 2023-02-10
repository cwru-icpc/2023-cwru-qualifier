#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    string result = "";
    for(int i = 0; i < n; i++) {
        string path;
        cin >> path;
        result.push_back(((path[i] - '0' + 1) & 1) + '0');
    }
    cout << result;
    return 0;
}