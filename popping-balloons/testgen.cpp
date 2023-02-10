#include <iostream>
#include <fstream>
#include "../brownie.h"
using namespace std;
#define oo INT_MAX

int dp[205][205];
int a[205];

int MAX_VAL = 1000000;
int MIN_VAL = 0;

string infile(int x) {
    return "test/input/input" + formatNumber(x, 2) + ".txt";
}

string outfile(int x) {
    return "test/output/output" + formatNumber(x, 2) + ".txt";
}

void solution(ifstream& in, ofstream& out) {
    int n;
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        in >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = -oo;
        }
    }

    for (int o = 0; o < n; o++)
    {
        for (int i = 1; i + o <= n; i++)
        {
            int j = i + o;
            if (o == 0)
            {
                dp[i][j] = a[i - 1] + a[i] + a[j + 1];
                continue;
            }

            dp[i][j] = max(dp[i][j], dp[i + 1][j] + a[i - 1] + a[i] + a[j + 1]);

            dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i - 1] + a[j] + a[j + 1]);

            for (int k = i + 1; k <= j - 1; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[i - 1] + a[k] + a[j + 1]);
            }
        }
    }
    out << dp[1][n];
}

void print_test(int test_id, int n_min, int n_max) {

    int x = randomInt(n_min, n_max);
    ofstream in(infile(test_id));
    ofstream out(outfile(test_id));

    in << x << "\n";
    for(int i = 0; i < x; i++) {
        in << randomInt(MIN_VAL, MAX_VAL);
        if(i < x - 1) in << ' ';
    }
    in.close();
    ifstream in2(infile(test_id));

    solution(in2, out);
    in2.close();
    out.close();

}

int main()
{
    // sample test
    ofstream in0(infile(0));
    ofstream out0(outfile(0));
    in0 << 4 << '\n' << "1 2 3 4";
    out0 << 25;
    in0.close();
    out0.close();

    // small test: 9
    for(int i = 1; i < 10; i++) {
        print_test(i, 10, 50);
    }

    // big test: 9
    for(int i = 10; i < 20; i++) {
        print_test(i, 151, 200);
    }

    // biggest: 1
    print_test(19, 200, 200);

    return 0;
}