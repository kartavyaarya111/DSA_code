//I tried to do the same with the help of set but it does not work keep in mind to use the map

// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// */

// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(node==NULL)  return NULL;
//         unordered_set<Node*> s;
//         Node* t = new Node(node->val);
//         s.insert(node);
//         // Node* ans = t;
//         queue<pair<Node*,Node*>> q;
//         q.push({node,t});
//         while(!q.empty()){
//             auto [z,nn]  = q.front();
//             q.pop();
//             for(auto &x:z->neighbors){
//                 if(s.find(x)==s.end()){
//                     s.insert(x);
//                     Node* tt = new Node(x->val);
//                     nn->neighbors.push_back(tt);
//                     q.push({x,tt});
//                 }
//             }
//         }
//         return t;
//     }
// };


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        // Use unordered_map to store the original node to its clone mapping
        unordered_map<Node*, Node*> clones;

        // Create the clone of the starting node
        Node* t = new Node(node->val);
        clones[node] = t;

        // Queue for BFS that holds pairs of original and cloned nodes
        queue<pair<Node*, Node*>> q;
        q.push({node, t});

        while (!q.empty()) {
            auto [z, nn] = q.front(); // z is the original node, nn is the clone
            q.pop();

            // Iterate over all the neighbors of the original node z
            for (auto& x : z->neighbors) {
                if (clones.find(x) == clones.end()) {
                    // Clone the neighbor if it hasn't been cloned yet
                    Node* tt = new Node(x->val);
                    clones[x] = tt;
                    q.push({x, tt});
                }
                // Add the cloned neighbor to the current clone's neighbors
                nn->neighbors.push_back(clones[x]);
            }
        }

        return t;
    }
};
