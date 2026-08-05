class Solution {
private:
    int findparent(int node, vector<int>&parent)
    {
        if(parent[node]==node)return node;
        return parent[node]=findparent(parent[node],parent);
    }
    bool unionNodes(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int pu=findparent(u,parent);
        int pv=findparent(v,parent);
        if(pu==pv)return false;
        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv])
        {
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
        return true;
    }
public: 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i=1;i<n;i++)
        {
            parent[i]=i;
        }
        for(auto& edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            if(!unionNodes(u,v,parent,rank))
            return{u,v};
        }
        return {};
    }
};
