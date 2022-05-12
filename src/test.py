import matplotlib.pyplot as plt
import random
import math


class Points:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def __eq__(self, other):
        if self.getX() == other.getX() and self.getY() == other.getY():
            return False
        return True

    def __repr__(self):
        return f"<|x={self.getX()},y={self.getY()}|>"


region_first = []

for i in range(-100, -50):
    if i % 2 == 1:
        continue
    for j in range(50, 100):
        if j % 2 == 1:
            continue
        region_first.append(Points(i, j))

random.shuffle(region_first)
print(region_first)

srez_1 = random.randint(100, 200)
region_first = region_first[:srez_1]
print(region_first)

region_second = []

for i in range(50, 100):
    if i % 2 == 1:
        continue
    for j in range(-50, 0):
        if j % 2 == 1:
            continue
        region_second.append(Points(i, j))

random.shuffle(region_second)
print(region_second)

srez_2 = random.randint(100, 200)
region_second = region_second[:srez_2]
print(region_second)


index_max = [0,0]
index_min = [0,0]

max_dist = 0
min_dist = math.sqrt(((region_first[0].getX() - region_second[0].getX()) ** 2) + (
        (region_first[0].getY() - region_second[0].getY()) ** 2))

for i in range(0, len(region_first)):
    for j in range(0, len(region_second)):
        next = math.sqrt(((region_first[i].getX() - region_second[j].getX()) ** 2) + (
                (region_first[i].getY() - region_second[j].getY()) ** 2))
        print(next)
        if next > max_dist:
            max_dist = next
            index_max = [i,j]

        if next < min_dist:
            min_dist = next
            index_min = [i,j]

def getMinMaxDist(arr):
    region = list(arr)
    max_dist = 0
    min_dist = math.sqrt((region[0].getX() - region[1].getX())**2 + (region[0].getY()-region[1].getY())**2)
    tmp = 0
    for i in range(0,len(region)):
        if i + 1 < len(region):
            for j in range(i + 1, len(region)):
                tmp = math.sqrt((region[i].getX() - region[j].getX())**2 + (region[i].getY()-region[j].getY())**2)
                if tmp > max_dist:
                    max_dist = tmp
                if tmp <= min_dist:
                    min_dist = tmp
    print("Max dist = ", max_dist)
    print("Min dist = ", min_dist)
















print()
print(max_dist)
print(min_dist)
getMinMaxDist(region_first)
getMinMaxDist(region_second)








fig, ax = plt.subplots()



for i in range(len(region_first)):
    ax.scatter(region_first[i].getX(),region_first[i].getY(),s=8,color="red")


for j in range(len(region_second)):
    ax.scatter(region_second[j].getX(),region_second[j].getY(),s=8,color="blue")

plt.plot([region_first[index_max[0]].getX(),region_first[index_max[0]].getY()],[region_second[index_max[1]].getX(),region_second[index_max[1]].getY()])
plt.plot([region_first[index_min[0]].getX(),region_first[index_min[0]].getY()],[region_second[index_min[1]].getX(),region_second[index_min[1]].getY()])






ax.spines['left'].set_position('center')
ax.spines['bottom'].set_position('center')
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)

ax.set_ylim(-110, 110)
ax.set_xlim(-110, 110)

ax.grid()
plt.show()

