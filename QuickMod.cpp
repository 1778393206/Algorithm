#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long QuickMode(long long a, long long b, long long mode)
{
	long long sum = 1;
	while (b) {
		if (b & 1) {
			sum = (sum * a) % mode;
		}
		b>>=1;
		a = (a * a) % mode;
	}
	return sum;
}
