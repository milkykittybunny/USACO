#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

struct coordinates {
    int x;
    int y;
};

int check_vertex(coordinates &vertex, coordinates f[2]) {
    if ((vertex.x <= f[1].x && vertex.x >= f[0].x) && (vertex.y >= f[0].y && vertex.y <= f[1].y)){
        return 1;
    }
    else {
        return 0;
    }
}

// takes mowerboard (g)'s area and subtracts the overlapping area to get the returned value
// common area four point cut remainder
int total(coordinates &f1, coordinates &f2, coordinates &g1, coordinates &g2) {
    int Lx = max(f1.x, g1.x);
    int Ly = max(f1.y, g1.y);

    int Rx = min(f2.x, g2.x);
    int Ry = min(f2.y, g2.y);
    return ((g2.x - g1.x)*(g2.y - g1.y)) - ((Rx-Lx)*(Ry-Ly));
}

int vertexes_being_covered(coordinates f[2], coordinates g[2]) {
    int dotamount = 0;
    coordinates g3, g4;
    g3.x = g[0].x;
    g3.y = g[1].y;
    g4.x = g[1].x;
    g4.y = g[0].y;
    dotamount += check_vertex(g[0], f);
    dotamount += check_vertex(g[1], f);
    dotamount += check_vertex(g3, f);
    dotamount += check_vertex(g4, f);
    return dotamount;
}

int main() {

    ifstream fIn;
    fIn.open("billboard.in");

    coordinates g[2], f[2];

    fIn >> g[0].x >> g[0].y;
    fIn >> g[1].x >> g[1].y;

    fIn >> f[0].x >> f[0].y;
    fIn >> f[1].x >> f[1].y;

    ofstream fOut;
    fOut.open("billboard.out");


    int dotamount = vertexes_being_covered(f, g);
    if (dotamount < 2) {
        fOut << (g[1].x - g[0].x) * (g[1].y - g[0].y);
    }
    else if (dotamount == 2) {
        fOut << total(f[0], f[1], g[0], g[1]);
    }
    else {
        fOut << 0;
    }
    fIn.close();
    fOut.close();
    return 0;
}