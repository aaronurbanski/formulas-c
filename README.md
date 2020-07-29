# formulas.c
Generate sets of notes as described in the book [An Improviser's OS by Wayne Krantz](https://waynekrantz.bandcamp.com/merch/wayne-krantz-an-improvisers-os-2nd-edition) (All Rights Reserved)

formulas.c is a simple C program that will generate a list of all possible note combinations for a given (optional) root note.

Usage: **formulas** [note]<br />
where [note] is a note name e.g. C, C#, Db, etc. If [note] is omitted, formulas are generated using notation a la Krantz (1, b2, 2, b3, 3, 4, b5, 5, b6, 6, b7, 7).

2048 sets of 1 through 12 notes will be generated. These comprise all possible combinations of notes in the chromatic scale which include the given root note. When no note is specified, the formulas are shown without reference to any particular pitch.

For more information, please [read the book](https://waynekrantz.bandcamp.com/merch/wayne-krantz-an-improvisers-os-2nd-edition) - no, really - it will tell you everything you need to know.
