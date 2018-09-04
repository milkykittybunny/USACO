def compare(one, two, index):
    oneg = 0
    twog = 0
    for arr in index:
        if arr[one] < arr[two]:
            oneg += 1

        else:
            twog += 1

    if twog > oneg:
        return -1
    elif twog == oneg:
        return 0
    else:
        return 1

def bubble_cow(index, output):
    for i in range(len(output) - 1):
        for j in range(len(output)-i-1):
            result = compare(output[j], output[j+1], index)
            if result == -1:
                temp = output[j+1]
                output[j+1] = output[j]
                output[j] = temp
    return output

# Copy and paste this checker to run the program~!

# checker
def mdiff(file1, file2):
    first = file1.readlines()
    second = file2.readlines()
    if first == second:
        return 0
    else:
        return 1


for x in range(3, 11):
    print(x)
    fIn = open("I.{}".format(x), "r")
    n = int(fIn.readline())
    lst = []
    for y in range(5):
        t = []
        for z in range(n):
            t.append(int(fIn.readline()))
        lst.append(t)


    indexes = []
    for y in range(5):
        t = [-1] * n
        for z in range(n):
            t[lst[y][z] - 1] = z
        indexes.append(t)
    fIn.close()

    outPut = [z for z in range(n)]
    fOut = open("out.{}".format(x), "w")
    bubble = bubble_cow(indexes, outPut)
    for b in bubble:
        fOut.write(str(b+1) + "\n")
    fOut.close()

    fOut = open("out.{}".format(x), "r")
    second = open("O.{}".format(x), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(x))
        break

if result == 0:
    print("The program was right, congrats, have  an ice cream~!")