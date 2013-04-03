/*
	abc_string_replacement.cpp
	by PG @ SENSE Lab / Copyright(c) 2013
	Released under the MIT License

	Give you a string that contains a, b, or c only.
	Replace two different adjacent chars with another one untill only one type of char left.
	Ex. aaabbc >> aa[ab][bc] >> aaca >> a[ac]a >> aba >> [ab]a >> ca >> [ca] >> b

*/

#include <iostream>
#define NEXT_CHAR(q) ((char)('a' + (q - 'a' + 1)%3) )
using namespace std;

char transfer(char tp, int times, char in) // type, repeat times, char_input
{
	int diff;
	int tp_num = tp - 'a';
	if ( NEXT_CHAR(tp) == in) diff = 0;
	else diff = 1;
	static char table[3][2] =
	{
		{'b', 'c'},
		{'c', 'a'},
		{'a', 'b'}
	};
	return table[tp_num][(times + diff)%2];
}
int main()
{
	string q;
	while (cin >> q)
	{
		char tp = q[0];
		int times = 1;
		for (int i = 1; i < q.size(); i++)
		{
			if (q[i] != tp)
			{
				tp = transfer(tp, times, q[i]);
				times = 1;
			}
			else times++;
		}
		for (int i = 0; i < times; i++) cout << tp;
		cout << endl;
	}
}