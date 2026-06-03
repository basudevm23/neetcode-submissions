class Solution:
    def checkalpha(self, c):
        return (ord('Z')>=ord(c) and ord(c)>=ord('A')) or (ord('z')>=ord(c) and ord(c)>=ord('a')) or(ord('9')>=ord(c) and ord(c)>=ord('0'))
        

    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        l = 0
        r = n-1

        while l<r:
            while l<r and not self.checkalpha(s[l]):
                l = l+1
            while l<r and not self.checkalpha(s[r]):
                r -= 1
            if(s[l].lower() != s[r].lower()):
                return False;
            l = l+1
            r = r-1
        return True;
        
        

        