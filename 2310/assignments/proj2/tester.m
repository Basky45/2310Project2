comment(`Andrew Sanborn')
comment(`Spring 2018')
comment(`CPSC 2310, lab 003')
comment(`Lab 2: prints a table of equivalent Celsius and Fahrenheit values')

bipush(-40)
istore_1
bipush(-40)
istore_2
label(loop)
  iconst_1           comment(`  print C ')
  invokevirtual(1)

  iconst_2           comment(`  print F ')
  invokevirtual(2)

  iload_1            comment(` C += 10 ')
  bipush(10)
  iadd
  istore_1

  iload_2            comment(` F += 18 ')
  bipush(18)
  iadd
  istore_2

  iload_1           comment(` while(C <= 120) ')
  bipush(120)
  isub
  ifle(loop)

return
