
restoraid: restoraid.c
	$(CC) -o restoraid restoraid.c

clean:
	$(RM) restoraid

run:
	./restoraid < input.txt
