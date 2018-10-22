#include <bits/stdc++.h>
using namespace std;

set<string> palindromesUp;
set<string> palindromesDown;
int n;

// this is a classic 2D recursive example by prof melody!

void f1(int x, int y, string current, vector<vector<char> > &field) {
    current += field[x][y];
    if (x + y == n-1) {
        palindromesUp.insert(current);
        return;
    }

    else {
        if (y+1 <= n-1) {
            f1(x, y + 1, current, field);
        }
        if (x+1 <= n-1) {
            f1(x + 1, y, current, field);
        }
    }
}

void f2(int x, int y, string current, vector<vector<char> > &field) {
    current += field[x][y];
    if (x + y == n-1) {
        palindromesDown.insert(current);
        return;
    }

    else {
        if (y-1 >= 0) {
            f2(x, y - 1, current, field);
        }
        if (x-1 >= 0) {
            f2(x - 1, y, current, field);
        }
    }
}

/*
 * dumb solution by prof melody
bool palindrome(string input) {
    int len = input.size();
    for (int i = 0; i < len/2; i++) {
        if (input[i] != input[len - i - 1]) {
            return false;
        }
    }
    return true;
}

void f(int x, int y, string current, vector<vector<char> > &field) {
    current += field[x][y];
    if (x == n-1 && y == n-1) {
        if (palindrome(current)) {
            palindromes.insert(current);
        }
        return;
    }

    else {
        if (y+1 <= n-1) {
            f(x, y + 1, current, field);
        }
        if (x+1 <= n-1) {
            f(x + 1, y, current, field);
        }
    }
}
*/

int main() {
    ifstream fIn("palpath.in");
    ofstream fOut("palpath.out");

    // solution comes here

    fIn >> n;

    vector<vector<char> > field(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fIn >> field[i][j];
        }
    }

    f1(0, 0, "", field);
    f2(n-1, n-1, "", field);

    int total = 0;
    for (auto it = palindromesUp.begin(); it != palindromesUp.end(); it++) {
        if (palindromesDown.find(*it) != palindromesDown.end()) {
            cout << *it << endl;
            total++;
        }
    }

    fOut << total;

    fIn.close();
    fOut.close();
}