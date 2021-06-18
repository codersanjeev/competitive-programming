class Solution {
    func openLock(_ deadends: [String], _ target: String) -> Int {
        let wheels = 4, digits = 10, target = Int(target) ?? 0
        var states = [Bool](repeating: true, count: 10_000), queue = [Int](), turn = 0
        for deadend in deadends {
            states[Int(deadend) ?? 0] = false
        }

        func rotate(_ state: Int, _ wheel: Int, _ direction: Int) -> Int {
            var remainder = state, result = 0, divisor = 10_000
            for i in 0..<wheels {
                remainder %= divisor
                divisor /= 10
                let digit = remainder / divisor
                result += (wheel == i ? (digit + digits + direction) % digits : digit) * divisor
            }
            return result
        }

        func appendQueue(_ state: Int) {
            if states[state] {
                queue.append(state)
                states[state] = false
            }
        }

        appendQueue(0)
        while !queue.isEmpty {
            let nextQueue = queue
            queue = []
            for state in nextQueue {
                if state == target {
                    return turn
                }
                for i in 0..<wheels {
                    appendQueue(rotate(state, i, 1))
                    appendQueue(rotate(state, i, -1))
                }
            }
            turn += 1
        }
        return -1
    }
}