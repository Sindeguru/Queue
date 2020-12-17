#include <iostream>
#include <queue.h>
//#include <queue>

using namespace std;

int main()
{

  TQueue<int> A(2);
  A.Push(31);
  A.Push(2);
  cout << A.Pop() <<' ' << 31<<endl;
  cout << A.Pop() << ' ' <<2;

	return 0;
}