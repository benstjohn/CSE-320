#Ben St. John
#CSE320 - Project 8
proj08: proj08.main.o
	gcc -o proj08 proj08.main.o

proj08.main.o:
	gcc -c proj08.main.s
