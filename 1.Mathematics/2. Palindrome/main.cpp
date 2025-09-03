#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int checkPalindrome(int n) {
    int reverse = 0, original = n;
    while (n > 0) {
        int digit = n % 10;
        n = n / 10;
        reverse = reverse * 10 + digit;
    }
    return original == reverse;
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
        fout << checkPalindrome(n) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}