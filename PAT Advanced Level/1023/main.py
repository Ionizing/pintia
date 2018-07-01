n = input()
n2 = n << 1
list_n = sorted(list(str(n)))
list_n2 = sorted(list(str(n * 2)))
if len(list_n) != len(list_n2):
    print 'No'
else:
    for x,y in zip(list_n, list_n2):
        if x != y:
            print 'No'
            break
    else:
        print 'Yes'
print n2