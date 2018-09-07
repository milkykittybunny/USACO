#include <bits/stdc++.h>
using namespace std;

struct point {
    int x;
    int y;
};
int main() {
    ifstream fIn("marathon.in");
    ofstream fOut("marathon.out");
    int n;
    fIn >> n;
    vector<point> path(n);
    for (int i = 0; i < n; i++) {
        fIn >> path[i].x >> path[i].y;
    }
    // looping through possibilities, brute force
    int mintotal = 1000000000;
    int total = 0;
    for (int i = 0; i < n-1; i++) {
        total += abs(path[i].x - path[i+1].x) + abs(path[i].y - path[i+1].y);
    }
    for (int i = 1; i < n - 1; i++) {
        int ctotal = total;
        ctotal -= abs(path[i].x - path[i+1].x) + abs(path[i].y - path[i+1].y);
        ctotal -= abs(path[i].x - path[i-1].x) + abs(path[i].y - path[i-1].y);
        ctotal += abs(path[i-1].x - path[i+1].x) + abs(path[i-1].y - path[i+1].y);
        if (ctotal < mintotal) {
            mintotal = ctotal;
        }
    }


    fOut << mintotal;

    fIn.close();
    fOut.close();
}

