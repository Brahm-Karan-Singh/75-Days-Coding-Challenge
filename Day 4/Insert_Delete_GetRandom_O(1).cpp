class RandomizedSet {
private:
    vector<int> ans;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        for(int i = 0;i<ans.size();i++){
            if(ans[i] == val)
                return false;
        }
        ans.push_back(val);
        return true;      
    }
    
    bool remove(int val) {
        for(auto i= ans.begin();i != ans.end();i++){
            if(*i == val){
                ans.erase(i);
                return true;
            }
        }
        return false;
    }
    
    int getRandom() {
        int randomIndex = rand()%ans.size();
        return ans[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */