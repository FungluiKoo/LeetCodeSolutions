
class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()
        left_paren = set("([{")
        right_paren = dict(zip(")]}","([{"))
        for ch in s:
            if ch in left_paren:
                stack.append(ch)
            elif ch in right_paren:
                if len(stack)==0 or stack[-1]!=right_paren[ch]:
                    return False
                stack.pop()
        return len(stack)==0