print(a)  # @violation

a = 2
b= 4
a_dict = {a:5,b:6}
del a
print(a_dict[a])		# @violation
print(a_dict[b])



myArray = [1, 2, 3, 4, 5, 6]
for i in myArra:  # @violation
    print (i)
