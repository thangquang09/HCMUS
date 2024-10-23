from queue import PriorityQueue

expected_position = {
    1: (0, 1),
    2: (0, 2),
    3: (1, 0),
    4: (1, 1),
    5: (1, 2),
    6: (2, 0),
    7: (2, 1),
    8: (2, 2),
    0: (0, 0)
}

goal = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8]
]

def H(node):
    total = 0
    for i in range(3):
        for j in range(3):
            val = node[i][j]
            if val == 0:
                # không tính vị trí của ô trống
                continue 
            point_x, point_y = expected_position[val]
            manhattan_distance = abs(i - point_x) + abs(j - point_y)
            total += manhattan_distance
    return total

def make_tuple(node):
    return tuple(map(tuple, node))

def is_goal(node, goal):
    return node == goal

def get_0_position(node):
    for i in range(3):
        for j in range(3):
            if node[i][j] == 0:
                return (i, j)

def move_0(state, pos_0, move):
    state = [row[:] for row in state]
    x_0, y_0 = pos_0
    dx, dy = move
    new_x, new_y = x_0 + dx, y_0 + dy
    if 0 <= new_x < 3 and 0 <= new_y < 3:
        state[x_0][y_0], state[new_x][new_y] = state[new_x][new_y], state[x_0][y_0]  # swap
        return state
    return None

def expand(node): 
    successors = []
    state, parent, G, H_value = node  # Keep track of H(state)
    pos_0 = get_0_position(state)
    steps = [
        (0, -1), # left
        (0, 1),  # right
        (-1, 0), # up
        (1, 0)   # down
    ]

    for step in steps:
        new_state = move_0(state, pos_0, step)
        if new_state:  # valid new state
            new_G = G + 1
            new_H = H(new_state)  # Calculate new H(new_state)
            new_F = new_G + new_H
            successors.append((new_F, (new_state, node, new_G, new_H)))  # Pass new_H as part of the tuple
    return successors

def bfs(initial_state, goal_state):
    fringe = PriorityQueue()
    initial_H = H(initial_state)  # Initial H(state)
    fringe.put((0 + initial_H, (initial_state, None, 0, initial_H)))  # (F, (state, parent, G, H))

    visited = set()

    while not fringe.empty():
        F, node = fringe.get() 
        state, parent, G, H_value = node  # Extract H(state)

        if is_goal(state, goal_state):
            return node 
        
        state_tuple = make_tuple(state)
        if state_tuple not in visited:
            visited.add(state_tuple)

            successors = expand(node)

            for success in successors:
                fringe.put(success)

def get_path(node):
    path = []

    while node:
        state, parent, G, H_value = node  # Extract H(state) for each node
        path.append((state, H_value))  # Append H(state) with the state
        node = parent

    path.reverse()

    for step in path:
        state, H_value = step
        print("State:")
        for idx, row in enumerate(state):
            if idx == 1:
                print(row, "  H(state)=", H_value)
            else:
                print(row)
        print()

if __name__ == "__main__":
    try:
        print("Input your initial state")
        initial_state = []
        for i in range(3):
            row = [int(x) for x in input().split(" ")]
            initial_state.append(row)

        print("Solving...")
        res = bfs(initial_state, goal)
        print("Path:\n")
        get_path(res)
    except Exception as e:
        print(f"Error: {e}")
