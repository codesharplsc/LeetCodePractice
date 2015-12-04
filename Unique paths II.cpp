class Solution {
public:
    /* using DP with recursive call, Time Limit Exceed
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        map<pair<int,int>,int> Mymap;
        
        if(obstacleGrid.size() == 0)
            return 0;
        
        return ComputePath(obstacleGrid,Mymap,0,0,obstacleGrid.size()-1,obstacleGrid[0].size()-1);
    }
    
    int ComputePath(vector<vector<int>> &obstacleGrid, map<pair<int,int>, int> &Mymap,int X,int Y,int targetX,int targetY ){
        int result;
        if(X == targetX && Y == targetY)
            return 1;
        if(X >targetX || Y>targetY || obstacleGrid[X][Y] ==1)
            return 0;
            
        if(Mymap[make_pair(X,Y)] != 0)
            result = Mymap[make_pair(X,Y)];
        else{
            result = ComputePath(obstacleGrid,Mymap,X+1,Y,targetX,targetY)+ComputePath(obstacleGrid,Mymap,X,Y+1,targetX,targetY);
            Mymap[make_pair(X,Y)] = result;
        }
        
        return result;
            
    }
    */
    
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        
          
        if (obstacleGrid.size() == 0)
            return 0;
        
        vector<vector<int>> MyPath= obstacleGrid;
        for (int i = 0; i < obstacleGrid[0].size(); i++)
            MyPath[0][i] = 0;
        for (int i = 0; i < obstacleGrid[0].size()&&obstacleGrid[0][i]!=1; i++)
            MyPath[0][i] = 1;
            
        for (int i = 0; i<obstacleGrid.size();i++)
            MyPath[i][0] = 0;
        for (int i = 0; i<obstacleGrid.size()&&obstacleGrid[i][0]!=1; i++)
            MyPath[i][0] = 1;
        
        
        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            MyPath[0][0] = 1;
        
        
        for (int i = 1 ;i < obstacleGrid.size(); i++)
            for (int j = 1; j < obstacleGrid[0].size(); j++){
                if (obstacleGrid[i][j] == 1)
                    MyPath[i][j] = 0;
                else
                    MyPath[i][j] = MyPath[i-1][j] + MyPath[i][j-1];
                
            }
        
        return MyPath[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};