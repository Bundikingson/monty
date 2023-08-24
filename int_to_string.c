#include <stdlib.h>

int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);
char *get_int(int num);
unsigned int _abs(int);

/**
 * get_int - GETS a CHAR POINTER to NEW STRING containing INT..
 * @num: NUMBER to CONVERT TO STRING..
 *
 * RETURN: CHAR POINTER to newly created STRING. NULL if MALLOC FAILS..
 */

char *get_int(int num)

{
	unsigned int temp;
	int R = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	R = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		R++; /* negative sign */
	ret = malloc(R + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, R);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - GETS THE ABSOLUTE VAL of an INT..
 * @i: INT to GET ABSOLUTE VAL of
 *
 * RETURN: UNSIGNED INT abs rep of P ..
 */

unsigned int _abs(int P)

{
	if (P < 0)
		return (-(unsigned int)P);
	return ((unsigned int)P);
}

/**
 * get_numbase_len - GETS LENGTH OF BUFFER needed for an UNSIGNED INT..
 * @num: NUM TO GET LENGTH needed for..
 * @base: BASE OF NUM REP used by Buffer..
 *
 * RETURN: INT containing LENGTH OF BUFFER needed (doesn't contain null bt)..
 */

int get_numbase_len(unsigned int num, unsigned int base)

{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - FILLS BUFFER with correct numbers UP TO Base 36..
 * @num: NUM TO CONVERT TO string given base..
 * @base: BASE OF NUM used in conversion, only works up to base 36..
 * @buff: BUFFER to fill with result of conversion..
 * @buff_size: size of BUFFER in BYTES..
 *
 * RETURN: ALWAYS void..
 */

void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, P = buff_size - 1;

	buff[buff_size] = '\0';
	while (P >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[P] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[P] = rem + '0';
		num /= base;
		P--;
	}
}
