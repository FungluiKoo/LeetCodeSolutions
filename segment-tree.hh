// Usage Sample 
//
// struct mymax{
//     int operator()(int a, int b) const{
//         return max(a,b);
//     }
// };
//
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums, int k) {
//         segment_tree<int, mymax> st(nums);
//         return st.query(2,4);
//     }
// };


#ifndef SEGMENT_TREE
#define SEGMENT_TREE

#include <vector>

template<typename T, typename Oper>
class segment_tree{
private:
    std::vector<T> tree;
    Oper op;
    size_t N;
    void build(const std::vector<T> &arr, size_t v, size_t tl, size_t tr){
        if(tl==tr){
            tree[v] = arr[tl];
        }else{
            size_t tm = (tl+tr)>>1;
            build(arr, v+1, tl, tm);
            build(arr, v+2*(tm-tl+1), tm+1, tr);
            tree[v] = op(tree[v+1], tree[v+2*(tm-tl+1)]);
        }
    }
    void build(T val, size_t v, size_t tl, size_t tr){
        if(tl==tr){
            tree[v] = val;
        }else{
            size_t tm = (tl+tr)>>1;
            build(val, v+1, tl, tm);
            build(val, v+2*(tm-tl+1), tm+1, tr);
            tree[v] = op(tree[v+1], tree[v+2*(tm-tl+1)]);
        }
    }
    void update_helper(size_t v, size_t tl, size_t tr, size_t pos, T newval){
        if(tl==tr){
            tree[v] = newval;
        }else{
            size_t tm = (tl+tr)>>1;
            if(pos<=tm){
                update_helper(v+1, tl, tm, pos, newval);
            }else{
                update_helper(v+2*(tm-tl+1), tm+1, tr, pos, newval);
            }
            tree[v] = op(tree[v+1], tree[v+2*(tm-tl+1)]);
        }
    }
    T query_helper(size_t v, size_t tl, size_t tr, size_t l, size_t r)const{
        if(l>r){return T();}
        if(l==tl && r==tr){return tree[v];}
        size_t tm = (tl+tr)>>1;
        return op(query_helper(v+1, tl, tm, l, std::min(r,tm)),\
                  query_helper(v+2*(tm-tl+1), tm+1, tr, std::max(l,tm+1), r));
    }
public:
    segment_tree(size_t size, T val = T()){
        N = size;
        tree.resize(2*N-1);
        build(val, 0, 0, N-1);
    }
    segment_tree(const std::vector<T> &arr){
        N = arr.size();
        tree.resize(2*N-1);
        build(arr, 0, 0, N-1);
    }
    void update(size_t pos, T newval){
        update_helper(0, 0, N-1, pos, newval);
    }
    T query(size_t l, size_t r)const{
        return query_helper(0, 0, N-1, l, r);
    }
};

#endif // SEGMENT_TREE