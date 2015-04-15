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

    def get_name(self):
        return self._name

    def get_pwd(self):
        return self._pwd

    def tostring(self):
        return "name:{0}, password:{1}\n".format(self._name, self._pwd)

user_list = []
input_str = ""


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


def login_in():
    name = raw_input("name:")
    pwd = raw_input("password:")

    islogin = False
    for u in user_list:
        if u.get_name() == name and u.get_pwd() == pwd:
            print("login success")
            islogin = True
            break

    if not islogin:
        print("login fail")


def is_user_exsit(name):
    for u in user_list:
        if u.get_name() == name:
            return True
    return False


def add_user():
    global user_list
    name = raw_input("input your name:")
    pwd = raw_input("input your password:")
    if is_user_exsit(name):
        print("the user:{0} has exist".format(name))
        return
    else:
        user = User(name, pwd)
        user_list.append(user)


def get_user_index(name):
    index = 0
    for u in user_list:
        if u.get_name() == name:
            break
        else:
            index += 1

    return index


def del_user():
    name = raw_input("input your del user name:")
    if is_user_exsit(name):
        index = get_user_index(name)
        del user_list[index]
        print("del user:{0} success".format(name))
    else:
        print("the user:{0} is not exist".format(name))


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
    print("5.input key<l> to login system")
    print("6.input key<d> to del user info")
    print("*" * 20)
    input_str = raw_input("input your choose:")

load_info()
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
        login_in()
    elif input_str == 'd':
        del_user()
    else:
        print("input command is no valid.")
