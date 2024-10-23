import random
import math
import queue
import pandas as pd # đảm bảo rằng đã cài thư viện pandas để xuất ra thống kê đẹp hơn

goal_state = (0, 1, 2, 3, 4, 5, 6, 7, 8)

def is_solvable(puzzle):
    """
    Kiểm tra xem trạng thái 8-puzzle có thể giải được hay không.

    Một trạng thái của 8-puzzle có thể giải được nếu số lượng hoán vị nghịch của nó là chẵn.

    Tham số:
    - puzzle (tuple): Trạng thái của trò chơi, biểu diễn dưới dạng tuple chứa các số từ 0 đến 8.

    Trả về:
    - bool: True nếu trạng thái có thể giải được, False nếu không.
    """
    inversion_count = 0
    puzzle_list = [tile for tile in puzzle if tile != 0]
    for i in range(len(puzzle_list)):
        for j in range(i + 1, len(puzzle_list)):
            if puzzle_list[i] > puzzle_list[j]:
                inversion_count += 1
    return inversion_count % 2 == 0

def generate_solvable_puzzle():
    """
    Sinh một trạng thái 8-puzzle ngẫu nhiên có thể giải được.

    Tham số:
    - Không có.

    Trả về:
    - puzzle (tuple): Trạng thái 8-puzzle có thể giải được.
    """
    puzzle = list(range(9))  # Tạo danh sách từ 0 đến 8
    while True:
        random.shuffle(puzzle)  # Xáo trộn ngẫu nhiên các ô số
        if is_solvable(puzzle):
            return tuple(puzzle)

def print_puzzle(puzzle):
    """
    In trạng thái 8-puzzle dưới dạng ma trận 3x3.

    Tham số:
    - puzzle (tuple): Trạng thái của trò chơi.

    Trả về:
    - Không có.
    """
    for i in range(0, 9, 3):
        print(puzzle[i:i+3])
    print()

def manhattan_distance(state):
    """
    Tính tổng khoảng cách Manhattan của tất cả các ô số đến vị trí đích.

    Khoảng cách Manhattan là tổng số bước di chuyển theo hàng và cột từ vị trí hiện tại đến vị trí đích.

    Tham số:
    - state (tuple): Trạng thái hiện tại của trò chơi.

    Trả về:
    - distance (int): Tổng khoảng cách Manhattan của tất cả các ô số.
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

    Tham số:
    - state (tuple): Trạng thái hiện tại của trò chơi.

    Trả về:
    - successors (list): Danh sách các trạng thái lân cận.
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

    Tham số:
    - state (tuple): Trạng thái của trò chơi.

    Trả về:
    - Không có.
    """
    for i in range(0, 9, 3):
        row = [' ' if num == 0 else str(num) for num in state[i:i+3]]
        print(' '.join(row))
    print()

def hill_climbing_steepest_ascent(initial_state):
    """
    Thuật toán Leo đồi (Hill Climbing) dạng Steepest-Ascent để giải bài toán 8-puzzle.

    Cách hoạt động:
    - Bắt đầu từ trạng thái ban đầu.
    - Tại mỗi bước, xem xét tất cả các trạng thái lân cận.
    - Chọn trạng thái lân cận có giá trị heuristic tốt nhất (khoảng cách Manhattan nhỏ nhất).
    - Nếu không có trạng thái lân cận nào tốt hơn trạng thái hiện tại, dừng lại (mắc kẹt tại cực đại cục bộ).
    - Nếu tìm thấy trạng thái tốt hơn, chuyển sang trạng thái đó và tiếp tục lặp lại quá trình.
    - Tiếp tục cho đến khi tìm được lời giải (khoảng cách Manhattan bằng 0) hoặc mắc kẹt.

    Tham số:
    - initial_state (tuple): Trạng thái ban đầu của trò chơi.

    Trả về:
    - Tuple (result_state, search_cost):
        - result_state (tuple): Trạng thái giải pháp nếu tìm thấy, hoặc None nếu không tìm thấy.
        - search_cost (int): Chi phí tìm kiếm, tức là số lần đánh giá trạng thái.
    """
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
    """
    Thuật toán Leo đồi (Hill Climbing) dạng First-Choice để giải bài toán 8-puzzle.

    Cách hoạt động:
    - Bắt đầu từ trạng thái ban đầu.
    - Tại mỗi bước, sinh ngẫu nhiên các trạng thái lân cận.
    - Chọn trạng thái lân cận đầu tiên tốt hơn trạng thái hiện tại và chuyển sang trạng thái đó.
    - Nếu không tìm thấy trạng thái lân cận tốt hơn sau khi duyệt qua các lân cận, dừng lại (mắc kẹt tại cực đại cục bộ).
    - Tiếp tục cho đến khi tìm được lời giải (khoảng cách Manhattan bằng 0) hoặc đạt số lần lặp tối đa.

    Tham số:
    - initial_state (tuple): Trạng thái ban đầu của trò chơi.
    - max_iterations (int): Số lần lặp tối đa (mặc định là 1000).

    Trả về:
    - Tuple (result_state, search_cost):
        - result_state (tuple): Trạng thái giải pháp nếu tìm thấy, hoặc None nếu không tìm thấy.
        - search_cost (int): Chi phí tìm kiếm, tức là số lần đánh giá trạng thái.
    """
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
    """
    Thuật toán Leo đồi với Khởi động lại Ngẫu nhiên để giải bài toán 8-puzzle.

    Cách hoạt động:
    - Thực hiện thuật toán Leo đồi (Steepest-Ascent) nhiều lần, mỗi lần bắt đầu từ một trạng thái ban đầu ngẫu nhiên.
    - Giới hạn số lần khởi động lại bằng max_restarts.
    - Nếu tìm thấy lời giải trong một lần thử, trả về lời giải đó.
    - Nếu sau tất cả các lần khởi động lại vẫn không tìm thấy lời giải, trả về None.

    Tham số:
    - max_restarts (int): Số lần khởi động lại tối đa (mặc định là 10).

    Trả về:
    - Tuple (result_state, total_search_cost):
        - result_state (tuple): Trạng thái giải pháp nếu tìm thấy, hoặc None nếu không tìm thấy.
        - total_search_cost (int): Tổng chi phí tìm kiếm qua tất cả các lần khởi động lại.
    """
    total_search_cost = 0  # Tổng chi phí tìm kiếm qua các lần khởi động lại
    for i in range(max_restarts):
        initial_state = generate_solvable_puzzle()
        result, search_cost = hill_climbing_steepest_ascent(initial_state)
        total_search_cost += search_cost
        if result:
            # print(f"Tìm thấy lời giải sau {i} lần khởi động lại.")
            return result, total_search_cost
    # print("Không tìm thấy lời giải sau số lần khởi động lại tối đa.")
    return None, total_search_cost

def simulated_annealing(initial_state, max_iterations=10000, initial_temp=1000, cooling_rate=0.003):
    """
    Thuật toán Simulated Annealing để giải bài toán 8-puzzle.

    Cách hoạt động:
    - Bắt đầu từ trạng thái ban đầu.
    - Tại mỗi bước, thực hiện:
        - Chọn ngẫu nhiên một trạng thái lân cận.
        - Tính sự thay đổi năng lượng (delta_e) giữa trạng thái hiện tại và trạng thái mới.
        - Nếu trạng thái mới tốt hơn (khoảng cách Manhattan giảm), chấp nhận trạng thái mới.
        - Nếu trạng thái mới kém hơn, chấp nhận với xác suất exp(delta_e / temperature).
    - Nhiệt độ (temperature) giảm dần sau mỗi bước theo cooling_rate.
    - Tiếp tục cho đến khi tìm được lời giải (khoảng cách Manhattan bằng 0), đạt số lần lặp tối đa, hoặc nhiệt độ xuống thấp dưới ngưỡng cho phép.

    Tham số:
    - initial_state (tuple): Trạng thái ban đầu của trò chơi.
    - max_iterations (int): Số lần lặp tối đa (mặc định là 10000).
    - initial_temp (float): Nhiệt độ ban đầu (mặc định là 1000).
    - cooling_rate (float): Tốc độ giảm nhiệt độ (mặc định là 0.003).

    Trả về:
    - Tuple (result_state, search_cost):
        - result_state (tuple): Trạng thái giải pháp nếu tìm thấy, hoặc None nếu không tìm thấy.
        - search_cost (int): Chi phí tìm kiếm, tức là số lần đánh giá trạng thái.
    """
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
    print("Đang giải bài toán 8-Puzzle...")

    for epoch in range(num_test):
        initial_state = generate_solvable_puzzle()
        for algorithm in algorithms:
            if algorithm == "hill_climbing_random_restart":
                result, cost = hill_climbing_random_restart(max_restarts=10)
            else:
                result, cost = globals()[algorithm](initial_state)
            if result:
                num_solved[algorithm] += 1
            else:
                num_cannot_solved[algorithm] += 1
            search_cost[algorithm].append(cost)

    print("Đang tính toán kết quả...")

    mean_search_cost = {algorithm: sum(costs) / len(costs) for algorithm, costs in search_cost.items()}
    df = pd.DataFrame({
        'algorithm': algorithms,
        'num_solved': [num_solved[algo] for algo in algorithms],
        'num_cannot_solved': [num_cannot_solved[algo] for algo in algorithms],
        'mean_search_cost': [mean_search_cost[algo] for algo in algorithms]
    })
    df["percentage_of_solved"] = round(df['num_solved'] / num_test, 4)
    df.to_csv("8_puzzle_results.csv", index=False)
    print(df)
