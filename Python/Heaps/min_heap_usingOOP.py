class MinHeap:
    def __init__(self):
        self.heap = []

    def push(self, value):
        self.heap.append(value)
        self._bubble_up(len(self.heap) - 1)

    def pop(self):
        if len(self.heap) == 0:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._sink(0)
        return root

    def _bubble_up(self, index):
        while index > 0:
            parent_index = (index - 1) // 2
            if self.heap[index] >= self.heap[parent_index]:
                break
            self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
            index = parent_index

    def _sink(self, index):
        left_child_index = 2 * index + 1
        right_child_index = 2 * index + 2
        smallest = index

        if (
            left_child_index < len(self.heap)
            and self.heap[left_child_index] < self.heap[smallest]
        ):
            smallest = left_child_index
        if (
            right_child_index < len(self.heap)
            and self.heap[right_child_index] < self.heap[smallest]
        ):
            smallest = right_child_index

        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._sink(smallest)

# Example usage of the custom Min-Heap:
min_heap = MinHeap()
min_heap.push(3)
min_heap.push(1)
min_heap.push(4)
min_heap.push(1)
min_heap.push(5)
min_heap.push(9)
min_heap.push(2)
min_heap.push(6)
min_heap.push(5)
min_heap.push(3)
min_heap.push(5)

min_sorted = []
while len(min_heap.heap) > 0:
    min_sorted.append(min_heap.pop())

print("Custom Min-Heap Sorted:", min_sorted)
