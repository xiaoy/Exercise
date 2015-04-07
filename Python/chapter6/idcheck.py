# this program is used to check python identify

import string
import keyword

alphas = string.letters + '_'
digits = string.digits
keys = keyword.kwlist

input_word = raw_input("input a variable:")

# check length
if len(input_word) < 2:
    print 'the input word should be longer 1.'
else:
    # check first character
    first_ch = input_word[0]
    if first_ch not in alphas:
        print 'the first variable must be a alphas.'
    else:
        # check key word
        ret = True
        for key in keys:
            if key == input_word:
                print 'key word can not be a variable.'
                ret = False
                break

        # check other char
        if ret:
            all_str = alphas + digits
            for ch in input_word:
                if ch not in all_str:
                    print 'can not include special char:', ch
                    ret = False
                    break

if ret:
    print 'the input word is ok'
