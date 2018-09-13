#include <bits/stdc++.h>
using namespace std;

int get_bit(int n, int pos) {
    return (n & (1 << pos)) >> pos;
}

int main() {
    ifstream fIn("meeting.in");
    ofstream fOut("meeting.out");

    int n, m;
    fIn >> n >> m;

    vector<vector<int> > bessie(n+1, vector<int> (n+1));
    vector<vector<int> > elsie(n+1, vector<int> (n+1));
    for (int i = 0; i < m; i++) {
        int one, two;
        fIn >> one >> two;
        fIn >> bessie[one][two];
        fIn >> elsie[one][two];
    }

    int total = pow(2, n-2);
    set<int> bessietimes;
    set<int> elsietimes;
    for (int binnum = 0; binnum < total; binnum++) {
        int lastStopC = 1, lastStopD = 1, ctime = 0, dtime = 0;
        for (int i = 0; i < n - 2; i++) {
            if (get_bit(binnum, i) == 1) {
                if (bessie[lastStopC][i+2] != 0) {
                    ctime += bessie[lastStopC][i+2];
                    lastStopC = i+2;
                }

                if (elsie[lastStopD][i+2] != 0) {
                    dtime += elsie[lastStopD][i+2];
                    lastStopD = i+2;
                }
            }
        }

        if (bessie[lastStopC][n] != 0) {
            ctime += bessie[lastStopC][n];
            bessietimes.insert(ctime);
        }

        if (elsie[lastStopD][n] != 0) {
            dtime += elsie[lastStopD][n];
            elsietimes.insert(dtime);
        }
    }

    vector<int> common_data;
    set_intersection(bessietimes.begin(),bessietimes.end(),
            elsietimes.begin(),elsietimes.end(), back_inserter(common_data));

    if (common_data.size() == 0) {
        fOut << "IMPOSSIBLE";
    }
    else {
        fOut << common_data[0];
    }
    fIn.close();
    fOut.close();

    return 0;
}