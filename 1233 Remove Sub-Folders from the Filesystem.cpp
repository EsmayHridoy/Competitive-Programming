// 1233. Remove Sub-Folders from the Filesystem
// cpp solution


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folders) {
        unordered_map<string, bool> visited;
        vector<string> result;
        sort(folders.begin(), folders.end());
        for (auto folder : folders) {
            bool isSubfolder = false;
            string currentPath = "";
            for (auto ch : folder) {
                if (currentPath.empty()) {
                    currentPath.push_back(ch);
                    continue;
                }
                if (ch == '/') {
                    isSubfolder |= visited[currentPath];
                }
                currentPath.push_back(ch);
            }
            isSubfolder |= visited[currentPath];

            if (isSubfolder) continue;

            visited[folder] = true;
            result.push_back(folder);
        }

        return result;
    }
};
