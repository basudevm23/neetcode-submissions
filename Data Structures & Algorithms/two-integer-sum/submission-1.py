class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_map = {}
        for i in range(len(nums)):
            reqd = target - nums[i]
            if reqd in my_map:
                return [my_map[reqd], i]
            my_map[nums[i]]= i
        return []