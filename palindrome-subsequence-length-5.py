class Solution(object):
    def countSubsequence(self, string:str) -> int: 
        n = len(string)
        if n<5:
            return 0
        # right part
        right0 = [0]*n # # of 0s on the right of i, not including itself
        right1 = [0]*n
        for i in range(n-2,-1,-1):
            if string[i+1]=='0':
                right0[i] = right0[i+1] + 1
                right1[i] = right1[i+1]
            else:
                right0[i] = right0[i+1]
                right1[i] = right1[i+1] + 1
        right00 = [0]*n
        right01 = [0]*n
        right10 = [0]*n
        right11 = [0]*n
        for i in range(n-3,-1,-1):
            if string[i+1]=='0':
                right00[i] = right00[i+1] + right0[i+1]
                right01[i] = right01[i+1] + right1[i+1]
                right10[i] = right10[i+1]
                right11[i] = right11[i+1]
            else:
                right00[i] = right00[i+1]
                right01[i] = right01[i+1]
                right10[i] = right10[i+1] + right0[i+1]
                right11[i] = right11[i+1] + right1[i+1]
        # left part
        left0 = [n]*0
        left1 = [n]*0
        for i in range(1,n):
            if string[i-1]=='0':
                left0[i] = left0[i-1] + 1
                left1[i] = left1[i-1]
            else:
                left0[i] = left0[i-1]
                left1[i] = left1[i-1] + 1      
        left00 = [0]*n
        left01 = [0]*n
        left10 = [0]*n
        left11 = [0]*n
        for i in range(2,n):
            if string[i-1]=='0':
                left00[i] = left00[i-1] + left0[i-1]
                left01[i] = left01[i-1]
                left10[i] = left10[i-1] + left1[i-1]
                left11[i] = left11[i-1]
            else:
                left00[i] = left00[i-1]
                left01[i] = left01[i-1] + left0[i-1]
                left10[i] = left10[i-1]
                left11[i] = left11[i-1] + left1[i-1]
        # calculating result
        result = 0
        for i in range(2,n-2):
            result += (left00[i]*right00[i] + left01[i]*right10[i] + \
                       left10[i]*right01[i] + left11[i]*right11[i])
        return result