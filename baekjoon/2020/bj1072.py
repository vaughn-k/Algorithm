a,b = input().split(" ")
x = int(a)
y = int(b)

before = (y*100)//x
after = before + 1
count_back = 1
count_now = 1
bound = True
if(before >= 99):
    print(-1)
else:
    while(True):
        if(bound): # 2배씩 늘려가며 범위찾기
            answer = (y+count_now)*100//(x+count_now)
            if(answer == after):
                print(count_now)
                break
            if(answer < after):
                count_back = count_now
                count_now = count_now*2
            else:
                mid = (count_now+count_back)//2
                bound = False

        else: # 범위찾으면 이분법으로 구하기
            answer = (y+mid)*100//(x+mid)
            if(mid == after):
                print(mid)
                break
            elif(mid < after):
                count_now = mid-1
            else:
                count_back = mid+1
            mid = (count_now+count_back)//2
            
