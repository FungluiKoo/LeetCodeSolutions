#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool pathexists(int c, int sx, int sy, int tx, int ty){
    vector<bool> isperfect(tx+ty+1, false);
    for(int i=0; i*i<=tx+ty+1; ++i){
        isperfect[i*i] = true;
    }
    if(sx>tx || sy>ty || isperfect[sx+sy] || isperfect[tx+ty]){return false;}
    if(sx==tx && sy==ty){return true;}
    vector<vector<bool>> visited(tx+1, vector<bool>(ty+1,false));
    queue<pair<int,int>> Q;
    Q.push({tx,ty});
    while(!Q.empty()){
        auto [x,y] = Q.front();
        Q.pop();
        auto px = (x>y?(x-y):x);
        auto py = (x>y?y:(y-x));
        if((px==sx && py==sy) || (x-c==sx && y-c==sy)){return true;}
        if(px>=sx && py>=sy && !isperfect[px+py] && !visited[px][py]){
            visited[px][py] = true;
            Q.push({px,py});
        }
        if(x-c>=sx && y-c>=sy && !isperfect[x+y-(c<<1)] && !visited[x-c][y-c]){
            visited[x-c][y-c] = true;
            Q.push({x-c,y-c});
        }
    }
    return false;
}

int main(){
    int c = 1, sx, sy, tx, ty;
    cin >> c;
    while(c>0){
        cin >> sx >> sy >> tx >> ty;
        cout << pathexists(c, sx, sy, tx, ty) << "\n";
        cin >> c;
    }
    return 0;
}