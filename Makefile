default:
	g++ -std=c++26 -O3 -Wall -Wextra main.cpp src/algorithms/* src/graphics/* -lraylib -o main

run: default
	GLFW_PLATFORM=x11 ./main

clean:
	rm -rf main
