class MaxHeap:
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
            if self.heap[index] <= self.heap[parent_index]:
                break
            self.heap[index], self.heap[parent_index] = self.heap[parent_index], self.heap[index]
            index = parent_index

    def _sink(self, index):
        left_child_index = 2 * index + 1
        right_child_index = 2 * index + 2
        largest = index

        if (
            left_child_index < len(self.heap)
            and self.heap[left_child_index] > self.heap[largest]
        ):
            largest = left_child_index
        if (
            right_child_index < len(self.heap)
            and self.heap[right_child_index] > self.heap[largest]
        ):
            largest = right_child_index

        if largest != index:
            self.heap[index], self.heap[largest] = self.heap[largest], self.heap[index]
            self._sink(largest)

# Example usage of the custom Max Heap:
max_heap = MaxHeap()
max_heap.push(3)
max_heap.push(1)
max_heap.push(4)
max_heap.push(1)
max_heap.push(5)
max_heap.push(9)
max_heap.push(2)
max_heap.push(6)
max_heap.push(5)
max_heap.push(3)
max_heap.push(5)

max_sorted = []
while len(max_heap.heap) > 0:
    max_sorted.append(max_heap.pop())

print("Custom Max Heap Sorted:", max_sorted)
