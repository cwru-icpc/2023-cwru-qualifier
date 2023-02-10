#include <iostream>
#include <fstream>
#include "../brownie.h"
using namespace std;

const char dna[4][2] = {{'A', 'U'}, {'T', 'A'}, {'C', 'G'}, {'G', 'C'}};

void print_state(int test_id, int n_min, int n_max) {
    int x = randomInt(n_min, n_max);

    ofstream in(infile(test_id));
    ofstream out(outfile(test_id));

    for(int i = 0; i < x; i++) {
        int val = randomInt(0, 3);
        in << dna[val][0];
        out << dna[val][1];
    }
    in.close();
    out.close();
}

int main() {

    // sample test: 1
    ofstream in0(infile(0));
    ofstream out0(outfile(0));
    in0 << "ATCG";
    out0 << "UAGC";
    in0.close();
    out0.close();

    // small test: 9
    for(int i = 1; i < 10; i++) {
        print_state(i, 10, 50);
    }

    // big test: 9
    for(int i = 10; i < 19; i++) {
        print_state(i, 500, 1000);
    }

    // biggest test: 1
    print_state(19, 1000, 1000);


    return 0;
}