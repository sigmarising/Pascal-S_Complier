CC = g++
CFLAGS = -g
OBJS = main.o Syntax_TTree.o pasc.tab.o SemanticAnalysis.o CodeGenerate.o

pas2c : $(OBJS)
	$(CC) $(CFLAGS) -o pas2c $(OBJS) 

$(OBJS) : Public_define.h Syntax_Tree.h

main.o : pasc.tab.c SemanticAnalysis.h CodeGenerate.h

Syntax_Tree.o : 

pasc.tab.o : lex.yy.c pasc.tab.h

SemanticAnalysis.o : SemanticAnalysis.h

CodeGenerate.o : CodeGenerate.h

clean:
	rm -f *.o pasc
