class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> s;
    vector<int> v;

    MinStack()
    {
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            v.push_back(val);
        }
        else
        {
            s.push(val);

            if (val > v[v.size() - 1])
            {
                v.push_back(v[v.size() - 1]);
            }
            else
            {
                v.push_back(val);
            }
        }
    }

    void pop()
    {
        s.pop();
        v.pop_back();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return v[v.size() - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */