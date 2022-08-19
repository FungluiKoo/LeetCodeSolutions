#include <vector>

using namespace std;

class DisjointSet{
private:
    long set_cnt;
    long *parent;
    long *rank;
    long getRoot(long idx);

public:
    DisjointSet(long size);
    ~DisjointSet();
    void unionByRank(long a, long b);
    bool isSameSet(long a, long b);
    long getSetCnt()const{
        return this->set_cnt;
    }
};

long DisjointSet::getRoot(long idx){
    long root = idx;
    while(this->parent[root] != root){
        root = this->parent[root];
    }
    // path compression
    while(this->parent[idx] != root){
        long temp = this->parent[idx];
        this->parent[idx] = root;
        idx = temp;
    }
    return root;
}

DisjointSet::DisjointSet(long n){
    this->set_cnt = n;
    this->parent = new long[n];
    this->rank = new long[n];
    for(long i=0; i<n; ++i){
        parent[i]=i;
        rank[i]=0;
    }
}

DisjointSet::~DisjointSet(){
    delete[] parent;
    delete[] rank;
}

void DisjointSet::unionByRank(long a, long b){
    long root_a = this->getRoot(a);
    long root_b = this->getRoot(b);
    if(root_a == root_b){
        return;
    }else if(this->rank[root_a] == this->rank[root_b]){
        this->rank[root_a]++;
        this->parent[root_b]=root_a;
    }else if(this->rank[root_a] > this->rank[root_b]){
        this->parent[root_b]=root_a;
    }else{
        this->parent[root_a]=root_b;
    }
    this->set_cnt--;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet dset(n);
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(isConnected[i][j]){dset.unionByRank(i,j);}
            }
        }
        return dset.getSetCnt();
    }
};