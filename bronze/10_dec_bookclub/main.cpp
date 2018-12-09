#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("bookclub.in");
    ofstream fOut("bookclub.out");

    // solution comes here
    int n, nq, p;
    fIn >> n >> nq >> p;


    vector<vector<int> > cowsAnswers(n, vector<int> (nq));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nq; j++) {
            fIn >> cowsAnswers[i][j];
        }
    }

    vector<pair<int, int> > requirements(p);
    for (int i = 0; i < p; i++) {
        int q, a;
        fIn >> q >> a;
        requirements[i] = make_pair(q, a);
    }

    // each question
    for (int i = 0; i < p; i++) {
        // each cow
        vector<vector<int> > temp;
        for (int j = 0; j < cowsAnswers.size(); j++) {
            if (cowsAnswers[j][requirements[i].first - 1] == requirements[i].second) {
                temp.push_back(cowsAnswers[j]);
            }
        }
        cowsAnswers = temp;
    }

    fOut << cowsAnswers.size();


    fIn.close();
    fOut.close();
}