//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

struct Point {
	int x, y;
	Point(int _x, int _y) {
		x = _x,	y = _y;
	}
	Point(){x = -1, y = -1;}
};

int a[1111][1111];
int b[1111][1111];

int main()
{
	int n;

	Sf("%d", &n);

	Point topleft, topright, botleft, botright;

	forn(i, n)	forn(j, n)
		Sf("%d", &a[i][j]);

	if(n % 2 == 1) {
		b[n/2][n/2] = a[n/2][n/2];
		topleft = Point(n/2-1, n/2-1);
		topright = Point(n/2+1, n/2-1);
		botleft = Point(n/2-1, n/2+1);
		botright = Point(n/2+1, n/2+1);
	}
	else {
		topleft = Point(n/2-1, n/2-1);
		topright = Point(n/2, n/2-1);
		botleft = Point(n/2-1, n/2);
		botright = Point(n/2, n/2);
	}

	bool flag = true;

	if((n/2) % 2 == 1)
		flag = false;

	while(topleft.x >= 0 && topleft.y >= 0) {

		int x = topleft.x, y = topleft.y;

		if(flag ) {
			while(x < topright.x) {
				b[x+1][y] = a[x][y];
				x++;
			}
			while(y < botright.y) {
				b[x][y+1] = a[x][y];
				y++;
			}
			while(x > botleft.x ) {
				b[x-1][y] = a[x][y];
				x--;
			}
			while(y > topleft.y) {
				b[x][y-1] = a[x][y];
				y--;
			}
		}
		else {
			while(y < botleft.y) {
				b[x][y+1] = a[x][y];
				y++;
			}
			while(x < botright.x) {
				b[x+1][y] = a[x][y];
				x++;
			}
			while(y > topright.y) {
				b[x][y-1] = a[x][y];
				y--;
			}
			while(x > topleft.x) {
				b[x-1][y] = a[x][y];
				x--;
			}
		}

		topleft.x--;	topleft.y--;
		topright.x++;	topright.y--;
		botleft.x--;	botleft.y++;
		botright.x++;	botright.y++;
		flag = !flag;
	}
/*
	forn(i, n) {
		forn(j, n)
			Pf("%d ", a[i][j]);
		Pf("\n");
	}
	cout << endl;
*/
	forn(i, n) {
		forn(j, n)
			Pf("%d ", b[i][j]);
		Pf("\n");
	}
	
	return 0;
}

