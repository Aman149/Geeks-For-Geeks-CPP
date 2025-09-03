#include <iostream>
#include <fstream>
#include <string>
using namespace std;

long long int factorial(int n) {
    long long int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Error opening input/output file\n";
        return 1;
    }

    int n;
    while (fin >> n) {   // keep reading until EOF
        fout << factorial(n) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}