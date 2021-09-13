######################## Variables ########################

SRC = src
BIN = bin
OBJ = obj
LIB = lib
MKDIR_P = mkdir -p

######################## LISTADO - LISTENINGS ########################
all: clean listing_1 listing_2.1 listing_2.2 listing_2.3 listing_2.4 listing_2.5 listing_2.6 listing_2.7 listing_2.8 listing_2.9 listing_3.1 listing_3.2 listing_3.3 listing_3.4 listing_3.5 listing_3.6 listing_3.7 listing_4.1 listing_4.2 listing_4.3 listing_4.4 listing_4.5 listing_4.6 listing_4.7 listing_4.8 listing_4.9 listing_4.10 listing_4.11 listing_4.12 listing_4.13 listing_4.14 listing_4.15 listing_5.1 listing_5.2 listing_5.3 listing_5.4 listing_5.5 listing_5.6 listing_5.7 listing_5.8 listing_5.9 listing_5.10 listing_5.11 listing_5.12

listing_1: directories reciprocal
listing_2.1: directories arglist
listing_2.2: directories getopt_long
listing_2.3: directories print-env
listing_2.4: directories client
listing_2.5: directories temp_file
listing_2.6: directories readfile
listing_2.7: directories test
listing_2.8: directories app
listing_2.9: directories tifftest
listing_3.1: directories print-pid
listing_3.2: directories system
listing_3.3: directories fork
listing_3.4: directories fork-exec
listing_3.5: directories sigusr1
listing_3.6: directories zombie
listing_3.7: directories sigchld
listing_4.1: directories thread-create
listing_4.2: directories thread-create2
listing_4.3: directories thread-create2
listing_4.4: directories primes
listing_4.5: directories detached
listing_4.6: directories critical-section
listing_4.7: directories tsd
listing_4.8: directories cleanup
listing_4.9: directories cxx-exit
listing_4.10: directories job-queue
listing_4.11: directories job-queue2
listing_4.12: directories job-queue3
listing_4.13: directories spin-condvar
listing_4.14: directories condvar
listing_4.15: directories thread-pid
listing_5.1: directories shm
listing_5.2: directories sem_all_dead
listing_5.3: directories sem_init
listing_5.4: directories sem_pv
listing_5.5: directories mmap-write
listing_5.6: directories mmap-read
listing_5.7: directories pipe
listing_5.8: directories dup2
listing_5.9: directories popen
listing_5.10: directories socket-server
listing_5.11: directories socket-client
listing_5.12: directories socket-inet
######################## DIRECTORIOS ########################
directories: crear_bin crear_obj crear_lib

crear_bin:
	@echo "Creando directorios"
	@$(MKDIR_P) $(BIN)
	@$(MKDIR_P) ${BIN}/Capitulo1 ${BIN}/Capitulo2 ${BIN}/Capitulo3 ${BIN}/Capitulo4 $(BIN)/Capitulo5

crear_obj:
	@${MKDIR_P} ${OBJ}

crear_lib:
	@${MKDIR_P} ${LIB}
	@echo "Directorios creados"
################################################ CAPITULO 1 ################################################

######################## LISTING 1 ########################
reciprocal: main.o reciprocal.o
	@echo "Compilando Listing 1"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo1/listing_1  $(OBJ)/main.o  $(OBJ)/reciprocal.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo1/listing_1"

main.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo1/1.1/main.c -o $(OBJ)/main.o

reciprocal.o:
	@g++  $(CFLAGS) -c $(SRC)/Capitulo1/1.1/reciprocal.cpp -o $(OBJ)/reciprocal.o

################################################ CAPITULO 2 ################################################

######################## LISTING 2.1 ########################

arglist: arglist.o
	@echo "Compilando Listing 2.1"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.1  $(OBJ)/arglist.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo2/listing_2.1"

arglist.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.1/arglist.c -o $(OBJ)/arglist.o

######################## LISTING 2.2 ########################

getopt_long: getopt_long.o
	@echo "Compilando Listing 2.2"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.2  $(OBJ)/getopt_long.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo2/listing_2.2"

getopt_long.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.2/getopt_long.c -o $(OBJ)/getopt_long.o

