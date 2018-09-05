/*
git commands to upload code to github after finishing a new question

cd USACO

git add .
git commit -m "added a new solution!"
git push -u origin master

*/

//use this standard C++ template for all codes

#include <bits/stdc++.h>
using namespace std;

int main() {
  // solution comes here

}


//STL examples
//vector
vector<int> v;
v.push_back(3); // [3]
v.push_back(2); // [3,2]

//set
set<int> s;
set<int> s{2,5,6,8};
s.insert(3);
s.insert(2);
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

if (m.count("aybabtu")) {
   // key exists
}

//map iterate
for (auto x : m) {
  cout << x.first << " " << x.second << "\n";
}

//sort vector , list
sort(v.begin(), v.end());

//reverse
reverse(v.begin(), v.end());

//random shuffle
random_shuffle(v.begin(), v.end());
