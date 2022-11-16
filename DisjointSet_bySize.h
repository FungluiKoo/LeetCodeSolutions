class DisjointSet{
private:
    long *parent;
    long *size;
    long largest_size;
    long group_cnt;
public:
    DisjointSet(long n);
    ~DisjointSet();
    long getRoot(long idx);
    void unionBySize(long a, long b);
    long getMaxGroupSize()const{
        return this->largest_size;
    }
    long getGroupCnt()const{
        return this->group_cnt;
    }
};

DisjointSet::DisjointSet(long n){
    this->parent = new long[n];
    this->size = new long[n];
    for(long i=0; i<n; i++){
        this->parent[i]=i;
        this->size[i]=1;
    }
    this->largest_size = 1;
    this->group_cnt = n;
}

DisjointSet::~DisjointSet(){
    delete[] this->parent;
    delete[] this->size;
}

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

void DisjointSet::unionBySize(long a, long b){
    // union by size
    long root_a = this->getRoot(a);
    long root_b = this->getRoot(b);
    if(root_a == root_b){
        return;
    }
    long root_small = (this->size[root_a] < this->size[root_b]) ? root_a : root_b;
    long root_big = (this->size[root_a] < this->size[root_b]) ? root_b : root_a;
    this->parent[root_small] = root_big;
    this->size[root_big] += this->size[root_small];
    if(this->size[root_big] > this->largest_size){
        this->largest_size = this->size[root_big];
    }
    --(this->group_cnt);
}
