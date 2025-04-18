#!/usr/bin/env python
# coding: utf-8

# In[11]:


#Question 1: 23k-0071

from collections import deque
pirate_grid = [
    ['P', 'L', 'L', 'w', 'T'],
    ['L', 'w', 'L', 'w', 'L'],
    ['L', 'L', 'L', 'L', 'L'],
    ['L', 'L', 'w', 'L', 'L'],
    ['L', 'L', 'L', 'L', 'L']
]

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
def Start(pirate_grid):
    n = len(pirate_grid)
    for i in range(n):
        for j in range(len(pirate_grid[0])):
            if pirate_grid[i][j] == 'P':
                return (i, j)
    return None
def BFS(pirate_grid):
    start = Start(pirate_grid)
    if not start:
        return None
    queue = deque([(start, [start])])
    visited = set()
    visited.add(start)
    while queue:
        (current, path) = queue.popleft()
        row, col = current
        if pirate_grid[row][col] == 'T':
            return path
        for dr, dc in directions:
            r, c = row + dr, col + dc
            if 0 <= r < len(grid) and 0 <= c < len(pirate_grid[0]) and (r, c) not in visited and pirate_grid[r][c] != 'W':
                visited.add((r, c))
                queue.append(((r, c), path + [(r, c)]))
    return None
    
def print_grid_with_path(pirate_grid, path):
    for i in range(len(pirate_grid)):
        for j in range(len(pirate_grid[0])):
            if (i, j) in path:
                print('*', end=' ')
            else:
                print(pirate_grid[i][j], end=' ')
        print()
bfs_path = BFS(pirate_grid)
print("BFS Path:")
if bfs_path:
    print_grid_with_path(pirate_grid, bfs_path)
else:
    print("No path found.")
    


# In[17]:


#Question 2: 23k-0071

import heapq
def a_star(grid, start=(0, 0), goal=None):
    rows, cols = len(grid), len(grid[0])
    if goal is None:
        goal = (rows - 1, cols - 1)
    if grid[goal[0]][goal[1]] == '#':
        return None, float('inf')
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    def heuristic(x, y):
        return abs(x - goal[0]) + abs(y - goal[1])
    queue = [(heuristic(*start), 0, start)]
    visited = set()
    came_from = {}
    g_cost = {start: 0}
    while queue:
        f, g, (x, y) = heapq.heappop(queue)
        if (x, y) == goal:
            path = []
            while (x, y) in came_from:
                path.append((x, y))
                x, y = came_from[(x, y)]
            path.append(start)
            return path[::-1], g_cost[goal]
        if (x, y) in visited:
            continue
        visited.add((x, y))
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != '#':
                try:
                    cost = int(grid[nx][ny])
                except ValueError:
                    continue
                new_g = g_cost[(x, y)] + cost
                if (nx, ny) not in g_cost or new_g < g_cost[(nx, ny)]:
                    g_cost[(nx, ny)] = new_g
                    new_f = new_g + heuristic(nx, ny)
                    heapq.heappush(queue, (new_f, new_g, (nx, ny)))
                    came_from[(nx, ny)] = (x, y)

    return None, float('inf')
#lets assume start=0 and goal=4
#for grid name i saw the file at the end and i have almost coded the grid with "grid" name
grid = [
    ['0', '1', '2', '#', '3'],
    ['1', '#', '2', '#', '#'],
    ['1', '2', '1', '2', '#'],
    ['#', '#', '1', '#', '#'],
    ['1', '1', '1', '2', '4']
]
path, cost = a_star(grid)
if path:
    print("Optimal Path:", path)
    print("Total Cost:", cost)
else:
    print("No path found.")



# In[19]:


#QUESTION 3: 23K-0071
import random

def fitness(x):
    return 1 * (x ** 2) - 1

def binary_to_decimal(binary_str):
    return int(binary_str, 5)


def generate_population(size):
    return [''.join(random.choice('01') for _ in range(6)) for _ in range(size)]

def tournament_selection(population, k=3):
    selected = random.sample(population, k)
    return max(selected, key=lambda ind: fitness(binary_to_decimal(ind)))

def uniform_crossover(parent1, parent2):
    child = ''.join(random.choice([p1, p2]) for p1, p2 in zip(parent1, parent2))
    return child

def adaptive_mutation(individual, gen, max_gen):
    mutation_rate = 0.1 * (1 - gen / max_gen) 
    mutated = ''.join(bit if random.random() > mutation_rate else str(1 - int(bit)) for bit in individual)
    return mutated

def genetic_algorithm(pop_size=20, generations=50):
    population = generate_population(pop_size)
    best_solution = None
    best_fitness = float('-inf')

    for gen in range(generations):
        new_population = []
        for _ in range(pop_size // 2):
            parent1 = tournament_selection(population)
            parent2 = tournament_selection(population)
            child1 = uniform_crossover(parent1, parent2)
            child2 = uniform_crossover(parent1, parent2)
            child1 = adaptive_mutation(child1, gen, generations)
            child2 = adaptive_mutation(child2, gen, generations)
            new_population.extend([child1, child2])

        population = new_population

        for individual in population:
            x = binary_to_decimal(individual)
            fit = fitness(x)
            if fit > best_fitness:
                best_fitness = fit
                best_solution = individual

    return best_solution, binary_to_decimal(best_solution), best_fitness

best_individual, best_x, best_value = genetic_algorithm()
print(f"Best Individual: {best_individual} (x={best_x}) >> f(x)={best_value}")

#made a little bit changes for my clearification according to the code that i have practiced



# In[ ]:




