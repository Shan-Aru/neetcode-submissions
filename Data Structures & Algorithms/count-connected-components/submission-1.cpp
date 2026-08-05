class Solution {
private:
    void dfs(int node,vector<vector<int>>&adj,vector<int>& visited)
    {
        visited[node]=1;
        for( int neighbours : adj[node])
        {
            if(!visited[neighbours])
                dfs(neighbours,adj,visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int component=0;
        vector<vector<int>>adj(n);
        vector<int>visited(n+1,0);
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int node=0;node<n;node++)
        {
            if(!visited[node])
            {
                component++;
                dfs(node,adj,visited);
            }
        }
        return component;
    }
};
