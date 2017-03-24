Github URL: https://github.com/prajjwaldangal/SyntaxAnalysisProgrammingAssingment

1. March 19, 2017  12:13 AM EDT:
	added lex, getchar, getnonblank among other other function from the book

	https://github.com/prajjwaldangal/SyntaxAnalysisProgrammingAssingment/commit/ca79c648853a573f61e2d2d05f01d4be2faf1540

2. March 22, 2017	4:42 PM EDT:
	added getCharHelper() to account for reading multiple lines from the file, abandoned 	the approach later on

	https://github.com/prajjwaldangal/SyntaxAnalysisProgrammingAssingment/commit/fb6ac20e3d12ae50c0a18609cb5cb8946461f217

3. March 22, 2017		10:18 PM EDT:
	replaced getCharHelper by using getline, made necessary adjustments in main and 	
		getchar

	https://github.com/prajjwaldangal/SyntaxAnalysisProgrammingAssingment/commit/fe3802f073348e9bfa44c5ac4aac49836dbcef35

4.  March 23, 2017	2:34 PM EDT:
	Fixed getchar error, i.e. I was calling with wrong function name.
	Not a really major modification, but something that got me stuck for quite a while.

	https://github.com/prajjwaldangal/SyntaxAnalysisProgrammingAssingment/commit/2f9cb200f9700fc1c4ad25b26f6b8c221ed9c2ef
 
5. March 23, 2017	8:55 PM EDT:
	add done

	https://github.com/prajjwaldangal/SyntaxAnalysisProgrammingAssingment/commit/af2ffa1089d891beda19c1050768b61b8c23dd89


Instructions to compile:

1. Compile the main. file:
						gcc -o parser main.c
2. Run the executable generated thus by supplying the path of the input file as:
						/parser input.txt



	Reasons why the program is highly efficient:
1. Use of getline.
2. Use of line_ind (line index) to identify where syntax error occurs.

Also, if you 