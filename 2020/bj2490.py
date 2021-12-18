s = [0] * 3
for i in range(3):
    s[i] = list(map(int,input().split(" ")))
    
for i in range(3):
    total = s[i][0] + s[i][1] + s[i][2] + s[i][3]
    if(total == 0):
        print("D")
    elif(total == 1):
        print("C")
    elif(total == 2):
        print("B")
    elif(total == 3):
        print("A")
    else:
        print("E")