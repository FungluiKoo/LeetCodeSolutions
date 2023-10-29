class Solution:
    def minFlips(self, target: str) -> int:
        prev = '0'
        res = 0
        for ch in target:
            if ch != prev:
                res += 1
                prev = ch
        return res