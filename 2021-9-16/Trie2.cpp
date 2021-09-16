    Trie() {
        IsEnd=false;
        for(int i=0;i<26;i++)
        {
            next[i]=nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node=this;

        for(auto&e:word)
        {
            if(node->next[e-'a']==nullptr)//当前没有该字符
                node->next[e-'a']=new Trie;
            
            node=node->next[e-'a'];
        }
        node->IsEnd=true;//标记结尾
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {//查找这个单词
        Trie *node=this;

        for(auto&e:word)
        {
            if(node->next[e-'a']==nullptr)
                return false;//当前没有
            
            node=node->next[e-'a'];
        }
        if(node->IsEnd==true)//是结尾
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {//查找部分
         Trie *node=this;
        for(auto&e:prefix)
        {
            if(node->next[e-'a']==nullptr)
                return false;//当前没有
            node=node->next[e-'a'];
        }
        return true;
    }

    bool IsEnd;
    Trie* next[26];
};