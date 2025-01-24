// 9248 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Suffix
{
  int index;
  int rank[2];

  bool operator<(const Suffix& other) {
    return (rank[0]==other.rank[0])? rank[1]<other.rank[1] : rank[0]<other.rank[0];
  }
};

void print_vectors(const std::vector<Suffix>& suffixes, const std::string& s, int k=-1)
{
  std::cout << "i\t\tleft-rank\t\tright-rank\t\tindex\t\tsub-string\n\n";
  for (int i=0;i<suffixes.size();++i) {
    std::cout << i << "\t\t\t" << suffixes[i].rank[0] << "\t\t\t\t" << suffixes[i].rank[1] << "\t\t\t" << suffixes[i].index << "\t\t\t";
    std::string substr;
    if (k==-1 || suffixes[i].index+k>=s.size()) substr = s.substr(suffixes[i].index);
    else substr = s.substr(suffixes[i].index, k);
    std::cout << substr << '\n';
  }
  std::cout << "----------------------------------------------------------------" << std::endl;
}

std::vector<int> suffix_array(const std::string& s)
{
  int n=s.size();
  std::vector<Suffix> suffixes(n);
  std::vector<int> rank(n);
  
  for (int i=0;i<n;++i) {
    suffixes[i].index = i;
    suffixes[i].rank[0] = s[i];
    suffixes[i].rank[1] = (i+1<=n)? s[i+1] : 0;
  }

  // print_vectors(suffixes, s, 2);
  std::sort(suffixes.begin(), suffixes.end());
  // print_vectors(suffixes, s, 2);
  
  auto make_rank = [&] () {
    int r=1;
    rank[suffixes[0].index] = r;
    for (int i=1;i<n;++i) {
      if (suffixes[i].rank[0]!=suffixes[i-1].rank[0] || suffixes[i].rank[1]!=suffixes[i-1].rank[1]) {
        ++r;
      }
      rank[suffixes[i].index] = r;
    }
  };

  for (int k=2;k<=n;k<<=1) {
    make_rank();
    for (int i=0;i<n;++i) {
      suffixes[i].rank[0] = rank[i];
      suffixes[i].rank[1] = (i+k<n)? rank[i+k]: 0;
      suffixes[i].index = i; 
    }
    std::sort(suffixes.begin(), suffixes.end());
    // print_vectors(suffixes, s, k*2);
  }

  
  std::vector<int> result(n);
  for (int i=0;i<n;++i) {
    result[i] = suffixes[i].index;
  }

  return result;
}


std::vector<int> LCP(const std::vector<int>& sa, const std::string& s)
{
  int n=s.size();
  std::vector<int> rank(n), lcp(n-1);

  for (int i=0;i<n;++i) {
    rank[sa[i]] = i;
  }
  // std::cout << "RANK: ";
  // for (int i: rank) std::cout << i << ' ';
  // std::cout << std::endl;

  int k=0;
  // std::cout << "FOR LOOP:";
  for (int i=0;i<n;++i) {
    // std::cout << "\n\ti=" << i << ", rank[i]=" << rank[i] << "\n\tsuffix: " << s.substr(sa[rank[i]]) << std::endl;
    if (rank[i]>0) {
      int j = sa[rank[i]-1];
      // std::cout << "\tPrevious suffix: " << s.substr(j) << std::endl;
      int m = std::max(i, j);
      // std::cout << "\t(i, j) = (" << i << ", " << j << ')' << std::endl;
      while (m+k<n && s[i+k]==s[j+k])  ++k;
      lcp[rank[i]-1]=k;
      if (k>0) --k;
    }
  }
  return lcp;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string str;  std::cin >> str;
  std::vector<int> sa = suffix_array(str);

  for (const int& i: sa) {
    std::cout << i+1 << ' ';
  }
  std::cout << '\n' << 'x' << ' ';
  for (const int& i: LCP(sa, str)) {
    std::cout << i << ' ';
  }

  return 0;
}
