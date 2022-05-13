
class Solution 
{
    private:
    bool knows(vector<vector<int> >& M,int a, int b){
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // 1. Brute force approach
        // bool candidate;
        // for(int i = 0; i< n;i++){
        //     candidate = true;
        //     // row Check 
        //     for(int j = 0; j< n;j++){
        //         if(M[i][j] == 1){
        //             candidate = false;
        //             break;
        //         }
        //     }
            
        //     if(candidate == false)
        //         continue;
                
        //     // column check 
        //     for(int j = 0;j<n;j++){
        //         if(i == j)
        //             continue;
        //         if(M[j][i] == 0){
        //             candidate = false;
        //             break;
        //         }
        //     }
            
        //     if(candidate == true)
        //         return i;
        // }
        
        // return -1;
        
        // 2. Optimized Approach
        // step 1- Push all the elements to the stack
        stack<int> s;
        
        for(int i = 0;i<n;i++){
            s.push(i);
        }
        
        // pop 2 elements and check if 1 knows another the person who knows don't push him
        // bcoz he cannot be the celebrity, push the other one 
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        // verify if top is candidate
        int candidate = s.top();
        bool rowCheck = true;
        bool colCheck = true;
        
        for(int i = 0;i< n;i++){
            if(M[candidate][i] == 1){
                rowCheck = false;
                break;
            }
        }
        
        
        for(int i = 0;i< n;i++){
            if(i == candidate)
                continue;
            if(M[i][candidate] == 0){
                colCheck = false;
                break;
            }
        }
        
        if(rowCheck == true && colCheck == true)
            return candidate;
        else
            return -1;
        
        
    }
};
