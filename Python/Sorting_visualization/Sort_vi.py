import pygame
import random
import math
pygame.init()

class DrawInformation:
	BLACK = (255, 118, 117)
	WHITE = (45, 52, 54)
	GREEN = 0, 255, 0
	RED = 255, 0, 0
	BACKGROUND_COLOR = WHITE

	GRADIENTS = [
		(128, 128, 128),
		(160, 160, 160),
		(192, 192, 192)
	]

	FONT = pygame.font.SysFont('comicsans', 40)
	LARGE_FONT = pygame.font.SysFont('comicsans', 50)

	SIDE_PAD = 100
	TOP_PAD = 150

	def __init__(self, width, height, lst):
		self.width = width
		self.height = height

		self.window = pygame.display.set_mode((width, height))
		pygame.display.set_caption("Sorting Algorithm Visualization")
		self.set_list(lst)

	def set_list(self, lst):
		self.lst = lst
		self.min_val = min(lst)
		self.max_val = max(lst)

		self.block_width = round((self.width - self.SIDE_PAD) / len(lst))
		self.block_height = math.floor((self.height - self.TOP_PAD) / (self.max_val - self.min_val))
		self.start_x = self.SIDE_PAD // 2


def draw(draw_info, algo_name, ascending):
	draw_info.window.fill(draw_info.BACKGROUND_COLOR)

	title = draw_info.LARGE_FONT.render(f"{algo_name} - {'Ascending' if ascending else 'Descending'}", 1, draw_info.GREEN)
	draw_info.window.blit(title, (draw_info.width/2 - title.get_width()/2 , 5))

	controls = draw_info.FONT.render("R - Reset | SPACE - Start Sorting | A - Ascending | D - Descending", 1, draw_info.BLACK)
	draw_info.window.blit(controls, (draw_info.width/2 - controls.get_width()/2 , 45))

	sorting = draw_info.FONT.render("I - Insertion Sort | B - Bubble Sort | M - Merge Sort | S - Selection Sort | H - Heap Sort | Q - Quick Sor | x - Radix Sort \n | L - Shell Sort | count Sort | Bucket Sort", 1, draw_info.BLACK)
	draw_info.window.blit(sorting, (draw_info.width/2 - sorting.get_width()/2 , 75))



	draw_list(draw_info)
	pygame.display.update()


def draw_list(draw_info, color_positions=None, clear_bg=False):
	if color_positions is None:
		color_positions = {}
	lst = draw_info.lst

	if clear_bg:
		clear_rect = (draw_info.SIDE_PAD//2, draw_info.TOP_PAD, 
						draw_info.width - draw_info.SIDE_PAD, draw_info.height - draw_info.TOP_PAD)
		pygame.draw.rect(draw_info.window, draw_info.BACKGROUND_COLOR, clear_rect)

	for i, val in enumerate(lst):
		x = draw_info.start_x + i * draw_info.block_width
		y = draw_info.height - (val - draw_info.min_val) * draw_info.block_height

		color = draw_info.GRADIENTS[i % 3]

		if i in color_positions:
			color = color_positions[i] 

		pygame.draw.rect(draw_info.window, color, (x, y, draw_info.block_width, draw_info.height))

	if clear_bg:
		pygame.display.update()

#range of elements of the list
def generate_starting_list(n, min_val, max_val):
	lst = []

	for _ in range(n):
		#random value between min_val and max_val inclusively
		val = random.randint(min_val, max_val)
		lst.append(val)

	return lst
#function to count the number of swaps in the list and show it on pygame window
def count_sort(draw_info, ascending=True):
	lst = draw_info.lst
	count = [0] * (max(lst) + 1)
	for i in lst:
		count[i] += 1
	i = 0
	for j, item in enumerate(count):
		for k in range(item):
			lst[i] = j
			i += 1
			draw_list(draw_info, {i - 1: draw_info.GREEN, i: draw_info.RED}, True)
			yield True
	return lst



def bubble_sort(draw_info, ascending=True):
	lst = draw_info.lst

	for i in range(len(lst) - 1):
		for j in range(len(lst) - 1 - i):
			num1 = lst[j]
			num2 = lst[j + 1]

			if (num1 > num2 and ascending) or (num1 < num2 and not ascending):
				lst[j], lst[j + 1] = lst[j + 1], lst[j]
				draw_list(draw_info, {j: draw_info.GREEN, j + 1: draw_info.RED}, True)
				yield True

	return lst

