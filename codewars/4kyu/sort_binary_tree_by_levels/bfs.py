class Node:
    def __init__(self, L, R, n):
        self.left = L
        self.right = R
        self.value = n


def tree_by_levels(node: Node) -> list:
    if not node:
        return []

    ans = []
    queue = [node]
    while queue:
        val = queue.pop(0)
        ans.append(val.value)
        if val.left:
            queue.append(val.left)
        if val.right:
            queue.append(val.right)

    return ans

if __name__ == "__main__":
    print(tree_by_levels(Node(Node(None, Node(None, None, 4), 2), Node(Node(None, None, 5), Node(None, None, 6), 3), 1)))
