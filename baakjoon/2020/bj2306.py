# python3로 하면 시간초과
# pypy 로하면 통과


def acgt(arr,answer,s,e):
    if(s >= e):
        return 0
    if(e-s == 1):
        if(arr[s] == 'a' and arr[e] == 't'):
            return 2
        if(arr[s] == 'g' and arr[e] == 'c'):
            return 2
        else:
            return 0
    if(answer[s][e] != -1):
        return answer[s][e]
    a,t,g,c = -1,-1,-1,-1
    st,sc = 0,0
    for i in range(s,e+1):
        if(a != -1 and g != -1):
            break
        if(a == -1 and arr[i] == 'a'):
            a = i
        if(g == -1 and arr[i] == 'g'):
            g = i
    for i in range(s,e+1):
        i = s+e-i
        if(t != -1 and c != -1):
            break
        if(t == -1 and arr[i] == 't'):
            t = i
        if(c == -1 and arr[i] == 'c'):
            c = i
    tmp1,tmp2,tmp3,maximum = 0,0,0,0
    if(a<t and a != -1 and t != -1):
        tmp1 = 2 + acgt(arr,answer,a+1,t-1)
    if(g<c and g != -1 and c != -1):
        tmp2 = 2 + acgt(arr,answer,g+1,c-1)
    for i in range(s,e):
        tmp3 = acgt(arr,answer,s,i) + acgt(arr,answer,i+1,e)
        if(maximum < tmp3):
            maximum = tmp3
    maximum = max(maximum,tmp1,tmp2)
    answer[s][e] = maximum
    return maximum



arr = input("")
n = len(arr)
answer = [[-1] * n for i in range(n)]

print(acgt(arr,answer,0,len(arr)-1))


# actacgtgatcgatcgatcgatcgatgcattatgctagctagctaccccggcgcgcagctagtcgatcgatcgtagctagctgcagtcgatcgtagctagcgagtcgatgctgctagtcgactggagctccctattagctagctagtagagagactagctacgatcgtatttacgatcatcgatgagatcatgcatgctagcgcgcgcgcgcgatcgatcgtgctagctaatatatcatcagcag