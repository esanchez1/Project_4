prog: main.o hangman.o tictacto.o Trivia.o Test.o Executive_Black_Jack.o Player.o
	g++ -std=c++11 -g -Wall main.o hangman.o tictacto.o Trivia.o Test.o Executive_Black_Jack.o Player.o -o prog

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

tictacto.o: tictacto.h tictacto.cpp
	g++ -std=c++11 -g -Wall -c tictacto.cpp tictacto.h

Trivia.o: Trivia.h Trivia.cpp
	g++ -std=c++11 -g -Wall -c Trivia.cpp Trivia.h

Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp Test.h

hangman.o: hangman.h hangman.cpp
	g++ -std=c++11 -g -Wall -c hangman.cpp hangman.h

Executive_Black_Jack.o: Executive_Black_Jack.h Executive_Black_Jack.cpp
	g++ -std=c++11 -g -Wall -c Executive_Black_Jack.cpp Executive_Black_Jack.h

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp Player.h

clean:
	rm -fr *.o prog.* hangman.h.gch tictacto.h.gch Trivia.h.gch Executive_Black_Jack.h.gch Player.h.gch Test.h.gch
