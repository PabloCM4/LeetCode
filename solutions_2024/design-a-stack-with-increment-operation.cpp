    //  Link: https://leetcode.com/problems/design-a-stack-with-increment-operation
class CustomStack {
private:

vector<int> myStack;
int myMax = 0;
int n_elem = 0;

public:

    CustomStack(int maxSize) {
        myMax = maxSize;
    }
    
    void push(int x) {
        if(n_elem < myMax)
        {
            myStack.push_back(x);
            n_elem++;
        }
    }
    
    int pop() {
        if(n_elem)
        {
            n_elem--;
            int result = myStack[n_elem];
            myStack.pop_back();
            return result;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i = 0; (i < k) && (i < n_elem); i++)
        {
            myStack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */