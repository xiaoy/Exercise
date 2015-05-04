# this program is used to test class


class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y
        print(self)

    def foo(self):
        print "this is point foo"


class Point3d(Point):
    def __init__(self, x=0, y=0, z=0):
        Point.__init__(self, x, y)
        self.z = z


class Player:
    @staticmethod
    def log():
        print("this is a static function")


class User:
    @classmethod
    def log(cls):
        print("this is a class function", cls.__name__)


def main():
    p = Point()
    print p.x, p.y

    p = Point(12, 22)
    print p.x, p.y

    Player.log()

    p = Player()
    p.log()

    User.log()

    print Point.__dict__

    p = Point3d(10, 20, 30)
    print p.x, p.y, p.z

    p.foo()

if __name__ == "__main__":
    main()
