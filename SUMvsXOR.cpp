#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */ 
long sumXorAlt(long n) {
    bitset<sizeof(int) * 8> bits(n);
    long zeroCounter = 0;
    while(bits.count() > 0) {
        if(bits[0] == 0) zeroCounter++;
        bits >>= 1;
    }
    return pow(2, zeroCounter);
}

long sumXor(long n){
    if(n == 0) return 1;
    bitset<sizeof(long) * 8> bits(n);
    int firstOne = 0;
    string bitstr = bits.to_string();
    while(bitstr.at(firstOne) == '0') {
        firstOne++;
    }
    int zeroCounter = 0;
    for(int i = ++firstOne; i < bitstr.length(); i++) {
        if(bitstr.at(i) == '0') {
            zeroCounter++;
        }
    }
    return pow(2, zeroCounter);
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}
