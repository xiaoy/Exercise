# this program is used for exercise
# just finish a guess number game
import random

guessNumber = random.randint(0, 100)
while True:
    inputNuber = input("please input a number between 0 ~ 100:")
    if inputNuber < guessNumber:
        print("you input number is small")
    elif inputNuber > guessNumber:
        print("you input number is too big")
    else:
        print("you are right, clever")
        break
