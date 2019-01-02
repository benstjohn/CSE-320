proj10: /user/cse320/Projects/project10.driver.o proj10.support.o
	gcc /user/cse320/Projects/project10.driver.o proj10.support.o -o proj10

driver.o: /user/cse320/Projects/project10.driver.o /user/cse320/Projects/proj10.support.h
	gcc -Wall -c /user/cse320/Projects/project10.driver.o

support.o: proj10.support.s /user/cse320/Projects/proj10.support.h
	gcc -Wall -c proj10.support.s
