/*
 * Modified CS:APP Data Lab
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Read the following instructions carefully.

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
  int pow2plus1(int x) {
      // exploit ability of shifts to compute powers of 2
      return (1 << x) + 1;
  }

  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
  int pow2plus4(int x) {
      // exploit ability of shifts to compute powers of 2
      int result = (1 << x);
      result += 4;
      return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any
arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  2. Use the btest test harness to check your functions for correctness.
  3. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
 */

/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x)
{
    return (x + (x >> 31)) ^ (x >> 31);
}

/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000, 0x80000000) = 0,
 *            addOK(0x80000000, 0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y)
{
    int same = !(((x ^ y) >> 31) & 0x1);
    int sign = ((x + y) >> 31) & 0x1;
    return !(same & (sign ^ ((x >> 31) & 0x1)));
}

/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x)
{
    x &= x >> 16;
    x &= x >> 8;
    x &= x >> 4;
    x &= x >> 2;
    return x & 1;
}

/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
    x &= x >> 16;
    x &= x >> 8;
    x &= x >> 4;
    x &= x >> 2;
    return (x >> 1) & 1;
}

/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x)
{
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    return x & 1;
}

/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x)
{
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    return (x >> 1) & 1;
}

/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x)
{
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    return (x ^ 1) & 1;
}

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x = (x & a4) + ((x >> 1) & a4);
    x = (x & a3) + ((x >> 2) & a3);
    x = (x & a2) + ((x >> 4) & a2);
    x = (x & a1) + ((x >> 8) & a1);
    x = (x & a0) + ((x >> 16) & a0);
    return x;
}

/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5, 3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit)
{
    int n = ~0;
    return (n << lowbit) & ~(n << highbit << 1);
}

/*
 * bitMatch - Create mask indicating which bits in x match those in y
 *            using only ~ and &
 *   Example: bitMatch(0x7, 0xE) = 0x6
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitMatch(int x, int y)
{
    return ~(~(x & y) & ~(~x & ~y));
}

/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y)
{
    return ~x & ~y;
}

/*
 * bitOr - x|y using only ~ and &
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y)
{
    return ~(~x & ~y);
}

/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7D3D591
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x = (x << 16) | ((x >> 16) & a0);
    x = ((x & a1) << 8) | ((x >> 8) & a1);
    x = ((x & a2) << 4) | ((x >> 4) & a2);
    x = ((x & a3) << 2) | ((x >> 2) & a3);
    return ((x & a4) << 1) | ((x >> 1) & a4);
}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
    return ~(x & y) & ~(~x & ~y);
}

/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m)
{
    int a = 0xFF;

    int n_shift = n << 3;
    int m_shift = m << 3;
    int remain = x & ~((a << n_shift) | (a << m_shift));

    int n_byte = (a & ((x & (a << n_shift)) >> n_shift)) << m_shift;
    int m_byte = (a & ((x & (a << m_shift)) >> m_shift)) << n_shift;

    return remain | n_byte | m_byte;
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
    x = !!x;
    x = ~x + 1;
    return (x & y) | (~x & z);
}

/*
 * countLeadingZero - count the number of zero bits preceding the
 *                    most significant one bit
 *   Example: countLeadingZero(0x00000F00) = 20,
 *            countLeadingZero(0x00000001) = 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int countLeadingZero(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x = ~x;

    x = (x & a4) + ((x >> 1) & a4);
    x = (x & a3) + ((x >> 2) & a3);
    x = (x & a2) + ((x >> 4) & a2);
    x = (x & a1) + ((x >> 8) & a1);
    x = (x & a0) + ((x >> 16) & a0);
    return x;
}

/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x)
{
    return ~(x & 1) + 1;
}

/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
int distinctNegation(int x)
{
    return !!((~x + 1) ^ x);
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *                Round toward zero
 *   Examples: dividePower2(15, 1) = 7, dividePower2(-33, 4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n)
{
    return (x + ((x >> 31) & ((1 << n) + ~0))) >> n;
}

/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void)
{
    int x = 0x55;
    x |= (x << 8);
    x |= (x << 16);
    return x;
}

/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *                  Should exactly duplicate effect of C expression (x*3/4),
 *                  including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x)
{
    int add;
    x = (x << 1) + x;
    add = (x >> 31) & 3;
    return (x + add) >> 2;
}

/*
 * fitsBits - return 1 if x can be represented as an n-bit, two's complement
 *            integer.
 *            1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
    int shift = 32 + (~n + 1);
    return !(x ^ (x << shift >> shift));
}

/*
 * fitsShort - return 1 if x can be represented as a 16-bit, two's complement
 *             integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x)
{
    return !(x ^ (x << 16 >> 16));
}

/*
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf)
{
    unsigned exp = (uf & 0x7F800000) >> 23;
    unsigned frac = (uf & 0x007FFFFF);
    if (exp == 0xFF && frac != 0)
        return uf;
    return 0x7FFFFFFF & uf;
}

/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *                  for floating point argument f.
 *                  Argument is passed as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point value.
 *                  Anything out of range (including NaN and infinity) should
 *                  return 0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
    unsigned sign = (uf & 0x80000000) >> 31;
    int exp = ((uf & 0x7F800000) >> 23) - 127;
    unsigned frac = (uf & 0x007FFFFF) | 0x00800000;
    unsigned num;

    if (exp < 0)
        return 0;
    else if (exp > 31)
        return 0x80000000u;

    if (exp < 23)
        num = frac >> (23 - exp);
    else
        num = frac << (exp - 23);

    if (sign)
        return ~num + 1;
    return num;
}

/*
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *                  Result is returned as unsigned int, but it is to be
 *                  interpreted as the bit-level representation of a
 *                  single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x)
{
    int sign = x & 0x80000000;
    int exp = -1;
    int frac = 0;

    if (x == 0)
        return 0;
    else if (x == 0x80000000)
        return 0xcf000000;

    if (sign)
        x = ~x + 1;

    frac = x;

    while (x) {
        x /= 2;
        exp++;
    }

    if (exp <= 23)
        frac <<= (23 - exp);
    else {
        frac += (1 << (exp - 24));
        if (!(frac << (55 - exp)))
            frac &= (0xFFFFFFFF << (exp - 22));
        if (!(frac & (1 << exp)))
            exp++;
        frac >>= (exp - 23);
    }

    frac &= 0x007fffff;

    exp = (exp + 127) << 23;

    return sign | exp | frac;
}

/*
 * floatIsEqual - Compute f == g for floating point arguments f and g.
 *                Both the arguments are passed as unsigned int's, but
 *                they are to be interpreted as the bit-level representations
 *                of single-precision floating point values.
 *                If either argument is NaN, return 0.
 *                +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 25
 *   Rating: 2
 */
