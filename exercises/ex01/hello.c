#include <stdio.h>

int main() {
    int x = 5; /* The added assembly are */
              /* subq	$16, %rsp */
              /* movl	$5, -4(%rbp) */
    int y = x + 1;
    printf("Hello, World! y = %d\n", y);
    return 0;
  }

/*
Question 2: When turning on optimization using flag -O2,
  additional assembly are created at the top and the body of main is shortened.
  The line of x = 5 in assembly is removed.

Question 3: The line movl	$5, -4(%rbp) becomes movl	$5, %edx which is shorter.
  And four lines of the ass
  The part of the assembly that is about the main function is shorter with
  optimization and additional lines such as
  ".section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.section	.text.startup,"ax",@progbits
.LHOTB1:
	.p2align 4,,15
	.globl	main" are added. printf in the assembly becomes __printf_chk.

Question 4
  With optimization, instead of sotring the value of both x and y, the value of
  y is computed during compilation and value of x is not stored in assembly.
  Optimization increases compilation time and the performance of the generated
  code and therefore decreases runtime by trying to reduce code size for the
  functions.
*/
