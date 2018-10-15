#include <bits/stdc++.h>
using namespace std;

struct bale {
    int size;
    int position;
};


bool less_than(bale a, bale b) {
    return a.position < b.position;
}



bool checker(vector<bale> &bales, int left, int right) {
    int change = true;
    while (right < bales.size() && left >= 0 && change) {
        change = false;
        int distance = bales[right].position - bales[left].position;
        if (bales[right].size < distance) {
            right++;
            if (right > bales.size() - 1) {
                break;
            }
            change = true;
        }
        if (bales[left].size < distance) {
            left--;
            if (left < 0) {
                break;
            }
            change = true;
        }
    }
    if (left < 0 || right > bales.size() - 1) {
        return false;
    }
    return true;
}

int main() {
    ifstream fIn("trapped.in");
    ofstream fOut("trapped.out");

    // solution comes here
    int n;
    fIn >> n;

    vector<bale> bales(n);

    for (int i = 0; i < n; i++) {
        fIn >> bales[i].size >> bales[i].position;
    }

    sort(bales.begin(), bales.end(), less_than);

    int total = 0;

    for (int i = 0; i < bales.size() - 1; i++) {
        if (checker(bales, i, i+1)) {
            total += bales[i+1].position - bales[i].position;
        }
    }

    fOut << total;
    fIn.close();
    fOut.close();
}