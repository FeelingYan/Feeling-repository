src = ./main.c $(wildcard ./src/*.c)
obj = $(patsubst %.c, %.o, $(src))
target = ./bin/app

$(target):$(obj)
	gcc $^ -o $@

%.o : %.c
	gcc -c $< -I ./inc -o $@

.PHONY:clean
clean:
	rm ./*.o ./src/*.o ./bin/app 



