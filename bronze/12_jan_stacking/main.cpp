#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1; i < 11; i++) {
        ifstream check(to_string(i) + ".out");
        ifstream fIn(to_string(i) + ".in");

        int n, k;
        fIn >> n >> k;

        vector<int> stacks(n);

        for (int i = 0; i < k; i++) {
            int start, end;
            fIn >> start >> end;
            stacks[start-1]++;
            stacks[end]--;
        }

        for (int i = 0; i < n; i++) {
            stacks[i] += stacks[i - 1];
        }

        sort(stacks.begin(), stacks.end());

        int mid = n / 2;

        fIn.close();

        int other;
        check >> other;
        if (other != stacks[mid]) {
            cout << "Testcase " + to_string(i) + " wrong." << endl;
        }
        else {
            cout << "Testcase " + to_string(i) + " right." << endl;
        }

        check.close();
    }
}