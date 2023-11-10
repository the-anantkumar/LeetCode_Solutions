class Solution {
public:
    unordered_map<int, vector<int>>adj;
    vector<int> answer;
    map<int, bool> vis;

    void dfs(int src)
    {
        answer.push_back(src);
        vis[src] = 1;

        for(auto x: adj[src])
        {
            if(!vis[x])
            {
                dfs(x);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();

       // adj.resize();
     
        for(auto x: adjacentPairs)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            vis[x[0]] = false;
            vis[x[1]] = false;
        }
        int root = INT_MIN;
        for(auto x: adj)
        {
            if(x.second.size() == 1) 
            {
                root = x.first;
                break;
            }
        }

        dfs(root);

        return answer;
    }
};