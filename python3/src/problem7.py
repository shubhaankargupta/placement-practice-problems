'''
Distribution file of the fill problem.
'''

from typing import List
def fill(array: List[int], i: int, x: int) -> None:
    '''
    Performs a fill operation on the list, replacing all continuous elements 
    with same value as list[i] with x.

    Note that this function works recursively.

    Arguments:
        array: a list of integers
        i: an integer
        x: an integer

    Returns:
        None
    '''
    # TODO: Implement this function.


    v = array[i]
    
    if(i<0 or i>=len(array)):
        print("i<0 or i>=len(array)")
        return array
    if(array[i]!=v):
        print("array[i]!=v")
        return array
    if(array[i]==x):
        print("array[i]==x")
        return array
    else:
        array[i]=x
        fill(array,i-1,x)
        return(fill(array,i+1,x))
    pass
print(fill([7,2,2,1,1,1,1,2,3,5],4,0))
