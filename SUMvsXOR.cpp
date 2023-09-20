#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>
#include <math.h>

#define CHAR_BIT 8

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXorAlt(long n) {
    int counter = 0;
    for(long i = 0; i <= n; i++) {
        long a = n + i, b = n ^ i;
        if(a == b) {
            printf("%d ) %d : %d \n", i, a, b);
            counter ++;
        }
    }
    return counter;
}

long sumXor(long n) {
    bitset<sizeof(int) * CHAR_BIT> bits(n);
    long zeroCounter = 0;
    while(bits.count() > 0) {
        if(bits[0] == 0) zeroCounter++;
        bits >>= 1;
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
