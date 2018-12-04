#include <bits/stdc++.h>
using namespace std;

vector<vector<char> > pattern;

int numbers(int x, int y, vector<pair<int, int> > &markLst, char mark) {
    if (x < pattern.size() && y < pattern[1].size()
    && x >= 0 && y >= 0) {
        pattern[x][y] = mark;
        markLst.push_back(make_pair(x, y));
        if (x + 1 < pattern.size()
        && pattern[x+1][y] == 'X') {
            numbers(x + 1, y, markLst, mark);
        }
        if (x - 1 >= 0
            && pattern[x-1][y] == 'X') {
            numbers(x - 1, y, markLst, mark);
        }
        if (y + 1 < pattern[0].size()
            && pattern[x][y+1] == 'X') {
            numbers(x, y + 1, markLst, mark);
        }
        if (y - 1 >= 0
            && pattern[x][y-1] == 'X') {
            numbers(x, y - 1, markLst, mark);
        }
    }

    return 0;
    /*if (xAmount != 0) {
        if (pattern[x][y] == 'X') {
            pattern[x][y] == mark;
            xAmount--;
            numbers(x + 1, y, xAmount, mark);
            numbers(x - 1, y, xAmount, mark);
            numbers(x, y + 1, xAmount, mark);
            numbers(x, y - 1, xAmount, mark);
        }
    }
    else {
        return 0;
    }*/
}

int main() {
    ifstream fIn("pageant.in");
    ofstream fOut("pageant.out");

    // solution comes here
    int n, m;
    fIn >> n >> m;

    pattern.resize(n, vector<char> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fIn >> pattern[i][j];
            /*if (pattern[i][j] == 'X') {
                xAmount++;
            }*/
        }
    }


    vector<pair<int, int> > ones;
    vector<pair<int, int> > twos;


    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pattern[i][j] == 'X') {
                numbers(i, j, ones, '1');
                flag = true;
                break;
            }
            if (flag) {
                break;
            }
        }
    }

    flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pattern[i][j] == 'X') {
                numbers(i, j, twos, '2');
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    int greatestDiff = 1000000;
    for (int i = 0; i < ones.size(); i++) {
        for (int j = 0; j < twos.size(); j++) {
            int cDiff = abs(ones[i].first - twos[j].first) +
                    abs(ones[i].second - twos[j].second) - 1;
            if (cDiff < greatestDiff) {
                greatestDiff = cDiff;
            }
        }
    }

    fOut << greatestDiff;

    fIn.close();
    fOut.close();
}