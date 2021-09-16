class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {//向前缀树中插入字符串
        st.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {//查找单词word是否在前缀树之中
        if(st.find(word)!=st.end())
            return true;
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {//查找是否有前缀为prefix的单词
        for(auto&e:st)
        {
            int begin1=0;
            int begin2=0;

            while(begin1<e.size()&&begin2<prefix.size())
            {
                if(e[begin1]==prefix[begin2])
                {
                    begin2++;//当前字符匹配，则挪到下一个位置
                    begin1++;
                }
                else//当前是不匹配的
                    break;
            }
            if(begin2>=prefix.size())//找到了前缀和
                return true;
        }
        return false;
    }

    unordered_set<string> st;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */