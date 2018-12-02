#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("milkorder.in");
    ofstream fOut("milkorder.out");

    // solution comes here
    int n, m, k;
    fIn >> n >> m >> k;

    vector<int> mlst(m);
    vector<int> corder(n);

    for (int i = 0; i < m; i++) {
        fIn >> mlst[i];
    }

    for (int i = 0; i < k; i++) {
        int cow, place;
        fIn >> cow >> place;
        corder[place - 1] = cow;
    }

    int last = 0;
    for (int i = 0; i < m; i++) {
        if (find(corder.begin(), corder.end(), mlst[i]) != corder.end()) {
            int currentIndex = find(corder.begin(), corder.end(), mlst[i]) - corder.begin();
            int mainSub = 1;
            int placeSub = 1;
            bool went_In = false;
            while (corder[last] != mlst[i - placeSub] && i - placeSub >= 0 && currentIndex - mainSub >= 0) {
                if (corder[currentIndex - mainSub] == 0) {
                    went_In = true;
                    corder[currentIndex - mainSub] = mlst[i - placeSub];
                    placeSub++;
                }
                mainSub++;
            }
            if (went_In) {
                last = currentIndex;
            }
        }
        if (mlst[i] == 1) {
            int lastIn = 0;
            for (int j = 0; j < i; j++) {
                if (find(corder.begin(), corder.end(), mlst[j]) == corder.end()) {
                    bool last = false;
                    for (int k = 0; k < corder.size(); k++) {
                        if (j != 0 && corder[k] == mlst[j - 1]) {
                            last = true;
                        }
                        if ((last && corder[k] == 0) ||
                                (corder[k] == 0 && j == 0)){
                            corder[k] = mlst[j];
                            lastIn = k;
                            break;
                        }
                    }
                }
                else {
                    lastIn = find(corder.begin(), corder.end(), mlst[j]) - corder.begin();
                }
            }
            for (int j = lastIn; j < corder.size(); j++) {
                if (corder[j] == 0) {
                    fOut << j + 1;
                    return 0;
                }
            }
        }
    }

    bool found = false;
    for (int i = 0; i < corder.size(); i++) {
        if (corder[i] == 0 && found == false) {
            fOut << i + 1;
            found = true;
        }
        if (corder[i] == 1) {
            fOut << i + 1;
            break;
        }
    }

    fIn.close();
    fOut.close();
}
