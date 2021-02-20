x,y = input().split(" ")
x = int(x)
y = int(y)

cal = [0] * 13
cal[1] = 31
cal[2] = 28
cal[3] = 31
cal[4] = 30
cal[5] = 31
cal[6] = 30
cal[7] = 31
cal[8] = 31
cal[9] = 30
cal[10] = 31
cal[11] = 30
cal[12] = 31


total = y
for i in range(1,x):
    total = total + cal[i]

final = total%7

if(final == 0):
    print("SUN")
elif(final == 1):
    print("MON")
elif(final == 2):
    print("TUE")
elif(final == 3):
    print("WED")
elif(final == 4):
    print("THU")
elif(final == 5):
    print("FRI")
else:
    print("SAT")
