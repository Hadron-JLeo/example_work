# This code first calculates the coulomb of a parallel sequence of capacitors
# Then we calculate the Ampere Hours

CONST_AH:float = 10**-4 * 2.7778
CONST_MICRO:int = 10**-6
# 1 μF (microfarad, one millionth (10^−6) of a Farad)


my_volt:float  =  50
my_farad:float = 220*6

def calc_q(volt:float=0, farad:float=0)->float:
    """
    calc_q Calculates the Coulomb value
    
            :param (float)volt: The voltage input
            :param (float)farad: The incurring farad
        
        :return float: Returns the Coulomb value
    """

    # farad is usually written as big C
    f = farad*CONST_MICRO 
    v = volt

    # q is a coulomb

    q = f * v

    print(f'Farad: {f}, Volt: {v}')
    return q
pass


def calc_amp(coulomb:float=1.0)->float:
    """ 
    calc_amp Calculates the ampere hours from my_farad and my_volt 

            :param (float)coulomb: The Input coulomb, defaults to 1.0

        :return float: Returns the value of Ampere Hours
    """

    amp_hours = my_farad * my_volt / 3600 #coulomb*CONST_AH
    return amp_hours
pass


def main()->None:
    """ The main executing function """
    q = calc_q(my_volt, my_farad)
    ah = calc_amp(q)
    print(f'Ampere Hours: {ah}')
pass


# -- End of Function definitions -- #

if __name__ == '__main__':
    main()