int floatIsEqual(unsigned uf, unsigned ug)
{
    unsigned uf_usb = uf & 0x7FFFFFFF, ug_sub = ug & 0x7FFFFFFF;

    if (!(uf_usb | ug_sub))
        return 1;

    if (uf_usb > 0x7F800000 || ug_sub > 0x7F800000)
        return 0;

    return uf == ug;
}

/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *               Both the arguments are passed as unsigned int's, but
 *               they are to be interpreted as the bit-level representations
 *               of single-precision floating point values.
 *               If either argument is NaN, return 0.
 *               +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug)
{
    unsigned uf_usb = uf & 0x7FFFFFFF, ug_sub = ug & 0x7FFFFFFF;
    unsigned uf_sign, ug_sign;
    unsigned uf_exp, ug_exp;
    unsigned uf_frac, ug_frac;

    if (uf_usb > 0x7F800000 || ug_sub > 0x7F800000)
        return 0;

    if (!(uf_usb | ug_sub))
        return 0;

    uf_sign = !!(uf & 0x80000000);
    ug_sign = !!(ug & 0x80000000);

    if (uf_sign < ug_sign)
        return 0;
    else if (uf_sign > ug_sign)
        return 1;

    uf_exp = uf & 0x7F800000;
    ug_exp = ug & 0x7F800000;

    uf_frac = uf & 0x007FFFFF;
    ug_frac = ug & 0x007FFFFF;

    if (uf_sign == 0) {
        if (uf_exp < ug_exp)
            return 1;
        else if (uf_exp > ug_exp)
            return 0;
        return uf_frac < ug_frac;
    } else {
        if (uf_exp < ug_exp)
            return 0;
        else if (uf_exp > ug_exp)
            return 1;
        return uf_frac > ug_frac;
    }
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level
 *               representations of single-precision floating point values.
 *               When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf)
{
    if ((uf & 0x7FFFFFFF) > 0x7F800000)
        return uf;

    return uf ^ 0x80000000;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *               (2.0 raised to the power x) for any 32-bit integer x.
 *
 *               The unsigned value that is returned should have the
 *               identical bit representation as the single-precision
 *               floating-point number 2.0^x.
 *               If the result is too small to be represented as a denorm,
 *               return 0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    if (x < -127)
        return 0;
    if (x > 128)
        return 0x7F800000;
    return (x + 127) << 23;
}

