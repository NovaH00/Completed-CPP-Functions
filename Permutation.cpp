
#include <vector>

bool is_in(std::vector<std::vector<int>> _2Dvec, std::vector<int> vec)
{
    for (auto i : _2Dvec)
    {
        if (i == vec)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::vector<int>> permute(std::vector<int> nums)
{
    if (nums.size() == 1)
    {
        std::vector<std::vector<int>> att;
        att.push_back(nums);
        return att;
    }

    std::vector<std::vector<int>> res;

    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[0];
        nums.erase(nums.begin());

        for (auto perm : permute(nums))
        {
            perm.push_back(n);

            if (is_in(res, perm) == false)
            {
                res.push_back(perm);
            }
        }
        nums.push_back(n);
    }
    return res;
}
