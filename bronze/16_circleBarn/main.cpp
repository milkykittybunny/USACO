#include <iostream>
#include <fstream>
#include <vector>
#include <valarray>

using namespace std;

int cows_passed(vector<int> rooms, int amountOfRooms) {
    int total = 0;
    int current = 1;
    while (current != (amountOfRooms)){
        total += current * rooms[current - 1];
        current++;
    }
    return total;
}

int main() {
    ifstream fIn("cbarn.in");
    int amountOfRooms;
    fIn >> amountOfRooms;
    vector<int> rooms(amountOfRooms*2);
    for (int i = 0; i < amountOfRooms; i++) {
        fIn >> rooms[i];
        rooms[i+amountOfRooms] = rooms[i];
    }
    vector<int> distances(amountOfRooms);
    int total = 10000000000000;
    for (int i = 0; i < amountOfRooms; i++) {
        int ctotal = 0;
        unsigned int size = i + 1;
        vector<int> subVec(rooms.begin() + size, rooms.end());
        ctotal += cows_passed(subVec, amountOfRooms);
        if (ctotal < total) {
            total = ctotal;
        }
    }
    ofstream fOut("cbarn.out");
    fOut << total;
}