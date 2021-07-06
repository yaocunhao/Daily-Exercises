class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        //{{姓名，餐桌号，餐品名称},{}}
        //ret:{{table,     菜品1，菜品2，菜品3}}
        //     对应的编号  对的数量.

        //1.先将所有的菜品拿出来进行排序，放在丢一行
        //2.统计每桌的菜品号，然后，填入表中
        vector<vector<string>> ret;

    //统计菜品,并且进行排序
        set<string> record;
        for(auto&e:orders)
        {
            record.insert(e[2]);
        }

    //第一行填入表中
    vector<string> arr;
    arr.push_back("Table");
    for(auto&e:record)//遍历菜单，添加至第一行
    {
        string s(e);
        arr.push_back(s);
    }
    ret.push_back(arr);

    
    //以桌号为key值，统计每桌的菜品数量
    map<int,vector<string>> mp;
    for(auto&e:orders)
    {
        mp[stoi(e[1])].push_back(e[2]);
    }
    
    //将菜品数量填入表中
    for(auto&e:mp)
    {
        unordered_map<string,int> count;
        vector<string> vec=e.second;//每一桌所有的菜品
        for(auto&e:vec)//统计菜品数量
        {
            count[e]++;
        }
        vector<string> add;
        add.push_back(to_string(e.first));//添加桌号

        for(int i=1;i<ret[0].size();i++)//变量菜名
        {
            add.push_back(to_string(count[ret[0][i]]));
        }
        ret.push_back(add);
    }
    return ret;
    }
};