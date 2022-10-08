class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        count=0
        for i in nums:
            count=count^i
        return count
