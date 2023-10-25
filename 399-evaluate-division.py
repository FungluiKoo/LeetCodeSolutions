from collections import defaultdict
from typing import Dict, List

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        baseof: Dict[str, str] = dict()
        valuein: defaultdict[str, Dict[str, float]] = defaultdict(dict)
        for (numer, denom), v in zip(equations, values):
            if numer not in baseof:
                if denom not in baseof: # both are new
                    baseof[numer] = baseof[denom] = denom
                    valuein[denom][numer] = v
                    valuein[denom][denom] = 1.0
                else: # numer new, denom known
                    base = baseof[denom]
                    baseof[numer] = base
                    valuein[base][numer] = valuein[base][denom] * v
            else:
                if denom not in baseof: # numer known, denom new
                    base = baseof[numer]
                    baseof[denom] = base
                    valuein[base][denom] = valuein[base][numer] / v
                else: # both known
                    b_numer, b_denom = baseof[numer], baseof[denom]
                    if b_numer != b_denom: # set union
                        mainb, subb = str(), str()
                        ratio = float()
                        if len(valuein[b_numer]) <= len(valuein[b_denom]):
                            mainb, subb = b_denom, b_numer
                            ratio = valuein[mainb][denom] * v / valuein[subb][numer]
                        else:
                            mainb, subb = b_numer, b_denom
                            ratio = valuein[mainb][numer] / (v * valuein[subb][denom])
                        for k,val in valuein[subb].items():
                            valuein[mainb][k] = val * ratio
                            baseof[k] = mainb
                        valuein.pop(subb)
                    else: # check contradiction
                        if valuein[b_numer][numer] / valuein[b_numer][denom] != v:
                            return list()
        ans: List[float] = list()
        for numer, denom in queries:
            if (numer not in baseof) or (denom not in baseof) or (baseof[numer] != baseof[denom]):
                ans.append(-1.0)
            else:
                base = baseof[numer]
                ans.append(valuein[base][numer] / valuein[base][denom])
        return ans