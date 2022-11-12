#Transfrom the String
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
