import math
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

    def __hash__(self):
        return hash((self.value, self.weight))


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
    return find_best_tree(tuple(node_list))

@functools.cache
def find_best_tree(node_list):
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

    top_three = sorted(zip(range(len(node_list)), node_list), reverse=True, key=lambda x: x[1].weight)[:math.ceil(len(node_list)/2)]
    for ind, pivot in top_three:        
        left_sublist = node_list[:ind]
        right_sublist = node_list[ind+1:]
        
        left = find_best_tree(left_sublist)
        right = find_best_tree(right_sublist)
        current = Tree(pivot, left, right)

        current_cost = cost(current)
        if current_cost < best_cost or not best_tree:
            best_tree = current
            best_cost = current_cost
        
    return best_tree

if __name__ == "__main__":
    node0 = Node("ACZ", 43774)
    node1 = Node("AHT", 26026)
    node2 = Node("ARW", 11314)
    node3 = Node("BKL", 74772)
    node4 = Node("BQV", 50745)
    node5 = Node("BRN", 35738)
    node6 = Node("BSD", 55784)
    node7 = Node("BSE", 38750)
    node8 = Node("CCF", 85227)
    node9 = Node("CKE", 85041)
    node10 = Node("DFF", 37676)
    node11 = Node("EHO", 10861)
    node12 = Node("EIB", 89338)
    node13 = Node("EIZ", 34137)
    node14 = Node("EJP", 94569)
    node15 = Node("EKM", 53137)
    node16 = Node("FAK", 80545)
    node17 = Node("FAL", 10207)
    node18 = Node("FFI", 3923)
    node19 = Node("FQT", 23535)
    node20 = Node("FTS", 29985)
    node21 = Node("FWO", 33716)
    node22 = Node("GUU", 99297)
    node23 = Node("HHR", 78718)
    node24 = Node("HOW", 4670)
    node25 = Node("HVM", 54708)
    node26 = Node("IPN", 98036)
    node27 = Node("IVC", 1130)
    node28 = Node("JKC", 3699)
    node29 = Node("JYV", 15550)
    node30 = Node("KYP", 57612)
    node31 = Node("LEO", 49073)
    node32 = Node("MCG", 15409)
    node33 = Node("MDT", 44643)
    node34 = Node("MKR", 63318)
    node35 = Node("MMF", 60070)
    node36 = Node("MUE", 1518)
    node37 = Node("MUO", 64761)
    node38 = Node("NBS", 80018)
    node39 = Node("NDU", 27633)
    node40 = Node("NHJ", 31645)
    node41 = Node("NJJ", 91837)
    node42 = Node("OHI", 52552)
    node43 = Node("OOE", 11541)
    node44 = Node("PGE", 79273)
    node45 = Node("PJX", 90860)
    node46 = Node("PNW", 16216)
    node47 = Node("PSW", 86909)
    node48 = Node("PVH", 53829)
    node49 = Node("QAF", 49657)
    node50 = Node("QJM", 50838)
    node51 = Node("QJR", 29468)
    node52 = Node("QKK", 40319)
    node53 = Node("QYH", 60789)
    node54 = Node("RQP", 8399)
    node55 = Node("SBW", 62438)
    node56 = Node("SNE", 88142)
    node57 = Node("SOF", 42771)
    node58 = Node("SRW", 55684)
    node59 = Node("SSA", 56171)
    node60 = Node("TDQ", 38585)
    node61 = Node("TDZ", 87560)
    node62 = Node("TJO", 90708)
    node63 = Node("TRR", 45686)
    node64 = Node("TVK", 17392)
    node65 = Node("UAO", 68002)
    node66 = Node("UCO", 1653)
    node67 = Node("UNF", 7084)
    node68 = Node("UUF", 78324)
    node69 = Node("UWF", 29017)
    node70 = Node("VGT", 96004)
    node71 = Node("VKA", 72444)
    node72 = Node("VML", 65251)
    node73 = Node("VNA", 29232)
    node74 = Node("VVZ", 20513)
    node75 = Node("VYT", 79534)
    node76 = Node("WAX", 25215)
    node77 = Node("WMH", 4827)
    node78 = Node("WQF", 76451)
    node79 = Node("WWB", 60476)
    node80 = Node("WZL", 22470)
    node81 = Node("XAZ", 16420)
    node82 = Node("XHU", 78615)
    node83 = Node("XMM", 71263)
    node84 = Node("XOM", 3950)
    node85 = Node("XYQ", 61227)
    node86 = Node("YEQ", 72147)
    node87 = Node("YET", 17552)
    node88 = Node("YHD", 77789)
    node89 = Node("YSM", 17982)
    node90 = Node("YWI", 75294)
    node91 = Node("YYN", 90936)
    node92 = Node("YZO", 97410)
    node93 = Node("ZAL", 3973)
    node94 = Node("ZEM", 15743)
    node95 = Node("ZPS", 19593)
    node96 = Node("ZRT", 16335)
    node97 = Node("ZSM", 78603)
    node98 = Node("ZWK", 58568)
    #all_nodes = [node0,node1,node2,node3,node4,node5,node6,node7,node8,node9,node10,node11,node12,node13,node14,node15,node16,node17,node18,node19,node20,node21,node22,node23,node24,node25,node26,node27,node28,node29,node30,node31,node32,node33,node34,node35,node36,node37,node38,node39,node40,node41,node42,node43,node44,node45,node46,node47,node48,node49,node50,node51,node52,node53,node54,node55,node56,node57,node58,node59,node60,node61,node62,node63,node64,node65,node66,node67,node68,node69,node70,node71,node72,node73,node74,node75,node76,node77,node78,node79,node80,node81,node82,node83,node84,node85,node86,node87,node88,node89,node90,node91,node92,node93,node94,node95,node96,node97,node98]
    #all_nodes = [node0, node1, node2, node3, node4, node5, node6, node7, node8, node9]
    a = Node('A', 110)
    b = Node('B', 168)
    c = Node('C', 167)
    d = Node('D', 76)
    e = Node('E', 147)
    f = Node('F', 100)
    g = Node('G', 70)
    h = Node('H', 86)
    i = Node('I', 51)
    j = Node('J', 22)


    a = Node('A', 100)
    b = Node('B', 101)
    c = Node('C', 102)
    d = Node('D', 103)
    e = Node('E', 104)
    f = Node('F', 1)
    g = Node('G', 2)
    h = Node('H', 3)
    i = Node('I', 4)
    j = Node('J', 5)

    #all_nodes = [h,i,j,e,f,g,a,d,b,c]
    all_nodes = [a,b,c,d,e,f,g,h,i,j]

    top_three = sorted(zip(range(len(all_nodes)), all_nodes), reverse=True, key=lambda x: x[1].weight)[:3]
    total = sum([x[1].weight for x in top_three])
    percentages = [(str(x[1]), x[1].weight/total) for x in top_three]
    print(percentages)
    
    readable = [str(x[1]) for x in top_three]
    print(readable)
    t = make_min_tree(all_nodes)
    print(t.root)
    print(str(t.root) in readable)

    print(t)
    print(display_tree(t, len(all_nodes)))
    