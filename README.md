# Diff Tool Task

Diff checker is a tool that compares two .text files and finds the differences between them.

The program reads the file paths from the input arguments and prints the result to the terminal.

-If files are identical prints: "Files are identical."

-In case of detected difference, the program marks different characters and lines with the "^" symbol.

<br>

## Tests:

#### Left file: 
`helio thire! 
`how 
`ari you.

#### Right file: 
`hello there 
`how 
`are you.

#### Output: 
`Left  1: helio thire!` 
`Diff   : ^ ^ ^` 
`Right 1: hello there` 
`Left  3: ari you.` 
`Diff   :   ^` 
`Right 3: are you.`

------------------

#### Left file: 
`` 
``

#### Right file: 
`hello` 
`world`

#### Output: 
`Left  1: ` 
`Diff   : ^^^^^` 
`Right 1: hello` 
`Left  2:` 
`Diff   : ^^^^^` 
`Right 2: world`


