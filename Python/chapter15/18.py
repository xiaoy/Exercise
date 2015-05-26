# use this program to verify the time
import re
from time import ctime

re_str = r".+::(\d+)"
f = open("data.txt", 'r')
for line in f:
    obj_arr = re.split('::', line)
    head_time_str = obj_arr[0]
    obj_len = len(obj_arr)
    re_obj = re.match(re_str, line)
    tail_time = int(re_obj.group(1))
    tail_time_str = ctime(tail_time)

    if tail_time_str != head_time_str:
        print("the generator data is wrong")

f.close()
