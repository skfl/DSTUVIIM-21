import math  
import matplotlib.pyplot as plt
import random


def check_if_exist(first_arr, second_arr, first_coord, second_coord):
    first_arr = list(first_arr)
    second_arr = list(second_arr)
    V = False
    for i in range(len(first_arr)):
        if first_arr[i] == first_coord and second_arr[i] == second_coord:
            V = True
            break
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


def get_even_coord(start, stop):
    start = int(start)
    stop = int(stop)
    num = random.randint(start, stop)
    if num % 2 != 0:
        while num % 2 != 0:
            num = random.randint(start, stop)
    return num


def set_coord(left_border, right_border, bottom_border, upper_border, quantity):
    quantity = int(quantity)
    left_border = int(left_border)
    right_border = int(right_border)
    upper_border = int(upper_border)
    bottom_border = int(bottom_border)

    X = []
    Y = []
    x_1 = random.randint(left_border, right_border)
    y_1 = random.randint(bottom_border, upper_border)
    X.append(x_1)
    Y.append(y_1)

    while check_if_fits(x_1, y_1) or check_if_exist(X, Y, x_1, y_1):
        x_1 = get_even_coord(left_border, right_border)
        y_1 = get_even_coord(bottom_border, upper_border)
    X[0] = x_1
    Y[0] = y_1

    for i in range(1, quantity - 1):
        x_c = get_even_coord(left_border, right_border)
        y_c = get_even_coord(bottom_border, upper_border)
        while check_if_exist(X, Y, x_c, y_c) or check_if_fits(x_c, y_c):
            x_c = get_even_coord(left_border, right_border)
            y_c = get_even_coord(bottom_border, upper_border)
        X.append(x_c)
        Y.append(y_c)

    return [X, Y]


def get_min_max_dist(X, Y):
    X = list(X)
    Y = list(Y)
    max_dist = 0
    min_dist = math.sqrt((X[0] - X[1]) ** 2 + (Y[0] - Y[1]) ** 2)
    tmp = 0
    for i in range(0, len(X)):
        if i + 1 < len(X):
            for j in range(i + 1, len(X)):
                tmp = math.sqrt((X[i] - X[j]) ** 2 + (Y[i] - Y[j]) ** 2)
                if tmp > max_dist:
                    max_dist = tmp
                if tmp <= min_dist:
                    min_dist = tmp
    print("Max dist = ", max_dist)
    print("Min dist = ", min_dist)


# main
coords_first = set_coord(0, 50, 0, 50, 100)
coords_second = set_coord(-100, -50, -100, -50, 100)
print("Min/Max distance for 1st area: ")
get_min_max_dist(coords_first[0], coords_first[1])
print("Min/Max distance for 2nd area: ")
get_min_max_dist(coords_second[0], coords_second[1])
#


# output graph
fig, ax = plt.subplots()
plt.scatter(coords_first[0], coords_first[1])
plt.scatter(coords_second[0], coords_second[1])

ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('center')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

ax.set_ylim(-110, 110)
ax.set_xlim(-110, 110)
ax.grid()
plt.show()
#
