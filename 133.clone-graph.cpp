/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }

private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        if (map.find(node) != map.end()){
            return map[node];
        }

        Node* clone = new Node(node->val);
        map[node] = clone;

        for (Node* neighbor : node->neighbors){
            clone->neighbors.push_back(dfs(neighbor, map));
        }

        return clone;
    }
};
// @lc code=end

