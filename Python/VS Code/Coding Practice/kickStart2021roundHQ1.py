# # https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435914/00000000008da461


def transformString():
    S = list(input("Enter the string S: "))
    F = chr(input("Enter the string F: "))
    C = 0

    for i in range(len(S)):
        while S[i] != F:
            print(S[i])
            if S[i] < F:
                S[i] = chr(ord(S[i]) + 1)
                ++C
            elif S[i] > F:
                S[i] = chr(ord(S[i]) - 1)
                ++C
            else:
                break
    return 1


testNo = int(input("Enter the number of test cases: "))

for i in range(testNo):
    print("Case #" + str(i + 1) + ":" + transformString())

# #Transfrom the String
# def transformString():
# 	S=list(input())
# 	alpha=['a','b','c','d','e','f','g','h','i','j','k','l','m',
# 			'n','o','p','q','r','s','t','u','v','w','x','y','z']
# 	F=list(input())
# 	list2=[]
# 	for i in range(len(S)):
# 		if S[i] not in F:
# 			count=[]
# 			for j in range(len(F)):
# 				list1=[]
# 				list1.append(alpha.index(F[j]))
# 				list1.append(alpha.index(S[i]))
# 				a=max(list1)-min(list1)
# 				count.append(26-a if a>13 else a)
# 			list2.append(min(count))
# 	return sum(list2) if len(list2)>0 else 0
# T=int(input())
# for i in range(T):
# 	print("Case #"+str(i+1)+":",transformString())
