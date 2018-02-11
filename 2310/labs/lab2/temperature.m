comment(` Keith Hammock ')
comment(` 1/30/18 ')
comment(` Lab 2 - Section 3 ')
  
bipush(-40)
bipush(-40)
istore_0
istore_1 comment(` Store -40 in registers 0 and 1 ')
label(loop)
iconst_0
invokevirtual(1) comment(` Print the value at register 0 ')
iload_0
bipush(10)
iadd comment(` Add the value at register 0 and the value 10 ')
istore_0
iconst_1
invokevirtual(2) comment(` Print the value at register 1 ')
iload_1
bipush(18)
iadd comment(` Add the value at register 1 and the value 18 ')
istore_1
bipush(120)
iload_0
isub
ifge(loop) comment(` Subtract 120 from the value at register 0 to check to loop ')
return