def insertion_sort(draw_info, ascending=True):
	lst = draw_info.lst

	for i in range(1, len(lst)):
		current = lst[i]

		while True:
			ascending_sort = i > 0 and lst[i - 1] > current and ascending
			descending_sort = i > 0 and lst[i - 1] < current and not ascending

			if not ascending_sort and not descending_sort:
				break

			lst[i] = lst[i - 1]
			i = i - 1
			lst[i] = current
			draw_list(draw_info, {i - 1: draw_info.GREEN, i: draw_info.RED}, True)
			yield True

	return lst
def heap_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def heapify(lst, n, i):
		largest = i
		l = 2 * i + 1
		r = 2 * i + 2

		if l < n and lst[i] < lst[l]:
			largest = l

		if r < n and lst[largest] < lst[r]:
			largest = r

		if largest != i:
			lst[i], lst[largest] = lst[largest], lst[i]
			draw_list(draw_info, {i: draw_info.GREEN, largest: draw_info.RED}, True)
			yield True
			yield from heapify(lst, n, largest)

	def heap_sort(lst, ascending=True):
		n = len(lst)

		for i in range(n, -1, -1):
			yield from heapify(lst, n, i)

		for i in range(n - 1, 0, -1):
			lst[i], lst[0] = lst[0], lst[i]
			draw_list(draw_info, {i: draw_info.GREEN, 0: draw_info.RED}, True)
			yield True
			yield from heapify(lst, i, 0)

		return lst

	yield from heap_sort(lst, ascending)
	return lst
def shell_sort(draw_info, ascending=True):
	lst = draw_info.lst

	gap = len(lst) // 2

	while gap > 0:
		for i in range(gap, len(lst)):
			temp = lst[i]
			j = i

			while j >= gap and lst[j - gap] > temp and ascending:
				lst[j] = lst[j - gap]
				j -= gap
				draw_list(draw_info, {j: draw_info.GREEN, j - gap: draw_info.RED}, True)
				yield True

			while j >= gap and lst[j - gap] < temp and not ascending:
				lst[j] = lst[j - gap]
				j -= gap
				draw_list(draw_info, {j: draw_info.GREEN, j - gap: draw_info.RED}, True)
				yield True

			lst[j] = temp
			draw_list(draw_info, {j: draw_info.GREEN}, True)
			yield True

		gap //= 2

	return lst

def counting_sort(draw_info, ascending=True):
	lst = draw_info.lst
	max_val = max(lst)
	min_val = min(lst)
	range1 = max_val - min_val + 1
	count = [0] * range1
	output = [0] * len(lst)

	for i, item in enumerate(lst):
		count[item - min_val] += 1

	for i in range(1, len(count)):
		count[i] += count[i - 1]

	for i in range(len(lst) - 1, -1, -1):
		output[count[lst[i] - min_val] - 1] = lst[i]
		count[lst[i] - min_val] -= 1
		draw_list(draw_info, {i: draw_info.GREEN, count[lst[i] - min_val]: draw_info.RED}, True)
		yield True

	for i in range(len(lst)):
		lst[i] = output[i]
		draw_list(draw_info, {i: draw_info.GREEN}, True)
		yield True

	return lst


def selection_sort(draw_info, ascending=True):
	lst = draw_info.lst

	for i in range(len(lst)):
		min_index = i

		for j in range(i + 1, len(lst)):
			if (lst[j] < lst[min_index] and ascending) or (lst[j] > lst[min_index] and not ascending):
				min_index = j
		lst[i], lst[min_index] = lst[min_index], lst[i]
		draw_list(draw_info, {i: draw_info.GREEN, min_index: draw_info.RED}, True)
		yield True
def merge_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def merge(lst, l, m, r):
		n1 = m - l + 1
		n2 = r - m

		L = [0] * (n1)
		R = [0] * (n2)

		for i in range(0, n1):
			L[i] = lst[l + i]

		for j in range(0, n2):
			R[j] = lst[m + 1 + j]

		i = 0
		j = 0
		k = l

		while i < n1 and j < n2:
			if (L[i] <= R[j] and ascending) or (L[i] >= R[j] and not ascending):
				lst[k] = L[i]
				i += 1
			else:
				lst[k] = R[j]
				j += 1
			k += 1
			draw_list(draw_info, {k: draw_info.GREEN}, True)
			yield True

		while i < n1:
			lst[k] = L[i]
			i += 1
			k += 1
			draw_list(draw_info, {k: draw_info.GREEN}, True)
			yield True

		while j < n2:
			lst[k] = R[j]
			j += 1
			k += 1
			draw_list(draw_info, {k: draw_info.GREEN}, True)
			yield True
			return lst
