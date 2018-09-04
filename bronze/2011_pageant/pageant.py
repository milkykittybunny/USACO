import sys

def colorIng(x, y):
    if M[x][y] == "X":
        M[x][y] = "1"
        if x+1 < len(M):
            colorIng(x+1, y)
        if x-1 >= 0:
            colorIng(x-1, y)
        if y+1 < len(M[0]):
            colorIng(x, y+1)
        if y-1 >= 0:
            colorIng(x, y-1)

def twoGroups(tOne, tTwo):
    distance = 9999999
    for one in tOne:
        for two in tTwo:
            if abs(one[0] - two[0]) + abs(one[1] - two[1]) < distance:
                distance = abs(one[0] - two[0]) + abs(one[1] - two[1])
    return distance


# checker
def mdiff(file1, file2):
    first = file1.readlines()
    second = file2.readlines()
    if first == second:
        return 0
    else:
        return 1

M = []

for f in range(1, 11):
    M = []

    fIn = open("I.{}".format(f), "r")
    first = list(map(int,fIn.readline().split()))
    for y in range(first[0]):
        M.append(list(fIn.readline().strip()))
    fIn.close()

    flag = False
    coordinates = tuple()
    for x in range(first[0]):
        for y in range(len(M[0])):
            if M[x][y] == "X":
                coordinates = (x, y)
                flag = True
                break
        if flag:
            break

    colorIng(coordinates[0], coordinates[1])

    #for z in M:
    #    print(z)

    tTwo = []
    tOne = []
    for x in range(first[0]):
        for y in range(len(M[0])):
            if M[x][y] == "X":
                tTwo.append((x, y))
            elif M[x][y] == "1":
                tOne.append((x, y))
    answer = twoGroups(tOne, tTwo)
    print(answer)

    fOut = open("out.{}".format(f), "w")
    fOut.write(str(answer - 1) + "\n")
    fOut.close()

    fOut = open("out.{}".format(f), "r")
    second = open("O.{}".format(f), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(f))
        break

if result == 0:
    print("The program was right, congrats, have  an ice cream~!")




