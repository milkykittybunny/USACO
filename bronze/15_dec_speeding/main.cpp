#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("speeding.in");
    ofstream fOut("speeding.out");

    // solution comes here
    int n, m;
    fIn >> n >> m;

    vector<int> limit(100);
    vector<int> bessie(100);

    int ctotal = 0;
    for (int i = 0; i < n; i++) {
        int temp, tempSpeed;
        fIn >> temp >> tempSpeed;
        for (int i = 0; i < temp; i++) {
            limit[ctotal + i] = tempSpeed;
        }
        ctotal += temp;
    }
    ctotal = 0;
    for (int i = 0; i < m; i++) {
        int temp, tempSpeed;
        fIn >> temp >> tempSpeed;
        for (int i = 0; i < temp; i++) {
            bessie[ctotal + i] = tempSpeed;
        }
        ctotal += temp;
    }

    int greatest_speed = 0;
    for (int i = 0; i < 100; i++) {
        if (bessie[i] > limit[i]) {
            int diff = bessie[i] - limit[i];
            if (diff > greatest_speed) {
                greatest_speed = diff;
            }
        }
    }

    fOut << greatest_speed;

    fIn.close();
    fOut.close();
}
