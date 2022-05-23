import json
import random
import time


def stats(count_all, count_right):
    percent = (count_right * 100) / count_all
    print("Правильных ответов - ", count_right, " из ", count_all, " вопросов")
    print("Итоговый процент - ", percent)


def check_if_exist(array, elem):
    array = list(array)
    for i in range(len(array)):
        if array[i] == elem:
            return True
    return False


def test_init():
    v = True
    w = 0
    while v:
        w = input("Для продолжения выберите тип тестa (1 - математический, 2 - тест по теме )...")
        if w == '1' or w == '2':
            v = False
    if w == '1':
        start_time = time.time_ns()
        ans = math_test(start_time)
        stats(ans[0], ans[1])
        return
    if w == '2':
        start_time = time.time_ns()
        ans = theme_test(start_time)
        stats(ans[0], ans[1])
        return


def math_test(start_time):
    cnt = [0, 0]
    while True:
        if time.time_ns() - start_time > 6 * 10 ** 10:
            print("Время вышло ")
            return cnt
        a = random.randint(1, 21)
        b = random.randint(1, 21)
        c = a + b
        print(a, " + ", b, " = ")
        ans = int(input("Введите правильный ответ... "))
        if ans == c:
            cnt[1] += 1
            cnt[0] += 1
        else:
            cnt[0] += 1


def theme_test(start_time):
    with open('data.json', 'r', encoding='utf8') as f:
        text = json.load(f)
    print(len(text))
    cnt = [0, 0]
    passed = []

    while True:
        for i in range(len(text)):
            if time.time_ns() - start_time > 6 * 10 ** 10:
                print("Время вышло ")
                return cnt

            if len(passed) >= len(text):
                return cnt

            print("Вопрос номер - ", i + 1)

            temp = random.randint(0, len(text) - 1)
            while check_if_exist(passed, temp):
                temp = random.randint(0, len(text) - 1)
            passed.append(temp)

            print(text[temp]['question'])
            print("Варианты ответа ")

            for j in range(len(text[temp]['answers'])):
                print(j + 1, ") ", text[temp]['answers'][j])

            ans = int(input("Введите номер правильного ответа... "))
            if ans == text[temp]['right_answer']:
                cnt[0] += 1
                cnt[1] += 1
            else:
                cnt[0] += 1
            print("")


test_init()
