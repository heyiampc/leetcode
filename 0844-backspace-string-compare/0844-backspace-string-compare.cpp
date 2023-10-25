class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> q1,q2;
        for(auto &it:s)
        {
            if(it=='#' && q1.size()>0)
                q1.pop();
            else
                q1.push(it);
        }
        for(auto &it:t)
        {
            if(it=='#' && q2.size()>0)
                q2.pop();
            else
                q2.push(it);
        }
        string s1="";
        string t1="";
        while(!q1.empty()){
            if(q1.top()!='#')
            s1+=q1.top();
            q1.pop();
        }
        while(!q2.empty()){
            if(q2.top()!='#')
            t1+=q2.top();
            q2.pop();
        }
        cout<<s1<<" "<<t1<<endl;
        return s1==t1;
    }
};