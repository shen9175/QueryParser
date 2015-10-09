# QueryParser

Learn the new features of C++11 by reading C++ primer 5th edition
This a practice and implementation of C++ primer 5th edition book's class query example
with self implement operator (),OR, AND, NOT with flex and bison.
The parser is built with flex with regular expressions
The grammar is built with bison.
The rest of them are built with C++11



Alice Emma has long flowing red hair.
Her Daddy says when the wind blows
through her hair, it looks almost alive,
like a fiery bird in flight.
A beautiful fiery bird, he tells her,
magical but untamed.
"Daddy, shush, there is no such thing,"
she tells him, at the same time wanting
him to tell her more.
Shyly, she asks, "I mean, Daddy, is there?"
------------------------------------------------------------
shen9175@TOSHIBA:~/practice/QueryParser$ ./Query test.txt
Now process the file: test.txt:
enter word to look for, or q to quit: Daddy
Executing Query for: Daddy
Daddy occurs 3 times
	(line 2)Her Daddy says when the wind blows
	(line 7)"Daddy, shush, there is no such thing,"
	(line 10)Shyly, she asks, "I mean, Daddy, is there?"
enter word to look for, or q to quit: ~Alice
Executing Query for: ~(Alice)
~(Alice) occurs 9 times
	(line 2)Her Daddy says when the wind blows
	(line 3)through her hair, it looks almost alive,
	(line 4)like a fiery bird in flight.
	(line 5)A beautiful fiery bird, he tells her,
	(line 6)magical but untamed.
	(line 7)"Daddy, shush, there is no such thing,"
	(line 8)she tells him, at the same time wanting
	(line 9)him to tell her more.
	(line 10)Shyly, she asks, "I mean, Daddy, is there?"
enter word to look for, or q to quit: hair|Alice
Executing Query for: (hair | Alice)
(hair | Alice) occurs 2 times
	(line 1)Alice Emma has long flowing red hair.
	(line 3)through her hair, it looks almost alive,
enter word to look for, or q to quit: hair&Alice
Executing Query for: (hair & Alice)
(hair & Alice) occurs 1 time
	(line 1)Alice Emma has long flowing red hair.
enter word to look for, or q to quit: fiery&bird|wind
Executing Query for: ((fiery & bird) | wind)
((fiery & bird) | wind) occurs 3 times
	(line 2)Her Daddy says when the wind blows
	(line 4)like a fiery bird in flight.
	(line 5)A beautiful fiery bird, he tells her,
enter word to look for, or q to quit: fiery&(bird|wind)
Executing Query for: (fiery & (bird | wind))
(fiery & (bird | wind)) occurs 2 times
	(line 4)like a fiery bird in flight.
	(line 5)A beautiful fiery bird, he tells her,
enter word to look for, or q to quit: q
shen9175@TOSHIBA:~/practice/QueryParser$ 
