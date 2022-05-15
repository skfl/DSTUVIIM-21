import numpy as np
import math
import random
import matplotlib.pyplot as plt

RADIUS = 10
n = 400
m = 400
k1 = 30
k2 = 20
t = 3

tetha = np.linspace(0, 2 * np.pi, 100)


def get_second_radius(radius, t):
    return radius + random.randint(1, t)


def check_if_exist(first_arr, second_arr, first_coord, second_coord):
    first_arr = list(first_arr)
    second_arr = list(second_arr)
    V = False
    for i in range(len(first_arr)):
        if first_arr[i] == first_coord and second_arr[i] == second_coord:
            V = True
            break
    return V


def get_av_x_coord(start, stop, step):
    av_x = []
    for i in range(start, stop, step):
        av_x.append(i)
    return av_x


def get_av_y_coor():
    av_y = []
    for i in range(40, 400):
        if i % 40 == 0:
            av_y.append(i)
    return av_y


def set_centre_coord(av_x, av_y, quantity):
    av_x = list(av_x)
    av_y = list(av_y)
    quantity = int(quantity)
    x = []
    y = []

    x.append(av_x[random.randint(0, len(av_x) - 1)])
    y.append(av_y[random.randint(0, len(av_y) - 1)])

    for i in range(1, quantity):
        tmp_x = av_x[random.randint(0, len(av_x) - 1)]
        tmp_y = av_y[random.randint(0, len(av_y) - 1)]
        while check_if_exist(x, y, tmp_x, tmp_y):
            tmp_x = av_x[random.randint(0, len(av_x) - 1)]
            tmp_y = av_y[random.randint(0, len(av_y) - 1)]
        x.append(tmp_x)
        y.append(tmp_y)
    return [x, y]


def check_for_crossing(first_x, first_y, second_x, second_y, first_rad, second_rad):
    first_x = list(first_x)
    first_y = list(first_y)
    second_x = list(second_x)
    second_y = list(second_y)
    second_rad = list(second_rad)
    first_index = []
    second_index = []
    cnt = 0
    for i in range(len(first_x)):
        for j in range(len(second_x)):
            if i == j:
                continue
            if first_y[i] == second_y[j]:
                if math.fabs(first_x[i] - second_x[j]) <= first_rad + second_rad[j]:
                    first_index.append(i)
                    second_index.append(j)
                    cnt += 1
    print("There are ", cnt, " crossing circles")
    return [first_index, second_index]


a = set_centre_coord(get_av_x_coord(40, 400, 40), get_av_y_coor(), k1)
b = set_centre_coord(get_av_x_coord(20, 400, 40), get_av_y_coor(), k2)
b_rad = []

fig, ax = plt.subplots()
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.set_ylim(0, m)
ax.set_xlim(0, n)
ax.grid()

################
# output circles
first_circle_x = a[0]
first_circle_y = a[1]
second_circle_x = b[0]
second_circle_y = b[1]
first_tmpx = []
first_tmpy = []
second_tmpx = []
second_tmpy = []

for i in range(len(a[0])):
    for j in range(100):
        first_tmpx.append(RADIUS * math.cos(tetha[j]) + first_circle_x[i])
        first_tmpy.append(RADIUS * math.sin(tetha[j]) + first_circle_y[i])
    plt.plot(first_tmpx, first_tmpy, color="red")
    first_tmpx = []
    first_tmpy = []

for i in range(len(b[0])):
    tmp_rad = get_second_radius(RADIUS, t)
    b_rad.append(tmp_rad)
    for j in range(100):
        second_tmpx.append(tmp_rad * math.cos(tetha[j]) + second_circle_x[i])
        second_tmpy.append(tmp_rad * math.sin(tetha[j]) + second_circle_y[i])
    plt.plot(second_tmpx, second_tmpy, color="blue")
    second_tmpx = []
    second_tmpy = []

c = check_for_crossing(first_circle_x, first_circle_y, second_circle_x, second_circle_y, RADIUS, b_rad)

plt.show()
