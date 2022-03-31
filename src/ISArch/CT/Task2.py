f = open("T1.txt", "r")
a = f.readlines()
tmp = []
toInt = 0
for i in range(len(a)):
    toInt = int(a[i])
    tmp.append(toInt)

cnt1 = 0
maxSum1 = 0
for i in range(len(tmp)):
    if (tmp[i] % 2 == 0):
        for j in range(0, len(tmp), 1):
            if (i == j):
                continue
            if ((tmp[j] % 2 != 0) and (cnt1 == 0)):
                sum = tmp[i] + tmp[j]
                maxSum1 = sum
            if ((tmp[j] % 2 != 0) and (cnt1 != 0)):
                sum = tmp[i] + tmp[j]
                if (maxSum1 < sum):
                    maxSum1 = sum
            for k in range(len(tmp)):
                if (tmp[k] == sum):
                    cnt1 += 1
cnt1 -= 1
cnt1 = cnt1 / 2

sum = 0
maxSum2 = 0
cnt2 = 0

for i in range(len(tmp)):
    if (tmp[i] % 2 != 0):
        for j in range(0, len(tmp), 1):
            if (i == j):
                continue
            if ((tmp[j] % 2 == 0) and (cnt2 == 0)):
                sum = tmp[i] + tmp[j]
                maxSum2 = sum
            if ((tmp[j] % 2 == 0) and (cnt2 != 0)):
                sum = tmp[i] + tmp[j]
                if (maxSum2 < sum):
                    maxSum2 = sum
            for k in range(len(tmp)):
                if (tmp[k] == sum):
                    cnt2 += 1
cnt2 = cnt2 / 2
print(cnt1)
print(cnt2)
print(cnt1 + cnt2, " количество пар")
print(maxSum1, " максимальная сумма пары")
