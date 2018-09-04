def mdiff(file1, file2):
        first = file1.readlines()
        second = file2.readlines()
        if first == second:
            return 0
        else:
            return 1


def ctime(day, hr, min):
    start = [11,11,11]
    end = [day, hr, min]
    total = 0
    # running through
    for time in range(len(start)):
            current = end[time] - start[time]
            if time == 0:
                current *= 1440
            elif time == 1:
                current *= 60
            total += current
    if total < 0:
        return -1
    return total



for x in range(1, 11):
    fIn = open("I.{}".format(x), "r")
    times = list(map(int, fIn.readline().split(" ")))
    fIn.close()

    fOut = open("out.{}".format(x), "w")
    fOut.write(str(ctime(times[0], times[1], times[2])) + "\n")
    fOut.close()

    fOut = open("out.{}".format(x), "r")
    second = open("O.{}".format(x), "r")
    result = mdiff(fOut, second)
    if result == 1:
        print("At file {} it was wrong.".format(x))
        break

if result == 0:
    print("The file was right, congrats, have  an ice cream~!")

