def isMAC48Address(inputString):
    a=list(inputString.split('-'))
    if len(a)!=6:
        return False
    for i in range(0,len(a)):
        if len(a[i])!=2:
            return False
        if a[i][0]<'0':
            return False
        elif a[i][0] >'9' and a[i][0]<'A':
            return False
        elif a[i][0] >'F':
            return False
        elif a[i][1]<'0':
            return False
        elif a[i][1] >'9' and a[i][1]<'A':
            return False
        elif a[i][1] >'F':
            return False
    return True
