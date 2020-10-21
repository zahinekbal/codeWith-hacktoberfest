extension Array {
    
    mutating func rotate(positions: Int) {
        let elementsToMove = self[..<positions]
        let topElements = self[positions...]
        self = Array(topElements) + Array(elementsToMove)
    }

}

// Example

var test = [1, 2, 3, 4, 5]
test.rotate(positions: 3)

print(test) // [4, 5, 1, 2, 3]
