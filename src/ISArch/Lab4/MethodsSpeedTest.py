import time

C = "ad45ret y657768ut yt566"


def lib_split_time(input_string):
    input_string = str(input_string)
    input_string = input_string.strip()
    arr = input_string.split()

    return arr


def split_time(input_string):
    input_string = input_string.strip()
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
    return arr


def lib_endswith_time(input_string, end):
    input_string = str(input_string)
    end = str(end)
    v = input_string.endswith(end)
    return v


def endswith_time(input_string, end):
    input_string = str(input_string)
    end = str(end)
    len_end = len(end) - 1
    j = len(input_string) - 1
    for i in range(len_end, -1, -1):
        if end[i] == input_string[j]:
            j -= 1
            continue
        else:
            return False
    return True


start_time_split_lib = time.time_ns()
for i in range(1, 1000000):
    lib_split_time(C)
duration_time_split_lib = time.time_ns() - start_time_split_lib;

start_time_split_algo = time.time_ns()
for i in range(1, 1000000):
    split_time(C)
duration_time_split_algo = time.time_ns() - start_time_split_algo

print("Split algo duration ", duration_time_split_algo / 1000000000, " Split lib duration ",
      duration_time_split_lib / 1000000000, " difference : ",
      (duration_time_split_algo - duration_time_split_lib) / 1000000000)

start_time_endswith_lib = time.time_ns()
for i in range(1, 1000000):
    lib_endswith_time(C,"66")
duration_time_endswith_lib = time.time_ns() - start_time_endswith_lib

start_time_endswith_algo = time.time_ns()
for i in range(1, 1000000):
    endswith_time(C,"66")
duration_time_endswith_algo = time.time_ns() - start_time_endswith_algo

print("Endswith algo duration ", duration_time_endswith_algo / 1000000000, " Endswith lib duration ",
      duration_time_endswith_lib / 1000000000, " difference : ",
      (duration_time_endswith_algo - duration_time_endswith_lib) / 1000000000)
