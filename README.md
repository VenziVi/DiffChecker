# Diff Tool Task

Diff checker is a tool that compares two .text files and finds the differences between them.
<<<<<<< HEAD
=======

The program reads the file paths from the input arguments and prints the result to the terminal.

-If files are identical prints: "Files are identical."

-In case of detected difference, the program marks different characters and lines with the "^" symbol.
>>>>>>> fedafbcd41be2a18476676534bebc90ef832941d

The program reads the file paths from the input arguments and prints the result to the terminal.

<<<<<<< HEAD
-If files are identical prints: "Files are identical."

-In case of detected difference, the program marks different characters and lines with the "^" symbol.
----

<br>

## Tests:

#### Left file: 
`helio thire!` 
`how` 
`ari you.`

#### Right file: 
`hello there` 
`how` 
`are you.`

#### Output: 
`Left  1: helio thire!` 
`Diff   : ^ ^ ^` 
`Right 1: hello there` 
`Left  3: ari you.` 
`Diff   :   ^` 
`Right 3: are you.`
=======
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
`Diff   : ^ ^ ^` <br> 
`Right 1: hello there` <br> 
`Left  3: ari you.` <br>
`Diff   :   ^` <br>
`Right 3: are you.` <br>
>>>>>>> fedafbcd41be2a18476676534bebc90ef832941d

------------------

#### Left file: 
<<<<<<< HEAD
` ` 
` `

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
=======
` ` <br>
` ` <br>

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
>>>>>>> fedafbcd41be2a18476676534bebc90ef832941d

