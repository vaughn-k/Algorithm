total = 0
for i in range(5):
    tmp = int(input(""))
    if(tmp < 40):
        total = total + 40
    else:
        total = total + tmp

print(total//5)


