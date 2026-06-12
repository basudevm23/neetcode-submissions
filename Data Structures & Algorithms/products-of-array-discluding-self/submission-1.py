class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ##For time complexity of O(n^2)
        # my_output = [1]*len(nums)
        # for i in range(len(nums)):
        #     for j in range(len(nums)):
        #         if j !=i :
        #             my_output[i] = my_output[i]*nums[j]
        # return my_output

        ## keeping the prefix product and suffix product
        prefix = 1
        postfix = 1
        myo = [0]*len(nums)

        for i in range(len(nums)):
            myo[i] = prefix
            prefix = prefix*nums[i]
        nums.reverse()
        myo.reverse()

        for i in range(len(nums)):
            myo[i] = myo[i]*postfix
            postfix = postfix*nums[i]
        myo.reverse()
        return myo




        