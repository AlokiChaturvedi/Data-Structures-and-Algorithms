#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
 using namespace std;

int findMaxHeight(std::vector<int>& stack1, std::vector<int>& stack2, std::vector<int>& stack3) {
    int sum1 =accumulate(stack1.begin(), stack1.end(), 0);
    int sum2 =accumulate(stack2.begin(), stack2.end(), 0);
    int sum3 =accumulate(stack3.begin(), stack3.end(), 0);

    while (!(sum1 == sum2 && sum2 == sum3)) {
        // Find the stack with the maximum height and remove the top cylinder
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1.back();
            stack1.pop_back();
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2.back();
            stack2.pop_back();
        } else {
            sum3 -= stack3.back();
            stack3.pop_back();
        }
    }

    return sum1;  // All stacks are now of the same height
}

int main() {
    // Example stacks (you can replace these with your input)
    vector<int> stack1 = {3, 2, 1, 1, 1};
    vector<int> stack2 = {4, 3, 2};
    vector<int> stack3 = {1, 1, 4, 1};

    int maxHeight = findMaxHeight(stack1, stack2, stack3);

    cout << "Maximum possible height of the stacks: " << maxHeight << endl;

    return 0;
}
