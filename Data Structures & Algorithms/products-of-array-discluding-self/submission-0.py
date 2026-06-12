class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        my_output = [1]*len(nums)
        for i in range(len(nums)):
            for j in range(len(nums)):
                if j !=i :
                    my_output[i] = my_output[i]*nums[j]
        return my_output




        