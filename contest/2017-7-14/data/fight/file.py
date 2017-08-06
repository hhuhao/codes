from cyaron import *
_n=[0,50,50000000,2**59,2333]
_t=[0,3000,2000,5000,1000]
for i in range(1,5):
    n=_n[i]
    t=_t[i]
    io=IO(file_prefix="fight",data_id=i)
    io.input_writeln(t)
    for tt in range(0,t):
        x=randint(2,n)
        io.input_writeln(x*2-1)
    io.output_gen("fight.exe")
    print("End {}".format(i))

    
