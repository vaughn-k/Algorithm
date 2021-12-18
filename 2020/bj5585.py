n = int(input(""))

m = 1000-n

total = 0

while(m != 0):
    if(m >= 500):
        m = m - 500
    elif(m >= 100):
        m = m - 100
    elif(m >= 50):
        m = m - 50
    elif(m >= 10):
        m = m - 10
    elif(m >= 5):
        m = m - 5
    elif(m >= 1):
        m = m - 1
    total = total + 1
print(total)
    