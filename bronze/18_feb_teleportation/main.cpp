#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("teleport.in");
    ofstream fOut("teleport.out");

    // solution comes here
    int a, b, x, y;
    fIn >> a >> b >> x >> y;
    int leastpos = abs(b - a);
    if (abs(x - a) + abs(y - b) < leastpos) {
        leastpos = abs(x - a) + abs(y - b);
    }
    if (abs(y - a) + abs(x - b) < leastpos) {
        leastpos = abs(y - a) + abs(x - b);
    }
    fOut << leastpos;
    fIn.close();
    fOut.close();
}