class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic1 = {}
        dic2 = {}

        if len(s) != len(t):
            return False

        for i in range(len(s)):
            if s[i] not in dic1:
                dic1[s[i]] = 1

            else: dic1[s[i]]+=1
        
        for j in range(len(t)):
            if t[j] not in dic2:
                dic2[t[j]] =1
            else: dic2[t[j]]+=1

        if dic1 == dic2:
            return True

        return False

            

