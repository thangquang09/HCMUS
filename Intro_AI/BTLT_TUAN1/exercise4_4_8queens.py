import random
import math
import pandas as pd

def generate_n_queens(n=8):
    """
    Sinh một trạng thái ngẫu nhiên cho bài toán n-queens.
    Mỗi quân hậu được đặt ngẫu nhiên trên một hàng.
    """
    state = [random.randint(0, n - 1) for _ in range(n)]
    return state

def print_board(state):
    """
    In bàn cờ với các quân hậu theo trạng thái cho trước.
    """
    n = len(state)
    for row in range(n):
        line = ""
        for col in range(n):
            if state[col] == row:
                line += "Q "
            else:
                line += ". "
        print(line)
    print()

def compute_conflicts(state):
    """
    Tính tổng số xung đột trong trạng thái.
    """
    n = len(state)
    conflicts = 0
    for col in range(n):
        for other_col in range(col + 1, n):
            if state[col] == state[other_col] or \
               abs(state[col] - state[other_col]) == abs(col - other_col):
                conflicts += 1
    return conflicts

def get_successors(state):
    """
    Sinh tất cả các trạng thái lân cận bằng cách di chuyển một quân hậu trong cột của nó.
    """
    n = len(state)
    successors = []
    for col in range(n):
        for row in range(n):
            if state[col] != row:
                new_state = state.copy()
                new_state[col] = row
                successors.append(new_state)
    return successors

def hill_climbing_steepest_ascent(initial_state):
    current = initial_state
    search_cost = 0
    while True:
        current_conflicts = compute_conflicts(current)
        search_cost += 1
        if current_conflicts == 0:
            return current, search_cost
        successors = get_successors(current)
        successor_conflicts = [(compute_conflicts(s), s) for s in successors]
        search_cost += len(successors)
        min_conflicts, best_successor = min(successor_conflicts, key=lambda x: x[0])
        if min_conflicts >= current_conflicts:
            return None, search_cost  # Mắc kẹt tại cực tiểu cục bộ
        current = best_successor

def hill_climbing_first_choice(initial_state, max_iterations=1000):
    current = initial_state
    current_conflicts = compute_conflicts(current)
    search_cost = 0
    iterations = 0
    while current_conflicts != 0 and iterations < max_iterations:
        successors = get_successors(current)
        random.shuffle(successors)
        search_cost += 1
        found_better = False
        for s in successors:
            s_conflicts = compute_conflicts(s)
            search_cost += 1
            if s_conflicts < current_conflicts:
                current = s
                current_conflicts = s_conflicts
                found_better = True
                break
        if not found_better:
            return None, search_cost  # Mắc kẹt tại cực tiểu cục bộ
        iterations += 1
    if current_conflicts == 0:
        return current, search_cost
    else:
        return None, search_cost

def hill_climbing_random_restart(n=8, max_restarts=100):
    total_search_cost = 0
    for _ in range(max_restarts):
        initial_state = generate_n_queens(n)
        result, search_cost = hill_climbing_steepest_ascent(initial_state)
        total_search_cost += search_cost
        if result:
            return result, total_search_cost
    return None, total_search_cost

def simulated_annealing(initial_state, max_iterations=10000, initial_temp=1000, cooling_rate=0.003):
    current = initial_state
    current_conflicts = compute_conflicts(current)
    temperature = initial_temp
    iterations = 0
    search_cost = 0
    n = len(initial_state)
    while current_conflicts != 0 and iterations < max_iterations and temperature > 0.1:
        col = random.randint(0, n - 1)
        row = random.randint(0, n - 1)
        next_state = current.copy()
        next_state[col] = row
        next_conflicts = compute_conflicts(next_state)
        search_cost += 1
        delta_e = current_conflicts - next_conflicts
        if delta_e > 0:
            current = next_state
            current_conflicts = next_conflicts
        else:
            probability = math.exp(delta_e / temperature)
            if random.random() < probability:
                current = next_state
                current_conflicts = next_conflicts
        temperature *= 1 - cooling_rate
        iterations += 1
    if current_conflicts == 0:
        return current, search_cost
    else:
        return None, search_cost

if __name__ == "__main__":
    num_solved = {
        "hill_climbing_steepest_ascent": 0,
        "hill_climbing_first_choice": 0,
        "hill_climbing_random_restart": 0,
        "simulated_annealing": 0,
    }
    num_cannot_solved = {
        "hill_climbing_steepest_ascent": 0,
        "hill_climbing_first_choice": 0,
        "hill_climbing_random_restart": 0,
        "simulated_annealing": 0,
    }
    search_cost = {
        "hill_climbing_steepest_ascent": [],
        "hill_climbing_first_choice": [],
        "hill_climbing_random_restart": [],
        "simulated_annealing": [],
    }

    num_test = 1000
    algorithms = list(num_solved.keys())
    n = 8  # Kích thước bàn cờ

    print("Solving 8-Queens problem...")
    for epoch in range(num_test):
        initial_state = generate_n_queens(n)
        for algorithm in algorithms:
            if algorithm == "hill_climbing_random_restart":
                result, cost = hill_climbing_random_restart(n=n, max_restarts=100)
            else:
                result, cost = globals()[algorithm](initial_state)
            if result:
                num_solved[algorithm] += 1
            else:
                num_cannot_solved[algorithm] += 1
            search_cost[algorithm].append(cost)

    print("Calculating results...")
    mean_search_cost = {algorithm: sum(costs) / len(costs) for algorithm, costs in search_cost.items()}
    df = pd.DataFrame({
        'algorithm': algorithms,
        'num_solved': [num_solved[algo] for algo in algorithms],
        'num_cannot_solved': [num_cannot_solved[algo] for algo in algorithms],
        'mean_search_cost': [mean_search_cost[algo] for algo in algorithms]
    })
    df["percentage_of_solved"] = round(df['num_solved'] / num_test, 4)
    df.to_csv("nqueens_results.csv", index=False)
    print(df)
