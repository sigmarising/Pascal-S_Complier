pasc: pasc.l pasc.y
	yacc -d pasc.y
	lex pasc.l
	g++ -o pasc y.tab.c