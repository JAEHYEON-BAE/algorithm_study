var n: [Int] = Array(repeating: 0, count: 10036)
n[0] = 1
var i: Int = 9999
while (i != 0) {
    n[i + i%10 + (i/10)%10 + (i/100)%10 + (i/1000)%10] += 1
    i -= 1
}
while (i < 10001) {
    if (n[i] == 0) {
        print("\(i)")
    }
    i += 1
}