def fun1(x):
    if x&1:
        return"是奇数"
    else:
        return"是偶数"

# s=int(input("请输入一个整数"))
# print("这个整数{}".format(fun1(s)))
x=input("请输入整数")
if x.isdigit():
    x1=int(x)
    print("这个整数{}".format(fun1(x1)))
else:
    print("你输入的不是数字")
