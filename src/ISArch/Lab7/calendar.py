import datetime


def out_red(text):
    print("\033[31m{}".format(text))


def out_yellow(text):
    print("\033[33m{}".format(text), end="")


def out_blue(text):
    print("\033[34m{}".format(text), end=" ")


def get_year(year):
    date = datetime.date.toordinal(datetime.date.today())
    if int(datetime.date.fromordinal(date).strftime("%Y")) < year:
        while int(datetime.date.fromordinal(date).strftime("%Y")) < year:
            date += 1
        return date
    if int(datetime.date.fromordinal(date).strftime("%Y")) > year:
        while int(datetime.date.fromordinal(date).strftime("%Y")) > year:
            date -= 1
        while datetime.date.fromordinal(date).strftime("%j") != "001":
            date -= 1
        return date
    if int(datetime.date.fromordinal(date).strftime("%Y")) == year:
        while datetime.date.fromordinal(date).strftime("%j") != "001":
            date -= 1
    return date


def get_month(year, month):
    date = get_year(year)
    month_list = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
    month = month_list[month - 1]
    while datetime.date.fromordinal(date).strftime("%b") != month:
        date += 1
    return date


def print_month(year, month):
    date = get_month(year, month)
    current_month = datetime.date.fromordinal(date).strftime("%B")
    days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

    out_red(datetime.date.fromordinal(date).strftime("%Y"))
    out_red(datetime.date.fromordinal(date).strftime("%B"))
    for i in range(len(days)):
        string = str(days[i])
        out_blue(string)
    print('')
    while datetime.date.fromordinal(date).strftime("%B") == current_month:
        res = ''
        cnt = 1
        for i in range(len(days)):
            if datetime.date.fromordinal(date).strftime("%a") != days[i]:
                cnt += 4
            else:
                res = ''.join([res, ' ' * cnt, datetime.date.fromordinal(date).strftime("%d")])
                date += 1
                break
        while datetime.date.fromordinal(date).strftime("%a") != 'Mon':
            res = ''.join([res, ' ' * 2, datetime.date.fromordinal(date).strftime("%d")])
            date += 1
        out_yellow(res)
        print("")


def print_month_new(year, start_month, stop_month, start_date, stop_date):
    date = get_month(year, start_month)
    stop_date = stop_date + 1
    while datetime.date.fromordinal(date).strftime("%d") != str(start_date):  # default str_date = 1
        date += 1
    current_month = datetime.date.fromordinal(date).strftime("%B")
    days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

    out_red(datetime.date.fromordinal(date).strftime("%Y"))
    out_red(datetime.date.fromordinal(date).strftime("%B"))
    for i in range(len(days)):
        string = str(days[i])
        out_blue(string)
    print('')

    while datetime.date.fromordinal(date).strftime("%B") == current_month:
        res = ''
        cnt = 1
        for i in range(len(days)):
            if datetime.date.fromordinal(date).strftime("%a") != days[i]:
                cnt += 4
            else:
                res = ''.join([res, ' ' * cnt, datetime.date.fromordinal(date).strftime("%d")])
                date += 1
                break
        while datetime.date.fromordinal(date).strftime("%a") != 'Mon':
            res = ''.join([res, ' ' * 2, datetime.date.fromordinal(date).strftime("%d")])
            date += 1
        out_yellow(res)
        print("")

    while start_month != stop_month - 1:
        start_month += 1
        print_month(year, start_month)

    date = get_month(year, stop_month)
    out_red(datetime.date.fromordinal(date).strftime("%Y"))
    out_red(datetime.date.fromordinal(date).strftime("%B"))
    for i in range(len(days)):
        string = str(days[i])
        out_blue(string)
    print('')
    while datetime.date.fromordinal(date).strftime("%d") != str(stop_date):
        res = ''
        cnt = 1
        for i in range(len(days)):
            if datetime.date.fromordinal(date).strftime("%a") != days[i]:
                cnt += 4
            else:
                res = ''.join([res, ' ' * cnt, datetime.date.fromordinal(date).strftime("%d")])
                date += 1
                break
        while datetime.date.fromordinal(date).strftime("%a") != 'Mon' and datetime.date.fromordinal(date).strftime(
                "%d") != str(stop_date):
            res = ''.join([res, ' ' * 2, datetime.date.fromordinal(date).strftime("%d")])
            date += 1
        out_yellow(res)
        print("")


def task1(n):
    if n < 11:
        month = n % 10 + 1
        print_month(2022, month)
    if n > 10:
        month = n % 10
        print_month(2023, month)


def task2(n):
    quarter = n % 4 + 1
    month = 1
    for i in range(quarter - 1):
        if quarter == 1:
            break
        month += 3

    for i in range(3):
        print_month(2022, month)
        month += 1


def task3(m1, m2, a, b, g):
    print_month_new(g, m1, m2, a, b)


print_month(2024,2)
# task2(4)
# task3(2, 7, 10, 22, 2020)
