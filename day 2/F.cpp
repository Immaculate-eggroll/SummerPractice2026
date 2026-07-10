#include <bits/stdc++.h>
using namespace std;
 
const int MAX_BIT = 30;
 
struct TrieNode {
    TrieNode* child[2];
    int cnt;
    
    TrieNode() {
        child[0] = child[1] = nullptr;
        cnt = 0;
    }
};
 
class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int x) {
        TrieNode* node = root;
        for (int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            if (!node->child[b]) {
                node->child[b] = new TrieNode();
            }
            node = node->child[b];
            node->cnt++;
        }
    }
    
    void remove_val(int x) {
        TrieNode* node = root;
        for (int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            node = node->child[b];
            node->cnt--;
        }
    }
    
    int get_min_xor(int x) {
        TrieNode* node = root;
        int res = 0;
        for (int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            if (node->child[b] && node->child[b]->cnt > 0) {
                node = node->child[b];
            } else {
                res |= (1 << bit);
                node = node->child[b ^ 1];
            }
        }
        return res;
    }
    
    int get_max_xor(int x) {
        TrieNode* node = root;
        int res = 0;
        for (int bit = MAX_BIT; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            if (node->child[b ^ 1] && node->child[b ^ 1]->cnt > 0) {
                res |= (1 << bit);
                node = node->child[b ^ 1];
            } else {
                node = node->child[b];
            }
        }
        return res;
    }
    
    void destroy(TrieNode* node) {
        if (!node) return;
        destroy(node->child[0]);
        destroy(node->child[1]);
        delete node;
    }
    
    ~Trie() {
        destroy(root);
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    Trie trie;
    
    for (int i = 0; i < n; i++) {
        trie.insert(a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        trie.remove_val(a[i]);
        int min_xor = trie.get_min_xor(a[i]);
        int max_xor = trie.get_max_xor(a[i]);
        trie.insert(a[i]);
        cout << min_xor << ' ' << max_xor << '\n';
    }
}
