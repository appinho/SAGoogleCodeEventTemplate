# Template for Google Code Events

## Sources
https://cses.fi/book/book.pdf
https://cp-algorithms.com/


### Bit Manipulation

- pascal_walk(CJ20/1A/EASY): Walk through pascal triangle to achieve a sum  **Quadratic numbers/decomposing number**
- the_equation(KS19/G/MEDIUM): Find the maximum number K so that the XOR sum is less than a threshold to make the universe good **XOR/Greedy**
- x_or_what(KS19/D/EASY): Find the maximum interval of values that have an even XOR sum **XOR/Digit traversal**

### Complete Search
- a_whole_new_word(CJ18/1C/MEDIUM): Tiles of letters are forming words and a new unique word has to be found **Recursion/Set**
- code_eat_switcher_PAR.cpp(KS19/E/HARD): Find the right balance between coding and eating so that both achieve a minimum of units **Sorting/Binary Search**
- food_stalls(KS19/D/MEDIUM): Building stalls and warehouses to reduce the cost **Sorting/Long long**
- latest_guests(KS19/D/MEDIUM): Let G guests drive a long a circular street for M minutes and output for each guest how many consulates will remember him **Circular buffer**
- pylons(CJ19/1A/HARD): Place pylons in a grid so the adjacent numeration is not in same row, column or diagonal **Backtracing/Random**
- teach_me(KS19/F/HARD): Count the number of pairs so that the first entry can teach a skill to the second entry **Permutation/Subset**

### Dynamic Programming
- ant_stack(CJ18/1C/HARD): Maximum number of ants that form a stack so the lower one is larger and can carry the weight of the upper ones **Memset**
- building_palindromes(KS19/B/MEDIUM): Count the number of possible palindromes by checking N queries of intervals **Prefix sum/ASCII/Palindrome**
- plates(KS20/A/MEDIUM): Take P plates from N stacks of height K to maximize the sum value of them **0-1 Knapsack Problem**
- training(KS/19/A/MEDIUM): Find the minimum number of hours to spend to train a subset of size P from a team of size N that they have all equal level **Prefix sum**
- wandering_robot(KS20/B/MEDIUM): Calculate the probability that a robot does not fall into a rectangular hole within a grid by traversing through it **Grid traversal/Probability**

### Game Theory
- overrandomized(CJ20/1A/EASY): From 10000 queries determine what ten letters stand for to find decoding **Counting/Codeword**
- robot_programming_strategy(CJ19/1C/EASY): Find R/P/S to beat everybody with the same strategy in the tournament **Rock Paper Scissors**  
- senate_evacuation(CJ18/P/EASY): Release max. two senators at a time so there is no absolute majority in the room left  **ASCII/Max element**  
- you_can_go_your_own_way(CJ19/Q/EASY): Traverse through grid from top left to bottom right by doing the **Grid traversal/Opposite strategy**

### Graphs
- cherries_mesh(KS19/E/MEDIUM): All cherries are connected by red or black strands. Try to remove as much strands so that they are still connected **DFS/Connected Components**
- parcels(KS19/A/MEDIUM): Find the location in a grid to place a delivery shop to minimize the worst case delivery time **BFS/Manhattan Distance**
- stable_wall(KS20/C/MEDIUM): Find the topological order of placing items so it builds up a wall **Topological sort/DFS**

### Greedy

- allocation(KS20/A/EASY): Buy the maximum number of houses **Sorting**
- bus_routes(KS20/B/EASY): Find the latest point in time to take the busses to still arrive to a certain time by reverse calculation **Long long/Reverse**
- oversized_pancake_flippers(CJ17/P/HARD): Flip N pancakes with a flipper of width K to make all pancakes face the same side **Bit manipulation**
- parenting_partnering_returns(CJ20/Q/EASY): Come up with scheduler that kid is always observed by sorting intervals and then assigning **Scheduling**
- saving_the_universe_again(CJ18/Q/EASY): Find the minimum amount of hacks that needs to be done to protect the shield against charging and shooting commands of aliens **Swap**

### Grid
- circuit_board(KS19/C/MEDIUM): Find the maximum rectangle in a grid with a maximum difference of row cells of K **Stack/Histogram**
- expogo(CJ20/1B/MEDIUM): Jump in (i-1)^2 steps to see if you can reach a goal **Odd Even**  
- manhattan_crepe_cart(CJ19/1B/EASY): Find crepe cart in manhattan by **Manhattan Distance**
- overexcited_fan(CJ20/1C/EASY): Determine if a fan starting at 0,0 can reach a vip following a certain path **Manhattan Distance**
- robot_path_decoding(KS20/B/EASY): Decode the nested commands of robot movements to find the final cell **Stack/Nested/Parenthesis**
- square_dance(CJ20/1A/HARD): Each dancer in the grid battles against compass neighbors **Linked list**  
- vestigium(CJ20/Q/EASY): Compute trace and number of rows and columns with duplicated entries in Latin square matrix, when each row and cell have values from 1,...,N **Set**
- waffle_choppers(CJ18/1A/MEDIUM): Slide a waffle with chocolate bits vertically and horizontally so that each piece has the same numbers of chocolate bits **Sorting/Counting**
- wiggle walk(KS19/C/EASY): Follow a commands of movement by never stopping at a cell that has already been traversed **Grid traversal**

### Interactive

