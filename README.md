# Diff Tool Task

Diff checker is a tool that compares two .text files and finds the differences between them.

The program reads the file paths from the input arguments and prints the result to the terminal.

-If files are identical prints: "Files are identical."

-In case of detected difference, the program marks different characters and lines with the "^" symbol.

<br>

## Tests:

#### Left file: 
`helio thire!` <br>
`how` <br>
`ari you.` <br>

#### Right file: 
`hello there` <br>
`how` <br>
`are you.` <br>

#### Output: 
`Left  1: helio thire!` <br>
`Diff   :    ^    ^  ^` <br>
`Right 1: hello there` <br>
`Left  3: ari you.` <br>
`Diff   :   ^` <br>
`Right 3: are you.` <br>

------------------

#### Left file: 
`   ` <br>
`   ` <br>

#### Right file: 
`hello` <br>
`world` <br>

#### Output: 
`Left  1: ` <br>
`Diff   : ^^^^^` <br>
`Right 1: hello` <br>
`Left  2:` <br>
`Diff   : ^^^^^` <br>
`Right 2: world` <br>


