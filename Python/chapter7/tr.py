# this program is used to translate string


def tr(srcstr, dsstr, retstr):
    tr_dic = {}
    for i in range(len(srcstr)):
        if i == len(dsstr):
            break
        else:
            tr_dic[srcstr[i]] = dsstr[i]

    tempstr = ""
    for ch in retstr:
        if ch in tr_dic:
            tempstr += tr_dic[ch]
        else:
            tempstr += ch

    return tempstr


def tr2(srcstr, dsstr, retstr):
    tr_dic = {}
    for i in range(len(srcstr)):
        if i >= len(dsstr):
            tr_dic[srcstr[i]] = ""
        else:
            tr_dic[srcstr[i]] = dsstr[i]

    tempstr = ""
    for ch in retstr:
        if ch in tr_dic:
            tempstr += tr_dic[ch]
        else:
            tempstr += ch

    return tempstr

# test
print(tr("abc", "mno", "abcdef") == "mnodef")

print(tr2("abcdef", "mno", "abcdefghi") == "mnoghi")
