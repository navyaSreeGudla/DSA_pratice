class Solution {
public:
    class TrieNode {
    public:
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }

        void insert(const string& s) {
            TrieNode* node = this;

            for (char c : s) {
                int idx = c - 'a';

                if (node->child[idx] == nullptr)
                    node->child[idx] = new TrieNode();

                node = node->child[idx];
            }

            node->word = s;      // Store complete word at the end
        }
    };

    vector<string> res;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {

        // Boundary check
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return;

        char ch = board[r][c];

        // Visited or character not in trie
        if (ch == '#' || node->child[ch - 'a'] == nullptr)
            return;

        node = node->child[ch - 'a'];

        // Found a complete word
        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";        // Prevent duplicates
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, node);
        dfs(board, r - 1, c, node);
        dfs(board, r, c + 1, node);
        dfs(board, r, c - 1, node);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode* root = new TrieNode();

        // Build Trie
        for (string& word : words)
            root->insert(word);

        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return res;
    }
};