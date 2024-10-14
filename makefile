rpg: Game.cpp Character.cpp Move.cpp Player.cpp Party.cpp Screens.cpp
	g++ -std=c++11 Game.cpp Character.cpp Move.cpp Player.cpp Party.cpp Screens.cpp -o rpg

run: rpg
	./rpg

clean:
	rm -f rpg
## Usage:
## To compile: Run make in your terminal.
## To run: Run make run.
## To clean: Run make clean.