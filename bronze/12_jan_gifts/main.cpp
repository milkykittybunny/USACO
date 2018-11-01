#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first + a.second < b.first + b.second;
}

int main() {
    ifstream fIn("gifts.in");
    ofstream fOut("gifts.out");

    int n, b;
    fIn >> n >> b;

    vector<pair<int, int> > cows(n);

    for (int i = 0; i < n; i++) {
        int tempprice, tempship;
        fIn >> tempprice >> tempship;
        cows[i] = make_pair(tempprice, tempship);
    }

    sort(cows.begin(), cows.end(), compare);

    int greatestCowsIn = 0;

    for (int i = 0; i < n; i++) {
        int currentB = 0;
        vector<pair<int, int> > temp = cows;
        int cowsIn = 0;
        temp[i].first = temp[i].first/2;
        sort(temp.begin(), temp.end(), compare);
        int j = 0;
        while (currentB < b) {
            currentB += temp[j].first + temp[j].second;
            j++;
            cowsIn++;
        }
        if (currentB > b) {
            cowsIn--;
        }
        if (cowsIn > greatestCowsIn) {
            greatestCowsIn = cowsIn;
        }
    }

    fOut << greatestCowsIn;

    fIn.close();
    fOut.close();
}