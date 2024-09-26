class minHeap {
private:
    vector<int> nums;
public:
    void push(int num) {
        nums.push_back(num);
        int i = nums.size() - 1;
        int j = (i - 1) / 2;
        while (j >= 0 && nums[i] < nums[j]) {
            swap(nums[i], nums[j]);
            i = j;
            j = (i - 1) / 2;
        }
    }

    void remove() {
        if (nums.empty()) {
            return;
        }
        nums[0] = nums.back();
        nums.pop_back();
        int n = nums.size();
        int i = 0;
        int L = 2 * i + 1;
        int R = 2 * i + 2;
        while (true) {
            int smallest = i;
            if (L < n && nums[L] < nums[smallest])
                smallest = L;
            if (R < n && nums[R] < nums[smallest])
                smallest = R;
            if (smallest != i) {
                swap(nums[i], nums[smallest]);
                i = smallest;
                L = 2 * i + 1;
                R = 2 * i + 2;
            }
            else break;
        }
    }

    int peek() {
        if (nums.empty()) {
            return INT_MAX;
        }
        return nums[0];
    }

    void displayHeap() {
        for (const int num : nums) {
            cout << num << ' ';
        }
        cout << '\n';
    }
};
