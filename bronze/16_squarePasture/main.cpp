#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream fIn("square.in");
    int d1x, d1y, u1x, u1y, d2x, d2y, u2x, u2y;
    fIn >> d1x >> d1y >> u1x >> u1y;
    fIn >> d2x >> d2y >> u2x >> u2y;
    int d3x = min(d1x, d2x);
    int d3y = min(d1y, d2y);
    int u3x = max(u1x, u2x);
    int u3y = max(u1y, u2y);
    int side1 = u3x - d3x;
    int side2 = u3y - d3y;
    ofstream fOut("square.out");
    if (side1 > side2) {
        fOut << side1*side1;
    }
    else {
        fOut << side2*side2;
    }
    return 0;
}

//20 mins