//
//  Suhanna and Matrix World.cpp
//  
//
//  Created by Dagny L. on 08.08.17.
//
//

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long n, x, y;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        x = n / 3;
        y = 2*(n / 3);
        n %= 3;
        switch(n)
        {
            case 2:
                y++;
            case 1:
                x++;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
