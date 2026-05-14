def main():
    n = int(input())
    re= 1
    for i in range(1,n+1):
        re *= i
    re = str(re)
    res = re[-1:-len(re)]
    for i in res:
        if i!="0":
            print(i)
            return
main()