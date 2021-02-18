# coding=utf8

a = "Hello, Python!"
b = "I am Groot."
c = "Secure, Contain, Protect"
d = "SCP foundation"
e = "Hello"
num = "123456789"

# string catenate
e = a + b
print("a + b: ", e)


# string repeat
f = b * 1
g = b * 3
print("b * 1: ", f)
print("b * 3: ", g)


# string access
print(a[0])     #the first entry
print(a[-14])   #the first entry
print(a[13])    #the last entry
print(a[-1])    #the last entry


# string cut
print("The first word of scp: ", c[0:6])
print("The second word of scp: ", c[8:15])
print("The last word of scp: ", c[-7:])

print(num[0:10:1])
print(num[0:10:2])
print(num[::-1])
print(num[::-2])
print(num[:4:-2])
print(num[4::-2])


# string include

if(e in a):
    print("e is in a.")
else:
    print ("e is not in a.")

