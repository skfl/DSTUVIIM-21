import time

C = "ad45ret y657768ut yt566"


def lib_split_time(input_string):
    input_string = str(input_string)
    input_string = input_string.strip()
    start_time = time.time_ns()
    arr = input_string.split()
    end_time = time.time_ns()
    duration = end_time - start_time
    print("Функция split(lib). Время на выполнение : ", duration, " мс")
    return arr


def split_time(input_string):
    input_string = input_string.strip()
    start_time = time.time_ns()
    arr = []
    first_point = 0
    second_point = 0
    for i in range(len(input_string)):
        if input_string[i] != " ":
            second_point += 1
        elif input_string[i] == " ":
            arr.append(input_string[first_point:second_point + 1])
            first_point = second_point + 1
    arr.append(input_string[first_point:len(input_string)])
    end_time = time.time_ns()
    duration = end_time - start_time
    print("Функция split(algo). Время на выполнение : ", duration, " мс")
    return arr


def lib_endswith_time(input_string, end):
    input_string = str(input_string)
    end = str(end)
    start_time = time.time_ns()
    v = input_string.endswith(end)
    end_time = time.time_ns()
    duration = end_time - start_time
    print("Функция endswith(lib).Время на выполнение : ", duration, " мс")
    return v


def endswith_time(input_string, end):
    input_string = str(input_string)
    end = str(end)
    start_time = time.time_ns()
    len_end = len(end) - 1
    j = len(input_string) - 1
    for i in range(len_end, -1, -1):
        if end[i] == input_string[j]:
            j -= 1
            continue
        else:
            end_time = time.time_ns()
            duration = end_time - start_time
            print("Функция endswith(algo).Время на выполнение : ", duration, " мс")
            return False
    end_time = time.time_ns()
    duration = end_time - start_time
    print("Функция endswith(algo).Время на выполнение : ", duration, " мс")
    return True


print(lib_split_time(C))
print(split_time(C))
print(lib_endswith_time(C, "566"))
print(endswith_time(C, "566"))
