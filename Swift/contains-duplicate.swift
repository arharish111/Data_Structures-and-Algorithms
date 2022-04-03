import Foundation
class Solution {
    func containsDuplicate(_ nums: [Int]) -> Bool {
       if nums.count <= 1 {
           return false
       } 
       var numSet = Set<Int>()
       for i in nums {
           if numSet.contains(i) {
               return true
           }
           numSet.insert(i)
       }
       return false
    }
}