import time

def nl():
    print()

neednot='''def refresh():
    # To avoid Python's automatic time merging mechanism, use this function to refresh
    print(" ", end="")'''

def unit(is_x, bpm, stay, h=16, dot=False):
    """
    stay: 在bpm下，等待stay个h分音符
    dot: 附点
    is_x: 为真打印X，否则打印O
    """
    sleep_for = 240 / (bpm * h)
    real_sleep = sleep_for * stay * \
                 (1.5 if dot else 1)
    
    s = "X" if is_x else "O"
    print(s, end="", flush=True)
    time.sleep(real_sleep)

def a1(t):
    # 4+4+2+2+4=16
    unit(t, 130, 4)
    unit(t, 130, 4)
    unit(t, 130, 2)
    unit(t, 130, 2)
    unit(t, 130, 4)
    nl()

def a2(t):
    # 2+3+3+2+2+4=16
    unit(t, 130, 2)
    unit(t, 130, 3)
    unit(t, 130, 3)
    unit(t, 130, 2)
    unit(t, 130, 2)
    unit(t, 130, 4)
    nl()

def a3(t):
    # sum = 16就对了
    unit(t, 135, 3)
    unit(t, 135, 3)
    unit(t, 135, 2)
    unit(t, 135, 1, 12)
    unit(t, 135, 1, 12)
    unit(t, 135, 1, 12)
    unit(t, 135, 4)
    nl()

def a4(t):
    x = 140 if t else 145
    # 1+2+1+2+1+1+2+2+4=16
    unit(t, x, 1)
    unit(t, x, 2)
    unit(t, x, 1)
    unit(t, x, 2)
    unit(t, x, 1)
    unit(t, x, 1)
    unit(t, x, 2)
    unit(t, x, 2)
    unit(t, x, 4)
    nl()

def b1(t):
    unit(t, 150, 2)
    unit(t, 150, 2)
    unit(t, 150, 4)
    nl()

def b2(t):
    unit(t, 150, 1)
    unit(t, 150, 1)
    unit(t, 150, 2)
    unit(t, 150, 4)
    nl()

def b3(t):
    for _ in range(2):
        unit(t, 160, 1)
        unit(t, 160, 1)
        unit(t, 160, 2)
    nl()

def b4(t):
    for _ in range(4):
        unit(t, 160, 1, 12)
    unit(t, 160, 2, 12)
    nl()

def b5(t):
    for _ in range(6):
        unit(t, 170, 1)
    unit(t, 170, 2)
    nl()

def b6(t):
    # 0.5+0.5+1+2+2+2=8
    unit(t, 170, 1, 32)
    unit(t, 170, 1, 32)
    unit(t, 170, 1)
    unit(t, 170, 2)
    unit(t, 170, 2)
    unit(t, 170, 2)
    nl()

def c1(t, bpm):
    unit(t, bpm, 2)
    unit(t, bpm, 2)
    print(" ", end="")

if __name__ == "__main__":
    order = [a1, a2, a3, a4, b1, b2, b3, b4, b5, b6]
    for i in order:
        i(True)
        i(False)
    
    for i in (180, 190):
        for _ in range(2):
            c1(True, i)
            c1(False, i)
    nl()
    
    for i in range(200, 260, 10):
        for _ in range(4):
            unit(True, i, 2)
            unit(False, i, 2)
        print(" ", end="")
    nl()
    
    for _ in range(31):
        unit(True, 256, 1)
    nl()
