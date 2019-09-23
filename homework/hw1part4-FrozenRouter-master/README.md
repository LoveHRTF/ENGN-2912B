# Assignment 01 (Part 4)

TA Comments:

Q1) How many decimal digits of precision a "float" and a "double" have? [1/5]

Q2) What are the general rules of conversion? [2/5]

Q3) [5/5]

Q4) What are the general rules of floating-point to integral type conversion? [0/5]

Q5) [5/5]

Q6) What is ilogb(v)-52 computing? When might such a test case fail? [2/5]

## Ziwei Chen

Insert your answers to the assignment questions below under the appropriate heading number.  Code should be checked into the repository using the naming scheme hw1pX.cpp (where X is the question number).

# 1.1
Precision for Double: 0.1458085799999999931930716456918162293732166290283203125, 55 digits in fractional part.
Reason for drop     : Double occupies 8 bytes of memory, a.k.a 64 bits. In which 52 bits were fraction part.
Precision for Float : 0.14580857753753662109375, 23 digits in fractional part
Reason for drop     : Float occupies 4 bytes of memory, a.k.a 32 bits. In which 32 bits were fraction part.
Which has been said that type double can go as little as 2^-52 for fraction accuracy, and type float can only go 2^-23. In this case, accuracy for double would be:
  +1 * biased exponent * fraction w/ resultion of 2^-52; for the float would be:
  +1 * biased exponent * fraction w/ resultion of 2^-23. Once it exceeds this range, the precision drops, and that is why double drops after 55 digits in fractional part while float drops only after 23 digits.

# 1.2
When doing the signed to unsigned casts, the value may wrap around, which results the unsigned data type to be overflowed. This results the
original value to be changed. The real output depends on what the input data type is, what the output data type is, and the specific value.
However, it is for sure that the cast from signed to any unsigned should be avoided for preventing any issue.

# 1.3
0x3F400000
Step 1: Convert to binary
0b 0011 1111 0100 0000 0000 0000 0000 0000
Step 2: Extract the sign, exponent, and fraction part
0|0111 1110|1000 0000 0000 0000 000
Step 3: Calculate each part
+1|126|1.5
Step 4: Apply the bias
+1|126 - 127|1.5
+1|-1|1.5
Step 5: Calculate the result
+1 * 2^-1 * 1.5 = +1 * 0.5 * 1.5 = 0.75

# 1.4
By doint cross-type comparisions, when both values were int, regardless signed or unsigned, or even float and double, as long as they have the same value, the cross-type comparision is always feasible. When the values were not equal, the cross-type comparisons will also gives the correct logical decision, either true or false. However, the compiler may gives a warning when one of the value exceed the range for the other, although this does not affect the final result.

# 1.5
The essencial idea for solving this problem was to have a tolerance that changes
base on the value of this perticular double value. A.K.A as the double value incerase, the tolerance value increase. With that being said, the approach was designed in following steps:
(1) Take the absoult value for this initial value
(2) Drop the precision for this value, and only keep it as an integer
(3) Convert this integer to a tolerance
(4) Do the value compaersion, any value within this tolerance would be considered as equal.

Otherwise solution from 1.6 can also be applied.

Essentially equal here means the two values should be equal from a mathematical point of view, however were calculated differently by program
due to issues such as data type precision. As a result, an approximation should be applied when comparing these two values.


# 1.6
hw1p6.cpp was designed to test the output tolerance 

Yes and No.
Accroding to description, ilogb() only cares about the unbiased exponents part, which means it will increase while the actual value increase.
However by running the test, I found that the tolerance will change, and increase when the actual value itself exponentially or squarely increases. However a linear curve does not necessary changes the eps output. Therefore, it would be okay to say that this test does work
for testing the equality, however there may be other better solution exists.
