
class ThroneInheritance {
public:
    ThroneInheritance(string kingName)
    :_king(kingName)
    {
        _mp[kingName];//第一个人
    }
    
    void birth(string parentName, string childName) {//有了一个新的孩子
        
        //得到它父亲的孩子集合,并且将该孩子添加进去
       _mp[parentName].push_back(childName);//将该孩子添加进去

        _mp.insert(make_pair(childName,vector<string>()));//这个孩子也有可能成为父亲
    }
    
    void death(string name) {//死了
        _death.insert(name);//死亡的将其进行标记
    }

    void prevOrder(vector<string>& ret,string name)
    {
        vector<string> arr=_mp[name];
        for(int i=0;i<arr.size();i++)
        {
            if(_death.find(arr[i])==_death.end())//没有死亡，则添加进去
                ret.push_back(arr[i]);
            
            prevOrder(ret,arr[i]);
        }
    }
    
    vector<string> getInheritanceOrder() {//返回继承顺序列表
        vector<string> ret;

        if(_death.find(_king)==_death.end())//不在死亡列表之中
            ret.push_back(_king);
        
        prevOrder(ret,_king);

        return ret;
    }
    
    string _king;//保存第一位国王
    unordered_map<string,vector<string>> _mp;//记录每个人，和它的孩子
    unordered_set<string> _death;//记录这个人是否死亡
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */