#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("cowtip.in");
    ofstream fOut("cowtip.out");

    // solution comes here
    int n;
    fIn >> n;

    vector<vector<char> > farm(n, vector<char> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char temp;
            fIn >> temp;
            farm[i][j] = temp;
        }
    }

    int totalflips = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (farm[i][j] == '1') {
                totalflips++;
                // function cow_flip()
                for (int a = 0; a <= i; a++) {
                    for (int b = 0; b <= j; b++) {
                        if (farm[a][b] == '0') {
                            farm[a][b] = '1';
                        }
                        else {
                            farm[a][b] = '0';
                        }
                    }
                }
                // end function cow_flip()
            }
        }
    }

    fOut << totalflips;

    fIn.close();
    fOut.close();
}