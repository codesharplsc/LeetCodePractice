/*
 The same problem with Course Schedule problem one.
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> CoursesRequire(numCourses,0);
        map<int, vector<int>> NodeEdges;
        vector<int> EdgesElement;
        vector<int> path;
        int node;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            CoursesRequire[prerequisites[i].first]++;
            NodeEdges[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        for (int i = 0; i < numCourses; i++) {
            node = SelectNode(CoursesRequire);
            path.push_back(node);
            if (node == -1)
                return {};
            for (int j = 0 ;j < NodeEdges[node].size(); j++)
                CoursesRequire[NodeEdges[node][j]]--;
            CoursesRequire[node] = -2;
        }
            
        return path;
    }
    
     // 0 means no prerequisite, -2 means visited
    int SelectNode(vector<int> &CoursesRequire){
        for (int i = 0 ; i < CoursesRequire.size(); i++)
            if (CoursesRequire[i] == 0)
                return i;
        return -1;
    }
};