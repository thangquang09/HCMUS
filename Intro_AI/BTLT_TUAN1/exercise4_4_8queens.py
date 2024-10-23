import random

def generate_n_queens(n=8):
    """
    Sinh một trạng thái ngẫu nhiên cho bài toán n-queens.
    Mỗi quân hậu được đặt ngẫu nhiên trên một hàng và một cột khác nhau.
    """
    state = list(range(n))
    random.shuffle(state)
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

# Ví dụ sử dụng:
if __name__ == "__main__":
    state = generate_n_queens()
    print("Trạng thái ngẫu nhiên cho bài toán 8-queens:")
    print_board(state)