######################## LISTING 2.3 ########################

print-env: print-env.o
	@echo "Compilando Listing 2.3"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.3  $(OBJ)/print-env.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo2/listing_2.3"

print-env.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.3/print-env.c -o $(OBJ)/print-env.o

######################## LISTING 2.4 ########################

client: client.o
	@echo "Compilando Listing 2.4"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.4  $(OBJ)/client.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo2/listing_2.4"

client.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.4/client.c -o $(OBJ)/client.o
	
######################## LISTING 2.5 ########################

temp_file: temp_file.o
	@echo "Compilando Listing 2.5"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.5  $(OBJ)/temp_file.o
	@echo "Compilación finalizada. Generado en ./bin/Capitulo2/listing_2.5"

temp_file.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.5/temp_file.c -o $(OBJ)/temp_file.o

######################## LISTING 2.6 ########################

readfile: readfile.o
	@echo "Compilando Listing 2.6"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.6  $(OBJ)/readfile.o
	@cp $(SRC)/Capitulo2/2.6/readfile.txt $(BIN)/Capitulo2/
	@echo "Compilación finalizada. Generado en ./bin/Capitulo2/listing_2.6"

readfile.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.6/readfile.c -o $(OBJ)/readfile.o

######################## LISTING 2.7 ########################

test: test.a testmain.o
	@echo "Compilando Listing 2.7"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.7 $(OBJ)/testmain.o -L$(LIB)/ -l_mylib
	@echo "Compilación finalizada. Generado en ./bin/Capitulo2/listing_2.7"

testmain.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.7/testmain.c -o $(OBJ)/testmain.o 

test.a:	test.o
	@ar rcs  $(LIB)/lib_mylib.a $(OBJ)/test.o

test.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.7/test.c -o $(OBJ)/test.o

######################## LISTING 2.8 ########################

app: app.o
	@echo "Compilando Listing 2.8"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.8 $(OBJ)/app.o -L$(LIB)/ -l_mylib
	@echo "Compilación finalizada. Generado en ./bin/Capitulo2/listing_2.8"

app.o: test.a
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.8/app.c -o $(OBJ)/app.o

######################## LISTING 2.9 ########################

tifftest: tifftest.o

	@echo "Compilando Listing 2.9"
	@cp $(SRC)/Capitulo2/2.9/img.tiff $(BIN)/Capitulo2/
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo2/listing_2.9 $(OBJ)/tifftest.o -L. -ltiff
	@echo "Compilación finalizada. Generado en ./bin/Capitulo2/listing_2.9"

tifftest.o: test.a
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo2/2.9/tifftest.c -o $(OBJ)/tifftest.o 

################################################ CAPITULO 3 ################################################

######################## LISTING 3.1 ########################
print-pid: print-pid.o
	@echo "Compilando Listing 3.1"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.1  $(OBJ)/print-pid.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.1"

print-pid.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.1/print-pid.c -o $(OBJ)/print-pid.o


######################## LISTING 3.2 ########################
system: system.o
	@echo "Compilando Listing 3.2"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.2  $(OBJ)/system.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.2"

system.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.2/system.c -o $(OBJ)/system.o

######################## LISTING 3.3 ########################
fork: fork.o
	@echo "Compilando Listing 3.3"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.3  $(OBJ)/fork.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.3"

fork.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.3/fork.c -o $(OBJ)/fork.o

######################## LISTING 3.4 ########################
fork-exec: fork-exec.o
	@echo "Compilando Listing 3.4"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.4  $(OBJ)/fork-exec.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.4"

fork-exec.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.4/fork-exec.c -o $(OBJ)/fork-exec.o

######################## LISTING 3.5 ########################
sigusr1: sigusr1.o
	@echo "Compilando Listing 3.5"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.5  $(OBJ)/sigusr1.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.5"

sigusr1.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.5/sigusr1.c -o $(OBJ)/sigusr1.o

######################## LISTING 3.6 ########################
zombie: zombie.o
	@echo "Compilando Listing 3.6"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.6  $(OBJ)/zombie.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.6"

zombie.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.6/zombie.c -o $(OBJ)/zombie.o

