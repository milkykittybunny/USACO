#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("taming.in");
    ofstream fOut("taming.out");

    // solution comes here
    int n;
    fIn >> n;

    if (n <= 0) {
        fOut << -1;
        return 0;
    }

    vector<int> log(n);

    for (int i = 0; i < n; i++) {
        fIn >> log[i];
    }
    log[0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (log[i] > 0) {
            for (int j = 0; j < log[i] - 1; j++) {
                if (log[i - j - 1] != log[i] - j - 1 &&
                log[i - j - 1] != -1) {
                    fOut << -1;
                    return 0;
                }
                log[i - j - 1] = log[i] - j - 1;
            }
            log[i - log[i]] = 0;
        }
    }

    int min = 0, max = 0;
    for (int i = 0; i < n; i++) {
        if (log[i] == 0) {
            min++;
            max++;
        }
        if (log[i] == -1) {
            max++;
        }
    }

    fOut << min << " " << max;
    fIn.close();
    fOut.close();
}