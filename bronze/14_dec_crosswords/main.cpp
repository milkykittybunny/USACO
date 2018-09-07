#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn("crosswords.in");
    ofstream fOut("crosswords.out");
    int n, m;
    fIn >> n >> m;
    vector<vector<char> > crossword(n, vector<char>(m));
    vector<pair<int, int> > returned;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fIn >> crossword[i][j];
        }
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (y+2 < m && ((y == 0) || crossword[x][y-1] != '.')
            && crossword[x][y] == '.' && crossword[x][y+1] == '.'
            && crossword[x][y+2] == '.') {
                returned.push_back(make_pair(x+1, y+1));
            }

            else if (x+2 < n && ((x == 0) || crossword[x-1][y] != '.')
            && crossword[x][y] == '.' && crossword[x+1][y] == '.'
            && crossword[x+2][y] == '.') {
                returned.push_back(make_pair(x+1, y+1));
            }
        }
    }
    fOut << returned.size() << endl;
    for (int i = 0; i < returned.size(); i++) {
        fOut << returned[i].first << " " << returned[i].second << endl;
    }
    fIn.close();
    fOut.close();
}
