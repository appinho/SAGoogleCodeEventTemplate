class Trie {
private:
    int _abc = 26;
    vector<vector<int>> _trie;
    vector<bool> _end;
public:
    /** Initialize your data structure here. */
    Trie() {
        _abc = 26;
        _trie.emplace_back(vector<int>(_abc, -1));
        _end.emplace_back(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int d = 0;
        for(auto c: word){
            int pos = c - 'a';
            cout << d << " " << _trie[d][pos] << endl;
            if(_trie[d][pos] == -1){
                _trie.emplace_back(vector<int>(_abc, -1));
                _end.emplace_back(false);
                _trie[d][pos] = _trie.size() - 1;
            }
            d = _trie[d][pos];
        }
        _end[d] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int d = 0;
        for(auto c: word){
            int pos = c - 'a';
            if(_trie[d][pos] == -1){
                return false;   
            }
            d = _trie[d][pos];
        }
        if(_end[d]){
            return true;
        }
        else{
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int d = 0;
        for(auto c: prefix){
            int pos = c - 'a';
            if(_trie[d][pos] == -1){
                return false;   
            }
            d = _trie[d][pos];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */