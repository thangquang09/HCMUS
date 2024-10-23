import random
import math
import queue  # Sử dụng thư viện Queue

goal_state = (0, 1, 2, 3, 4, 5, 6, 7, 8)

def is_solvable(puzzle):
    inversion_count = 0
    puzzle_list = [tile for tile in puzzle if tile != 0]
    for i in range(len(puzzle_list)):
        for j in range(i + 1, len(puzzle_list)):
            if puzzle_list[i] > puzzle_list[j]:
                inversion_count += 1
    return inversion_count % 2 == 0

def generate_solvable_puzzle():
    puzzle = list(range(9))  # Tạo danh sách từ 0 đến 8
    while True:
        random.shuffle(puzzle)  # Xáo trộn ngẫu nhiên các ô số
        if is_solvable(puzzle):
            return tuple(puzzle)

def print_puzzle(puzzle):
    """
    In trạng thái 8-puzzle dưới dạng ma trận 3x3.
    """
    for i in range(0, 9, 3):
        print(puzzle[i:i+3])
    print()

def manhattan_distance(state):
    """
    Tính tổng khoảng cách Manhattan của tất cả các ô số đến vị trí đích.
    """
    distance = 0
    for i in range(9):
        if state[i] != 0:
            x_current, y_current = i % 3, i // 3
            x_goal, y_goal = state[i] % 3, state[i] // 3
            distance += abs(x_current - x_goal) + abs(y_current - y_goal)
    return distance

def get_successors(state):
    """
    Tạo ra tất cả các trạng thái lân cận bằng cách di chuyển ô trống lên, xuống, trái, phải.
    """
    successors = []
    zero_index = state.index(0)
    x, y = zero_index % 3, zero_index // 3

    moves = {'Up': (x, y - 1), 'Down': (x, y + 1),
             'Left': (x - 1, y), 'Right': (x + 1, y)}

    for move, (new_x, new_y) in moves.items():
        if 0 <= new_x < 3 and 0 <= new_y < 3:
            new_index = new_y * 3 + new_x
            new_state = list(state)
            new_state[zero_index], new_state[new_index] = new_state[new_index], new_state[zero_index]
            successors.append(tuple(new_state))
    return successors

def print_state(state):
    """
    In trạng thái 8-puzzle dưới dạng ma trận 3x3.
    """
    for i in range(0, 9, 3):
        row = [' ' if num == 0 else str(num) for num in state[i:i+3]]
        print(' '.join(row))
    print()

def hill_climbing_steepest_ascent(initial_state):
    current = initial_state
    search_cost = 0  # Khởi tạo chi phí tìm kiếm
    while True:
        current_score = manhattan_distance(current)
        search_cost += 1  # Tăng chi phí tìm kiếm mỗi khi đánh giá trạng thái
        if current_score == 0:
            return current, search_cost  # Trả về lời giải và chi phí tìm kiếm
        successors = get_successors(current)
        successor_scores = [(manhattan_distance(s), s) for s in successors]
        search_cost += len(successors)  # Tăng chi phí tìm kiếm cho các lân cận
        best_score, best_successor = min(successor_scores, key=lambda x: x[0])
        if best_score >= current_score:
            return None, search_cost  # Mắc kẹt tại cực đại cục bộ
        current = best_successor

def hill_climbing_first_choice(initial_state, max_iterations=1000):
    current = initial_state
    current_score = manhattan_distance(current)
    search_cost = 0  # Khởi tạo chi phí tìm kiếm
    iterations = 0
    while current_score != 0 and iterations < max_iterations:
        successors = get_successors(current)
        random.shuffle(successors)  # Ngẫu nhiên hóa thứ tự các lân cận
        search_cost += 1  # Tăng chi phí tìm kiếm mỗi lần lặp
        found_better = False
        for s in successors:
            s_score = manhattan_distance(s)
            search_cost += 1  # Tăng chi phí tìm kiếm mỗi khi đánh giá lân cận
            if s_score < current_score:
                current = s
                current_score = s_score
                found_better = True
                break
        if not found_better:
            return None, search_cost  # Mắc kẹt tại cực đại cục bộ
        iterations += 1
    if current_score == 0:
        return current, search_cost
    else:
        return None, search_cost

def hill_climbing_random_restart(max_restarts=10):
    total_search_cost = 0  # Tổng chi phí tìm kiếm qua các lần khởi động lại
    for i in range(max_restarts):
        initial_state = generate_solvable_puzzle()
        result, search_cost = hill_climbing_steepest_ascent(initial_state)
        total_search_cost += search_cost
        if result:
            print(f"Tìm thấy lời giải sau {i} lần khởi động lại.")
            return result, total_search_cost
    print("Không tìm thấy lời giải sau số lần khởi động lại tối đa.")
    return None, total_search_cost

def simulated_annealing(initial_state, max_iterations=10000, initial_temp=1000, cooling_rate=0.003):
    current = initial_state
    current_score = manhattan_distance(current)
    temperature = initial_temp
    iterations = 0
    search_cost = 0  # Khởi tạo chi phí tìm kiếm
    while current_score != 0 and iterations < max_iterations and temperature > 0.1:
        successors = get_successors(current)
        next_state = random.choice(successors)
        next_score = manhattan_distance(next_state)
        search_cost += 1  # Tăng chi phí tìm kiếm mỗi lần lặp
        delta_e = current_score - next_score
        if delta_e > 0:
            current = next_state
            current_score = next_score
        else:
            probability = math.exp(delta_e / temperature)
            if random.random() < probability:
                current = next_state
                current_score = next_score
        temperature *= 1 - cooling_rate  # Giảm nhiệt độ
        iterations += 1
    if current_score == 0:
        return current, search_cost
    else:
        return None, search_cost

if __name__ == "__main__":
    # Ví dụ sử dụng các thuật toán và in ra chi phí tìm kiếm
    initial_state = generate_solvable_puzzle()
    print("Trạng thái ban đầu:")
    print_state(initial_state)

    print("Giải bằng Hill Climbing (Steepest-Ascent):")
    result, search_cost = hill_climbing_steepest_ascent(initial_state)
    if result:
        print("Tìm thấy lời giải:")
        print_state(result)
    else:
        print("Không tìm thấy lời giải bằng Hill Climbing (Steepest-Ascent).")
    print(f"Chi phí tìm kiếm: {search_cost}")

    print("Giải bằng Hill Climbing (First-Choice):")
    result, search_cost = hill_climbing_first_choice(initial_state)
    if result:
        print("Tìm thấy lời giải:")
        print_state(result)
    else:
        print("Không tìm thấy lời giải bằng Hill Climbing (First-Choice).")
    print(f"Chi phí tìm kiếm: {search_cost}")

    print("Giải bằng Hill Climbing với Khởi động lại Ngẫu nhiên:")
    result, search_cost = hill_climbing_random_restart(max_restarts=5)
    if result:
        print("Tìm thấy lời giải:")
        print_state(result)
    else:
        print("Không tìm thấy lời giải bằng Hill Climbing với Khởi động lại Ngẫu nhiên.")
    print(f"Tổng chi phí tìm kiếm: {search_cost}")

    print("Giải bằng Simulated Annealing:")
    result, search_cost = simulated_annealing(initial_state)
    if result:
        print("Tìm thấy lời giải:")
        print_state(result)
    else:
        print("Không tìm thấy lời giải bằng Simulated Annealing.")
    print(f"Chi phí tìm kiếm: {search_cost}")
