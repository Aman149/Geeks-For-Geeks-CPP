#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

// Function to multiply two large numbers (represented as strings)
string multiply(string num, int x) {
    int carry = 0;
    string result = "";
    reverse(num.begin(), num.end());
    for (char digit : num) {
        int prod = (digit - '0') * x + carry;
        result += (prod % 10) + '0';
        carry = prod / 10;
    }
    while (carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Factorial using string for large n
string factorial(int n) {
    string result = "1";
    for (int i = 2; i <= n; ++i) {
        result = multiply(result, i);
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
    while (fin >> n) {
        fout << factorial(n) << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}
