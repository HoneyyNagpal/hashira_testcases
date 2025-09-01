#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;

long long convertToDecimal(const string &value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = tolower(c) - 'a' + 10;
        else continue;
        result = result * base + digit;
    }
    return result;
}

void multiplyPoly(vector<long long> &poly, int &degree, long long root) {
    vector<long long> newPoly(poly.size(), 0);
    for (int i = 0; i <= degree; i++) {
        newPoly[i]     += poly[i] * -root;
        newPoly[i + 1] += poly[i];
    }
    degree++;
    for (int i = 0; i <= degree; i++) {
        poly[i] = newPoly[i];
    }
}

int main() {
    
    // Testcase 1
    /*
    int n = 4, k = 3;
    vector<string> bases = {"10", "2", "10", "4"};
    vector<string> values = {"4", "111", "12", "213"};
    */

    // Testcase 2
    int n = 10, k = 7;
    vector<string> bases = {
        "6", "15", "15", "16", "8", "3", "3", "6", "12", "7"
    };
    vector<string> values = {
        "13444211440455345511",
        "aed7015a346d635",
        "6aeeb69631c227c",
        "e1b5e05623d881f",
        "316034514573652620673",
        "2122212201122002221120200210011020220200",
        "20120221122211000100210021102001201112121",
        "20220554335330240002224253",
        "45153788322a1255483",
        "1101613130313526312514143"
    };
   
    vector<long long> roots(n);
    for (int i = 0; i < n; i++) {
        roots[i] = convertToDecimal(values[i], stoi(bases[i]));
        cout << "Root " << i + 1
             << " (base " << bases[i]
             << ", value " << values[i]
             << ") -> " << roots[i] << "\n";
    }

    vector<long long> poly(500, 0);
    int degree = 0;
    poly[0] = 1;

    for (int i = 0; i < k; i++) {
        multiplyPoly(poly, degree, roots[i]);
    }

    cout << "\nPolynomial coefficients:\n";
    for (int i = 0; i <= degree; i++) {
        cout << "a" << i << " = " << poly[i] << "\n";
    }

    return 0;
}
