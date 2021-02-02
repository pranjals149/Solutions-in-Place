#include <iostream>
#include <vector>

using namespace std;

class MinMaxStack {
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;
    
    public: 
        void push(int d) {
            int current_min = d;
            int current_max = d;

            if (min_stack.size()) {
                current_min = min(min_stack[min_stack.size()-1], d);
                current_max = max(max_stack[max_stack.size()-1], d);
            }

            min_stack.push_back(current_min);
            max_stack.push_back(current_max);
            stack.push_back(d);
        }

        int getMin() {
            return min_stack[min_stack.size()-1];
        }

        int getMax() {
            return max_stack[max_stack.size()-1];
        }

        int top() {
            return stack[stack.size()-1];
        }

        void pop() {
            min_stack.pop_back();
            max_stack.pop_back();
            stack.pop_back();
        }

        bool empty() {
            return stack.size() == 0;
        }
};

int main() {
    MinMaxStack s;

    s.push(1);
    s.push(9);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);

    cout << s.getMax() << endl;
    s.pop();
    cout << s.getMin() << endl;
    cout << s.getMax() << endl;

    s.pop();
    s.pop();

    cout << s.top() << endl;
    cout << s.getMax() << endl;

    return 0;

}
