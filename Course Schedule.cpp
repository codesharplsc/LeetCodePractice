/*

Please note the SelectNode function is not the optimal one. It takes O(n) time. The efficient approach will be to maintain a queue for BFS (Stack for DFS).Add
any vertices to this data sturcture when its degree first becomes zero.
*/


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> CoursesRequire(numCourses,0);
        map<int, vector<int>> NodeEdges;
        vector<int> EdgesElement;
        int node;
        
        for(int i = 0; i<prerequisites.size();i++){
            CoursesRequire[prerequisites[i].first]++;
            NodeEdges[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        for(int i = 0; i < numCourses; i++){
            node = SelectNode(CoursesRequire);
            if (node == -1)
                return false;
            for (int j = 0 ;j < NodeEdges[node].size();j++)
                CoursesRequire[NodeEdges[node][j]]--;
            CoursesRequire[node] = -2;
        }
            
        return true;
        
    }
    // 0 means no prerequisite, -2 means visited
    int SelectNode(vector<int> &CoursesRequire){
        for (int i = 0 ; i < CoursesRequire.size();i++)
            if (CoursesRequire[i] == 0)
                return i;
        return -1;
    }
};