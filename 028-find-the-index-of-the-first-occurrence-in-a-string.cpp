#include <string>
#include <vector>

using namespace std;

class Solution {
    // KMP algorithm
public:
    int strStr(string haystack, string needle) {
        int k = -1, n = haystack.length(), p = needle.length();
        if (p == 0) return 0;
        vector<int> next(p, -1); // -1表示不存在相同的最大前缀和后缀
        for (int j = 1, h = -1; j < needle.length(); ++j) {
            while (h > -1 && needle[h+1] != needle[j]) {
                h = next[h]; // 如果下一位不同，往前回溯
            }
            if (needle[h+1] == needle[j]) {
                ++h; // 如果下一位相同，更新相同的最大前缀和最大后缀长
            }
            next[j] = h;
        }
        for (int i = 0; i < n; ++i) {
            while (k > -1 && needle[k+1] != haystack[i]) {
                k = next[k]; // 有部分匹配，往前回溯
            }
            if (needle[k+1] == haystack[i]) {
                ++k;
            }
            if (k == p-1) {
                return i - p + 1; // 说明k移动到needle的最末端，返回相应的位置
            }
        }
        return -1;
    }
};

class Solution2 {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};