#include <iostream>
#include <fstream>
#include "../brownie.h"
using namespace std;

void print_test(int test_id, int nm_min, int nm_max, int q_min, int q_max, int z_min, int z_max) {

    int z = randomInt(z_min, z_max);
    int q = randomInt(q_min, q_max);
    int n = randomInt(nm_min, nm_max);
    int m = randomInt(nm_min, nm_max);
    ofstream in(infile(test_id));

    in << n << " " << m << " " << z << " " << q << endl;

    for (int i = 0; i < z; i++) {
        in << randomInt(1, n) << " " << randomInt(1, m) << "\n";
    }

    for(int i = 0; i < q; i++) {
        in << randomInt(1, n) << " " << randomInt(1, m) << 
        " " << randomInt(1, n) << " " << randomInt(1, m) << "\n";
    }

    in.close();

}

int main() {

    // sample test :1 

    // small test: 6

    for(int i = 1; i < 7; i++) {
        print_test(i, 10, 20, 5, 10, 5, 10);
    }

    // medium test: 6

    for(int i = 7; i < 13; i++) {
        print_test(i, 80000, 100000, 900, 1000, 900, 1000);
    }

    // big test: 6

    for(int i = 13; i < 19; i++) {
        print_test(i, 800000000, 1000000000, 80000, 100000, 80000, 100000);
    }

    // biggest:
    print_test(19, 1000000000, 1000000000, 100000, 100000, 100000, 100000);
    
}