def cocktail_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def cocktail_shaker_sort(lst, ascending=True):
		n = len(lst)
		swapped = True
		start = 0
		end = n - 1

		while swapped:
			swapped = False

			for i in range(start, end):
				if (lst[i] > lst[i + 1] and ascending) or (lst[i] < lst[i + 1] and not ascending):
					lst[i], lst[i + 1] = lst[i + 1], lst[i]
					swapped = True
					draw_list(draw_info, {i: draw_info.GREEN, i + 1: draw_info.RED}, True)
					yield True

			if not swapped:
				break

			swapped = False
			end -= 1

			for i in range(end - 1, start - 1, -1):
				if (lst[i] > lst[i + 1] and ascending) or (lst[i] < lst[i + 1] and not ascending):
					lst[i], lst[i + 1] = lst[i + 1], lst[i]
					swapped = True
					draw_list(draw_info, {i: draw_info.GREEN, i + 1: draw_info.RED}, True)
					yield True

			start += 1

		return lst

	yield from cocktail_shaker_sort(lst, ascending)
	return lst

def merge_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def merge(lst, l, m, r):
		n1 = m - l + 1
		n2 = r - m

		L = [0] * (n1)
		R = [0] * (n2)

		for i in range(0, n1):
			L[i] = lst[l + i]

		for j in range(0, n2):
			R[j] = lst[m + 1 + j]

		i = 0
		j = 0
		k = l

		while i < n1 and j < n2:
			if (L[i] <= R[j] and ascending) or (L[i] >= R[j] and not ascending):
				lst[k] = L[i]
				i += 1
			else:
				lst[k] = R[j]
				j += 1
			k += 1
			draw_list(draw_info, {k: draw_info.GREEN}, True)
			yield True

		while i < n1:
			lst[k] = L[i]
			i += 1
			k += 1
			draw_list(draw_info, {k: draw_info.GREEN}, True)
			yield True

		while j < n2:
			lst[k] = R[j]
			j += 1
			k += 1
			draw_list(draw_info, {k: draw_info.GREEN}, True)
			yield True
			return lst

	def merge_sort(lst, l, r, ascending=True):
		if l < r:
			m = (l + (r - 1)) // 2

			yield from merge_sort(lst, l, m, ascending)
			yield from merge_sort(lst, m + 1, r, ascending)
			yield from merge(lst, l, m, r)

	yield from merge_sort(lst, 0, len(lst) - 1, ascending)
	return lst

def bucket_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def bucket_sort(lst, ascending=True):
		arr = []
		slot_num = 10
		for i in range(slot_num):
			arr.append([])

		for j in lst:
			index_b = int(slot_num * j)
			arr[index_b].append(j)

		for i in range(slot_num):
			arr[i] = sorted(arr[i])

		k = 0
		for i in range(slot_num):
			for j, item in enumerate(arr[i]):
				lst[k] = item
				k += 1
				draw_list(draw_info, {k: draw_info.GREEN}, True)
				yield True

	yield from bucket_sort(lst, ascending)
	return lst




def quick_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def partition(lst, low, high, ascending=True):
		i = (low - 1)
		pivot = lst[high]

		for j in range(low, high):
			if (lst[j] < pivot and ascending) or (lst[j] > pivot and not ascending):
				i = i + 1
				lst[i], lst[j] = lst[j], lst[i]
				draw_list(draw_info, {i: draw_info.GREEN, j: draw_info.RED}, True)
				yield True

		lst[i + 1], lst[high] = lst[high], lst[i + 1]
		draw_list(draw_info, {i + 1: draw_info.GREEN, high: draw_info.RED}, True)
		yield True
		return (i + 1)

	def quick_sort(lst, low, high, ascending=True):
		if low < high:
			pi = yield from partition(lst, low, high, ascending)
			yield from quick_sort(lst, low, pi - 1, ascending)
			yield from quick_sort(lst, pi + 1, high, ascending)

	yield from quick_sort(lst, 0, len(lst) - 1, ascending)
	return lst
