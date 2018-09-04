def digit_lst(numberLst, base):
    returnLst = set()
    for digit in range(len(numberLst)):
        for x in range(base):
            if x != numberLst[digit]:
                temp = 0
                for y in range(len(numberLst)):
                    if y == digit:
                        temp += base ** (len(numberLst) - (y + 1)) * x
                    else:
                        temp += base ** (len(numberLst) - (y + 1)) * numberLst[y]
                returnLst.add(temp)
    return list(returnLst)


def awkward_digits(number2, number3):
    numberLst2 = [int(i) for i in number2]
    numberLst3 = [int(i) for i in number3]
    twoLst = digit_lst(numberLst2, 2)
    threeLst = digit_lst(numberLst3, 3)
    for x in twoLst:
        for y in threeLst:
            if x == y:
                return x


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
    number2 = fIn.readline().strip()
    number3 = fIn.readline().strip()
    fIn.close()

    fOut = open("out.{}".format(x), "w")
    fOut.write(str(awkward_digits(number2, number3)) + "\n")
    fOut.close()

    fOut = open("out.{}".format(x), "r")
    second = open("O.{}".format(x), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(x))
        # break

if result == 0:
    print("The file was right, congrats, have  an ice cream~!")