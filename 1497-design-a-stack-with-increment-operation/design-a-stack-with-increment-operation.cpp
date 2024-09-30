class CustomStack {
public:
    vector<int> v;
    int siz, top;
    
    CustomStack(int maxSize) {
        siz = maxSize;
        top = 0;
        v.assign(siz, -1);
    }

    void push(int x) {
        if (top < siz) {
            v[top] = x;
            top++;
        }
    }

    int pop() {
        if (top == 0) return -1; 
        top--;
        int ans = v[top];
        v[top] = -1; 
        return ans;
    }

    void increment(int k, int val) {
        int limit = min(k, top); 
        for (int i = 0; i < limit; i++) {
            v[i] += val;
        }
    }
};
