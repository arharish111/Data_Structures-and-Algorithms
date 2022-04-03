import Foundation
class Solution {
    func romanToInt(_ s: String) -> Int {
        let knownRomanSymbols:[String:Int] = [
            "I":1,
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000
        ]
        
        if let val = knownRomanSymbols[s]{
            return val
        }
        let stack = Stack()
        for char in s
        {
            if let num = knownRomanSymbols[String(char)]
            {
                if stack.isEmpty
                {
                    stack.push(num)
                }
                else
                {
                    if stack.top() < num
                    {
                        let temp = num - stack.top()
                        stack.pop()
                        stack.push(temp)
                    }
                    else
                    {
                        stack.push(num)
                    }
                }
            }
        }
        var result = 0
        while !stack.isEmpty
        {
            result += stack.top()
            stack.pop()
        }
        return result
    }
    func strStr(_ haystack: String, _ needle: String) -> Int {
        
       if needle.count < 1
        {
            return 0
        }
        if needle.count > haystack.count {return -1}
         
        let distance = haystack.count - needle.count
        
        for i in 0...distance
        {
            let sIndex = haystack.index(haystack.startIndex, offsetBy: i)
            let eIndex = haystack.index(haystack.startIndex, offsetBy: i+needle.count)
            
            if haystack[sIndex..<eIndex] == needle {return sIndex.utf16Offset(in: haystack)}
        }
        return -1
    }
    func countBits(_ num: Int) -> [Int] {
        var numsOfOne = [Int]()
        if num < 0 {return numsOfOne}
        var powersOfTwo = [Int]()
        for i in 0..<31
        {
            powersOfTwo.append(Int(pow(Double(2),Double(i))))
        }
        numsOfOne.append(0)
        if num == 0 {return numsOfOne}
        var lastPowerOfTwo = 0
        for i in 1...num
        {
            if powersOfTwo.contains(i)
            {
                numsOfOne.append(1)
                lastPowerOfTwo = i
            }
            else
            {
                numsOfOne.append(numsOfOne[lastPowerOfTwo]+numsOfOne[i-lastPowerOfTwo])
            }
        }
        return numsOfOne
    }
}