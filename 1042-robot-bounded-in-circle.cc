#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions){
        int x = 0, y = 0, dir = 0;
        vector<pair<int, int>> dirs{{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(auto c : instructions){
            if(c == 'L'){
                dir = (dir + 1) % 4;
            }else if(c == 'R'){
                dir = (dir + 3) % 4;
            }else{
                x += dirs[dir].first;
                y += dirs[dir].second;
            }
        }
        return (x == 0 && y == 0) || dir != 0;
    }
};

class Solution0 {
private:
    class Robot{
    private:
        int x;
        int y;
        char dir;
    public:
        Robot(): x(0), y(0), dir('N') {}
        char getdir() {
            return dir;
        }
        void move(char c) {
            if (c == 'G') {
                switch (dir) {
                    case 'E': ++x; break;
                    case 'S': --y; break;
                    case 'W': --x; break;
                    case 'N': ++y; break;
                }
            } else if (c == 'L') {
                switch (dir) {
                    case 'E': dir = 'N'; break;
                    case 'N': dir = 'W'; break;
                    case 'W': dir = 'S'; break;
                    case 'S': dir = 'E'; break;
                }
            } else if (c == 'R') {
                switch (dir) {
                    case 'E': dir = 'S'; break;
                    case 'S': dir = 'W'; break;
                    case 'W': dir = 'N'; break;
                    case 'N': dir = 'E'; break;
                }
            }
        }
        bool operator==(const Robot const& other) const {
            return x == other.x && y == other.y;
        }
    };
public:
    bool isRobotBounded(string instructions) {
        Robot robot;
        for (auto c : instructions) {
            robot.move(c);
        }
        return robot == Robot() || robot.getdir() != 'N';
    }
};