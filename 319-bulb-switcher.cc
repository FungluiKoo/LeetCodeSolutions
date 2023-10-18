class Solution {
public:
    int bulbSwitch(int n) {
        int result = 1;
        while (result * result <= n) {
            result++;
        }
        return result - 1;
    }
};