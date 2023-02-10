#include <iostream>
#include <fstream>
#include "../brownie.h"
using namespace std;
#define oo LONG_MAX

void solution(ifstream &in, ofstream &out)
{
    int n;
    in >> n;

    long min_right = oo, max_left = -oo, min_top = oo, max_bot = -oo;

    for (int i = 0; i < n; i++)
    {

        int a, b, c, d;
        in >> a >> b >> c >> d;
        min_right = min(min_right, (long)c);
        max_left = max(max_left, (long)a);
        min_top = min(min_top, (long)d);
        max_bot = max(max_bot, (long)b);
    }

    if (min_right > max_left && min_top > max_bot)
        out << (min_right - max_left) * (min_top - max_bot);
    else
        out << 0;
}

void print_test_overlapping(int test_id, int n_min, int n_max, int m_min, int m_max)
{

    int n = randomInt(n_min, n_max);
    long left, right, bot, top;

    while (true)
    {
        left = (long) randomInt(m_min, m_max);
        right = (long) randomInt(m_min, m_max);
        if (left != right)
            break;
    }

    if (left > right)
        swap(left, right);

    while (true)
    {
        bot = (long) randomInt(m_min, m_max);
        top = (long) randomInt(m_min, m_max);
        if (bot != top)
            break;
    }

    if (bot > top)
        swap(bot, top);

    ofstream inp(infile(test_id));
    inp << n << "\n";

    for (int i = 0; i < n; i++)
    {
        long x_1 = (long) randomInt(m_min, left);
        long x_2 = (long) randomInt(right, m_max);
        long y_1 = (long) randomInt(m_min, bot);
        long y_2 = (long) randomInt(top, m_max);
        
        inp << x_1 << " " << y_1 << " " << x_2 << " " << y_2;
        if (i < n - 1)
            inp << "\n";
    }
    inp.close();

    ifstream in(infile(test_id));
    ofstream out(outfile(test_id));

    solution(in, out);

    in.close();
    out.close();
}

void print_test_random(int test_id, int n_min,
                       int n_max, int m_min, int m_max)
{
    int n = randomInt(n_min, n_max);

    ofstream inp(infile(test_id));
    inp << n << "\n";

    for (int i = 0; i < n; i++)
    {
        long left, right, bot, top;

        while (true)
        {
            left = randomInt(m_min, m_max);
            right = randomInt(m_min, m_max);
            if (left != right)
                break;
        }

        if (left > right)
            swap(left, right);

        while (true)
        {
            bot = randomInt(m_min, m_max);
            top = randomInt(m_min, m_max);
            if (bot != top)
                break;
        }

        if (bot > top)
            swap(bot, top);

        inp << left << " " << bot << " " << right << " " << top;
        if (i < n - 1)
            inp << "\n";
    }
    inp.close();

    ifstream in(infile(test_id));
    ofstream out(outfile(test_id));

    solution(in, out);

    in.close();
    out.close();
}

void max_test(int test_id, int n, int m)
{

    ofstream inp(infile(test_id));
    inp << n << "\n";

    for (int i = 0; i < n; i++)
    {

        inp << -m << " " << -m << " " << m << " " << m;
        if (i < n - 1)
            inp << "\n";
    }
    inp.close();

    ifstream in(infile(test_id));
    ofstream out(outfile(test_id));

    solution(in, out);

    in.close();
    out.close();
}

int main()
{
    // sample test : 2

    // small test: 4 with guarantee overlap, 2 without

    for (int i = 2; i < 6; i++)
    {
        print_test_overlapping(i, 5, 10, -100, 100);
    }

    for (int i = 6; i < 8; i++)
    {
        print_test_random(i, 5, 10, -100, 100);
    }

    // medium test: 4 with guarantee overlap, 2 without

    for (int i = 8; i < 12; i++)
    {
        print_test_overlapping(i, 800, 1000, -100000, 100000);
    }

    for (int i = 12; i < 14; i++)
    {
        print_test_random(i, 800, 1000, -100000, 100000);
    }

    // big test : 4 with guarantee overlap, 2 without
    for (int i = 14; i < 17; i++)
    {
        print_test_overlapping(i, 80000, 100000, -1000000000, 1000000000);
    }

    // max test
    max_test(17, 100000, 1000000000);

    for (int i = 18; i < 20; i++)
    {
        print_test_random(i, 80000, 100000, -1000000000, 1000000000);
    }

    return 0;
}