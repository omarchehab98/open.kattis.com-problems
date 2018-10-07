import sys

class Ferry:
    def __init__(self, length):
        self._side = -1
        self._length = length * 100
        self._cargo = 0

    def get_side(self):
        return 'left' if self._side == -1 else 'right'

    def can_load(self, length):
        return self._cargo + length < self._length

    def load(self, length):
        self._cargo += length

    def change_side(self):
        self._side *= -1

    def unload(self):
        self._cargo = 0

testCases = int(sys.stdin.readline())
for n in range(testCases):
    args = sys.stdin.readline().split(' ')
    ferry_length = int(args[0])
    ferry = Ferry(ferry_length)
    number_of_cars = int(args[1])
    left_queue = []
    right_queue = []
    for i in range(number_of_cars):
        args = sys.stdin.readline().split(' ')
        side = args[1][:-1]
        if side == 'left':
            left_queue.append(int(args[0]))
        else:
            right_queue.append(int(args[0]))
    result = 0
    while len(left_queue) + len(right_queue) > 0:
        side = ferry.get_side()
        if side == 'left':
            while len(left_queue) > 0 and ferry.can_load(left_queue[0]):
                ferry.load(left_queue.pop(0))
        elif side == 'right':
            while len(right_queue) > 0 and ferry.can_load(right_queue[0]):
                ferry.load(right_queue.pop(0))
        ferry.change_side()
        result += 1
        ferry.unload()
    print(result)
