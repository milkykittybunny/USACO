#include <bits/stdc++.h>
using namespace std;
/*
 NOTE: In this project the x and y are reversed. X is y and Y is x.
 recursive recursion 2d matrix maze backtrack
 */

const int MazeHeight = 7;
const int MazeWidth = 9;

char maze[MazeHeight][MazeWidth];

void print_maze() {

    std::system("clear");
    char c;
    for (int i = 0; i < MazeHeight; i++) {
        for (int j = 0; j < MazeWidth; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
    cin.get(c);
}

int f(int x, int y) {
    if (x == MazeHeight - 1 && y == MazeWidth - 1) {
        maze[x][y] = '*';
        return 1;
    }

    if (x < MazeHeight && x >= 0 && y >= 0 && y < MazeWidth && maze[x][y] == ' ') {
        maze[x][y] = '*';
        int total = 0;
        total += f(x - 1, y);
        print_maze();
        total += f(x + 1, y);
        print_maze();
        total += f(x, y + 1);
        print_maze();
        total += f(x, y - 1);
        print_maze();
        maze[x][y] = ' ';
        return total;
    }

    return 0;
}

int main() {
    ifstream fIn("maze.in");

    char line[80];

    for (int x = 0; x < MazeHeight; x++) {
        fIn.getline(line, 100);
        for (int y = 0; y < MazeWidth; y++) {
            maze[x][y] = line[y];
        }
    }

    f(0, 0);

    return 0;
}