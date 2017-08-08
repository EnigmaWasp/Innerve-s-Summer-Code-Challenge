#include <iostream>
using namespace std;
 
int main()
{
	int t;
	double u, v, x;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> u >> v >> x;
		printf("%.10lf\n", x/(u+v));
	}
	return 0;
} 
