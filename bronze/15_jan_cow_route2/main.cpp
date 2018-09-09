#include <bits/stdc++.h>

using namespace std;


bool possible(vector<int> route1, vector<int> route2, int a, int b) {
    auto it = find(route1.begin(), route1.end(), a);
    auto tt = find(route2.begin(), route2.end(), b);
    if (it == route1.end() || tt == route2.end()) {
        return false;
    }
    for (int i = 0; i < route1.size(); i++) {
        for (int j = 0; j < route2.size(); j++) {
            if ((route1[i] == route2[j])
            && (i > it - route1.begin())
            && (j < tt - route2.begin())) {
                    return true;
            }
        }
    }
    return false;
}


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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (possible(routes[i], routes[j], a, b)) {
                    int tempcost = costs[i] + costs[j];
                    if (tempcost < leastcost) {
                        leastcost = tempcost;
                    }
                }
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