/*
 * floatScale1d2 - Return bit-level equivalent of expression 0.5*f for
 *                 floating point argument f.
 *                 Both the argument and result are passed as unsigned int's,
 *                 but they are to be interpreted as the bit-level
 *                 representation of single-precision floating point values.
 *                 When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale1d2(unsigned uf)
{
    unsigned sign = uf & 0x80000000;
    unsigned exp = uf & 0x7F800000;

    if (exp >= 0x7F800000)
        return uf;

    exp >>= 23;
    if (exp <= 1) {
        if ((uf & 3) == 3)
            uf += 2;
        return sign | ((uf >> 1) & 0x007FFFFF);
    }

    return (uf & 0x807FFFFF) | ((exp - 1) << 23);
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *               floating point argument f.
 *               Both the argument and result are passed as unsigned int's,
 *               but they are to be interpreted as the bit-level representation
 *               of single-precision floating point values.
 *               When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
    unsigned sign = uf & 0x80000000;
    unsigned exp = (uf & 0x7F800000) >> 23;

    if (exp == 255)
        return uf;

    if (exp == 0)
        return sign | (uf << 1);

    exp++;
    if (exp == 255)
        return sign | 0x7F800000;

    return (uf & 0x807FFFFF) | (exp << 23);
}

/*
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *                floating point argument f.
 *                Both the argument and result are passed as unsigned int's,
 *                but they are to be interpreted as the bit-level
 *                representation of single-precision floating point values.
 *                When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf)
{
    int exp = (uf & 0x7F800000) >> 23;
    int sign = uf & 0x80000000;
    int cnt = 22;
    if (exp == 0) {
        if (!(uf & 0x007E0000))
            return (uf << 6) | sign;
        while (!(uf & (1 << cnt)))
            cnt--;
        uf <<= (23 - cnt);
        return sign | (uf & 0x807FFFFF) | ((cnt - 16) << 23);
    }
    if (exp == 255)
        return uf;
    exp += 6;
    if (exp >= 255)
        return 0x7F800000 | sign;
    return (uf & 0x807FFFFF) | (exp << 23);
}

/*
 * floatUnsigned2Float - Return bit-level equivalent of expression (float) u
 *                       Result is returned as unsigned int, but it is to be
 *                       interpreted as the bit-level representation of a
 *                       single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatUnsigned2Float(unsigned u)
{
    int exp = -1;
    int frac = 0;

    if (u == 0)
        return 0;

    frac = u;

    while (u) {
        u /= 2;
        exp++;
    }

    if (exp <= 23)
        frac <<= (23 - exp);
    else {
        frac += (1 << (exp - 24));
        if (!(frac << (55 - exp)))
            frac &= (0xFFFFFFFF << (exp - 22));
        if (!(frac & (1 << exp)))
            exp++;
        frac >>= (exp - 23);
    }

    frac &= 0x007fffff;

    exp = (exp + 127) << 23;

    return exp | frac;
}

/*
 * getByte - Extract byte n from word x
 *           Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
    return (x >> (n << 3)) & 0xFF;
}

/*
 * greatestBitPos - return a mask that marks the position of the
 *                  most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x & ((~x >> 1) ^ (1 << 31));
}

/* howManyBits - return the minimum number of bits required to represent x in
 *               two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
    int sign, bit0, bit1, bit2, bit4, bit8, bit16;

    sign = x >> 31;

    x = (sign & ~x) | (~sign & x);

    bit16 = !!(x >> 16) << 4;
    x = x >> bit16;

    bit8 = !!(x >> 8) << 3;
    x = x >> bit8;

    bit4 = !!(x >> 4) << 2;
    x = x >> bit4;

    bit2 = !!(x >> 2) << 1;
    x = x >> bit2;

    bit1 = !!(x >> 1);
    x = x >> bit1;

    bit0 = x;

    return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}

/*
 * implication - return x -> y in propositional logic - 0 for false,
 *               1 for true
 *   Example: implication(1, 1) = 1
 *            implication(1, 0) = 0
 *   Legal ops: ! ~ ^ |
 *   Max ops: 5
 *   Rating: 2
 */
int implication(int x, int y)
{
    return (!x) | y;
}

