#include <bits/stdc++.h>

using namespace std;

int buy_all(vector<int> &street, int current) {
    int transactions = 0;
    for (int pointer = 0; pointer < street.size(); pointer++) {
        int nextNeighbor = pointer + 1;
        while (street[pointer] > 0) {
            //find the next negative neighbour
            while (street[nextNeighbor] >= 0) {
                nextNeighbor++;
            }
            //exchange
            if (abs(street[nextNeighbor]) < street[pointer]) {
                street[pointer] -= abs(street[nextNeighbor]);
                transactions += (nextNeighbor - pointer) * abs(street[nextNeighbor]);
                street[nextNeighbor] = 0;
            }
            else {
                street[nextNeighbor] += street[pointer];
                transactions += (nextNeighbor - pointer) * abs(street[pointer]);
                street[pointer] = 0;
            }
            //go on
        }
        while (street[pointer] < 0) {
            while (street[nextNeighbor] <= 0) {
                nextNeighbor++;
            }
            if (abs(street[pointer]) < street[nextNeighbor]) {
                street[nextNeighbor] -= abs(street[pointer]);
                transactions += (nextNeighbor - pointer) * abs(street[pointer]);
                street[pointer] = 0;
            }
            else {
                street[pointer] += street[nextNeighbor];
                transactions += (nextNeighbor - pointer) * abs(street[nextNeighbor]);
                street[nextNeighbor] = 0;
            }
        }
    }
    return transactions;
}


int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0) {
            return 0;
        }
        vector<int> street(n);
        for (int i = 0; i < n; i++) {
            cin >> street[i];
        }
        cout << buy_all(street, 0) << endl;
    }
}