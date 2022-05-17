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

fig, ax = plt.subplots()
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.set_ylim(0, m)
ax.set_xlim(0, n)
ax.grid()


def draw_circle(x, y, rad, color):
    tetha = np.linspace(0, 2 * np.pi, 100)
    color = str(color)
    tmp_x = []
    tmp_y = []
    for i in range(100):
        tmp_x.append(rad * math.cos(tetha[i]) + x)
        tmp_y.append(rad * math.sin(tetha[i]) + y)
    plt.plot(tmp_x, tmp_y, color=color)


def get_second_radius(radius, t):
    return radius + random.randint(1, t)


def check_if_exist(first_arr, second_arr, first_coord, second_coord):
    first_arr = list(first_arr)
    second_arr = list(second_arr)
    v = False
    for i in range(len(first_arr)):
        if first_arr[i] == first_coord and second_arr[i] == second_coord:
            v = True
            break
    return v


def get_av_x_coord(start, stop, step):
    av_x = []
    for i in range(start, stop, step):
        av_x.append(i)
    return av_x


def get_av_y_coord():
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


def check_for_crossing_by_coord(first_x, first_y, second_x, second_y, first_rad, second_rad):
    v = False
    if first_y == second_y:
        if math.fabs(first_x - second_x) <= first_rad + second_rad:
            v = True
            return v
    return v


def color_intersection(first_x, first_y, second_x, second_y, first_rad, second_rad):
    first_x = list(first_x)
    first_y = list(first_y)
    second_x = list(second_x)
    second_y = list(second_y)
    second_rad = list(second_rad)
    for i in range(len(first_x)):
        for j in range(len(second_x)):
            if first_y[i] == second_y[j]:
                if math.fabs(first_x[i] - second_x[j]) <= first_rad + second_rad[j]:
                    draw_circle(first_x[i], first_y[i], first_rad, "black")
                    draw_circle(second_x[j], second_y[j], second_rad[j], "black")


def get_square_for_intersection(x1, y1, r1, x2, y2, r2):
    distance = math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
    f1 = 2 * math.acos((r1 * r1 - r2 * r2 + distance * distance) / (2 * r1 * distance))
    f2 = 2 * math.acos((r2 * r2 - r1 * r1 + distance * distance) / (2 * r2 * distance))
    s1 = (r1 * r1 * (f1 - math.sin(f1))) / 2
    s2 = (r2 * r2 * (f2 - math.sin(f2))) / 2
    return s1 + s2


a = set_centre_coord(get_av_x_coord(40, n, 40), get_av_y_coord(), k1)
b = set_centre_coord(get_av_x_coord(20, n, 40), get_av_y_coord(), k2)
b_rad = []
for i in range(len(b[0])):
    b_rad.append(get_second_radius(RADIUS, t))

for i in range(len(a[0])):
    draw_circle(a[0][i], a[1][i], RADIUS, "red")

for i in range(len(b[0])):
    draw_circle(b[0][i], b[1][i], b_rad[i], "blue")

color_intersection(a[0], a[1], b[0], b[1], RADIUS, b_rad)

f = 0
max1 = 0
max2 = 0
max_index = np.zeros(6)
for i in range(len(a[0])):
    for j in range(len(b[0])):
        v = check_for_crossing_by_coord(a[0][i], a[1][i], b[0][j], b[1][j], RADIUS, b_rad[j])
        if v:
            f += 1
            tmp = get_square_for_intersection(a[0][i], a[1][i], RADIUS, b[0][j], b[1][j], b_rad[j])
            if f == 1:
                max1 = tmp
                continue
            if tmp > max1:
                max1 = tmp
                max_index[0] = a[1][i]
                max_index[1] = a[0][i]
                max_index[2] = b[0][j]
                continue
            if max2 < tmp <= max1:
                max2 = tmp
                max_index[3] = a[1][i]
                max_index[4] = a[0][i]
                max_index[5] = b[0][j]

print(max1, " - biggest square of intersection")
print(max2, " - second biggest square of intersection")
ax.hlines(max_index[0], max_index[1], max_index[2], color="yellow")
ax.hlines(max_index[3], max_index[4], max_index[5], color="yellow")
print("There are ", f, " intersections")
plt.show()
