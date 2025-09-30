void counting_sort(vector<int>& nums, int n) {
    int L = *min_element(nums.begin(), nums.end());
    int R = *max_element(nums.begin(), nums.end());

    const int auxSize = R - L + 1;
    vector<int> countArr(auxSize, 0);
    for (int i = 0; i < (int) nums.size(); i++) {
        countArr[nums[i] - L]++;
    }
    for (int i = 1; i < auxSize; i++) {
        countArr[i] += countArr[i - 1];
    }
    vector<int> copyNums(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
        copyNums[--countArr[nums[i] - L]] = nums[i];
    }
    nums = copyNums;
}
