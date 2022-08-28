#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    string endWord;
    unordered_map<string,vector<string>> children;
    unordered_set<string> unvisited;
    vector<vector<string>> solutions;
    vector<string> path;
public:
    void helper(string currWord){
        if(currWord==endWord){
            solutions.push_back(path);
            return;
        }
        for(const auto &child:children[currWord]){
            path.push_back(child);
            helper(child);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->endWord = endWord;
        for(auto &word:wordList){
            children[word] = {};
            unvisited.insert(word);
        }
        if(!children.count(endWord)){return {};}
        unvisited.erase(beginWord);
        unvisited.erase(endWord);
        
        unordered_set<string> q1{beginWord}, q2{endWord};
        bool q1_left = true;
        bool found = false;
        while(!q1.empty() && !found){
            unordered_set<string> qt;
            for(const auto &w:q1){
                string word = w;
                for(int i=0; i<w.length(); ++i){
                    for(auto ch = 'a'; ch<='z'; ++ch){
                        if(ch==w[i]){continue;}
                        word[i] = ch;
                        if(q2.count(word)){
                            found = true;
                            if(q1_left){
                                children[w].push_back(word);
                            }else{
                                children[word].push_back(w);
                            }
                        }else if(unvisited.count(word)){
                            qt.insert(word);
                            if(q1_left){
                                children[w].push_back(word);
                            }else{
                                children[word].push_back(w);
                            }
                        }
                    }
                    word[i] = w[i];
                }
            }
            for(const auto &w:qt){
                unvisited.erase(w);
            }
            if(qt.size()>=q2.size()){
                q1 = qt;
            }else{
                q1 = q2;
                q2 = qt;
                q1_left = !q1_left;
            }
        }
        // backtrack to create solutions
        if(found){
            this->path.push_back(beginWord);
            helper(beginWord);
        }
        return solutions;
    }
};

// Incorrect answer:
class Solution2 {
private:
    unordered_map<string,string> parent;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto &word:wordList){
            parent[word] = "";
        }
        if(!parent.count(endWord)){return {};}
        parent.erase(beginWord);
        parent.erase(endWord);
        // Specaial case
        // int cnt=0;
        // for(int i=0; i<beginWord.length() && cnt<=1; ++i){
        //     if(beginWord[i]!=endWord[i]){++cnt;}
        // }
        // if(cnt<=1){return {{endWord}};}
        
        // Normal case
        unordered_set<string> q1{beginWord}, q2{endWord};
        bool q1_left = true; 
        int found = 0;
        vector<string> leaf_1, leaf_2;
        while(!q1.empty() && !found){
            unordered_set<string> qt;
            for(const auto &w:q1){
                string word = w;
                for(int i=0; i<w.length(); ++i){
                    for(auto ch = 'a'; ch<='z'; ++ch){
                        if(ch==w[i]){continue;}
                        word[i] = ch;
                        if(q2.count(word)){
                            ++found;
                            if(q1_left){
                                leaf_1.push_back(w);
                                leaf_2.push_back(word);
                            }else{
                                leaf_1.push_back(word);
                                leaf_2.push_back(w);
                            }
                        }else if(parent.count(word) && parent[word]==""){
                            parent[word] = w;
                            qt.insert(word);
                        }
                    }
                    word[i] = w[i];
                }
            }
            if(qt.size()>=q2.size()){
                q1 = qt;
            }else{
                q1 = q2;
                q2 = qt;
                q1_left = !q1_left;
            }
        }
        vector<vector<string>> solution(found);
        for(int i=0; i<found; ++i){
            //left part
            stack<string> S;
            string word = leaf_1[i];
            do{
                S.push(word);
                word = parent[word];
            } while(word!="");
            while(!S.empty()){
                solution[i].push_back(S.top());
                S.pop();
            }
            // right part
            word = leaf_2[i];
            do{
                solution[i].push_back(word);
                word = parent[word];
            }while(word!="");
        }
        return solution;
    }
};