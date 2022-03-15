import math
import matplotlib.pyplot as plt
import numpy as np
import random


def check_if_exist(first_arr, second_arr, first_coord, second_coord):
    first_arr = list(first_arr)
    second_arr = list(second_arr)
    V = False
    for i in range(0, len(first_arr), 1):
        if first_arr[i] == first_coord and second_arr[i] == second_coord:
            V = True
            break
        else:
            V = False
    return V


def check_if_fits(x, y):
    x = int(x)
    y = int(y)
    V = False
    if x == 0:
        for i in range(-100, 101, 50):
            if y == i:
                V = True
                return V
    if y == 0:
        for i in range(-100, 101, 50):
            if x == i:
                V = True
                return V
    return V


def set_coord(left_border, right_border, bottom_border, upper_border, quantity):
    quantity = int(quantity)
    left_border = int(left_border)
    right_border = int(right_border)
    upper_border = int(upper_border)
    bottom_border = int(bottom_border)

    X = [1]
    Y = [1]
    X[0] = 0
    Y[0] = 0

    for i in range(quantity):
        x_c = random.randint(left_border, right_border)
        y_c = random.randint(bottom_border, upper_border)
        while check_if_fits(x_c, y_c) and check_if_exist(X, Y, X[i], Y[i]):
            x_c = random.randint(left_border, right_border)
            y_c = random.randint(bottom_border, upper_border)
        X.append(x_c)
        Y.append(y_c)
    print(Y)
    return X

print(set_coord(0,20,0,20,10))