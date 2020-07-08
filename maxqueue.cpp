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
    void pop()
    {
        if(!s2.empty())
        {
            s2.pop();
        }
        else
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
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
};
