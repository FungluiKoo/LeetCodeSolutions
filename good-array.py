class Solution(object):
    def countSubsequence(self, N: int, queries: list) -> int: 
        goodArray = list()
        x = 2
        while x <= N:
            remainder = N%x
            if remainder:
                goodArray.append(remainder)
                N -= remainder
            x <<= 1
        results = list()
        for query in queries:
            l = query[0]
            r = query[1]
            m = query[2]
            result = 1
            for i in range(l-1,r):
                result = ((goodArray[i]%m) * result)%m
            results.append(result)
        return results