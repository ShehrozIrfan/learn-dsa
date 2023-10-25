from typing import List
class solution:
    def maxProfit(self,Prices:List[int])->int:
        res = 0
        lowest = Prices[0]
        for price in Prices:
            if price < lowest:
                lowest = price
            res = max(res,price-lowest)
        return res
# Get the user input 
Prices = input("Enter a list of Prices: ").split()
Prices = [int (price)for price in Prices]

solution = solution()
max_profit = solution.maxProfit(Prices)
print("Max Prfit: ",max_profit)