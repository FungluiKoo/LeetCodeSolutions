from typing import List

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        return [x for _,x in sorted([(bin(x).count('1'), x) for x in arr])]