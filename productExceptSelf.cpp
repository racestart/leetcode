#include <vector>
#include <iostream>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  int n = nums.size();
  vector<int> res;
  res.resize(nums.size());
  res[0] = 1;
  for (int i = 1; i < n; i++) {
    res[i] = res[i - 1] * nums[i - 1];
  }
  int reverse = 1;
  for (int i = n - 1; i >= 0; i--) {
    res[i] *= reverse;
    reverse *= nums[i];
  }
  return res;
}

int main(int argc, char* argv[]) {
  vector<int> input = {1,2,3,4};
  vector<int> res = productExceptSelf(input);
  for (auto v : res) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}