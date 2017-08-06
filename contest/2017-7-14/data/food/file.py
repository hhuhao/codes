from cyaron import *
_n=[0,10,10,10,100,100,100,100,100,100,100,100]
for i in range(1,12):
    io=IO(file_prefix="food",data_id=i)
    n=_n[i]
    io.input_writeln(n)
    vt=Vector.random(n,[(-1000,1000),(-1000,1000)],1)
    for i in range(0,n):
        s=vt[i]
        io.input_writeln(s[0],s[1])
    io.output_gen("food.exe")

