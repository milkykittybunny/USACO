def all_same(items):
    return all(x == items[0] for x in items)

def amount_to_be_moved(haybales):
    total = 0
    for bale in haybales:
        total += bale
    average = total/len(haybales)
    moves = 0
    for bale in haybales:
        if bale > average:
            moves += bale-average
    return int(moves)


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
    num = int(fIn.readline())
    haybales = []
    for n in range(num):
        haybales.append(int(fIn.readline()))
    fIn.close()

    fOut = open("out.{}".format(x), "w")
    fOut.write(str(amount_to_be_moved(haybales))+ "\n")
    fOut.close()

    fOut = open("out.{}".format(x), "r")
    second = open("O.{}".format(x), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(x))
        break

if result == 0:
    print("The program was right, congrats, have  an ice cream~!")