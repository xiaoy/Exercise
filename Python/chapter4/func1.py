#this program use to exercise

import random

def compare(a, b):
    return a - b

def score(times):
    print("You have guess times:", times)
    if times == 1:
        print("You can to buy a stock.")
    elif times <= 5:
        print("You have talent to learn math.")
    else:
        print("You need to exercise more time.")

guessNumber = random.randint(0, 100)
guessTimes = 0

while(True):
    inputNumber = input("Guess a number between (0~100):")
    guessTimes = guessTimes + 1
    if compare(inputNumber, guessNumber) > 0:
        print("Your input number is too bigger.")
    elif compare(inputNumber, guessNumber) < 0:
        print("Your input number is too small.")
    else:
        print("You get right number, congratulation.")
        break

score(guessTimes)
