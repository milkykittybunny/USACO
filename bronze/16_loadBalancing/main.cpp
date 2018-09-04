#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct coordinates {
    int x;
    int y;
};

int amount_possible(vector<int> lines, vector<coordinates> cows) {
    int one=0, two=0, three=0, four=0;
    for (int i = 0; i < cows.size(); i++) {
        if (cows[i].x < lines[0] && cows[i].y > lines[1]) {
            one++;
        }
        if (cows[i].x < lines[0] && cows[i].y < lines[1]) {
            two++;
        }
        if (cows[i].x > lines[0] && cows[i].y > lines[1]) {
            three++;
        }
        if (cows[i].x > lines[0] && cows[i].y < lines[1]) {
            four++;
        }
    }
    cout << lines[0] << " " << lines[1] << endl;
    cout << one << " " << two << " " << three << " " << four << endl;
    return max(one, max(two, (max(three, four))));
}

int main() {
    ifstream fIn("balancing.in");
    int n, b;
    fIn >> n >> b;
    vector<coordinates> cows(n);
    vector<int> xlst(n);
    vector<int> ylst(n);
    for (int i = 0; i < n; i++) {
        fIn >> cows[i].x >> cows[i].y;
        xlst[i] = cows[i].x;
        ylst[i] = cows[i].y;
    }
    sort(xlst.begin(), xlst.end());
    sort(ylst.begin(), ylst.end());
    vector<int>lines(2);
    int least = 100000000;
    for (int i = 0; i < n; i++) {
        if (xlst[i+1] != xlst[i]) {
            lines[0] = xlst[i] + 1;
        }
        else {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (ylst[j] != ylst[j+1]) {
                lines[1] = ylst[j] + 1;
            }
            else {
                continue;
            }
            int current = amount_possible(lines, cows);
            if (current < least) {
                least = current;
            }
        }
    }
    ofstream fOut("balancing.out");
    fOut << least << endl;
}