void heapify(vector<int>& nums, int i, int n) {
    int L = 2 * i + 1;
    int R = 2 * i + 2;
    while (true) {
        int smallest = i;
        if (L < n && nums[L] > nums[i])
            smallest = L;
        if (R < n && nums[R] > nums[smallest])
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
void makeHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, i, n);
    }
}
void heapSort(vector<int>& nums) {
    makeHeap(nums);
    int n = nums.size();
    for (int i = n - 1; i >= 1; i--) {
        swap(nums[i], nums[0]);
        heapify(nums, 0, --n);
    }
}
