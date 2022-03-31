f = open("v1.txt", "r")
a = f.readlines()
tmp = []
toInt = []
firstGroup = []
secondGroup = []
thirdGroup = []
for i in range (len(a)):
    toInt = a[i].split(" ")
    for j in range(len(toInt)):
        tmp.append(int(toInt[j]))
sum = 0

for i in range(0,len(tmp),3):
    sum = tmp[i]+tmp[i+1]+tmp[i+2]

    if(sum%2==0):
        firstGroup.append(tmp[i])
        firstGroup.append(tmp[i+1])
        firstGroup.append(tmp[i+2])
    else:
        secondGroup.append(tmp[i])
        secondGroup.append(tmp[i+1])
        secondGroup.append(tmp[i+2])
    sum = 0

maxSum = firstGroup[0]+firstGroup[1]+firstGroup[2]
maxIndex1 = 0
maxIndex2 = 1
maxIndex3 = 2
for i in range(3,len(firstGroup),3):
    sum = firstGroup[i]+firstGroup[i+1]+firstGroup[i+2]
    if sum>maxSum:
        maxSum = sum;
        maxIndex1 = i
        maxIndex2 = i+1
        maxIndex3 = i+2
    sum = 0
thirdGroup.append(firstGroup[maxIndex1])
thirdGroup.append(firstGroup[maxIndex2])
thirdGroup.append(firstGroup[maxIndex3])

maxSum = secondGroup[0]+secondGroup[1]+secondGroup[2]
maxIndex1 = 0
maxIndex2 = 1
maxIndex3 = 2

for i in range(3,len(secondGroup),3):
    sum = secondGroup[i]+secondGroup[i+1]+secondGroup[i+2]
    if sum>maxSum:
        maxSum = sum;
        maxIndex1 = i
        maxIndex2 = i+1
        maxIndex3 = i+2
    sum = 0
thirdGroup.append(secondGroup[maxIndex1])
thirdGroup.append(secondGroup[maxIndex2])
thirdGroup.append(secondGroup[maxIndex3])


print(secondGroup)
print(firstGroup)
print(thirdGroup)