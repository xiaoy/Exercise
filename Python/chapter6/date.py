# simple date test
leap_days_list = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
days_list = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
split_char = '/'

def is_leap_year(year):
    if year % 4 == 0:
        if year % 100 == 0 and year % 400 != 0:
            return False
        return True
    else:
        return False

def get_year_day(year):
    sum_day = 0
    if is_leap_year(year):
        for d in leap_days_list:
            sum_day += d
    else:
        for d in days_list:
            sum_day += d

    return sum_day

def get_month_day(year, month):
    if is_leap_year(year):
        return leap_days_list[month]
    else:
        return days_list[month]


def get_days(d1, d2):
    d1_list = d1.split(split_char)
    d2_list = d2.split(split_char)

    y1, y2 = int(d1_list[0]), int(d2_list[0])
    m1, m2 = int(d1_list[1]) - 1, int(d2_list[1]) - 1
    d1, d2 = int(d1_list[2]), int(d2_list[2])

    sum_day = 0
    for y in range(y1, y2):
        sum_day += get_year_day(y)

    if y1 == y2:
        for md in range(m1, m2):
            sum_day += get_month_day(y1, md)

        for md in range(m1):
            sum_day -= get_month_day(y1, md)

    if y1 != y2:
        for md in range(0, m1):
            sum_day -= get_month_day(y1, md)

        for md in range(0, m2):
            sum_day += get_month_day(y2, md)

    sum_day -= d1
    sum_day += d2

    return sum_day





# test get day
print get_days('2003/1/5', '2003/2/5')
print get_days('2003/2/9', '2015/4/9')
