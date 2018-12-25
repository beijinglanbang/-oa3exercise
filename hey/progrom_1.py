# coding: utf-8

# author: everpuck
# just for fun


import copy


def get_longest_continuous_subsquence(array_list, desc=False):
    if not array_list:
        return []
    
    ret = []
    sub_array = []
    sub_length = 1
    # cmp_func = lambda desc, x, y:  x < y if desc else x > y 
    cmp_func = lambda desc, x, y:  desc if x < y else x > y
    for i, value in enumerate(array_list):
        if not sub_array:
            sub_array.append(value)
            continue
        if cmp_func(desc, value, sub_array[-1]):
            sub_array.append(value)
        else:
            sub_length = len(sub_array)
            if len(ret) < len(sub_array):
                ret = copy.copy(sub_array)
            if sub_length > len(array_list) - (i+1):
                break
            del sub_array
            sub_array = []

    return ret


def main():
    print get_longest_continuous_subsquence([1, 3, 5, 4, 7])
    print len(get_longest_continuous_subsquence([1, 3, 5, 4, 7]))
    print len(get_longest_continuous_subsquence([1, 3, 5, 4, 7], True))
    print len(get_longest_continuous_subsquence([2, 2, 2, 2, 2]))


if __name__ == "__main__":
    main()