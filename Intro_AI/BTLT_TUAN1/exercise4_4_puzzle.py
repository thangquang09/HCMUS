import random

def is_solvable(puzzle):
    """
    Kiểm tra xem một trạng thái 8-puzzle có thể giải được hay không.
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
    Sinh một trạng thái 8-puzzle có thể giải được.
    """
    puzzle = list(range(9))  # Tạo danh sách từ 0 đến 8
    while True:
        random.shuffle(puzzle)  # Xáo trộn ngẫu nhiên các ô số
        if is_solvable(puzzle):
            return puzzle

def print_puzzle(puzzle):
    """
    In trạng thái 8-puzzle dưới dạng ma trận 3x3.
    """
    for i in range(0, 9, 3):
        print(puzzle[i:i+3])
    print()

# Ví dụ sử dụng:
if __name__ == "__main__":
    puzzle = generate_solvable_puzzle()
    print("Trạng thái 8-puzzle có thể giải được:")
    print_puzzle(puzzle)
