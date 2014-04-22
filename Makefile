CC = gcc
LDIR = /home/user/lib
CFLAGS = -DDEBUG -g -Wall -pedantic -std=c99 -I$(LDIR)/include
LFLAGS = -L$(LDIR)/lib -lbmp -lm
NAME = ww.out
#NBHOOD_TYPE =
NBHOOD_TYPE = torus_

$(NAME): main.o plansza.o rules.o boardio.o automaton.o $(NBHOOD_TYPE)neighborhood.o
	$(CC) -o $@ $^ $(LFLAGS)

main.o: boardio.h automaton.h

boardio.o: plansza.o

plansza.o: plansza.h state.h

rules.o: rules.h state.h neighborhood.h

$(NBHOOD_TYPE)neighborhood.o: neighborhood.h plansza.h

.PHONY: clean cleanbmps testnbh

clean:
	rm -f *.o test/*.o *.out

cleanbmps:
	cd output; rm *.bmp

## testy

diode1: $(NAME)
	./$< test2/$@ 20 1 output/ww_$@

## stare testy

zabka: $(NAME)
	./$< test/$@ 20 1 output/$@

diehard: $(NAME)
	./$< test/$@ 150 1 output/$@

glider: $(NAME)
	./$< test/$@ 200 1 output/$@

gosperglidergun: $(NAME)
	./$< test/$@ 100 2 output/$@

lwss: $(NAME)
	./$< test/$@ 40 1 output/$@

gosperglidergun2: $(NAME)
	./$< test/$@ 100 1 output/$@

## testy neighborhood

nbhood_test.out: test/nbhood_test.o plansza.o rules.o neighborhood.o boardio.o
	$(CC) -o $@ $^ $(LFLAGS)

testnbh: nbhood_test.out
	./nbhood_test.out test/dane2

## inne

bmplibfix:
	LD_LIBRARY_PATH=$(LDIR)/lib \
export LD_LIBRARY_PATH
