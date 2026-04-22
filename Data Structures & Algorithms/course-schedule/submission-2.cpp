

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegrees;
        unordered_map<int, vector<int>> adjList;

        for (const auto& prereq : prerequisites) {
            indegrees[prereq[0]]++;
            adjList[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;
            for (int nei : adjList[node]) {
                indegrees[nei]--;
                if(indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return finish == numCourses;
    }
};

