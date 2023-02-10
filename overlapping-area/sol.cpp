#include <iostream>
#include <climits>
using namespace std;
#define oo LONG_MAX


int main() {
    int n;
    cin >> n;

    long min_right = oo, max_left = -oo, min_top = oo, max_bot = -oo;

    for(int i = 0; i < n; i++) {

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        min_right = min(min_right, (long) c);
        max_left = max(max_left, (long) a);
        min_top = min(min_top, (long) d);
        max_bot = max(max_bot, (long) b);

    }

    if(min_right > max_left && min_top > max_bot) 
        cout << (min_right - max_left) * (min_top - max_bot);
    else 
        cout << 0;

    return 0;
}