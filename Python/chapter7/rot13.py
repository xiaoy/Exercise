# this program use to encrypt or decrypt by rot 13
import string

max_len = 13


def get_ch(instr, ch):
    if ch in instr:
        index = instr.index(ch)
        if index >= max_len:
            return instr[index - max_len]
        else:
            return instr[index + max_len]

    return ch


def encrypt(input_str):
    output_str = ""
    for ch in input_str:
        if ch in string.lowercase:
            output_str += get_ch(string.lowercase, ch)
        elif ch in string.uppercase:
            output_str += get_ch(string.uppercase, ch)
        else:
            output_str += ch

    return output_str


# test
in_str = raw_input("input a string:")
print("the encrypt/decrypt is:", encrypt(in_str))
in_str = raw_input("input a string:")
print("the encrypt/decrypt is:", encrypt(in_str))
