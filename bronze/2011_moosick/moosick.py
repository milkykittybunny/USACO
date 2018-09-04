def transpose(trans):
    small = trans[0]
    for y in trans:
        trans[trans.index(y)] = y - small
    return trans


def moosick(lst1, lst2):
    counter = 0
    indexes = []
    cut = len(lst2)
    d = -1
    lst2.sort()
    lst2 = transpose(lst2)
    for x in range(len(lst1) - len(lst2) + 1):
        flag = True
        lst3 = lst1[d + 1:d+cut+1]
        d+=1
        lst3.sort()
        lst3 = transpose(lst3)
        for i in range(len(lst2)):
            if lst2[i] != lst3[i]:
                flag = False
        if flag == True:
            counter += 1
            indexes.append(d+1)
    return counter, indexes

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
    num = int(fIn.readline().strip())
    numLst = []
    for z in range(num):
        numLst.append(int(fIn.readline().strip()))
    sickNum = int(fIn.readline().strip())
    sequence = []
    for y in range(sickNum):
        sequence.append(int(fIn.readline().strip()))
    fIn.close()
    writeLst = moosick(numLst, sequence)
    fOut = open("out.{}".format(x), "w")
    fOut.write(str(writeLst[0]) + "\n")
    for z in range(writeLst[0]):
        fOut.write(str(writeLst[1][z]) + "\n")
    fOut.close()

    fOut = open("out.{}".format(x), "r")
    second = open("O.{}".format(x), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(x))
        break

if result == 0:
    print("The file was right, congrats, have  an ice cream~!")