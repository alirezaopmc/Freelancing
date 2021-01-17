"""
علت آن است که متغیر در تابع تغیر می کند و متغیر در تابع اصلی تغیر نمی کند
مفهوم
scope
"""

def proc(x):
    x = 2 * x * x
    # x changes in this scope

def main():
    num = 10
    proc(num)
    print(num)

# main()

def proc2(x):
    return 2 * x * x

def main2():
    num = 10
    print(proc(num))

main2()