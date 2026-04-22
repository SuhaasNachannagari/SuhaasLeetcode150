

class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            adjList[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }

        return true;
    }

    bool dfs (int c) {
        if (visited.count(c) > 0) {
            return false;
        }

        if (adjList[c].empty()) {
            return true;
        }
        visited.insert(c);
        for (int pre : adjList[c]) {
            bool cycle = dfs(pre);
            if (!cycle) {
                return false;
            } 
        }

        visited.erase(c);
        adjList[c].clear();
        return true;
    }
};

