# testing data
a = 140
b = 79

a1 = 675
b1 = 846

a2 = 357
b2 = 231

a3 = 228
b3 = 183


def evklid_algo(firstNum, secondNum):
    a = int(firstNum)
    b = int(secondNum)

    while True:
        if (get_max(a, b) == 0):
            tmp = a / b
            if (tmp.is_integer()):
                if (get_max(a, b) == 0):
                    return b
            else:
                a = a % b
        elif (get_max(a, b) == 1):
            tmp = b / a
            if (tmp.is_integer()):
                if (get_max(a, b) == 1):
                    return a
            else:
                b = b % a
        else:
            return a


def get_max(firstNum, secondNum):
    a = int(firstNum)
    b = int(secondNum)

    if (a > b):
        return 0
    elif (a == b):
        return 2
    else:
        return 1


def get_scm(firstNum, secondNum):
    a = int(firstNum)
    b = int(secondNum)

    return (a * b) / (evklid_algo(a, b))


def evklid_algo2(firstNum, secondNum):
    a = int(firstNum)
    b = int(secondNum)
    while (a != b):
        if (a > b):
            a -= b
        else:
            b -= a
    return a


def evklid_algo_2_output(firstNum, secondNum):
    a = int(firstNum)
    b = int(secondNum)
    tmp = evklid_algo(a, b) - 1
    while tmp != 0:
        if a % tmp == 0 and b % tmp == 0:
            return tmp
        else:
            tmp -= 1
    return 1


def get_max_dividers(num):
    a = int(num)
    res = a - 1
    cnt = 0
    output = []
    while cnt < 2:
        if a % res == 0:
            output.append(res)
            res-=1
            cnt+=1
        res-=1
    return output


print("First evklid algo result is :")
print(evklid_algo(a, b), " for numbers ", a, " ", b)
print(evklid_algo(a1, b1), " for numbers ", a1, " ", b1)
print(evklid_algo(a2, b2), " for numbers ", a3, " ", b2)
print(evklid_algo(a3, b3), " for numbers ", a3, " ", b3)
print("\n")
print("Second evklid algo result is :")
print(evklid_algo2(a, b), " for numbers ", a, " ", b)
print(evklid_algo2(a1, b1), " for numbers ", a1, " ", b1)
print(evklid_algo2(a2, b2), " for numbers ", a2, " ", b2)
print(evklid_algo2(a3, b3), " for numbers ", a3, " ", b3)
print("\n")
print("The smallest common multiple")
print(get_scm(a, b), " for numbers ", a, " ", b)
print(get_scm(a1, b1), " for numbers ", a1, " ", b1)
print(get_scm(a2, b2), " for numbers ", a2, " ", b2)
print(get_scm(a3, b3), " for numbers ", a3, " ", b3)
print("\n")
print("Two biggest divider algo :")
print(evklid_algo(a1, b1), evklid_algo_2_output(a1, b1), " for numbers", a1, " and ", b1)
print(evklid_algo(a2, b2), evklid_algo_2_output(a2, b2), " for numbers", a2, " and ", b2)
print(evklid_algo(a3, b3), evklid_algo_2_output(a3, b3), " for numbers", a3, " and ", b3)
print(evklid_algo(a, b), evklid_algo_2_output(a, b), " for numbers", a, " and ", b)
print("\n")
print("Max dividers :")
print(get_max_dividers(375)," for 375")