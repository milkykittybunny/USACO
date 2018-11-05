#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("lostcow.in");
    ofstream fOut("lostcow.out");

    // solution comes here
    int farmer, bessie;
    fIn >> farmer >> bessie;

    int step = 1;

    int totalSteps = 0;
    int pos = 1;

    if (bessie > farmer) {
        while (abs(bessie - farmer) > abs(step) || pos < 0) {
            step *= -2;
            totalSteps += abs(step);
            pos *= -1;
        }
    }
    else {
        while (abs(bessie - farmer) > abs(step) || pos > 0) {
            step *= -2;
            totalSteps += abs(step);
            pos *= -1;
        }
    }

    totalSteps += abs(bessie - farmer);

    fOut << totalSteps;

    fIn.close();
    fOut.close();
}