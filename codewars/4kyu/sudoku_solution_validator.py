
def valid_solution(board):
    # check it doesn't contain 0s
    # check rows
    # check cols
    # check 3x3s
    contains_zero(board)
    for row in board:
        list_repeats(row) 
    
    cols = []
    for i, row in enumerate(board):
        col = []
        for j in range(len(row)):
            col.append(board[j][i])
        cols.append(col)

    for col in cols:
        list_repeats(col)

def contains_zero(board: list) -> bool:
    for row in board:
        for val in row:
            if not val:
                return True
    return False

def list_repeats(row: list) -> bool:
    # if there isn't a zero, then there must be a repeated char.
    # so just check for repeats.
    if len(set(row)) == len(row):
        return True
    return False

def valid_col(col: list) -> bool:
    # if there isn't a zero, then there must be a repeated char.
    # so just check for repeats.
    pass

print(valid_solution([[5, 3, 4, 6, 7, 8, 9, 1, 2],
                      [6, 7, 2, 1, 9, 5, 3, 4, 8],
                      [1, 9, 8, 3, 4, 2, 5, 6, 7],
                      [8, 5, 9, 7, 6, 1, 4, 2, 3],
                      [4, 2, 6, 8, 5, 3, 7, 9, 1],
                      [7, 1, 3, 9, 2, 4, 8, 5, 6],
                      [9, 6, 1, 5, 3, 7, 2, 8, 4],
                      [2, 8, 7, 4, 1, 9, 6, 3, 5],
                      [3, 4, 5, 2, 8, 6, 1, 7, 9]]))

