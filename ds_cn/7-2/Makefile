main:
	@clang -o main main.c -Wall -g -Os -fno-omit-frame-pointer -fsanitize=address --std=c99 -DONLINE_JUDGE

test:	clean main
	@./main < in.txt
	
clean:
	@touch main
	@rm main
