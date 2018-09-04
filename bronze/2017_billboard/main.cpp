#include <iostream>
#include <fstream>

using namespace std;

struct point {
    int x;
    int y;
};

int overlapping(point &a1, point &a2, point &b1, point &b2){
    int x1 = max(a1.x, b1.x);
    int x2 = min(a2.x, b2.x);
    int y1 = max(a1.y, b1.y);
    int y2 = min(a2.y, b2.y);
    return (x2 - x1) * (y2 - y1);
}

bool in(point &b1L, point &b1H, point &t1L, point &t1H) {
    if (t1H.x <= b1H.x && t1H.x >= b1L.x && t1H.y <= b1H.y && t1H.y >= b1L.y) {
        return true;
    }
    if (t1L.x <= b1H.x && t1L.x >= b1L.x && t1L.y <= b1H.y && t1L.y >= b1L.y) {
        return true;
    }
    if (t1L.x <= b1H.x && t1L.x >= b1L.x && t1H.y <= b1H.y && t1H.y >= b1L.y) {
        return true;
    }
    if (t1H.x <= b1H.x && t1H.x >= b1L.x && t1L.y <= b1H.y && t1L.y >= b1L.y) {
        return true;
    }
    return false;
}


bool half(point &b1L, point &b1H, point &t1L, point &t1H) {
    if (t1L.x <= b1H.x && t1L.x >= b1L.x || t1H.x <= b1H.x && t1H.x >= b1L.x) {
        return true;
    }
    if (t1L.y <= b1H.y && t1L.y >= b1L.y || t1H.y <= b1H.y && t1H.y >= b1L.y) {
        return true;
    }
    return false;
}


int main() {
    point b1L, b1H, b2L, b2H, t1L, t1H;
    ifstream fIn("billboard.in");
    fIn >> b1L.x >> b1L.y >> b1H.x >> b1H.y;
    fIn >> b2L.x >> b2L.y >> b2H.x >> b2H.y;
    fIn >> t1L.x >> t1L.y >> t1H.x >> t1H.y;
    ofstream fOut("billboard.out");
    if (in(b1L, b1H, t1L, t1H) == true && in(b2L, b2H, t1L, t1H) == true) {
        fOut << ((b1H.x - b1L.x) * (b1H.y - b1L.y) + (b2H.x - b2L.x) * (b2H.y - b2L.y))
                - (overlapping(b1L, b1H, t1L, t1H) + overlapping(b2L, b2H, t1L, t1H));
    }
    else if (in(b1L, b1H, t1L, t1H) == true && in(b2L, b2H, t1L, t1H) == false) {
        fOut << ((b1H.x - b1L.x) * (b1H.y - b1L.y) - overlapping(b1L, b1H, t1L, t1H)
        + ((b2H.x - b2L.x) * (b2H.y - b2L.y) - overlapping(b2L, b2H, t1L, t1H))) + 1;
    }
    else if (in(b1L, b1H, t1L, t1H) == false && in(b2L, b2H, t1L, t1H) == true) {
        fOut << ((b2H.x - b2L.x) * (b2H.y - b2L.y) - overlapping(b2L, b2H, t1L, t1H)
                 + ((b1H.x - b1L.x) * (b1H.y - b1L.y) - overlapping(b1L, b1H, t1L, t1H)));
    }
    else if (in(t1L, t1H, b1L, b1H) == true && in(t1L, t1H, b2L, b2H) == false) {
        fOut << (b1H.x - b1L.x) * (b1H.y - b1L.y);
    }
    else if (half(b1L, b1H, t1L, t1H) == true && half(b2L, b2H, t1L, t1H) == true) {
        fOut << ((b1H.x - b1L.x) * (b1H.y - b1L.y) + (b2H.x - b2L.x) * (b2H.y - b2L.y))
                - (overlapping(b1L, b1H, t1L, t1H) + overlapping(b2L, b2H, t1L, t1H));
    }
    else if (in(t1L, t1H, b1L, b1H) == false && in(t1L, t1H, b2L, b2H) == true) {
        fOut << (b2H.x - b2L.x) * (b2H.y - b2L.y);
    }
    else if (in(t1L, t1H, b1L, b1H) == true && in(t1L, t1H, b2L, b2H) == true) {
        fOut << 0;
    }
    else {
        fOut << (b1H.x - b1L.x) * (b1H.y - b1L.y) + (b2H.x - b2L.x) * (b2H.y - b2L.y);
    }
    fIn.close();
    fOut.close();
};




/*
 *
 * SOLUTION 2: simulation
using namespace std;

struct point {
    int x;
    int y;
};

inline int point_inside_truck(int &px, int &py, point &tL, point &tH) {
    if (px < tH.x && px >= tL.x && py < tH.y && py >= tL.y) {
        return 0;
    }
    return 1;
}

int main() {
    point b1L, b1H, b2L, b2H, t1L, t1H;
    ifstream fIn("billboard.in");
    fIn >> b1L.x >> b1L.y >> b1H.x >> b1H.y;
    fIn >> b2L.x >> b2L.y >> b2H.x >> b2H.y;
    fIn >> t1L.x >> t1L.y >> t1H.x >> t1H.y;
    int total = 0;
    for (int x = b1L.x; x < b1H.x; x++) {
        for (int y = b1L.y; y < b1H.y; y++) {
            total += point_inside_truck(x, y, t1L, t1H);
        }
    }

    for (int x = b2L.x; x < b2H.x; x++) {
        for (int y = b2L.y; y < b2H.y; y++) {
            total += point_inside_truck(x, y, t1L, t1H);
        }
    }

    ofstream fOut("billboard.out");
    fOut << total;
    fIn.close();
    fOut.close();
    return 0;
}
 */