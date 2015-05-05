# this program is used to instantiate a dollar


class Dollarize:
    def __init__(self, var):
        self.var = var

    def __str__(self):
        dstr = str(self.var)
        strarr = dstr.split('.')
        if len(strarr) == 2:
            istr = strarr[0]
            fstr = strarr[1]
        else:
            istr = strarr[0]
            fstr = '00'

        istr = self.setup_comma(istr)
        ret = '$' + istr + '.' + fstr

        return ret

    def setup_comma(self, info):
        i = 0
        ret = ""
        info = info[::-1]
        for ch in info:
            if i == 3 and len(info) > 3:
                ret += ','
                i = 0
            ret += ch
            i += 1
        ret = ret[::-1]
        return ret

    def upate(self, var):
        self.var = var

    def __nonzero__(self):
        return self.var == 0


def main():
    d = Dollarize(12.22)
    print d

    d.upate(12)
    print d

    d.upate(1222222.22)
    print d


if __name__ == "__main__":
    main()
