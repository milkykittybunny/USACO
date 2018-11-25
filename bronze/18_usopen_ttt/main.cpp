#include <bits/stdc++.h>
using namespace std;

set<char> individualWinners;
set<pair<char, char> > teamWinners;

void insert(int one, int two, int three) {
    if (one == two && one == three) {
        individualWinners.insert(one);
    }

    else if (one == two || one == three || two == three) {
        pair<int, int> tempPair;

        if (one == two) {
            if (one < three) {
                tempPair = make_pair(one, three);
            }
            else {
                tempPair = make_pair(three, one);
            }
            teamWinners.insert(tempPair);
        }

        if (two < three) {
            tempPair = make_pair(two, three);
        }
        else {
            tempPair = make_pair(three, two);
        }
        if (one == three) {
            if (two < three) {
                tempPair = make_pair(two, three);
            }
            else {
                tempPair = make_pair(three, two);
            }
            teamWinners.insert(tempPair);
        }
    }
}

int main() {
    ifstream fIn("tttt.in");
    ofstream fOut("tttt.out");

    vector<vector<char> > board(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fIn >> board[i][j];
        }
    }

    int individual = 0, team = 0;

    char one, two, three;
    for (int i = 0; i < 3; i++) {
        // horizontally

        insert(board[i][0], board[i][1], board[i][2]);

        // vertically
        insert(board[0][i], board[1][i], board[2][i]);

    }
    // diagonally

    insert(board[0][0], board[1][1], board[2][2]);

    // other way
    insert(board[0][2], board[1][1], board[2][0]);

    fOut << individualWinners.size() << endl << teamWinners.size();

    fIn.close();
    fOut.close();
}
