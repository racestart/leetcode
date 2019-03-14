#include <vector>
#include <iostream>
#include <map>

using namespace std;

#if 0
vector<int> twoSum(vector<int>& nums, int target) {
  vector<vector<int> > diff;
  for (size_t i = 0; i < nums.size(); i++) {
    vector<int> d;
    d.push_back(i);
    d.push_back(target - nums[i]);
    diff.push_back(d);
  }
        
  vector<int> res;
  for (size_t i = 0; i < nums.size(); i++) {
    for (size_t j = 0; j < diff.size(); j++) {
      if (nums[i] == diff[j][1]) {
        if (i == diff[j][0])
          continue;
                  
          res.push_back(i);
          res.push_back(diff[j][0]);
          return res;
      }
    }
  }
  return res;
}
#endif

#if 0
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> diff;
  map<int, int> hash;
  for (size_t i = 0; i < nums.size(); i++) {
    diff.push_back(target - nums[i]);
    hash[nums[i]] = i;
  }

  vector<int> res;
  for (size_t i = 0; i < diff.size(); i++) {
    map<int, int>::iterator iter = hash.find(diff[i]);
    if (iter != hash.end()) {
      if (iter->second == i)
        continue;
      res.push_back(i);
      res.push_back(iter->second);
      return res;
    }
  }

  return res;
}

#endif

vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> hash;
  for (size_t i = 0; i < nums.size(); i++) {
    map<int, int>::iterator iter = hash.find(nums[i]);
    if (iter != hash.end()) {
      return {iter->second, int(i)};
    }
    hash[target - nums[i]] = i;
  }

  return {};
}

int main(int argc, char* argv[]) {
  vector<int> input = {3,2,4};
  vector<int> res = twoSum(input, 6);
  cout << res[0] << res[1] << endl;
  return 0;
}