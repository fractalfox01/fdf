
# Ft_printf
##	c
The int argument is converted to an unsigned char, and the resulting character is written.

##  s
The char * argument is expected to be a pointer to an array of character type (pointer to a string).  Characters from
the array are written up to (but not including) a terminating NUL character; if a precision is specified, no more than
the number specified are written.  If a precision is given, no null character need be present; if the precision is not
specified, or is greater than the size of the array, the array must contain a terminating NUL character.

If the l (ell) modifier is used, the wchar_t * argument is expected to be a pointer to an array of wide characters
(pointer to a wide string).  For each wide character in the string, the (potentially multi-byte) sequence representing
the wide character is written, including any shift sequences.  If any shift sequence is used, the shift state is also
restored to the original state after the string.  Wide characters from the array are written up to (but not including)
a terminating wide NUL character; if a precision is specified, no more than the number of bytes specified are written
(including shift sequences).  Partial characters are never written.  If a precision is given, no null character need
be present; if the precision is not specified, or is greater than the number of bytes required to render the multibyte
representation of the string, the array must contain a terminating wide NUL character.

##	p	
The void * pointer argument is printed in hexadecimal (as if by \`%#x' or `%#lx').

## diouxX 
`w/flags: hh, h, l and ll`

The int (or appropriate variant) argument is converted to signed decimal (d and i), unsigned octal (o), unsigned deci-
mal (u), or unsigned hexadecimal (x and X) notation.  The letters \``abcdef'' are used for x conversions; the letters
``ABCDEF'' are used for X conversions.  The precision, if any, gives the minimum number of digits that must appear; if
the converted value requires fewer digits, it is padded on the left with zeros.

| Modifier       | d, i |          o, u, x, X     |       n    |
-----------------|------|-------------------------|-------------|
| hh             |signed char|    unsigned char   |      signed char *  |
| h              |   short   |    unsigned short  |      short *        |
| l (ell)        |  long     |    unsigned long   |      long *         |
| ll (ell ell)   |  long long|    unsigned long long|    long long *    |
---

<br/>

f with the following flags: l and L.

##  f

%f	floating-point number

____________________________________________________________
| Modifier  |  a, A, e, E, f, F, g, G                       |
------------|-----------------------------------------------|
|  l (ell)  |  double (ignored, same behavior as without it.|
|  L        |  long double                                  |
---


### _manage %%_

%

	A "%" is written.  No argument is converted.  The complete conversion specification is %%.


# flags \#0-+ and space

### \# 	  Various uses:

	The value should be converted to an "alternate form".  
	For c,d, i, n, p, s, and u conversions, this option
	has no effect.

	For o conversions, the precision of the number is increased to force the first character of the output string to a zero.

	For x and X conversions, a non-zero result has the string 0x (or 0X for X conversions) prepended to it.

	For a, A, e, E, f, F, g, and G conversions, the result will always contain a decimal point, even if no digits follow it (normally, a decimal point appears in the results of those conversions only if a digit follows).

	For g and G conversions, trailing zeros are not removed from the result as they would otherwise be.

| Option | Type   |    Description    |
|--------|--------|-------------------|
|  %#o   |(Octal) | 0 prefix inserted |
|  %#x   | (Hex)  | 0x prefix added to non-zero values.|	
| %#X    | (Hex)  | 0X prefix added to non-zero values.|
| %#e    |        | Always show the decimal point.|
| %#E    |        | Always show the decimal point.|
| %#f    |        | Always show the decimal point.|
| %#g    |        | Always show the decimal point trailing zeros not removed.|
| %#G    |        |Always show the decimal point trailing zeros not removed.|

### (zero) 0

	Zero padding.

	For all conversions except n, the converted value is padded on the left with zeros rather than
	blanks.  If a precision is given with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.

# \-

	A negative field width flag; the converted value is to be left adjusted on the field boundary.  Except for n
	conversions, the converted value is padded on the right with blanks, rather than on the left with blanks or
	zeros.  A - overrides a 0 if both are given.

### (space)

	A blank should be left before a positive number produced by a signed conversion (a, A, d, e, E, f, F, g, G,
	or i).

## \+

	A sign must always be placed before a number produced by a signed conversion.  A + overrides a space if both	are used.




# Manage minimum field-width

By default the width of a field will be the minimum required to hold the data. If you want to increase the field width you can use the following syntax.

<pre>
main()
  {
      int number    =  5;
      char *pointer = "little";

      printf("Here is a number-%4d-and a-%10s-word.\n", number, pointer);
  }
  
  /*********************************
   *
   *	Program result is:
   *
   * 	Here is a number-   5-and a-    little-word.
   *
   *********************************/
</pre>