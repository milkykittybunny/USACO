#include <bits/stdc++.h>

using namespace std;

const int N = 4;
int chess[N][N];

void print_chess() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (chess[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void n_queen(int col) {
    if (col == N) {
        print_chess();
    }
    else {
        for (int row = 0; row < N; row++) {
            bool flag = true;
            for (int i = 0; i < col; i++) {
                if (chess[i][row] == 1) {
                    flag = false;
                    break;
                }
            }
            for (int current = 1; col - current >= 0 && row - current >= 0; current++) {
                if (chess[col - current][row - current] == 1) {
                    flag = false;
                    break;
                }
            }
            for (int current = 1; col - current >= 0 && row + current < N; current++) {
                if (chess[col - current][row + current] == 1) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                chess[col][row] = 1;
                n_queen(col+1);
                chess[col][row] = 0;
            }
        }
    }
}

int main() {
    n_queen(0);
}