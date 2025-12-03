#include <iostream>
int main(){int s,m;std::cin>>s>>m;std::cout<<(s<1024?"No thanks":((m|(s-1023))==m)?"Thanks":"Impossible");}