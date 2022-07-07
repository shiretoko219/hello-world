# 用于git命令学习的测试代码
a=int(input('请输入一个整数:'))

if a<0:
    print('负数没有奇偶性！')
elif a % 2 == 0:
    print('这是一个偶数')
else:
    print('这是一个奇数')