######################## LISTING 3.7 ########################
sigchld: sigchld.o
	@echo "Compilando Listing 3.7"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo3/listing_3.7  $(OBJ)/sigchld.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo3/listing_3.7"

sigchld.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo3/3.7/sigchld.c -o $(OBJ)/sigchld.o

################################################ CAPITULO 4 ################################################

######################## LISTING 4.1 ########################
thread-create: thread-create.o
	@echo "Compilando Listing 4.1"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.1 -pthread $(OBJ)/thread-create.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.1"

thread-create.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.1/thread-create.c -o $(OBJ)/thread-create.o 


######################## LISTING 4.2 ########################
thread-create2: thread-create2.o
	@echo "Compilando Listing 4.2"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.2 -pthread $(OBJ)/thread-create2.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.2"

thread-create2.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.2/thread-create2.c -o $(OBJ)/thread-create2.o 

######################## LISTING 4.3 ########################
thread-create3: thread-create2.o
	@echo "Compilando Listing 4.3"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.3 -pthread $(OBJ)/thread-create2.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.3"

thread-create3.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.3/thread-create2.c -o $(OBJ)/thread-create2.o 

######################## LISTING 4.4 ########################
primes: primes.o
	@echo "Compilando Listing 4.4"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.4 -pthread $(OBJ)/primes.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.4"

primes.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.4/primes.c -o $(OBJ)/primes.o 


######################## LISTING 4.5 ########################
detached: detached.o
	@echo "Compilando Listing 4.5"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.5 -pthread $(OBJ)/detached.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.5"

detached.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.5/detached.c -o $(OBJ)/detached.o 

######################## LISTING 4.6 ########################
critical-section: critical-section.o
	@echo "Compilando Listing 4.6"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.6 -pthread $(OBJ)/critical-section.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.6"

critical-section.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.6/critical-section.c -o $(OBJ)/critical-section.o 


######################## LISTING 4.7 ########################
tsd: tsd.o
	@echo "Compilando Listing 4.7"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.7 -pthread $(OBJ)/tsd.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.7"

tsd.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.7/tsd.c -o $(OBJ)/tsd.o 

######################## LISTING 4.8 ########################
cleanup: cleanup.o
	@echo "Compilando Listing 4.8"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.8 -pthread $(OBJ)/cleanup.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.8"

cleanup.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.8/cleanup.c -o $(OBJ)/cleanup.o 


######################## LISTING 4.9 ########################
cxx-exit: cxx-exit.o
	@echo "Compilando Listing 4.9"
	@g++  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.9 -pthread $(OBJ)/cxx-exit.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.9"

cxx-exit.o:
	@g++  $(CFLAGS) -c $(SRC)/Capitulo4/4.9/cxx-exit.cpp -o $(OBJ)/cxx-exit.o 

######################## LISTING 4.10 ########################
job-queue: job-queue.o
	@echo "Compilando Listing 4.10"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.10 -pthread $(OBJ)/job-queue.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.10"

job-queue.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.10/job-queue.c -o $(OBJ)/job-queue.o 

######################## LISTING 4.11 ########################
job-queue2: job-queue2.o
	@echo "Compilando Listing 4.11"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.11 -pthread $(OBJ)/job-queue2.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.11"

job-queue2.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.11/job-queue2.c -o $(OBJ)/job-queue2.o 

######################## LISTING 4.12 ########################
job-queue3: job-queue3.o
	@echo "Compilando Listing 4.12"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.12 -pthread $(OBJ)/job-queue3.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.12"

job-queue3.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.12/job-queue3.c -o $(OBJ)/job-queue3.o 



######################## LISTING 4.13 ########################
spin-condvar: spin-condvar.o
	@echo "Compilando Listing 4.13"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.13 -pthread $(OBJ)/spin-condvar.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.13"

spin-condvar.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.13/spin-condvar.c -o $(OBJ)/spin-condvar.o

	
######################## LISTING 4.14 ########################
condvar: condvar.o
	@echo "Compilando Listing 4.14"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.14 -pthread $(OBJ)/condvar.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.14"

