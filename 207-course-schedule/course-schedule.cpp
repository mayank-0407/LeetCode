class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> inDegree(n,0);
        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++)
            if(inDegree[i] == 0) q.push(i);  

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]){
                inDegree[it] --;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        return topo.size() == n;
    }
};