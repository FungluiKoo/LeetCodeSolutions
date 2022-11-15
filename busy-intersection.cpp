#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> getResult(vector<int> &arrival, vector<int> &street){
    int n = arrival.size();
    queue<pair<int,int>> mainst, firstave;
    for(int i=0; i<n; ++i){
        if(street[i]){
            firstave.push({arrival[i],i});
        }else{
            mainst.push({arrival[i],i});
        }
    }
    vector<int> result(n);
    int t = 0;
    while(!mainst.empty() && !firstave.empty()){
        auto curr = (firstave.front().first<=mainst.front().first) ? &firstave : &mainst;
        t = max(curr->front().first, t);
        while(!curr->empty() && curr->front().first<=t){
            result[curr->front().second] = t;
            curr->pop();
            ++t;
        }
    }
    auto rem = mainst.empty() ? &firstave : &mainst;
    while(!rem->empty()){
        t = max(rem->front().first, t);
        result[rem->front().second] = t;
        rem->pop();
        ++t;
    }
    return result;
}

vector<int> getResult2(vector<int> &arrival, vector<int> &street){
    int n = arrival.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mainst, firstave;
    for(int i=0; i<n; ++i){
        if(street[i]){
            firstave.push({arrival[i],i});
        }else{
            mainst.push({arrival[i],i});
        }
    }
    vector<int> result(n);
    int t = 0;
    while(!mainst.empty() && !firstave.empty()){
        auto curr = (firstave.top().first<=mainst.top().first) ? &firstave : &mainst;
        t = max(curr->top().first, t);
        while(!curr->empty() && curr->top().first<=t){
            result[curr->top().second] = t;
            curr->pop();
            ++t;
        }
    }
    auto rem = mainst.empty() ? &firstave : &mainst;
    while(!rem->empty()){
        t = max(rem->top().first, t);
        result[rem->top().second] = t;
        rem->pop();
        ++t;
    }
    return result;
}

int main(){
    int n = 0;
    cin >> n;
    while(n>0){
        vector<int> arrival(n);
        vector<int> street(n);
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            arrival[i] = x;
        }
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            street[i] = x;
        }
        auto result = getResult(arrival, street);
        for(auto x : result){
            cout << x << " ";
        }
        cout << "\n\n";
        cin >> n;
    }
    return 0;
}