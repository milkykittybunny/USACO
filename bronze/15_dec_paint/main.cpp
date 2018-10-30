#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("paint.in");
    ofstream fOut("paint.out");

    // solution comes here
    int a, b, c, d;
    fIn >> a >> b >> c >> d;

    if (d > a && b > c) {
        int begin, end;
        if (a < c) {
            begin = a;
        } else {
            begin = c;
        }

        if (b > d) {
            end = b;
        } else {
            end = d;
        }
        fOut << (end - begin);
    }

    else {
        fOut << ((b - a) + (d - c));
    }

    fIn.close();
    fOut.close();
}