condvar.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.14/condvar.c -o $(OBJ)/condvar.o

		
######################## LISTING 4.15 ########################
thread-pid: thread-pid.o
	@echo "Compilando Listing 4.15"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo4/listing_4.15 -pthread $(OBJ)/thread-pid.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo4/listing_4.15"

thread-pid.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo4/4.15/thread-pid.c -o $(OBJ)/thread-pid.o 

################################################ CAPITULO 4 ################################################

######################## LISTING 5.1 ########################
shm: shm.o
	@echo "Compilando Listing 5.1"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.1 -pthread $(OBJ)/shm.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.1"

shm.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.1/shm.c -o $(OBJ)/shm.o 

######################## LISTING 5.2 ########################
sem_all_dead: sem_all_dead.o
	@echo "Compilando Listing 5.2"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.2 $(OBJ)/sem_all_dead.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.2"

sem_all_dead.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.2/sem_all_dead.c -o $(OBJ)/sem_all_dead.o

######################## LISTING 5.3 ########################
sem_init: sem_init.o
	@echo "Compilando Listing 5.3"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.3 $(OBJ)/sem_init.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.3"

sem_init.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.3/sem_init.c -o $(OBJ)/sem_init.o

######################## LISTING 5.4 ########################
sem_pv: sem_pv.o
	@echo "Compilando Listing 5.4"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.4 $(OBJ)/sem_pv.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.4"

sem_pv.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.4/sem_pv.c -o $(OBJ)/sem_pv.o

######################## LISTING 5.5 ########################
mmap-write: mmap-write.o
	@echo "Compilando Listing 5.5"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.5 $(OBJ)/mmap-write.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.5"

mmap-write.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.5/mmap-write.c -o $(OBJ)/mmap-write.o 


######################## LISTING 5.6 ########################
mmap-read: mmap-read.o
	@echo "Compilando Listing 5.6"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.6 $(OBJ)/mmap-read.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.6"

mmap-read.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.6/mmap-read.c -o $(OBJ)/mmap-read.o

######################## LISTING 5.7 ########################
pipe: pipe.o
	@echo "Compilando Listing 5.7"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.7 $(OBJ)/pipe.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.7"

pipe.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.7/pipe.c -o $(OBJ)/pipe.o

######################## LISTING 5.8 ########################
dup2: dup2.o
	@echo "Compilando Listing 5.8"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.8 $(OBJ)/dup2.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.8"

dup2.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.8/dup2.c -o $(OBJ)/dup2.o

######################## LISTING 5.9 ########################
popen: popen.o
	@echo "Compilando Listing 5.9"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.9 $(OBJ)/popen.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.9"

popen.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.9/popen.c -o $(OBJ)/popen.o

######################## LISTING 5.10 ########################
socket-server: socket-server.o
	@echo "Compilando Listing 5.10"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.10 $(OBJ)/socket-server.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.10"

socket-server.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.10/socket-server.c -o $(OBJ)/socket-server.o

######################## LISTING 5.11 ########################
socket-client: socket-client.o
	@echo "Compilando Listing 5.11"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.11 $(OBJ)/socket-client.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.11"

socket-client.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.11/socket-client.c -o $(OBJ)/socket-client.o

######################## LISTING 5.12 ########################
socket-inet: socket-inet.o
	@echo "Compilando Listing 5.12"
	@gcc  $(CFLAGS) -o $(BIN)/Capitulo5/listing_5.12 $(OBJ)/socket-inet.o
	@echo "Compilación finalizada. Programa generado en ./bin/Capitulo5/listing_5.12"

socket-inet.o:
	@gcc  $(CFLAGS) -c $(SRC)/Capitulo5/5.12/socket-inet.c -o $(OBJ)/socket-inet.o
 ##gcc -o app app.o -L. –ltest
 ##gcc -o app app.o -L. –ltest
 ##gcc -o app app.o -L. –ltest
 ##gcc -o app app.o -L. –ltest
######################## UTIL ########################
clean:
	@echo "Limpiando archivos"
	@rm -f $(OBJ)/*.o $(OBJ)/*.a $(BIN)/Capitulo1/* $(BIN)/Capitulo2/* $(BIN)/Capitulo3/* $(BIN)/Capitulo4/* $(BIN)/Capitulo5/*
	@echo "Limpieza completada"
