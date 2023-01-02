# Input-C
[![standard-readme compliant](https://img.shields.io/badge/readme%20style-standard-brightgreen.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

Demonstrates how to read input from the command line with C99

## Table of Contents
- [Install](#install)
- [Usage](#usage)
- [Maintainers](#maintainers)
- [Contributing](#contributing)
- [License](#license)

## Install
There are 10 input demo programs and they can all be compiled with the included makefile; simply run `make all`. Each and every program meets the C99 standard and can be compiled with `-Wall`, `-Wextra`, and `-pedantic` without any errors. One of the programs will produce a depracation warning for use of the `gets()` function. You can safely ignore this warning because the purpose of the program is to demonstrate the shortcomings of the `gets()` function and to discourage you from using it.

```
%
% make all
gcc -Wall -Wextra -pedantic -std=c99 input1_str_gets.c -o input1.exe
input1_str_gets.c:11:9: warning: 'gets' is deprecated: This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of gets(3), it is highly recommended that you use fgets(3) instead. [-Wdeprecated-declarations]
...
All input programs have been built
Please consult the source code and run them one at a time
input1.exe: input1_str_gets.c
input2.exe: input2_str_scanf_bad.c
input3.exe: input3_str_scanf_good.c
input4.exe: input4_str_fgets_good.c
input5.exe: input5_str_fgets_better.c
input6.exe: input6_str_dynamic.c
input7.exe: input7_int_atoi.c
input8.exe: input8_int_scanf.c
input9.exe: input9_int_strtol.c
input.exe:  input.c (uses the console_util library)

%
```

All of the programs work with friendly inputs. But some of them contain buffer overflows or integer overflows. Some will return invalid answers for hostile input.

If you'd like to delete the 10 demo programs all at once, run `make clean`.

## Usage
Choose a demo to run and explore the source code. Work through them one at a time starting with `input1.exe` and moving towards `input9.exe`. The final program, `input.exe` uses the Console Utility Library and is a model for how you should safely handle `stdin` input.
```
%
% ./input3.exe
What is your favorite ice cream? chocolate
I like 'chocolate' too!
%
% ./input3.exe
What is your favorite ice cream? mint chip
I like 'mint' too!
%
% ./input3.exe
What is your favorite ice cream? WhiteChocolateMacademiaNut    
I like 'WhiteChocolateM' too!
%
```

The programs were intended to be run in a specific order:
1. input1_str_gets.c
1. input2_str_scanf_bad.c
1. input3_str_scanf_good.c
1. input4_str_fgets_good.c
1. input5_str_fgets_better.c
1. input6_str_dynamic.c
1. input7_int_atoi.c
1. input8_int_scanf.c
1. input9_int_strtol.c
1. input.c

## Maintainers

[@JoshuaTallman](https://github.com/prof-tallman)

## Contributing
These programs were written as an example for students.

## License
[MIT](LICENSE) © [@JoshuaTallman](https://github.com/prof-tallman)
