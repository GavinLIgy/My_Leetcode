/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        unordered_set<string> visited;
        int ans = 1;
        queue<string> q;
        q.push(beginWord);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                string node = q.front();
                q.pop();

                if(node == endWord) return ans;

                for(int j=0; j<node.length(); j++){
                    char inStr = node[j];
                    for(char c ='a'; c<='z'; c++){
                        if(c == inStr) continue;
                        node[j]=c;
                        if((st.find(node) != st.end()) &&
                         (visited.find(node) == visited.end())){
                            q.push(node);
                            visited.insert(node);
                        }
                    }
                    node[j]=inStr;
                }
            }
            ans++;
        }

        return 0;
    }
};
// @lc code=end

