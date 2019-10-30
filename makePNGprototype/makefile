#Andrew Chittick
#makefile compile makePNG

#make a PNG
makePNG: main.o lodepng.o
	g++ main.o lodepng.o -o makePNG

#make a main
main: main.cpp lodepng.h
	g++ -c main.cpp

#make lodepng
lodepng: lodepng.cpp lodepng.h
	g++ -c lodepng.cpp

#make clean
clean:
	rm -f *.o
	rm makePNG

#make run
run: makePNG
	./makePNG

#end makefile
