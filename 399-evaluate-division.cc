#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, string> baseof;
        unordered_map<string, unordered_map<string,double>> valuein;
        for(auto i=0u; i<equations.size(); ++i){
            auto numer = equations[i][0];
            auto denom = equations[i][1];
            if(baseof.count(numer)==0){
                if(baseof.count(denom)==0){ // both are new
                    baseof[numer] = denom;
                    baseof[denom] = denom;
                    valuein[denom][numer] = values[i];
                    valuein[denom][denom] = 1.0;
                }else{ // numer new, denom known
                    auto base = baseof[denom];
                    baseof[numer] = base;
                    valuein[base][numer] = values[i] * valuein[base][denom];
                }
            }else{
                if(baseof.count(denom)==0){ // numer known, denom new
                    auto base = baseof[numer];
                    baseof[denom] = base;
                    valuein[base][denom] = valuein[base][numer] / values[i];
                }else{ // both known
                    auto b_numer = baseof[numer];
                    auto b_denom = baseof[denom];
                    if(b_numer!=b_denom){ // set union
                        string mainbase, subbase;
                        double ratio;
                        if(valuein[b_numer].size() <= valuein[b_denom].size()){
                            mainbase = b_denom;
                            subbase = b_numer;
                            ratio = values[i] * valuein[mainbase][denom] / valuein[subbase][numer];
                        }else{
                            mainbase = b_numer;
                            subbase = b_denom;
                            ratio = valuein[mainbase][numer] / (values[i] * valuein[subbase][denom]);
                        }
                        for(auto [k,v]: valuein[subbase]){
                            valuein[mainbase][k] = v * ratio;
                            baseof[k] = mainbase;
                        }
                        valuein.erase(subbase);
                    }
                }
            }
        }
        vector<double> ans;
        for(auto j=0u; j<queries.size(); ++j){
            auto numer = queries[j][0];
            auto denom = queries[j][1];
            if(baseof.count(numer)==0 || baseof.count(denom)==0 || baseof[numer]!=baseof[denom]){
                ans.push_back(-1.0);
            }else{
                auto base = baseof[numer];
                ans.push_back(valuein[base][numer] / valuein[base][denom]);
            }
        }
        return ans;
    }
};