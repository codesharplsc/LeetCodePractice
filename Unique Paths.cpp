class Solution {
public:
    int uniquePaths(int m, int n) {
        map<pair<int, int>, int>Mymap;
        return ComputePathCount(m-1, n-1, Mymap);
    }
    
    int ComputePathCount(int m, int n, map<pair<int, int>, int> &Mymap) {
        int result;
        if (m == 0 || n == 0)
            return 1;
        if (Mymap[make_pair(m, n)] != 0)
            result = Mymap[make_pair(m, n)];
        else {
            result = ComputePathCount(m, n-1, Mymap) + ComputePathCount(m-1, n, Mymap);
            Mymap[make_pair(m, n)] = result;
        }
        return result;
    }
};