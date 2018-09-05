/*
git commands to upload code to github after finishing a new question

cd USACO

git add .
git commit -m "added a new solution!"
git push -u origin master

*/

//C++ template for all USACO codes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fIn(".in");
    ofstream fOut(".out");

    // solution comes here
    int n;
    fIn >> n;



    fIn.close();
    fOut.close();
}


//STL examples
//vector
vector<int> v;
v.push_back(3); // [3]
v.push_back(2); // [3,2]
cout << v.size();
vector<int> v.resize(10);

vector<int> myvector;

for (int i = 1; i <= 3; i++) {
    myvector.push_back(i);
}

//vector iteration
for (auto it = myvector.begin(); it != myvector.end(); it++) {
    cout << *it;
}
cout << endl;
// vector reverse iteration
for (auto it = myvector.rbegin(); it != myvector.rend(); it++) {
    cout << *it;
}
cout << endl;

// vector insertion
myvector.insert(myvector.begin() + 2, 4);
for (auto it = myvector.begin(); it != myvector.end(); it++) {
    cout << *it;
}
cout << endl;
myvector.erase(myvector.begin() + 2);
for (auto it = myvector.begin(); it != myvector.end(); it++) {
            cout << *it;
}
cout << endl;

// vector search find
auto it = find(myvector.begin(), myvector.end(), 2);
cout << it - myvector.begin();




//set
set<int> s;
// set initialize
set<int> s{2,5,6,8};
// set insert
s.insert(3);
s.insert(2);
// set erase, find size
s.erase(3);
s.size()

//set iterate
for (auto it = s.begin(); it != s.end(); it++) {
  cout << *it << "\n";
}

//set search
auto it = s.find(x);
if (it == s.end()) {
// x is not found
}

//set find the largest/maximum member
if(!s.empty())
    cout << *s.rbegin(); //pay attention to the "*"
else
    //the set is empty




//std::map<key, value> map;
map<string,int> m;
m["monkey"] = 4;
m["banana"] = 3;
m["harpsichord"] = 9;

// map search for keys
if (m.count("aybabtu") == 0) {
   // key does not exist
}
else {
  // key exists
  m["aybabtu"] = 43770;
}

//map iterate
for (auto x : m) {
  cout << x.first << " " << x.second << "\n";
}

//sort vector , list
sort(v.begin(), v.end());

//reverse sort
reverse(v.begin(), v.end());

//random shuffle
random_shuffle(v.begin(), v.end());
