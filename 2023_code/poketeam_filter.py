# This script allows the user to input pokemon and sort them by a stat of their choosing, e.g. Highest Speed to lowest Speed


# -- Code start --

import pypokedex



SERPERIOR = pypokedex.get(name='serperior')
PSYDUCK = pypokedex.get(name='psyduck')
AMPHAROS = pypokedex.get(name='ampharos')

cur_pokemon = [SERPERIOR, PSYDUCK, AMPHAROS]

# --

END_CONDITION:str = 'exit'
FILTER_CONDITION:str ='filter'


def poke_print(arr, stat_name:str='speed'):

    for i in arr:
        print(f'Mon= {i.name} {stat_name}= {getattr(i.base_stats, stat_name)}')
pass

def insert_mon(n:str=''):

    try:
        cur_mon = pypokedex.get(name=n)
        cur_pokemon.append(cur_mon)
        return cur_mon
    except:
        print(f'Error! Pokemon with name ?{n}? not found!') 

pass


def sort_by_stat(stat_name:str='speed'):

    sorted_array = cur_pokemon


    n = len(cur_pokemon)
    for i in range(1, n):  # Iterate over the array starting from the second element
        key = cur_pokemon[i]  # Store the current element as the key to be inserted in the right position
        
        j = i-1
        while j >= 0 and getattr(key.base_stats, stat_name) < getattr(cur_pokemon[j].base_stats, stat_name):  # Move elements greater than key one position ahead
            sorted_array[j+1] = cur_pokemon[j]  # Shift elements to the right
            j -= 1
        sorted_array[j+1] = key  # Insert the key in the correct position
    

    return(sorted_array)
pass


def main():
    x = ''
    stat = 'speed'
    print(f'Enter {END_CONDITION} to end!')

    print(getattr(cur_pokemon[0].base_stats, 'speed'))

    while not (x==END_CONDITION):

        x = input('Insert a Pokemon:  \n')

        if not (x==FILTER_CONDITION):
            p = insert_mon(x)
            # print(p.base_stats.speed)
        else:
            if len(cur_pokemon) >1 :

                stat = input('Please enter the stat to filter by:  \n')
                sorted = sort_by_stat(stat)
                poke_print(sorted, stat)
    pass


if __name__ == '__main__':
    main()


# -- End of script -- #
