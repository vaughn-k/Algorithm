# 15m

def updown(room,i,n):
    count = 0
    check = 0
    for j in range(n):
        if(room[j][i] == '.'):
            check = check+1

        if(room[j][i] == 'X' or j == n-1):
            if(check >= 2):
                count = count + 1
            check = 0
    return count


def leftright(room,j,n):
    count = 0
    check = 0
    for i in range(n):
        if(room[j][i] == '.'):
            check = check+1

        if(room[j][i] == 'X' or i == n-1):
            if(check >= 2):
                count = count + 1
            check = 0
    return count





n = int(input(""))
room = [0] * n
for i in range(n):
    room[i] = input("")

total_ud = 0
total_lr = 0
for i in range(n):
    total_lr = total_lr + leftright(room,i,n)
    total_ud = total_ud + updown(room,i,n)

print(total_lr,total_ud)