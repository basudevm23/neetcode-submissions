class Solution: 

    def validPalindrome(self, s: str) -> bool:
        def is_Palindrome(l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True
        l  = 0
        r= len(s) -1

        while l < r:
            if s[l] != s[r]:
                return is_Palindrome(l+1, r) or is_Palindrome(l, r-1)

            l = l+1
            r = r-1
        return True

        


            
            