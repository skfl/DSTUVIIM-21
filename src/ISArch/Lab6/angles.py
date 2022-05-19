import time
import math
import numpy as np
import matplotlib.pyplot as plt

n = 530
m = 200

fig, ax = plt.subplots()
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.set_ylim(0, m)
ax.set_xlim(0, n)
ax.grid()


def l(num, n):
    if num > 6 or num < 0:
        print("l(n), n can not be more than 6 or less than zero")
        return
    if num == 0:
        print("l(n), n can not be equal to zero")
        return
    res = 0
    for i in range(num):
        res = 65
    return res


def f(num, n):
    if num > 6 or num < 0:
        print("f(n), n can not be more than 6 or less than zero")
        return
    if num == 0:
        print("f(n), n can not be equal to 0")
        return
    res = 0
    for i in range(num):
        res += 80
    return res


def get_tan(a, b):
    return a / b


def find_pos(l, f, n, m):
    nl = n - l
    nf = n - f
    df = 0
    res = 0
    stop = 0
    res2 = 0
    j = 0
    for i in range(1, m * 10, 1):
        j = i / 10
        tmp1 = get_tan(nl, j)
        df = tmp1 * (m - j)
        if df <= nf:
            res = j
            stop = i
            break
    for k in range(stop, m * 10, 1):
        j = k / 10
        tmp1 = get_tan(nl, j)
        df = tmp1 * (m - j)
        if df <= nf - 50:
            res2 = j
            break
    return res


def get_wall_length():
    first = find_pos(l(1, n), f(2, n), n, m)
    second = find_pos(l(1, n), f(2, n) + 50, n, m)
    return second - first


def get_angle_range():
    cat = l(1, n)
    a = find_pos(l(1, n), f(2, n), n, m)
    b = find_pos(l(1, n), f(2, n) + 50, n, m)
    first_tan = a / (n - cat)
    second_tan = b / (n - cat)
    return math.atan(second_tan) - math.atan(first_tan)


print("Wall length = ", get_wall_length())
a = find_pos(l(1, n), f(2, n), n, m)
b = find_pos(l(1, n), f(2, n) + 50, n, m)
print("Angle range is ", get_angle_range())
plt.scatter(n, b, color="blue")
plt.scatter(n, a, color="blue")

plt.scatter(l(1, n), 0, color="blue")

plt.scatter(f(2, n), m, color="blue")
plt.scatter(f(2, n) + 50, m, color="blue")

plt.plot([0, n], [a, a], linestyle="--", color="lime")
plt.plot([0, n], [b, b], linestyle="--", color="lime")

plt.plot([l(1, n), n], [0, a], color="blue")
plt.plot([n, f(2, n)], [a, m], color="blue")

plt.plot([l(1, n), n], [0, b], color="blue")
plt.plot([n, f(2, n) + 50], [b, m], color="blue")

plt.show()
