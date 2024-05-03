FLAGS = -Wall -Wextra -g

all: listen_up

listen_up: SongMenu.o Song.o BST_song.o BST_songTitle.o Heap.o Manager.o
	g++ SongMenu.o Song.o BST_song.o BST_songTitle.o Heap.o Manager.o -o listen_up

SongMenu.o: SongMenu.cpp
	g++ $(FLAGS) -c SongMenu.cpp

Song.o: Song.cpp Song.h 
	g++ $(FLAGS) -c Song.cpp

BST_song.o: BST_song.cpp BST_song.h
	g++ $(FLAGS) -c BST_song.cpp

BST_songTitle.o: BST_songTitle.cpp BST_songTitle.h
	g++ $(FLAGS) -c BST_songTitle.cpp

Heap.o: Heap.cpp Heap.h
	g++ $(FLAGS) -c Heap.cpp	

Manager.o: Manager.cpp Manager.h
	g++ $(FLAGS) -c Manager.cpp

clean:
	rm -f *.o listen_up