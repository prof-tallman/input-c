
all: input1.exe input2.exe input3.exe input4.exe input5.exe \
	 input6.exe input7.exe input8.exe input9.exe input.exe
	@echo
	@echo "All input programs have been built"
	@echo "Please consult the source code and run them one at a time"
	@echo "input1.exe: input1_str_gets.c"
	@echo "input2.exe: input2_str_scanf_bad.c"
	@echo "input3.exe: input3_str_scanf_good.c"
	@echo "input4.exe: input4_str_fgets_good.c"
	@echo "input5.exe: input5_str_fgets_better.c"
	@echo "input6.exe: input6_str_dynamic.c"
	@echo "input7.exe: input7_int_atoi.c"
	@echo "input8.exe: input8_int_scanf.c"
	@echo "input9.exe: input9_int_strtol.c"
	@echo "input.exe:  input.c (uses the console_util library)"
	@echo

input1.exe: input1_str_gets.c
	gcc -Wall -Wextra -pedantic -std=c99 input1_str_gets.c -o input1.exe

input2.exe: input2_str_scanf_bad.c
	gcc -Wall -Wextra -pedantic -std=c99 input2_str_scanf_bad.c -o input2.exe

input3.exe: input3_str_scanf_good.c
	gcc -Wall -Wextra -pedantic -std=c99 input3_str_scanf_good.c -o input3.exe

input4.exe: input4_str_fgets_good.c
	gcc -Wall -Wextra -pedantic -std=c99 input4_str_fgets_good.c -o input4.exe

input5.exe: input5_str_fgets_better.c
	gcc -Wall -Wextra -pedantic -std=c99 input5_str_fgets_better.c -o input5.exe

input6.exe: console_util.o input6_str_dynamic.c
	gcc -Wall -Wextra -pedantic -std=c99 input6_str_dynamic.c console_util.o -o input6.exe

input7.exe: input7_int_atoi.c
	gcc -Wall -Wextra -pedantic -std=c99 input7_int_atoi.c -o input7.exe

input8.exe: input8_int_scanf.c
	gcc -Wall -Wextra -pedantic -std=c99 input8_int_scanf.c -o input8.exe

input9.exe: input9_int_strtol.c
	gcc -Wall -Wextra -pedantic -std=c99 input9_int_strtol.c -o input9.exe

input.exe: console_util.o input.c
	gcc -Wall -Wextra -pedantic -std=c99 input.c console_util.o -o input.exe

console_util.o: console_util.c
	gcc -Wall -Wextra -pedantic -std=c99 -c console_util.c -o console_util.o


.PHONY: clean
clean:
	rm console_util.o
	rm input?.exe
	rm input.exe
