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
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> visited;
        queue<Node*> q;

        // Create a copy of the starting node and add it to visited
        visited[node] = new Node(node->val);

        q.push(node);

        while (!q.empty()) {
            Node* currNode = q.front();
            q.pop();

            // Loop through the current node's neighbors
            for (Node* neighbor : currNode->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                visited[currNode]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};