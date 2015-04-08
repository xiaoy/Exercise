# this is a Rochambeau game
import random
import string

stone = {'name':'stone', 'def':'cloth'}
cloth = {'name':'cloth', 'def':'scissor'}
scissor = {'name':'scissor', 'def':'stone'}

skill_list = [stone, cloth, scissor]
cur_score = 1
cur_turns = 1

def welcome():
    print '-' * 20
    print '1, you can play (stone, cloth, scissor), when your turn.'
    print '2, if you do not play three of the objects, that means you give up.'
    print '3, if you win you will add one score, if you lose it will decrease one score'
    print '4, you can input q to quit game. or you lose all your score you will quit game.'
    print '-' * 20

def print_turns():
    global cur_turns
    print '*' * 10 + str(cur_turns) + '*' * 10
    cur_turns += 1

def input_skill():
    skill_name = raw_input('your turns:')
    for skill in skill_list:
        if skill['name'] == skill_name:
            return skill
    return skill_name

def enemy_skill():
    index = random.randint(0, len(skill_list) - 1)
    return skill_list[index]

def lose_score():
    global cur_score
    cur_score -= 1

def win_score():
    global cur_score
    cur_score += 1

def play_skill_ret(player_skill, enemy_skill):
    if player_skill == None:
        print 'player give up game'
        lose_score()
        return

    print 'player skill:', player_skill['name'], 'enemy skill:', enemy_skill['name']
    if player_skill['def'] == enemy_skill['name']:
        print 'player lose'
        lose_score()
    elif player_skill == enemy_skill:
        print 'you and enemy have draw in this turns'
    else:
        print 'player win'
        win_score()


# main
welcome()
while True:
    print_turns()
    ret = input_skill()
    if isinstance(ret, str):
        if ret == 'q':
            print 'bye.'
            break
        else:
            ret = None
    skill = enemy_skill()
    play_skill_ret(ret, skill)
    print 'player score is:', cur_score
    if cur_score == 0:
        print 'Game Over.'
        break
