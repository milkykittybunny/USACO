#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > photos;

bool compare(int a, int b) {
    int aFirst = 0;
    for (int i = 0; i < n; i++) {
        aFirst += photos[i][a] < photos[i][b];
    }
    return aFirst >= 3;
}

int main() {
    ifstream fIn("photo.in");
    ofstream fOut("photo.out");

    fIn >> n;

    photos.resize(5, vector<int> (n));
    vector<int> cows(n);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            fIn >> temp;
            photos[i][temp] = j;
            cows[j] = temp;
        }
    }

    sort(cows.begin(), cows.end(), compare);

    for (int i = 0; i < cows.size(); i++) {
        fOut << cows[i] << endl;
    }

    fIn.close();
    fOut.close();
}