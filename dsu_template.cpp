#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> par(N);
vector<int> size(N);

void make_set(int v){
    par[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v==par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b){
        if(size[a] < size[b]) swap(a,b);
        par[b] = a;
        size[a] += size[b];
    }
}

int main(){
    for(int i=0;i<N;i++) make_set(i);

    int n,m; cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        edges.push_back({u,v});
    }
    bool cycle = false;
    for(auto &it : edges){
        int u = it[0];
        int v = it[1];
        int x = find_set(u);    
        int y = find_set(v);    
        
        if(x==y) cycle = true;
        else union_set(u,v);
    }
    
    if(cycle) cout << "Cycle yes\n";
    else cout << "NO cycle\n";
}       