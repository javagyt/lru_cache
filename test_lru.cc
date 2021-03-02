#include "lru_cache_test.h"
#include <iostream>

using namespace std;

int main(int args, const char **argv)
{
  lrucache* lcache = new lrucache(3);
  lcache->set(1, 1);
  lcache->set(2, 2);
  cout << lcache->get(1) << endl;

  lcache->set(3, 3);
  lcache->set(4, 4);

  cout << lcache->get(2) << endl;

  return 0;
}
