from cyaron import *
_n=ati([0,100,100,100,1E5,1E5,1E5,1E5,1E5,1E5,1E5,1E5])

for i in range(1,12):
    io=IO(file_prefix="missile",data_id=i)
    n=_n[i]
    io.input_writeln(n)
    vt=Vector.random(n,[(1,int(1E9))],0)
    io.input_writeln(vt)
    io.output_gen("missile.exe")
    
    
