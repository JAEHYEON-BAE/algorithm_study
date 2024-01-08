import Foundation

func algorithm(n: Int) -> Int {
    if (n%5 == 0) {return n/5}
    if (n%5 == 1 && n>=6) {return (n-6)/5 + 2}
    if (n%5 == 2 && n>=12) {return (n-12)/5 + 4}
    if (n%5 == 3 && n>=3) {return (n-3)/5 + 1}
    if (n%5 == 4 && n>=9) {return (n-9)/5 + 3}
    return -1
}

let n = Int(readLine()!)!
print(algorithm(n: n))