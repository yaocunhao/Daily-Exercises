class AnimalShelf {
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal)//添加动物
    {
        if(animal[1]==0)//猫
            cat.push(animal);
        else
            dog.push(animal);
    }
    
    vector<int> dequeueAny() //只能有最老的
    {
        vector<int> ret(2,-1);
        if(cat.empty()&&dog.empty())
            return ret;

        if(cat.empty())
        {
            ret=dog.front();
            dog.pop();
            return ret;
        }

        if(dog.empty())
        {
            ret=cat.front();
            cat.pop();
            return ret;
        }

        if(cat.front()[0]<dog.front()[0])
        {
            ret=cat.front();
            cat.pop();
        }
        else
        {
            ret=dog.front();
            dog.pop();
        }
        return ret;
    }
    
    vector<int> dequeueDog() {//最老的狗
        vector<int> ret(2,-1);
        if(dog.empty())
            return ret;
        
        ret=dog.front();
        dog.pop();
        return ret;
    }
    
    vector<int> dequeueCat() {//最老的猫
        vector<int> ret(2,-1);
        if(cat.empty())
            return ret;
        
        ret=cat.front();
        
        cat.pop();
        return ret;

    }

    queue<vector<int>> cat;
    queue<vector<int>> dog;
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */