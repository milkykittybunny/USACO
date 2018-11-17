#include <iostream>
//C++ template for all USACO codes
#include <bits/stdc++.h>
using namespace std;

vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

bool decrease(int a, int b) {
    return a > b;
}

int findMin(int sum) {
    int coinsAmount = 0;
    for (int i = 0; i < coins.size(); i++) {
        while (sum >= coins[i]) {
            sum -= coins[i];
            coinsAmount++;
        }
    }
    return coinsAmount;
}



int main() {
    int sum = 93;
    sort(coins.begin(), coins.end(), decrease);
    cout << "Following is minimal number of coins for " << sum << " is ";
    cout << findMin(sum);
    return 0;
}
