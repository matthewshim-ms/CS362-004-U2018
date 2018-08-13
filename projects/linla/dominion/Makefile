CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
# To run playdom you need to enter: ./playdom <any integer number>
# Example: ./playdom 10

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

myTests: randomtestcard1.out randomtestcard2.out randomtestadventurer.out

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

unittests: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o
	gcc -o unittests -g unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o $(CFLAGS)

cardtests: cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc -o cardtests -g cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o $(CFLAGS)

unittestresults: unittests cardtests
	echo "unit tests:" >> unittestresults.out
	unittests >> unittestresults.out
	echo "card tests:" >> unittestresults.out
	cardtests >> unittestresults.out
	gcov dominion.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