/*
 * intLog2 - return floor(log base 2 of x), where x > 0
 *   Example: intLog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int intLog2(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    x = (x & a4) + ((x >> 1) & a4);
    x = (x & a3) + ((x >> 2) & a3);
    x = (x & a2) + ((x >> 4) & a2);
    x = (x & a1) + ((x >> 8) & a1);
    x = (x & a0) + ((x >> 16) & a0);
    return x + ~0;
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters
 *                '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
    return !((x >> 3) ^ 6) | !(x ^ 0x38) | !(x ^ 0x39);
}

/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y)
{
    return !(x ^ y);
}

/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y)
{
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int equal = (!(sign_x ^ sign_y)) & ((~y + x) >> 31);
    int not_equal = sign_x & !sign_y;
    return !(equal | not_equal);
}

/*
 * isLess - if x < y  then return 1, else return 0
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y)
{
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int equal = (!(sign_x ^ sign_y)) & ((~x + y) >> 31);
    int not_equal = (!sign_x) & sign_y;
    return !(equal | not_equal);
}

/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int equal = (!(sign_x ^ sign_y)) & !((~y + x) >> 31);
    int not_equal = (!sign_x) & sign_y;
    return !(equal | not_equal);
}

/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x)
{
    return !!(x >> 31);
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNonNegative(int x)
{
    return !(x >> 31);
}

/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x)
{
    return !!x;
}

/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y)
{
    return !!(x ^ y);
}

/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567E6AC2480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x)
{
    int x_ = x;
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x_ = (x_ << 16) | ((x_ >> 16) & a0);
    x_ = ((x_ & a1) << 8) | ((x_ >> 8) & a1);
    x_ = ((x_ & a2) << 4) | ((x_ >> 4) & a2);
    x_ = ((x_ & a3) << 2) | ((x_ >> 2) & a3);
    x_ = ((x_ & a4) << 1) | ((x_ >> 1) & a4);

    return !(x ^ x_);
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x)
{
    return !(x >> 31) & !!x;
}

/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x)
{
    int minus_noe = (~0 ^ (x >> 31));
    return !((x & (x + minus_noe)) | !x);
}

/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
    x++;
    return (!((~x + 1) ^ x)) & !!x;
}

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x)
{
    return (!((~x + 1) ^ x)) & !!x;
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x)
{
    return !x;
}

/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x)
{
    return x & (~x + 1);
}

/*
 * leftBitCount - returns count of number of consective 1's in
 *                left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x)
{
    int a0 = 0xFF | (0xFF << 8);
    int a1 = a0 ^ (a0 << 8);
    int a2 = a1 ^ (a1 << 4);
    int a3 = a2 ^ (a2 << 2);
    int a4 = a3 ^ (a3 << 1);

    x = ~x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x = ~x;

    x = (x & a4) + ((x >> 1) & a4);
    x = (x & a3) + ((x >> 2) & a3);
    x = (x & a2) + ((x >> 4) & a2);
    x = (x & a1) + ((x >> 8) & a1);
    x = (x & a0) + ((x >> 16) & a0);
    return x;
}

/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
    x |= x >> 16;
    x |= x >> 8;
    x |= x >> 4;
    x |= x >> 2;
    x |= x >> 1;
    return (x ^ 1) & 1;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *                Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n)
{
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}

/*
 * maximumOfTwo - compute the maximum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int maximumOfTwo(int x, int y)
{
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int same = ~(!(sign_x ^ sign_y)) + 1;
    int larger = ~((x - y) >> 31);
    return (same & ((larger & x) | (~larger & y))) |
           (~same & ((sign_y & x) | (sign_x & y)));
}

/*
 * minimumOfTwo - compute the minimum of two integers without branching
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int minimumOfTwo(int x, int y)
{
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int same = ~(!(sign_x ^ sign_y)) + 1;
    int larger = ~((x - y) >> 31);
    return (same & ((larger & y) | (~larger & x))) |
           (~same & ((sign_x & x) | (sign_y & y)));
}

/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void)
{
    return (1 << 31) >> 31;
}

/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *                   Should exactly duplicate effect of C expression (x*5/8),
 *                   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x)
{
    int add;
    x = (x << 2) + x;
    add = (x >> 31) & 7;
    return (x + add) >> 3;
}

/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
    return ~x + 1;
}

/*
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void)
{
    int x = 0xAA;
    x |= x << 8;
    x |= x << 16;
    return x;
}

/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *                   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15, 2) = 3, remainderPower2(-35, 3) = -3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int remainderPower2(int x, int n)
{
    int sign = x >> 31;
    int pos = x + (~((x >> n) << n) + 1);
    int neg;
    x = ~x + 1;
    neg = x + (~((x >> n) << n) + 1);
    neg = ~neg + 1;

    return (~sign & pos) | (sign & neg);
}

/*
 * replaceByte(x,n,c) - Replace byte n in x with c
 *                      Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678, 1, 0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c)
{
    int mask = 0xFF << (n << 3);
    return (mask & (c << (n << 3))) | (~mask & x);
}

/*
 * rotateLeft - Rotate x to the left by n
 *              Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateLeft(int x, int n)
{
    int mask = ((1 << 31) >> (31 - n));
    int r = (((((1 << 31) >> n) << 1) & x) >> (32 + (~n + 1)));
    return ((x << n) & mask) | (r & ~mask);
}

/*
 * rotateRight - Rotate x to the right by n
 *               Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321, 4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
int rotateRight(int x, int n)
{
    int mask = ((1 << 31) >> n) << 1;
    int r = (~((1 << 31) >> (31 + (~n + 1))) & x) << (32 + (~n + 1));
    return ((x >> n) & ~mask) | (r & mask);
}

/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000, 0x40000000) = 0x7fffffff
 *             satAdd(0x80000000, 0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y)
{
    int sum = x + y;
    int sign = sum >> 31;
    int overflow =
        (((!(x >> 31) ^ (y >> 31)) & !!((sum >> 31) ^ (x >> 31))) << 31) >> 31;
    return (overflow & ((~sign & (1 << 31)) | (sign & ~(1 << 31)))) |
           (~overflow & sum);
}

/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x80000001) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x)
{
    int sign_x = x >> 31;
    int sign_2x = (x << 1) >> 31;
    int overflow = ~(!(sign_x ^ sign_2x)) + 1;
    return (overflow & (x << 1)) |
           (~overflow & ((~sign_x & ~(1 << 31)) | (sign_x & (1 << 31))));
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *   Examples: satMul3(0x10000000) = 0x30000000
 *             satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *             satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *              satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *             satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int satMul3(int x)
{
    int x2 = x + x;
    int x3 = x + x2;
    int g = ((x ^ x2) | (x ^ x3)) >> 31;
    return ((~g) & x3) + (g & ((1 << 31) + ~(x >> 31)));
}

/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *   Examples: sign(130) = 1
 *             sign(-23) = -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 2
 */
