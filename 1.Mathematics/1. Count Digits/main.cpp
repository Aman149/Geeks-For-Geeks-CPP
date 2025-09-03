#include <iostream>
#include <fstream>
using namespace std;

int countDigits(int n) {
    int count = 0;
    while(n>0) {
        n/=10;
        count++;
    }
    return count;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    fout << countDigits(n) << endl;
    fin.close();
    fout.close();
    return 0;
}