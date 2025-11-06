class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // --- Step 1: DSU (Disjoint Set Union) to find connected components ---
        vector<int> parent(c + 1), rank(c + 1, 0);
        for (int i = 1; i <= c; i++) parent[i] = i;
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        auto unite = [&](int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb) return;
            if (rank[pa] < rank[pb]) swap(pa, pb);
            parent[pb] = pa;
            if (rank[pa] == rank[pb]) rank[pa]++;
        };
        
        // --- Step 2: Build the graph connectivity ---
        for (auto &edge : connections) {
            unite(edge[0], edge[1]);
        }
        
        // --- Step 3: Build components ---
        unordered_map<int, set<int>> onlineStations; // comp_root -> set of online stations
        vector<int> compId(c + 1);
        for (int i = 1; i <= c; i++) {
            int root = find(i);
            compId[i] = root;
            onlineStations[root].insert(i);
        }
        
        // --- Step 4: Process queries ---
        vector<bool> online(c + 1, true);
        vector<int> result;
        
        for (auto &q : queries) {
            int type = q[0], x = q[1];
            int root = compId[x];
            
            if (type == 1) { // Maintenance check
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (!onlineStations[root].empty()) 
                        result.push_back(*onlineStations[root].begin());
                    else 
                        result.push_back(-1);
                }
            } 
            else if (type == 2) { // Go offline
                if (online[x]) {
                    online[x] = false;
                    onlineStations[root].erase(x);
                }
            }
        }
        
        return result;
    }
};

