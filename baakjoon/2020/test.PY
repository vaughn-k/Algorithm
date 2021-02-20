def test(a):
    if(a > 0):
        return 0
    elif(a < 0):
        return -1
    else:
        return None
    

def check(a):
    ans = test(a)
    if(ans != None):
        print("ok")
    else:
        print("no")

check(100)
check(0)
check(-1)