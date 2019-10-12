class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode
    {
        TrieNode* child[26];
        bool eow = false;
    };
    
    TrieNode* getNode()
    {
        TrieNode *temp = new TrieNode;
        for(int i = 0; i<26; i++)
            temp->child[i] = NULL;
        temp->eow = false;
        return temp;
    }
    
    TrieNode *root;
    Trie() 
    {
        root = getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *crawl = root;
        for(int i=0; i<word.length(); i++)
        {
            int index = word[i] - 'a';
            if(!crawl->child[index])
                crawl->child[index] = getNode();
            crawl = crawl->child[index];
        }
        
        crawl->eow = true;
        return;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode *crawl = root;
        for(int i = 0; i<word.length(); i++)
        {
            int index = word[i] - 'a';
            if(!crawl->child[index])
                return false;
            crawl = crawl->child[index];
        }
        
        return crawl->eow ? true : false ; 
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *crawl = root;
        for(int i=0; i<prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if(!crawl->child[index])
                return false;
            crawl = crawl->child[index];
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