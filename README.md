# 42push_swap
Implementing a sorting algorithm in C using stack data structure.

## Algorithm (Almighty Push Swap)
<img src="https://github.com/rajh-phuyal/42push_swap/assets/81531002/bb7550cc-9f11-40e5-aa5b-bbe96d871129" alt="APS" style="width: 90vw; height: 65vh;">

![Screenshot from 2023-11-12 23-10-14](https://github.com/rajh-phuyal/42push_swap/assets/117525743/7bc39584-4e91-4f31-bfa7-dbaa781f2705)



### Description
The goal of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you'll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

- **push_swap** - calculates and displays on the standard output the smallest progam using `push_swap` instruction language that sorts integer arguments received.

---

### Team
`push_swap` is a solo project but we decided to work together to create our own algorithm.
But the implementation of the algorithm was done individually.
We acheived 125/100 on this project.
You can check both of our implementations here:
- [**@Rajh Phuyal**]((https://github.com/rajh-phuyal/42push_swap))
- [**@AshParker19**](https://github.com/AshParker19/42_push_swap)


### Motivation
We thought creating our own algorithm to sort data would be a fun challenge.
After a lot of trial and error we finally came up with a solution that works.
The final verson of the algorithm is a many many iterations of the initial idea.
We learned a lot about how to optimize code and how to use the stack data structure.
This project helped us to improve our problem-solving skills, our ability to work in a team
and algorithmical thinking.

---

### Moves allowed to be performed on the stack
- **`sa`** - swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **`sb`** - swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **`ss`** - sa and sb at the same time.
- **`pa`** - push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **`pb`** - push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **`ra`** - rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- **`rb`** - rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- **`rr`** - ra and rb at the same time.
- **`rra`** - reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- **`rrb`** - reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- **`rrr`** - rra and rrb at the same time.

---


## Stats
| **Number of elements** | Average result | Best result | Visual |
| :----------------: | :---------: | :---------: | :---------: | 
|   100             |    615      |    570       | ![100](https://github.com/rajh-phuyal/42push_swap/assets/117525743/f1a20e1d-e58d-4a2b-9b1f-fa9f23c6dee0) |
|   500             |    5100     |    4800      | ![500](https://github.com/rajh-phuyal/42push_swap/assets/117525743/71bc155f-af43-4bc1-bc79-9324b8cb86e7) |

---

### Preparing for the algorithm
The algorithm is based on the idea of sorting the data in chunks.
The size of the chunks is calculated based on the size of the stack.

Dividing of the stack for chunks :
| Size of stack | Chunksize | Number of chunks | Remaining nodes on stack A |
| :-----------: | :-----------: | :-----------: | :-----------: |
| 100 | 12 | 8 | 4 |
| 500 | 35 | 14 | 10 |

_Remaining nodes on stack A: <10 nodes left to be sorted differently_

For the rest of the other sizes of stack we use the following formula:
```
number of chunks = 10 % of stacksize
chunksize = stacksize / number of chunks
```

## Sorting

### Small Data Set (<= 5 numbers)
**Sorting 3 numbers :**
```
Only few combinations of possibilities exist for sorting 3 numbers.
We needed to sort any combination of 3 numbers in 2 moves.
Pseudo code for sorting 3 numbers:
if stack if size 2:
    swap top two elements
else if first element is max:
    rotate stack
else if second element is max:
    reverse rotate stack
if first element is greater than second element:
    swap top two elements
```

**Sorting 5 numbers :**
```
We needed to sort any combination of 5 numbers in 12 moves at most.
Pseudo code for sorting 5 numbers:
Find the smallest number and push it to stack B
Find the second smallest number and push it to stack B
Sort the stack A using the sorting algorithm for 3 numbers
Push the second smallest number to stack A
Push the smallest number to stack A
```

The algorithm is divided into two parts:

_`Sending chunks to stack B`_

Starting from the smallest chunk pair, APS tries to find lowest cost for the nodes of those chunks.
APS makes three comparisons for the nodes of the chunks:
```
1. The cost of the node nearest to the top edge and the node nearest to the bottom edge for the first chunk.
2. The same for the second chunk.
3. The comparision between the least costly nodes from both chunks.
```

Now, APS has the least costly node to send to the stack B.
Based on the proximity of the node form either edge (North or South), APS either does
`ra` or `rra` to the node until it is at the top of stack A and can be pushed to stack B.
If in any of those cases it is possible to use the `rr` instruction, APS uses it.

APS repeats the above steps for each chunk pair until the last one.

For the last two chunks APS splits the chunks into two halves and sends the smaller numbers to the bottom
of stack B and keeps larger numbers at the top.

Stack A has <10 numbers which are sorted using the `sort 3` and `sort 5` algorithms.

Now, APS has all the numbers in stack B chunked and is ready to send it back to stack A.

_`Sending nodes back to stack A`_

Sending back to stack A relies on the similar idea of the direction, cost and proximity of the nodes to the edge.
But with a key difference, the difference being that APS is now calculating the cost and the direction for the
`biggest` and the `second biggest` values in the stack B.

_`APS keeps track of the last sent node to stack A`_
![pushswap](https://github.com/rajh-phuyal/42push_swap/assets/81531002/af1123ef-bc31-4552-b2bc-0a01e9347c57)



### Terminology
- **APS** - Almighty Push Swap
- **Stack** - A stack of numbers.
- **Node** - A number in the stack.
- **Stack A** - The stack that contains the numbers to be sorted.
- **Stack B** - The stack that is used to sort the numbers.
- **Chunk** - A group of numbers that are sorted in ascending order.
- **Chunk pair** - Two chunks that are consecutively.
- **Chunksize** - The size of the chunk.
- **Number of chunks** - The number of chunks in the stack.
- **Edges** - The first and the last nodes of the stack being the edge.
- **Direction** - From the middle if the node is closer to the top, its North else its South.
- **Cost** - The cost of sending a node to the top of the stack and to the other stack.

---

### Installation && Usage
1. Clone the repo
```sh
git clone
```
2. Run make in the root directory
```sh
make
```
3. Run the program
```sh
./push_swap 1 2 3 4 5
```

---

### Resources
- [**Linked List**](https://en.wikipedia.org/wiki/Linked_list)
- [**Stack Data Structure**](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [**Sorting Algorithms**](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [**Big O Notation**](https://en.wikipedia.org/wiki/Big_O_notation)
- [**Push Swap Visualizer**](https://github.com/o-reo/push_swap_visualizer.git)
- [**Push Swap Tester**](https://github.com/louisabricot/push_swap_tester)
