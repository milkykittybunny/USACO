#include <bits/stdc++.h>
using namespace std;

int max_items(vector<pair<int, int> > activities) {
    int itemsDone = 0;
    int ctime = 0;
    for (int i = 0; i < activities.size(); i++) {
        if (activities[i].first >= ctime) {
            itemsDone++;
            ctime = activities[i].second;
        }
    }
    return itemsDone;
}

bool lessThan(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        vector<pair<int, int> > activities;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int cn, cm;
            cin >> cn >> cm;
            pair<int, int> cpar = make_pair(cn, cm);
            activities.push_back(cpar);
        }
        sort(activities.begin(), activities.end(), lessThan);
        cout << max_items(activities) << endl;
    }
}