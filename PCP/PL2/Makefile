FLAGS = -fPIC -shared -Wall

all: cleanall creadir PRACGccO0.so PRACGccO3.so PRACIccO0.so PRACIccO3.so HelpAT.so

creadir: 
	@mkdir LIBS
	

cleanall: clean
	@rm -rf	LIBS

clean:
	@rm -f *.o core *~
	

PRACGccO0.so: PRAC02.c
	gcc -o LIBS/PRACGccO0.so $(FLAGS) -O0 PRAC02.c 

PRACGccO3.so: PRAC02.c
	gcc -o LIBS/PRACGccO3.so $(FLAGS) -O3 PRAC02.c 


PRACIccO0.so: PRAC02.c
	icx -o LIBS/PRACIccO0.so $(FLAGS) -O0 PRAC02.c 

PRACIccO3.so: PRAC02.c
	icx -o LIBS/PRACIccO3.so $(FLAGS) -O3 PRAC02.c 

HelpAT.so: HelpAT.c
	gcc -o LIBS/HelpAT.so $(FLAGS) -O3 HelpAT.c