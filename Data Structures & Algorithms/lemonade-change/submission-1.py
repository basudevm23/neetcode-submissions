class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        # when giving back changes, we should try to give back the changes starting from the highest denomination
        fives = 0 
        tens = 0

        for i in range(len(bills)):
            if bills[i] == 5:
                fives = fives + 1

            elif bills[i] == 10:
                tens = tens+1
                if fives >0: fives -= 1
                else: 
                    return False
                    
            
            else:
                if fives > 0 and tens > 0:
                    tens = tens-1
                    fives = fives - 1
                elif fives>=3:
                    fives = fives- 3
                else:
                    return False
        return True


            
            

            

            


            


