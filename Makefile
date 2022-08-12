all:
	clear && gcc ./*.c -ocheese -Wall || exit 1
	./cheese

tests:
	clear && ./cheese pack ./tests/test1.asm ./tests/test1.kso || exit 1
	./cheese ./tests/test1.kso || exit 1
