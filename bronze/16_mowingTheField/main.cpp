#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT 10000000

struct pixel {
    int x;
    int y;
    int t;
};

void move(vector<int> &xvect, int &t, char direction, int amount, vector<pixel> &pixels, int &x, int &y) {
    for (int i = 0; i < amount; i++) {
        if (direction == 'N') {
            y++;
            t++;
            pixel temp = {x, y, t};
            // is in
            for (int j = 0; j < pixels.size(); j++) {
                if (pixels[j].x == temp.x && pixels[j].y == temp.y) {
                    xvect.push_back(temp.t - pixels[j].t);
                }
            }
            pixels.push_back(temp);

        }
        if (direction == 'S') {
            y--;
            t++;
            pixel temp = {x, y, t};
            // is in
            for (int j = 0; j < pixels.size(); j++) {
                if (pixels[j].x == temp.x && pixels[j].y == temp.y) {
                    xvect.push_back(temp.t - pixels[j].t);
                }
            }
            pixels.push_back(temp);
        }
        if (direction == 'E') {
            x++;
            t++;
            pixel temp = {x, y, t};
            // is in
            for (int j = 0; j < pixels.size(); j++) {
                if (pixels[j].x == temp.x && pixels[j].y == temp.y) {
                    xvect.push_back(temp.t - pixels[j].t);
                }
            }
            pixels.push_back(temp);
        }
        if (direction == 'W') {
            x--;
            t++;
            pixel temp = {x, y, t};
            // is in
            for (int j = 0; j < pixels.size(); j++) {
                if (pixels[j].x == temp.x && pixels[j].y == temp.y) {
                    xvect.push_back(temp.t - pixels[j].t);
                }
            }
            pixels.push_back(temp);
        }
    }
}

int main() {
    int n;
    ifstream fIn("mowing.in");
    fIn >> n;
    vector<pixel> pixels;
    int t = 0;
    vector<int> xvect;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        char direction;
        int amount;
        fIn >> direction >> amount;
        move(xvect, t, direction, amount, pixels, x, y);
    }
    int returned = MAX_INT;
    for (int i = 0; i < xvect.size(); i++) {
        if (xvect[i] < returned) {
            returned = xvect[i];
         }
    }
    if (returned == MAX_INT) {
        returned = -1;
    }
    ofstream fOut("mowing.out");
    fOut << returned;
}