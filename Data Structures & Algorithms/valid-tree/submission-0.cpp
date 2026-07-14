class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
        visited[node]=1;
        for(int neighbor:adj[node])
        {
            if(!visited[neighbor])
            {
                dfs(neighbor,adj,visited);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;
        vector<vector<int >>adj(n);
        for(auto&edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        dfs(0,adj,visited);
        for(int i=0;i<n;i++)
        {

            if(!visited[i])return false;
        }
        return true;
    }
};
