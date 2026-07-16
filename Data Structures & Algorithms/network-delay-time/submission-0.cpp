class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list:
        // adj[u] = {v, time required to travel from u to v}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];

            adj[u].push_back({v, time});
        }

        // dist[i] = minimum time required to reach node i
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip an outdated heap entry
            if (currentTime > dist[node]) {
                continue;
            }

            for (auto& neighbour : adj[node]) {
                int nextNode = neighbour.first;
                int edgeTime = neighbour.second;

                int newTime = currentTime + edgeTime;

                // Relaxation
                if (newTime < dist[nextNode]) {
                    dist[nextNode] = newTime;
                    pq.push({newTime, nextNode});
                }
            }
        }

        int answer = 0;

        for (int node = 1; node <= n; node++) {
            // This node cannot receive the signal
            if (dist[node] == INT_MAX) {
                return -1;
            }

            answer = max(answer, dist[node]);
        }

        return answer;
    }
};