int sign(int x)
{
    return (x >> 31) | (!!x);
}

/*
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *                    where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x)
{
    int sign = x >> 31;
    int mag = x & ~(1 << 31);
    return (sign & (~mag + 1)) | (~sign & mag);
}

/*
 * specialBits - return bit pattern 0xffca3fff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 3
 *   Rating: 1
 */
int specialBits(void)
{
    return ~(0xD7 << 14);
}

/*
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000, 0x80000000) = 1,
 *            subtractionOK(0x80000000, 0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y)
{
    int x_y_not_same_sign = !!((x >> 31) ^ (y >> 31));
    int y_sub_same_sign = !(((x - y) >> 31) ^ (y >> 31));
    return !(x_y_not_same_sign & y_sub_same_sign);
}

/*
 * thirdBits - return word with every third bit (starting from the LSB)
 *             set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int thirdBits(void)
{
    int x = 0x49;
    x |= (x << 9);
    x |= (x << 18);
    return x;
}

/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void)
{
    return ~(1 << 31);
}

/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
    return 1 << 31;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *                   avoiding errors due to overflow
 *   Examples: trueFiveEighths(11) = 6
 *             trueFiveEighths(-9) = -5
 *             trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 4
 */
int trueFiveEighths(int x)
{
    int const eights = x >> 3;
    int const rem = x & 7;
    return eights + (eights << 2) + ((rem + (rem << 2) + (x >> 31 & 7)) >> 3);
}

/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *                    avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    int const four = x >> 2;
    int const rem = x & 3;
    return four + (four << 1) + ((rem + (rem << 1) + (x >> 31 & 3)) >> 2);
}

/*
 * twosComp2SignMag - Convert from two's complement to sign-magnitude
 *                    where the MSB is the sign bit
 *                    You can assume that x > TMin
 *   Example: twosComp2SignMag(-5) = 0x80000005.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int twosComp2SignMag(int x)
{
    int sign = x >> 31;
    int mag = (sign & (~x + 1)) | (~sign & x);
    return (sign & (1 << 31)) | mag;
}

/*
 * upperBits - pads n upper bits with 1's
 *             You may assume 0 <= n <= 32
 *   Example: upperBits(4) = 0xF0000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 1
 */
int upperBits(int n)
{
    int except = ~(!n) + 1;
    return ~except & ((1 << 31) >> (n + ~0));
}
