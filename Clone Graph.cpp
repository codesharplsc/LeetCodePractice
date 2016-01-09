/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode* newGraph;
        
        vector<UndirectedGraphNode* > Myqueue;
        
        map<UndirectedGraphNode*, int> IsVisited;
        map<UndirectedGraphNode*, UndirectedGraphNode*> NewNode;
     
        UndirectedGraphNode *Element;
        UndirectedGraphNode *NewElement;
        
        Myqueue.push_back(node);
        
        if (node == NULL)
            return NULL;
            
        newGraph = new UndirectedGraphNode(node->label);
        NewNode[node] = newGraph;
        
        while (!Myqueue.empty()) {
           
            Element = NewNode[Myqueue[0]];
            for (int i = 0; i < Myqueue[0]->neighbors.size(); i++) {
              
                
                //if the neighbor contains itself, then it revisited its nodes twice.
                if (IsVisited[Myqueue[0]->neighbors[i]] == 0 && Myqueue[0]!=Myqueue[0]->neighbors[i]) {
                    NewElement = new UndirectedGraphNode(Myqueue[0]->neighbors[i]->label);
                    NewNode[Myqueue[0]->neighbors[i]] = NewElement;
                    
                    Myqueue.push_back(Myqueue[0]->neighbors[i]);
                    IsVisited[Myqueue[0]->neighbors[i]] = 1;
                }
            
                Element->neighbors.push_back(NewNode[Myqueue[0]->neighbors[i]]);
            }
            
            Myqueue.erase(Myqueue.begin());
        
        }
        return newGraph;
        
    }
};