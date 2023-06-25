import timeit
import functools


class Tree(object):
    
    def __init__(self, root, left=None, right=None):
        assert root and type(root) == Node
        if left: assert type(left) == Tree and left.root < root
        if right: assert type(right) == Tree and root < right.root

        self.left = left
        self.root = root
        self.right = right
        
    def is_leaf(self):
        return not(self.left or self.right)
        
    def __str__(self):
        if self.is_leaf():
            string = f"[{self.root}]"
            return string

        string = f"{self.left}" if self.left else '_'
        string += f" {self.root} "
        string += f"{self.right}" if self.right else '_'
        return f"[{string}]"

    def __eq__(self, other):
        # check that this node is equal and then check the others recursively.
        if other == None:
            return False
        
        if self.root.value == other.root.value and self.left == other.left and self.right == other.right:
            return True
        return False
    
    def __ne__(self, other):
        # check that this node isn't equal and then check the others recursively.
        return not(self == other)
    

class Node(object):
    
    def __init__(self, value, weight=1):
        self.value = value
        self.weight = weight
    
    def __str__(self):
        return '%s:%d' % (self.value, self.weight)   

    def __lt__(self, other):
        return self.value < other.value
    
    def __gt__(self, other):
        return self.value > other.value
    
    def __eq__(self, other):
        return self.value == other.value 

    def __ne__(self, other):
        return self.value != other.value 


def cost(tree, depth=1):
    '''
    Returns the cost of a tree which root is depth deep.
    '''
    if not tree:
        return 0
    
    return tree.root.weight*depth + cost(tree.left, depth+1) + cost(tree.right, depth+1)

def make_min_tree(node_list):
    '''
    node_list is a list of Node objects
    Pre-cond: len(node_list > 0) and node_list is sorted in ascending order
    Returns a minimal cost tree of all nodes in node_list.
    '''
    if len(node_list) == 0:
        return None
    elif len(node_list) == 1:
        return Tree(node_list[0])
    elif len(node_list) == 2:
        if node_list[0].weight > node_list[1].weight:
            return Tree(node_list[0], None, Tree(node_list[1]))
        else:
            return Tree(node_list[1], Tree(node_list[0]), None)

    best_tree = None
    best_cost = 0

    top_three = sorted(zip(range(len(node_list)), node_list), reverse=True, key=lambda x: x[1].weight)[:3]
    for ind, pivot in top_three:
        left_sublist = node_list[:ind]
        right_sublist = node_list[ind+1:]
            
        left = make_min_tree(left_sublist)
        right = make_min_tree(right_sublist)
        current = Tree(pivot, left, right)

        current_cost = cost(current)
        if current_cost < best_cost or not best_tree:
            best_tree = current
            best_cost = current_cost
        
    return best_tree

if __name__ == "__main__":
    a = Node('A', 10)
    b = Node('B', 2)
    c = Node('C', 4)
    d = Node('D', 9)
    e = Node('E', 8)
    f = Node('F', 6)
    g = Node('G', 3)
    h = Node('H', 12)
    i = Node('I', 4)
    j = Node('J', 7)
    all_nodes = [a,b,c,d,e,f,g,h,i,j]
    # h, a, e

    times = []
    for i in range(100):
        t = timeit.timeit(lambda: make_min_tree([a,b,c,d,e]), number=1000)
        times.append(t)

    print(sum(times)/len(times))
