#include <bits/stdc++.h>
using namespace std;

struct rect {
    int topX;
    int topY;
    int bottomX;
    int bottomY;
    bool valid;
};

bool isOverlap(vector<rect> &colors, int i, int j, vector<vector<char> > &canvas) {
    for (int x = colors[i].topX; x <= colors[i].bottomX; x++) {
        for (int y = colors[i].topY; y <= colors[i].bottomY; y++) {
            if (colors[j].topX <= x && colors[j].topY <= y
            && colors[j].bottomX >= x && colors[j].bottomY >= y && canvas[x][y] == ('0' + i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ifstream fIn("art.in");
    ofstream fOut("art.out");

    // solution comes here
    int n;
    fIn >> n;

    vector<vector<char> > canvas(n, vector<char> (n));
    vector<rect> colors(10);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fIn >> canvas[i][j];

        }
    }

    for (int i = 1; i <= 9; i++) {
        colors[i].topX = n, colors[i].topY = n, colors[i].bottomX = -1, colors[i].bottomY = -1;
        colors[i].valid = false;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (canvas[j][k] == ('0'+i)) {
                    colors[i].valid = true;
                    if (j < colors[i].topX) {
                        colors[i].topX = j;
                    }
                    if (j > colors[i].bottomX) {
                        colors[i].bottomX = j;
                    }
                    if (k < colors[i].topY) {
                        colors[i].topY = k;
                    }
                    if (k > colors[i].bottomY) {
                        colors[i].bottomY = k;
                    }
                }
            }
        }
    }

    int globalCount = 0;
    for (int i = 1; i <= 9; i++) {
        bool overlap = false;
        if (colors[i].valid) {
            for (int j = 1; j <= 9; j++) {
                if (colors[j].valid && i != j) {
                    if (isOverlap(colors, i, j, canvas)) {
                        overlap = true;
                    }
                }
            }

            if (! overlap) {
                globalCount++;
            }
        }
    }

    fOut << globalCount;

    fIn.close();
    fOut.close();
}