def radix_sort(draw_info, ascending=True):
	lst = draw_info.lst

	def counting_sort(lst, exp1):
		n = len(lst)
		output = [0] * (n)
		count = [0] * (10)

		for i in range(0, n):
			index = (lst[i] // exp1)
			count[(index) % 10] += 1

		for i in range(1, 10):
			count[i] += count[i - 1]

		i = n - 1
		while i >= 0:
			index = (lst[i] // exp1)
			output[count[(index) % 10] - 1] = lst[i]
			count[(index) % 10] -= 1
			i -= 1

		i = 0
		for i in range(0, len(lst)):
			lst[i] = output[i]
			draw_list(draw_info, {i: draw_info.GREEN}, True)
			yield True

	max1 = max(lst)
	exp = 1
	while max1 // exp > 0:
		yield from counting_sort(lst, exp)
		exp *= 10
	return lst



#quick sort	algorithm function for pygame
# we will render the scree
#clicking different buttons and display of data on screen

def main():
	run = True #var for while loop
	clock = pygame.time.Clock()


	n = 30 #number of elements
	min_val = 1
	max_val = 100
	#we will do everything dynamicaly here so we don't have to hard code multiple time 
	#we will use the same function for all the algorithms
	#if we will change any verible the whole program will change accordingly

	lst = generate_starting_list(n, min_val, max_val) #if we will not create this function we dont have screen for display("no screen for display error occurs")
	#This function will draw a screen for us and without this we cannot show something on the acree
	#we will pass the list to this function with
	draw_info = DrawInformation(2000, 1400, lst)
	sorting = False
	ascending = True

	sorting_algorithm = bubble_sort
	sorting_algo_name = "Bubble Sort"
	sorting_algorithm_generator = None

# So whenever w are in pygame we need to have a while loop which always runs in background
# we will use this while loop to render the screen and display the data on screen
#if we Don't have this loop it will only draw for once and screen will vanish

	while run:
		clock.tick(10) #max num of time loop runs in 1 sec

		if sorting:
			try:
				next(sorting_algorithm_generator)
			except StopIteration:
				sorting = False
		else:
			draw(draw_info, sorting_algo_name, ascending)

		for event in pygame.event.get(): # This will return us list of all event occured since last loop
			#here it will provide the functionality for closing the screen 

			if event.type == pygame.QUIT:
				run = False

			if event.type != pygame.KEYDOWN:
				continue

			if event.key == pygame.K_r:
				lst = generate_starting_list(n, min_val, max_val)
				draw_info.set_list(lst)
				sorting = False
			elif event.key == pygame.K_SPACE and sorting is False:
				sorting = True
				sorting_algorithm_generator = sorting_algorithm(draw_info, ascending)
			elif event.key == pygame.K_a and not sorting:
				ascending = True
			elif event.key == pygame.K_d and not sorting:
				ascending = False
			elif event.key == pygame.K_i and not sorting:
				sorting_algorithm = insertion_sort
				sorting_algo_name = "Insertion Sort"
			elif event.key == pygame.K_b and not sorting:
				sorting_algorithm = bubble_sort
				sorting_algo_name = "Bubble Sort"
			elif event.key == pygame.K_m and not sorting:
				sorting_algorithm = merge_sort
				sorting_algo_name = "Merge Sort"
			elif event.key ==pygame.K_s and not sorting:
				sorting_algorithm = selection_sort
				sorting_algo_name = "Selection Sort"
			elif event.key == pygame.K_h and not sorting:
				sorting_algorithm = heap_sort
				sorting_algo_name = "Heap Sort"
			elif event.key == pygame.K_q and not sorting:
				sorting_algorithm = quick_sort
				sorting_algo_name = "Quick Sort"
			elif event.key == pygame.K_x and not sorting:
				sorting_algorithm = radix_sort
				sorting_algo_name = "Radix Sort"
			elif event.key == pygame.K_l and not sorting:
				sorting_algorithm = shell_sort
				sorting_algo_name = "Shell Sort"
			elif event.key == pygame.K_c and not sorting:
				sorting_algorithm = counting_sort
				sorting_algo_name = "Counting Sort"
			elif event.key == pygame.K_o and not sorting:
				sorting_algorithm = cocktail_sort
				sorting_algo_name = "Cocktail Sort"
			elif event.key == pygame.K_u and not sorting:
				sorting_algorithm = bucket_sort
				sorting_algo_name = "Bucket Sort"






 # As long as we have run = True this loop will run and when it ends then we have to close pygame window
	pygame.quit()

#This will insure that we are actually running this module and not importing it

if __name__ == "__main__":
	main()