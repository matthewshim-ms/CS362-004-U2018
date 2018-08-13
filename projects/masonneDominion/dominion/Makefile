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

unittest1.o: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	
unittest2.o: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	
unittest3.o: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unittest4.o: unittest4.c dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest1.o: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest2.o: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest3.o: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	
cardtest4.o: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)
	
<<<<<<< HEAD
randomtestcard1.o: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestcard2.o: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	
randomtestadventurer.o: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	
	
=======
>>>>>>> c9ddf737b50e74f811f74776d5660536af51420f
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

<<<<<<< HEAD
unittestresults.out: unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o cardtest4.o randomtestadventurer.o randomtestcard1.o randomtestcard2.o dominion.o rngs.o
=======
unittestresults.out: unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o cardtest4.o dominion.o rngs.o
>>>>>>> c9ddf737b50e74f811f74776d5660536af51420f
		echo "Dominion Unit Test Results:\n" > unittestresults.out
		
		echo "Unit test 1 test:" >> unittestresults.out
		unittest1 >> unittestresults.out
		gcov unittest1.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Unit test 2 test:" >> unittestresults.out
		unittest2 >> unittestresults.out
		gcov unittest2.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Unit test 3 test:" >> unittestresults.out
		unittest3 >> unittestresults.out
		gcov unittest3.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Unit test 4 test:" >> unittestresults.out
		unittest4 >> unittestresults.out
		gcov unittest4.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Card test 1 test:" >> unittestresults.out
		cardtest1 >> unittestresults.out
		gcov cardtest1.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Card test 2 test:" >> unittestresults.out
		cardtest2 >> unittestresults.out
		gcov cardtest2.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Card test 3 test:" >> unittestresults.out
		cardtest3 >> unittestresults.out
		gcov cardtest3.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Card test 4 test:" >> unittestresults.out
		cardtest4 >> unittestresults.out
		gcov cardtest4.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
<<<<<<< HEAD
		
		echo "Random Card test 1 test:" >> unittestresults.out
		randomtestcard1 >> unittestresults.out
		gcov randomtestcard1.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Random Card test 2 test:" >> unittestresults.out
		randomtestcard2 >> unittestresults.out
		gcov randomtestcard2.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
		
		echo "Random Adventurer Card Test:" >> unittestresults.out
		randomtestadventurer >> unittestresults.out
		gcov randomtestadventurer.c >> unittestresults.out
		gcov dominion.c >> unittestresults.out
=======
>>>>>>> c9ddf737b50e74f811f74776d5660536af51420f

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
