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
        print("name:{0}, password:{1}".format(self._name, self._pwd))


def save_info(user):
    pass


user_list = []
input_str = ""


def add_user(name, pwd):
    global user_list
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
    print("*" * 20)
    input_str = raw_input("input your choose:")

while True:
    menu()
    if input_str == 'q':
        print("bye")
        break
    elif input_str == 'a':
        name = raw_input("input your name:")
        pwd = raw_input("input your password:")
        add_user(name, pwd)
    elif input_str == 'p':
        print_all_user()
    else:
        print("input is no valid.")
