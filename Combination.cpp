#include <vector>

std::vector<std::vector<int>> combinations(std::vector<int> nums)
{
    if (nums.size() == 1)
    {
        std::vector<std::vector<int>> att;
        att.push_back(nums);
        return att;
    }

    std::vector<std::vector<int>> res;

    int lastNum = nums[nums.size() - 1];
    std::vector<int> att;   //"att" vector is used to change "lastNum" type
    att.push_back(lastNum); // from int to vector<int>, which is correct type for
    res.push_back(att);     // a member of "res" vector
    nums.erase(nums.begin() + nums.size() - 1);
    for (auto com : combinations(nums))
    {
        res.push_back(com);
        com.push_back(lastNum); // add the lastNum to the combination to create a new combination
        res.push_back(com);     // which is not in "res" yet
    }
    return res;
}
