#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<int> getsfx(const string &s) {
    int n = s.size(), lim=max(256,n+1);
    vector<int> sfx(n), g(n+1), ng(n+1), idx(n+1), cnt;
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]]=i;

        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[idx[i]]]]=idx[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };

        ng[sfx[0]]=1; ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g=ng;
    }
    return sfx;
}
vector<int> getlcp(const string &s, const vector<int> &sfx) {
    int n = s.size();
    vector<int> lcp(n), rev(n);
    for(int i=0; i<n; i++) rev[sfx[i]]=i;
    for(int i=0,c=0; i<n; i++) {
        if(rev[i]==0) { lcp[rev[i]]=0; continue; }
        while(s[i+c]==s[sfx[rev[i]-1]+c]) c++;
        lcp[rev[i]]=c;
        c=max(c-1,0);
    }
    return lcp;
}
int main() {
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    printf("sfx: ");
    for(auto &p : sfx) printf("%d ", p);
    puts("");

    vector<int> lcp = getlcp(s, sfx);
    printf("lcp: ");
    for(auto &p : lcp) printf("%d ", p);
    puts("");

    return 0;
}
