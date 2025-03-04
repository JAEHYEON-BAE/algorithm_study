// 7881

#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(a) std::cerr << "CHECKPOINT #" << a << std::endl

const int INF=(~0u)>>2;
const int nINF=(1<<31);
const int power10[10]={1, 10, 100, 1'000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000, 1'000'000'000};

/** Wilson's theorem
  *  : for arbitary prime number p>2, (p-1)! == p-1 (mod p)
  *
  *   Let A={a | s.t. a in Z and 1<=a<=p-1}.
  *   |A| = even number
  *
  *   for arbitary elements x in A, it has a p modular inverse  y of p in A
  *
  *   if x==y, x^2 == 1 (mod p)
  *            (x+1)(x-1) == 0 (mod p)
  *            x == 1 (mod p) or x == -1 (mod p)
  *            therfore, for 1 and p-1, its modular inverse is itself.
  *            for other elements in A, it has another modular inverse.
  *
  *   it means, except for 1 and p-1, each element x in A can be faired with y(s.t. x!=y) in A, x*y == 1 (mod p)
  *   Therefore, (p-1)! == 1*(p-1) (mod p)
  *                     == p-1 (mod p)
  *
  *   Q.E.D.
  */


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  const int MAX=3*1'000'000+7;
  std::vector<bool> is_prime(MAX, true);
  is_prime[0]=false, is_prime[1]=false;
  for (int i=2;i*i<=MAX;++i) {
    if (is_prime[i]) {
      for (int j=i<<1;j<=MAX;j+=i) is_prime[j]=false;
    }
  }
  std::vector<int> cnts(MAX, 0);
  int cnt=0;
  for (int i=1;i<=1'000'000;++i) {
    if (is_prime[3*i+7]) ++cnt;
    cnts[i]=cnt;
  }
  int t, n;  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cout << cnts[n] << '\n';
  }
  return 0;
}