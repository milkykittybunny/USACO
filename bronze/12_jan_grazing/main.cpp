#include <bits/stdc++.h>
using namespace std;

int k;

void print_maze(vector<vector<int> > farm) {

    std::system("clear");
    char c;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << farm[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;

}

int cow_path(int i, int j, vector<vector<int> > &farm) {
    // check if on boundary or if invalid position
    if (i < 0 || i > 4 || j < 0 || j > 4 || farm[i][j] == 0) {
        return 0;
    }
    //print_maze(farm);
    //cout << i << "," << j << "," << k << endl;
    //cin.get(c);

    // mark the place that's already been there
    farm[i][j] = 0;
    k++;

    if (i == 4 && j == 4 && k == 25) {
        // backtrack
        k--;
        farm[i][j] = 1;
        return 1;
    }

    int count = cow_path(i, j-1, farm) + cow_path(i+1, j, farm) + cow_path(i, j+1, farm)
            + cow_path(i-1, j, farm);

    // backtrack
    k--;
    farm[i][j] = 1;

    return count;
}

int main() {
    for (int num = 2; num < 3; num++) {
        ifstream check(to_string(num) + ".out");
        ifstream fIn(to_string(num) + ".in");

        fIn >> k;

        vector<vector<int> > farm(5, vector<int> (5));

        for (int i = 0; i < 5; i++) {
            for (int  j = 0; j < 5; j++) {
                farm[i][j] = 1;
            }
        }

        for (int i = 0; i < k; i++) {
            int x, y;
            fIn >> x >> y;
            farm[x-1][y-1] = 0;
        }

        int paths = cow_path(0, 0, farm);

        int answer;
        check >> answer;

        if (paths == answer) {
            cout << "Testcase " << num << " right" << endl;
        }
        else {
            cout << "Testcase " << num << " wrong" << endl;
        }

        fIn.close();
        check.close();
    }
}