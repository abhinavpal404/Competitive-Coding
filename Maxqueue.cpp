struct maxqueue
{
    stack<pii>s1;
    stack<pii>s2;
    maxqueue() {}
    void push (int x)
    {
        if(s1.empty())
        s1.push({x,x});
        else
        {
            
            s1.push({x,max(x,(int)s1.top().ss)});
        }
    }
    void pop_back()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int p = s1.top().ff;
                s1.pop();
                int next = s2.empty() ? p : max(s2.top().ss,p) ;
                s2.push({p,next}); 
            }
        }
        int ans = s2.top().ff;
        s2.pop();
    }
    int look_pop_back()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int p = s1.top().ff;
                s1.pop();
                int next = s2.empty() ? p : max(s2.top().ss,p) ;
                s2.push({p,next}); 
            }
        }
        int ans = s2.top().ff;
        s2.pop();
        return ans;
    }
    void pop_front()
    {
        if(s1.empty()) 
        {
            while(!s2.empty())
            {
                int p = s2.top().ff;
                int val = s1.empty() ? p : max(p,s1.top().ff);
                s1.push({p,val});
                s2.pop();
            }
        }
        int val = s1.top().ff;
        s1.pop();
    }
    int look_pop_front()
    {
        if(s1.empty()) 
        {
            while(!s2.empty())
            {
                int p = s2.top().ff;
                int val = s1.empty() ? p : max(p,s1.top().ff);
                s1.push({p,val});
                s2.pop();
            }
        }
        int val = s1.top().ff;
        s1.pop();
        return val;
    }
    int maximum()
    {
        int val = -1;
        for(auto s : {s1,s2})
        {
            if(s.size())
            {
                val = max(s.top().ss,val);
            }
        }
        return val;
    }
    int size()
    {
        return s1.size()+s2.size();
    }
};
