# this program is used for manage user login info


class User:
    def __init__(self, name, pwd):
        self._name = name
        self._pwd = pwd

    def login(self, name, pwd):
        if name != self.name or pwd != self._pwd:
            print("login failed")
        else:
            print("login success")

    def info(self):
        print(self.tostring())

    def tostring(self):
        return "name:{0}, password:{1}\n".format(self._name, self._pwd)


def save_info():
    f = open("userinfo.txt", "wr")
    for u in user_list:
        str = u.tostring()
        f.write(str)
    f.close()


def load_info():
    global user_list
    user_list = []
    f = open("userinfo.txt")
    alllines = f.readlines()
    for line in alllines:
        infos = line.strip().split(',')
        name_info = infos[0].split(':')
        pwd_info = infos[1].split(':')
        name = name_info[1]
        pwd = pwd_info[1]
        user = User(name, pwd)
        user_list.append(user)
    f.close()

user_list = []
input_str = ""


def add_user():
    global user_list
    name = raw_input("input your name:")
    pwd = raw_input("input your password:")
    user = User(name, pwd)
    user_list.append(user)


def print_user(user):
    user.info()


def print_all_user():
    print("#" * 20)
    for u in user_list:
        print_user(u)
    print("#" * 20)


def menu():
    global input_str
    print("*" * 20)
    print("1.input key<q> to quit")
    print("2.input key<a> to add user")
    print("3.input key<p> to print user info")
    print("4.input key<s> to save user info")
    print("5.input key<l> to load user info")
    print("*" * 20)
    input_str = raw_input("input your choose:")

while True:
    menu()
    if input_str == 'q':
        print("bye")
        break
    elif input_str == 'a':
        add_user()
    elif input_str == 'p':
        print_all_user()
    elif input_str == 's':
        save_info()
    elif input_str == 'l':
        load_info()
    else:
        print("input is no valid.")
