CFLAGS = -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

runTestDom: testdom
	rm testdominion.out
	rm gameResults.out
	./testdom >> gameResults.out 2>&1
	gcov dominion.c >> testdominion.out 2>&1
	cat dominion.c.gcov >> testdominion.out 2>&1

testdom: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c testdominion.c rngs.c assert.o -o testdom -lm -g

assert.o: assert.h assert.c
	gcc -c assert.c -g $(CFLAGS)

unit1: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest1.c rngs.c assert.o -o unittest1 -lm -g

unit2: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest2.c rngs.c assert.o -o unittest2 -lm -g

unit3: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest3.c rngs.c assert.o -o unittest3 -lm -g

unit4: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c unittest4.c rngs.c assert.o -o unittest4 -lm -g

card1: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest1.c rngs.c assert.o -o cardtest1 -lm -g

card2: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest2.c rngs.c assert.o -o cardtest2 -lm -g

card3: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest3.c rngs.c assert.o -o cardtest3 -lm -g

card4: assert.o
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.c cardtest4.c rngs.c assert.o -o cardtest4 -lm -g


myTest: unit1 unit2 unit3 unit4 card1 card2 card3 card4
	rm unittestresults.out
	./unittest1 >> unittestresults.out 2>&1
	./unittest2 >> unittestresults.out 2>&1
	./unittest3 >> unittestresults.out 2>&1
	./unittest4 >> unittestresults.out 2>&1
	./cardtest1 >> unittestresults.out 2>&1
	./cardtest2 >> unittestresults.out 2>&1
	./cardtest3 >> unittestresults.out 2>&1
	./cardtest4 >> unittestresults.out 2>&1
	gcov dominion.c >> unittestresults.out 2>&1
	cat dominion.c.gcov >> unittestresults.out 2>&1

unittestresults.out: myTest

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
