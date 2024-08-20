#include <bits/stdc++.h>
using namespace std;

#define int long long

// How to use:
// zero based indexing 

class Hash{
private:
    const int p1 = 31,p2 = 53;
    const int m1 = 1e9 + 7,m2 = 1e9 + 9;
    int n;
    vector<int> h1,h2,pof1,pof2;
    public:
    Hash(string &s){
        n = s.size();
        h1 = vector<int>(n + 1);
        h2 = vector<int>(n + 1);
        pof1 = vector<int>(n + 1);
        pof2 = vector<int>(n + 1);
        pof1[0] = pof2[0] = 1;
        for(int i = 1; i <= n; ++i) {
            pof1[i] = p1 * pof1[i - 1] % m1;
            pof2[i] = p2 * pof2[i - 1] % m2;
        }
        for(int i = 1; i <= n; ++i){
            h1[i] = (h1[i - 1] * p1) % m1 + (s[i - 1] - 'a');
            h1[i] %= m1;
            h2[i] = (h2[i - 1] * p2) % m2 + (s[i - 1] - 'a');
            h2[i] %= m2;
        }
    }
    pair<int,int> substr(int l,int len){
        int r = l + len - 1;
        assert(r < n);
        int f = h1[r + 1] - (h1[l] * pof1[len]) % m1;
        f %= m1;
        f += m1;
        f %= m1;
        int s = h2[r + 1] - (h2[l] * pof2[len]) % m2;
        s %= m2;
        s += m2;
        s %= m2;
        return {f,s};
    }
};

int main(){

}