- blindfolded_bullseye(CJ20/1B/MEDIUM): Try to hit center of a bulls eye by finding its edges through **Binary search**
- draupnir(CJ19/1B/MEDIUM): determine the number of each type of X-day ring by querying the total number of rings in existence at the end of a certain day **Modulo/Power of two/Evolution**
- esab_atad(CJ20/Q/MEDIUM): 25% of complementing, reversing bits **Bit manipulation**
- go_gopher(CJ18/Q/EASY): Get a rectangle hole by letting gopher randomly dig in a 3x3 range **Probability/Set**
- golf_gophers(CJ19/1A/MEDIUM): Ask how much flags of a windmill have changed by querying prime numbers **Probability/Chinese remainder/Prime**  
- lollipop_shop(CJ18/1C/EASY): Sell least popular lollipop by tracking count of lollipops already sold **Greedy/Probabilistic**
- number_guessing(CJ18/P/EASY): Guessing the number within a range **Binary search**
- pottery_lottery(CJ19/2/MEDIUM): Manipulation election so that you maximize the chance to win the lottery **Probability/Voting**
- power_arrangers(CJ19/1C/EASY): Ask max. 150 times for a permutation out of 5 puppets to find that one missing out of 120. 119/23/5/1 **Permutations**

### Numbers
- bathroom_stalls(CJ18/Q/HARD): Find the number of open stalls after K choices when everybody chooses the stall the furthest away from the others **Priority queue/Map/Ceil**
- bike_tour(KS20/B/EASY): Count the number of peaks of a bike tour **Counting peaks**
- book_reading(KS19/G/MEDIUM): Count the number of pagers all readers read if they only read each kth page by a certain number of torn out pages **Precomputation/Harmonic Number**
- countdown(KS20/C/EASY): Find the number of countdowns starting at K in a time series **Count**
- cryptopangrams(CJ19/Q/MEDIUM): Pangram is a phrase where each letter is there at least one time. Decode prime numbers that are assigned to each letter **Prime/GCD**
- cubic_ufo(CJ18/Q/HARD): Rotate a cube so that its shadow has a size of A **Precision/Geometry**
- elevenagram(KS10/H/MEDIUM): Check if the digits of a larger number can be rearranged so it divisible by 11, when alternating sum is divisible by 11 **Permutation/Modulo**
- even_digits(KS18/A/EASY): Find the minimum numbers of +- 1 to a number so all digits become even **Digit Traversal/Long long/Odd Even**
- foregone_solution(CJ19/Q/EASY): Split number into a sum so that no 4 occurs **Digit Traversing**
- lucky_dip(KS18/A/EASY): Find the expected value in case you play optically in a game with K drawings **Expected value/Probability/Precision**
- no_nine(KS18/B/HARD): Count all numbers between L and R that are neither containing a 9 or are divisible by 9 **Digit traversal**
- perfect_subarray(KS20/C/HARD): Count all intervals in an array of which the sum is a perfect sum **Prefix sum/Cache/Square numbers**
- rounding_error(CJ18/1B/MEDIUM): Determine how to distribute remaining votes so that the rounded number is maximized  **Rounding/Hash Map/Voting**
- steed_2_cruise_control(CJ18/P/EASY): Find the maximum speed so that no horse will be overtaken **Precision**
- street_checkers(KS19/E/HARD): Count in an interval the number of odd and even divisors **Divisor/Odd Even/Sieve of Eratosthenes**
- tidy_numbers(CJ17/Q/EASY): Make a number tidy so that its digits become non decreasing **Long long/Digit Traversing**

### Sorting
- bit_party(CJ18/1A/HARD): Robots buy bits at a checkout, so find the minium time **Binary Search/Range query**
- fair_fight(CJ19/1B/MEDIUM): Find pairs of fights so that the maximum difference is smaller than K **Binary Search/Range query**
- flattening(KS19/F/HARD): Adapt/Remove bins of a wall so that there are at most K height differences **Combinatorics/Range query/Binary search**
- h_index(KS19/H/MEDIUM): Calculate the h index after each publication **Priority queue**
- new_elements_part_1(CJ19/2/HARD): Sort molecule weights **Permutations/GCD**
- oversized_pancake_choppers(CJ20/1C/HARD): Find the minimal numbers of slicing pizza so that D diners have equal sizes **Binary Search/GCD**
- trouble_sort(CJ18/Q/MEDIUM): Determine the first index where triplet bubble sort fails by swapping left and right elements when it is always comparing even/odd elements **Bubble Sort/Odd Even**
- workout(KS20/A/MEDIUM): Find the maximum distance between workout intensities by placing K numbers between N workouts **Binary Search/Range query**

### String

- nesting_depth(CJ20/Q/EASY): Create string so that the integers have a closing pair of parenthesis around them **Parenthesis**
- pattern_matching(CJ20/1A_HARD): Find string that exists in patterns including asterisks by suffix and prefix **Prefix&Suffix**

### Tree
- candies(KS20/C/HARD): Calculate the candy score of an alternating range sum **Segment Tree**
- diameter_of_binary_tree(LC): Recursively traverse binary tree to find longest path between two nodes **BST/Recursion**
- diverse_subarry(KS19/B/HARD): Find the range that maximize the number of elements when their occurence is limited **Segment Tree/Prefix sum**
- spectating_villages(KS19/F/MEDIUM): Maximize the beauty value by placing light houses in a tree shape infrastructur **Complete search/Dynamic Programming**

### Trie
- alien_rhyme(CJ19/1A/HARD): Create suffix try to find longest suffix pairs **Prefix&Suffix**
- bundling(KS20/A/MEDIUM): Find groups of maximum K members so that the sum of their prefixes is maximized **Prefix/Combinatorics**
- prefix_trie(LC): Basic class of a prefix trie **Prefix**

## Common Mistakes

- Go with brute force/complete search first!  
- Use more memory to become faster!  
- check data types of inputs to avoid overflow like(long long instead of int)  
- float cast creates troubles  
- out of bounce check missing  
- alphabet helps with constant memory [26]  
- read line in python incorrectly
- swap to do fast memory changes  
- sort changed order that is important for result  

