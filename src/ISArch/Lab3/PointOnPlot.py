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


def shift_by(arr, num):
    arr = list(arr)
    for i in range(len(arr)):
        arr[i] -= num
    return arr


def count_common_points(x_first, y_first, x_second, y_second):
    x_first = list(x_first)
    y_first = list(y_first)
    x_second = list(x_second)
    y_second = list(y_second)
    coords_x = []
    coords_y = []
    for i in range(len(x_first)):
        if check_if_exist(x_first, y_first, x_second[i], y_second[i]):
            coords_x.append(x_second[i])
            coords_y.append(y_second[i])
    print("Number of common dots = ", len(coords_x))
    return [coords_x, coords_y]


def shift_back(arr, num):
    arr = list(arr)
    for i in range(len(arr)):
        arr[i] += num
    return arr


######
# main
coords_first = set_coord(0, 50, 0, 50, 100)
coords_second = set_coord(-100, -50, -100, -50, 100)

print("Min/Max distance for 1st area : ")
get_min_max_dist(coords_first[0], coords_first[1])
print("\n")
print("Min/Max distance for 2nd area : ")
get_min_max_dist(coords_second[0], coords_second[1])
print("\n")

shifted_x_first = shift_by(coords_first[0], 100)
shifted_y_second = shift_by(coords_second[1], -100)
common_coords = count_common_points(shifted_x_first, coords_first[1], coords_second[0], shifted_y_second)
print("\n")
common_x_in_first_area = shift_back(common_coords[0], 100)
common_y_in_first_area = common_coords[1]

common_x_in_second_area = common_coords[0]
common_y_in_second_area = shift_back(common_coords[1], -100)

print("Min/Max distance for common dots :")
get_min_max_dist(common_x_in_first_area, common_y_in_first_area)
print("\n")

#####


# output graph
fig, ax = plt.subplots()
plt.scatter(coords_first[0], coords_first[1], s=4, color="red")
plt.scatter(coords_second[0], coords_second[1], s=4, color="blue")
# plt.scatter(shifted_x_first, coords_first[1])
# plt.scatter(coords_second[0], shifted_y_second)
plt.scatter(common_x_in_first_area, common_y_in_first_area, s=4, color="black")
plt.scatter(common_x_in_second_area, common_y_in_second_area, s=4, color="black")

ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('center')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

ax.set_ylim(-110, 110)
ax.set_xlim(-110, 110)
ax.grid()
plt.show()
##############
