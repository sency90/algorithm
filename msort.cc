#include <vector>
#include <iostream>
using namespace std;
vector<int> v;
void merge(vector<int>& v, vector<int>& l, vector<int>& r) {
    v.clear();
    int i=0,j=0;
    while(i<l.size() && j<r.size()) {
        if(l[i]<r[j]) v.push_back(l[i++]);
        else v.push_back(r[j++]);
    }
    while(i<l.size()) v.push_back(l[i++]);
    while(j<r.size()) v.push_back(r[j++]);
}
void msort(vector<int>& v) {
    if(v.size()<=1) return;
    vector<int> l(v.begin(), v.begin()+v.size()/2);
    vector<int> r(v.begin()+v.size()/2, v.end());
    msort(l); msort(r);
    merge(v,l,r);
}
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    msort(v);
    for(auto &p : v) {
        cout << p << " ";
    }
    return 0;
}
