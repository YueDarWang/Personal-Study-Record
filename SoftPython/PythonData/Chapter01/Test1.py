# me={"name":"俞泽延","age":20,"nation":"中国"}
# print("我的名字是{0},我的年龄是{1},我来自{2}".format(me["name"],me["age"],me["nation"]))
# me1=["俞泽延",20,"中国"]
# print(f"我的名字是{me1[0]},我的年龄是{me1[1]},我来自{me1[2]}")
#
# name = input("请输入你的名字：")
# age = int(input("请输入你的年龄"))
# print(age,type(age))
# print("你的名字是{}，你的年龄是{}".format(name,age))

import string
from string import digits, ascii_letters

flag =input()
if flag in digits:
    result = "这是数字"
elif flag in ascii_letters:
    result ="这是字母"
else :
    result ="这是其他字符"
print(result)
