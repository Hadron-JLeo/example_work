""" This script calculates the profit/loss of an investment by:

1. Purchase price
2. Sell price
3. Amount

"""


import numpy as np

def get_user_input()->tuple:
    """
        Gets float values b and s through user input as float 
        as well as amount of purchases
    """

    price_buy = input("Enter the minimum stock price: ")
    price_sale = input("Enter the maximum stock price: ")
    amount = input("Enter the amount of stocks to buy (default = 5.0): ")

    # User entered his values

    values = np.array([price_buy, price_sale, amount])
    values = np.char.lower(values)

    # Array created

    """ QUIT ROUTINE """
    if np.any(np.char.find(values, "end") >= 0):
        print('End call found! Quitting..')
        quit()
    """     ----    """

    # Check for end call due to recursion

    print(values)

    return list(values.astype(float))
#--


def calculate_profit(price_buy:float=1, price_sale:float=1, amount:float = 5.0):
    # Calculate profit/loss
    cost_price = amount * price_buy
    selling_price = amount * price_sale
    profit = selling_price - cost_price        
    print(f"""\nIf you buy {amount} stocks at ${price_buy:.2f} and sell at ${price_sale:.2f}, your profit will be: ${profit:.2f} 
          That was an investment of ${price_buy * amount}""")
    return profit
#--

def main():
    try:
        val = get_user_input()
        calculate_profit(*val)
        
    except (ValueError, TypeError):
        print("Error! Please enter only numbers! Please try again")
        main()
        

if __name__ == "__main__":
    main()
