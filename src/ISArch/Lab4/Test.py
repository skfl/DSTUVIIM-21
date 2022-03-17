import time

num_of_quest = 3
num_of_answ = 4
arr = [[0] * num_of_answ for i in range(num_of_quest)]
questions = ["Метод string.count", "Метод string.find возвращает ... если строка не найдена", "Метод string.center"]
right_answers = [1, 3, 3]

arr[0][0] = "возвращает первый индекс в s который соответствует началу строки"
arr[0][1] = "подсчитывает количество вхождений подстроки в строку"
arr[0][2] = "ищет в строке заданную подстроку, начиная с конца"
arr[0][3] = "определяет, начинается ли строка с заданной подстроки"

arr[1][0] = "0"
arr[1][1] = "True"
arr[1][2] = "False"
arr[1][3] = "-1"

arr[2][0] = "обрезает пробельные символы слева"
arr[2][1] = "заменяет вхождения подстроки в строке"
arr[2][2] = "удаляет символы с левого и правого края строки"
arr[2][3] = "выравнивает строку по центру"


def start_test():
    cnt = 0
    start = int(
        input(
            "Приветствуем на тесте по методам строк в Python! Для начала теста наберите в консоли 1. Для выхода -1  "))
    print("\n")
    if start == 1:
        start_time = time.time()
        for i in range(len(questions)):
            print("Вопрос номер ", i + 1, " : ", questions[i])
            for j in range(len(arr[i])):
                print(j + 1, ") ", arr[i][j])
            ans = int(input("Введите цифру под которой стоит правильный ответ...  "))
            if ans == right_answers[i]:
                cnt += 1
            print("\n")
        end_time = time.time()
        print("Количество правильных ответов : ", cnt, " Время на выполнение ", end_time - start_time, " сек")
    elif start == -1:
        return -1
    else:
        print("Неизвестная команда")


start_test()
