#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct Class {
    int a, d, x, y;
    Class(int _a=0, int _d=0, int _x=0, int _y=0): a(_a), d(_d), x(_x), y(_y) {}
};

int n, result;
vector<Class> classes;
vector<int> selected;
unordered_set<int> available;

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

void backtrack(int pos) {
    result = max(result, evaluateSelected(selected));

    if (pos == n) 
        return;

    for(int i = 0; i < n; i++) {
        if (available.count(i)) {
            available.erase(i);
            selected.push_back(i);
            backtrack(pos + 1);
            available.insert(i);
            selected.pop_back();
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, d, x, y;
        cin >> a >> d >> x >> y;
        classes.push_back(Class(a, d, x, y));
    }

    for(int i = 0; i < n; i++)
        available.insert(i);

    result = 0;
    backtrack(0);

    cout << result;
    return 0;
}