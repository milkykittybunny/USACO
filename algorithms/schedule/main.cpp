#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;      // Job Id
    int deadline;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};

vector<Job> arr = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};

bool sorter(Job a, Job b) {
    return a.profit > b.profit;
}

int schedule() {
    set<int> timeSlots;
    for (int i = 0; i < arr.size(); i++) {
        for (int t = arr[i].deadline; t > 0; t--) {
            if (timeSlots.find(t) == timeSlots.end()) {
                timeSlots.insert(t);
                cout << "Job " << arr[i].id << " is scheduled at " << t << "." << endl;
                break;
            }
        }
    }
    return timeSlots.size();
}

int main() {
    sort(arr.begin(), arr.end(), sorter);
    cout << schedule();
}