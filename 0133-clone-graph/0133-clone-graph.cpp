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
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        // create a clone node
        Node* clone = new Node(cur->val);
        mp[cur] = clone; // map original to clone
        
        // traverse neighbors
        for (auto it : cur->neighbors) {
            if (mp.find(it) != mp.end()) {
                clone->neighbors.push_back(mp[it]); // use exstng cpy
            } else {
                clone->neighbors.push_back(dfs(it, mp)); // recursive dfs
            }
        }
        
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        
        unordered_map<Node*, Node*> mp;// mp to visit the node
        
        return dfs(node, mp);
    }
};
