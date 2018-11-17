#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("sum.in");
    ofstream fOut("sum.out");

    // solution comes here
    int n, sum;
    fIn >> n >> sum;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        fIn >> array[i];
    }
    bool found = false;
#if 1
    set<int> mySet;
    for (int i = 0; i < n; i++) {
        if (mySet.find(array[i]) == mySet.end()) {
            mySet.insert(sum - array[i]);
        }
        else {
            found = true;
            break;
        }
    }


#else
    sort(array.begin(), array.end());
    int p = 0, q = n-1;

    while (p < q) {
        if (array[p] + array[q] == sum) {
            found = true;
            break;
        }
        else if (array[p] + array[q] < sum) {
            p++;
        }
        else {
            q--;
        }
    }
#endif

    if (found) {
        fOut << "Yes";
    }
    else {
        fOut << "No";
    }

    fIn.close();
    fOut.close();
}