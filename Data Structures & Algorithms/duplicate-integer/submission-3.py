class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        ## We are considering a hash set which will result in a time complexity of O(n),
        ## while compromising with the space complexity

        # hash_map = set()

        # for i in nums:
        #     if i in hash_map:
        #         return True
        #     hash_map.add(i)

        # return False

        ##Trying the sliding window method

        nums.sort()
        n = len(nums)
        for i in range(n-1):
            if nums[i] == nums[i+1]:
                return True

        return False




            
              
    