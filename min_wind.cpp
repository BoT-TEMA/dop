#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> window_minimum(const vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;
    
    for (int i = 0; i < nums.size(); ++i) {
        // Удаляем те, что выходят за границы слева
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Удаляем те, что больше или равны справа
        while (!dq.empty() && nums[dq.back()] >= nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;
    
    vector<int> nums(n);
    cout << "Enter sequence: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    vector<int> mins = window_minimum(nums, k);
    
    cout << "Minimums in the windows: ";
    for (int num : mins) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
