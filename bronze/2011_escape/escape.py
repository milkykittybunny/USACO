def complete_set(lst):
    if len(lst) == 0:
        return [[]]
    set = complete_set(lst[1:])
    ret = []
    for x in set:
        ret.append(x)
        ret.append([lst[0]] + x)
    return ret

def cowcheck(one, two):
    if one > two:
        big = one
        small = two
    else:
        big = two
        small = one
    while small > 0:
        digitsmall = small % 10
        digitbig = big % 10
        if digitsmall + digitbig >= 10:
            return 0
        small /= 10
        big /= 10
    return one + two

def brute_cow(lst):
    cowSet = complete_set(lst)
    largeTotal = 0
    for cows in cowSet:
        total = 0
        flag = True
        if len(cows) > largeTotal:
            for cow in cows:
                temp = cowcheck(total, cow)
                if temp != 0:
                    total = temp
                else:
                    flag = False
                    break
            if flag == True and len(cows) > largeTotal:
                largeTotal = len(cows)
    return largeTotal

# Copy and paste this checker to run the program~!

# checker
def mdiff(file1, file2):
    first = file1.readlines()
    second = file2.readlines()
    if first == second:
        return 0
    else:
        return 1


for x in range(1, 11):
    fIn = open("I.{}".format(x), "r")
    num = fIn.readline()
    cows = []
    for i in range(int(num)):
        cows.append(int(fIn.readline()))
    fIn.close()

    fOut = open("out.{}".format(x), "w")
    fOut.write(str(brute_cow(cows)) + "\n")
    fOut.close()

    fOut = open("out.{}".format(x), "r")
    second = open("O.{}".format(x), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(x))
    else:
        print("At file {} it was right.".format(x))
        # break

if result == 0:
    print("The program was right, congrats, have  an ice cream~!")