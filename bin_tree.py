""" Python Binary Tree with Strings, comparison by Alphabet """

class Node:
    """ Node that is inserted to Tree """

    def __init__(self, title:str, ) -> None:
        """ Each node has a title, a child l and r node"""
        self.title = title

        self.left:Node = None
        self.right:Node = None
    pass

    def info(self):
        """ Print Node Info """
        print(f"| {self.key} : {self.title} |")

    # Print the Tree
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print( self.data),
        if self.right:
            self.right.PrintTree()

    # Inorder traversal
    # Left -> Root -> Right
    def inorderTraversal(self, root):
        res = []
        if root:
            res = self.inorderTraversal(root.left)
            res.append(root.title)
            res = res + self.inorderTraversal(root.right)
        return res


pass
## -- END OF NODE CLASS -- ##

class Tree:
    """ Tree composed of Nodes """

    def __init__(self, root:Node) -> None:
        """ Set root """
        self.root = root
    pass

    def getRoot(self):
        return self.root

    def _compare(self, a:str, b:str)->str:
        """ 
        Compare two words alphabetically, 
        returns what comes first 
        """
        
        if a < b:
            # If a comes before b
            return a
        # otherwise return b
        return b
    pass

    # Insert into tree #
    def _add(self, val, node):
        
        if val < str(node.title):
            if node.left is not None:
                self._add(val, node.left)
            else:
                node.left = Node(val)
        else:
            if node.right is not None:
                self._add(val, node.right)
            else:
                node.right = Node(val)

    def add(self, val):
        if self.root is None:
            self.root = Node(val)
        else:
            self._add(val, self.root)
    pass

    def find(self, val):
        """ Find Node through value """
        cur_node = self.root
    
        while not (cur_node.title == val):
            if cur_node.title < val:
                cur_node = cur_node.right
            else:
                cur_node = cur_node.left
            cur_node.info()

    pass

    def output(self):
        """ Output every node """
        print(self.root.inorderTraversal(self.root))


pass
## -- END OF TREE CLASS -- ##

def main():

    eg1 = "long string heaha"
    eg2 = "this is also a string"
    o = Node("hi", "50", "Obsolete")
    
    myTree = Tree(o)
    myTree.add("bye")
    myTree.add("hi2")
    myTree.add("Why not")
    myTree.add("why yes")
    myTree.add("Why")

    myTree.find("Why")
    myTree.output()
pass

main()
