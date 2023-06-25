
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
            string = f"[{self.root.value}]"
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
        return str(self.value)   
    
    def __lt__(self, other):
        return self.value < other.value
    
    def __gt__(self, other):
        return self.value > other.value
    
    def __eq__(self, other):
        return self.value == other.value 

    def __ne__(self, other):
        return self.value != other.value 

if __name__ == "__main__":
    tree2 = Tree(Node('B'), Tree(Node('A')), Tree(Node('C')))
    tree1 = Tree(Node('B'), None, Tree(Node('C')))
    print(tree1)
