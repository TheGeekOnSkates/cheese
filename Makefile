all:
	clear && gcc ./*.c -ocheese -Wall || exit 1
	./cheese
