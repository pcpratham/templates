#include<bits/stdc++.h>

using namespace std;
//union by rank 
class DisjointSet{

    vector<int> rank,size,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<parent.size();i++){
                parent[i] = i;
            }
        }

        int findParent(int u){
            if(u==parent[u]){
                return u;
            }

            return parent[u] = findParent(parent[u]);
        }

        void unionByRank(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v){
                return;
            }
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v){
                return;
            }
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    return 0;
}