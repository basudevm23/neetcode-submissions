class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ## what can enumerate do?
        ##  For each iteration, it yields a tuple in the format (index, value), which can be easily unpacked into two variables within a for loop.

        hash_map = {}

        for i, j in enumerate(nums):
            rem = target - j
            if rem in hash_map:
                return [hash_map[rem], i]

            hash_map[j] = i
        return []