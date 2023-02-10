#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < (int) s.size(); i++) {
        switch(s[i]) {
            case 'A':
                ans.push_back('U');
                break;
            case 'T':
                ans.push_back('A');
                break;
            case 'C':
                ans.push_back('G');
                break;
            case 'G':
                ans.push_back('C');
                break;
            default:
                ;
        }
    }
    cout << ans;
    return 0;
}