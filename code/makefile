CC = g++
CFLAGS = -O -g
OBJS = pasc.tab.o Syntax_Tree.o 
pasc:$(OBJS)
	$(CC) $(CFLAGS) -o pasc $(OBJS) 

Syntax_Tree.o:Syntax_Tree.cpp

pasc.tab.o:pasc.tab.c

clean:
	rm -f *.o pasc
