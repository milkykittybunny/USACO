#include <bits/stdc++.h>
using namespace std;

int swaps(vector<int> &lineup) {
    // finding bessie
    int bessieIndex = 0;
    while (bessieIndex < lineup.size() - 1 &&
    lineup[bessieIndex] <= lineup[bessieIndex + 1]) {
        bessieIndex++;
    }
    // doing swaps
    int swapsMade = 1;
    int tempVal = lineup[bessieIndex];
    lineup[bessieIndex] = lineup[bessieIndex + 1];
    lineup[bessieIndex + 1] = tempVal;
    // testing going -->
    if ((bessieIndex+2 < lineup.size()) &&
    (lineup[bessieIndex+2] < lineup[bessieIndex+1])) {
        if (lineup[bessieIndex+2] == lineup[bessieIndex]) {
            swapsMade--;
        }
        bessieIndex++;
        int tempIndex = bessieIndex+1;
        while (tempIndex < lineup.size() &&
        lineup[bessieIndex] > lineup[tempIndex]) {
            tempVal = lineup[tempIndex];
            // see if all the same
            while (tempIndex < lineup.size() &&
            lineup[tempIndex + 1] == tempVal) {
                tempIndex++;
            }
            // compare & swap
            tempVal = lineup[tempIndex];
            lineup[tempIndex] = lineup[bessieIndex];
            lineup[bessieIndex] = tempVal;
            bessieIndex = tempIndex;
            tempIndex = bessieIndex + 1;
            swapsMade++;
        }
    }
    // bessie going <--
    else if ((bessieIndex - 1 >= 0) &&
    lineup[bessieIndex - 1] > lineup[bessieIndex]) {
        if (lineup[bessieIndex-1] == lineup[bessieIndex+1]) {
            swapsMade--;
        }
        int tempIndex = bessieIndex - 1;
        while (tempIndex >= 0 &&
        lineup[bessieIndex] < lineup[tempIndex]) {
            tempVal = lineup[tempIndex];
            // see if all the same
            while (tempIndex >= 0 &&
            lineup[tempIndex] == tempVal) {
                tempIndex--;
            }
            tempIndex++;
            // compare & swap
            tempVal = lineup[tempIndex];
            lineup[tempIndex] = lineup[bessieIndex];
            lineup[bessieIndex] = tempVal;
            bessieIndex = tempIndex;
            tempIndex = bessieIndex - 1;
            swapsMade++;
        }
    }
    return swapsMade;
}

int main() {
    ifstream fIn("outofplace.in");
    ofstream fOut("outofplace.out");

    // solution comes here
    int n;
    fIn >> n;

    vector<int> lineup(n);
    for (int i = 0; i < n; i++) {
        fIn >> lineup[i];
    }

    fOut << swaps(lineup) << endl;
    fIn.close();
    fOut.close();
}