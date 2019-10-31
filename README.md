# Project printf
## Overview
Recreation of the printf function given by the standard library
## Usage
The function of printf produce output according to the format that will be decribed.
```
_printf [FORMAT] [ARGUMENTS...]
```
• The format specifier is used during input and output. It is a way to tell the compiler what type of data is in a variable

• The arguments are the ones from which a specifier will take its value for it to be printed

*examples*
```
#input
int main()
{
	int len;
	len =_printf("%s\n", "Hello, World");
	_printf("%d\n", len);
}

#expected output
Hello, World
12
```
This function prints the string on standard output and returns the number of character printed, the format is a string starting with % alongside with the character "s".

After that, it prints the number on standard output according with what returned from the fisrt printf, strating with % along with the character "d", what will replace the format with the conversion of it with the value given in the argument.

# References
[1] GeeksforGeeks: A computer science portal for geeks [online] [Consultation date: 10/31/2019] Availabel on: https://www.geeksforgeeks.org/format-specifiers-in-c/
# Creators:

- Adrián Hernandez

- Manuel Mosquera