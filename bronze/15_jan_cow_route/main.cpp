#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fIn("cowroute.in");
    ofstream fOut("cowroute.out");

    int a, b, n;
    fIn >> a >> b >> n;
    vector<int> costs(n);
    vector<vector<int> > routes;
    int length;
    for (int i = 0; i < n*2; i++) {
        if (i % 2 == 0) {
            fIn >> costs[i/2];
            fIn >> length;
        }
        else {
            vector<int> temp(length);
            for (int j=0; j < length; j++) {
                fIn >> temp[j];
            }
            routes.push_back(temp);
        }
    }
    int leastcost = 100000;
    for (int i = 0; i < n; i++) {
        auto it = find(routes[i].begin(), routes[i].end(), a);
        auto tt = find(routes[i].begin(), routes[i].end(), b);
        if (it != routes[i].end()
            && tt != routes[i].end()
            && tt > it) {
            if (costs[i] < leastcost) {
                leastcost = costs[i];
            }
        }
    }
    if (leastcost == 100000) {
        fOut << -1;
    }
    else {
        fOut << leastcost;
    }
    fIn.close();
    fOut.close();
}