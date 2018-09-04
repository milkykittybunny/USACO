#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



int main() {
    int m, n, k;
    ifstream fIn("cowsignal.in");
    fIn >> m >> n >> k;
    vector<vector<char>> signal(m, vector<char> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fIn >> signal[i][j];
        }
    }
    ofstream fOut("cowsignal.out");
    // up down
    for (int i = 0; i < m; i++) {
        // redo lines
        for (int l = 0; l < k; l++) {
            // print line
            for (int x = 0; x < n; x++) {
                for (int j = 0; j < k; j++) {
                    fOut << signal[i][x];
                }
            }
            fOut << endl;
            }
        }
    return 0;
}