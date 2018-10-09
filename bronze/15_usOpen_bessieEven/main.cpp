#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("geteven.in");
    ofstream fOut("geteven.out");

    // solution comes here
    int n;
    fIn >> n;

    map<char, vector<int> > characters;

    for (int i = 0; i < n; i++) {
        char temp;
        int tVal;
        fIn >> temp;
        fIn >> tVal;
        if (characters.count(temp) == 0) {
            if (tVal % 2 == 0) {
                characters[temp] = {1, 0};
            }
            else {
                characters[temp] = {0, 1};
            }
        }
        else {
            if (tVal % 2 == 0) {
                characters[temp][0]++;
            }
            else {
                characters[temp][1]++;
            }
        }
    }

    int total = 0;
    for (int b = 0; b < 2; b++) {
        for (int e = 0; e < 2; e++) {
            for (int s = 0; s < 2; s++) {
                for (int i = 0; i < 2; i++) {
                    for (int g = 0; g < 2; g++) {
                        for (int o = 0; o < 2; o++) {
                            for (int m = 0; m < 2; m++) {
                                if (((b + e + s + s + i + e) * (g + o + e + s) * (m + o + o)) % 2 == 0) {
                                    total += (characters['B'][b] *
                                            characters['E'][e] *
                                            characters['S'][s] *
                                            characters['I'][i] *
                                            characters['G'][g] *
                                            characters['O'][o] *
                                            characters['M'][m]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    fOut << total;

    fIn.close();
    fOut.close();
}