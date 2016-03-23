class TrieNode {
public:
    vector<TrieNode*> set;
    bool is_end;
    // Initialize your data structure here.
    TrieNode() {
	is_end = false;
	set.resize(26);
	std::fill (set.begin(), set.end(), nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
	if (word.empty()) return;
	TrieNode* tree = root;
	for (auto c : word) {
	    if (!tree->set[c-'a']) {
		tree->set[c-'a'] = new TrieNode();
	    }
	    tree = tree->set[c-'a'];
	}
	tree->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
	if (word.empty()) return true;
	auto tree = root;
	for (auto c : word) {
	    tree = tree->set[c-'a'];
	    if (!tree) return false;
	}
	return tree->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
	if (prefix.empty()) return true;
	auto tree = root;
	for (auto c : prefix) {
	    tree = tree->set[c-'a'];
	    if (!tree) return false;
	}
	return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
