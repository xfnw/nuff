nuff is a fork of a presentation tool


Dependencies

You need Xlib, Xft, and libpng

Demo

To get a little demo, just type

	make && ./nuff example

You can navigate with the arrow keys and quit with `q`.


Usage

	nuff [FILE]

If FILE is omitted or equals `-`, stdin will be read. Produce image slides by
prepending a `@` in front of the filename as a single paragraph. Lines starting
with `#` will be ignored. A `\` at the beginning of the line escapes `@` and
`#`. A presentation file could look like this:

	nuff
	
	@nyan.png
	
	depends on
	- Xlib
	- Xft
	- libpng
	
	nuff FILENAME
	one slide per paragraph
	# This is a comment and will not be part of the presentation
	\# This and the next line start with backslashes
	
	\@FILE.png
	
	thanks / questions?


