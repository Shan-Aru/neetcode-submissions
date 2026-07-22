class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto&it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        vector<int>order;
        while(!q.empty())
        {
            int currentcourse=q.front();
            q.pop();
            order.push_back(currentcourse);
            for(int nextcourse:adj[currentcourse])
            {
                indegree[nextcourse]--;
                if(indegree[nextcourse]==0)q.push(nextcourse);
            }
        }
        if(order.size()!=numCourses)return{};
        return order;

    }
};
