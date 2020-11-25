# Creating a maze through nodes
# Coordinates in 2D. Example: (x,y) -> (0, 0)
# Player will be able to move through empty spaces. Walls prevent the player from moving
import enum, random


Coord_Types = enum.Enum('Coord_Types', 'wall empty')
wall = Coord_Types.wall
empty = Coord_Types.empty

maze = [] # This is the collection of nodes

def generate_maze(spaces_x:int, spaces_y:int):
    
    rows = spaces_x # Rows
    col = spaces_y  # Columns    

    def randomize_cType():
        rand = random.randint(1,4)

        if rand > 1:
            return empty
        else:
            return wall
    # --------------------------> |

    for x in range(rows):
        for y in range(col):
            if search_brothers([x,y]) == None:
                coord_node(t_coord=randomize_cType(), coordinates=[x,y])
    # ------------------------------------> |

def print_maze(input_maze):

    rows = bitwise_sqrt(len(input_maze))

    for x in range(rows):
        pass

# ------------------------------------> |

def search_brothers(input_coord:list=[0,0]):
    # Iterate through the maze and find the corresponding nodes
    for node in maze:
        if node.coordinates == input_coord:
            return node

    #print("No fitting nodes found")
    return None
# -----------------------------> |

def set_all_brothers():
    # Set brothers of individual nodes once Maze has been generated
    for node in maze:
        node.manage_brothers()
# -------------------------> |
    
class coord_node(object):
    # An instance of this class has:
    #   - 2D vector as coord -> array with numpy as alternative
    #   - A Coord_Type enum variable
    #   - A next object which is left, right, bottom or top of it

    def __init__(self, t_coord:Coord_Types=None, coordinates:list=[0,0]):

        # ---------- >> Nodes that are next to this one: 'Brothers' << ---------- # 
        self.brother_array = [None] * 4 # Array with 4 Elements

        class Brother(enum.Enum):
            left = self.brother_array[0]
            right = self.brother_array[1]
            top = self.brother_array[2]
            bottom = self.brother_array[3]
        
        # --- >> Redefine Variable names for Ease of Use << --- #
        self.left = Brother.left.value
        self.right = Brother.right.value
        self.top = Brother.top.value
        self.bottom = Brother.bottom.value

        # ---------- >> Coordinates and types of coordinates << ---------- # 
        self.coord_type = t_coord       # Types: Walls, Empty
        self.coordinates = coordinates  # Coords: [x, y]

        if self.coord_type == None:
            self.coord_type = empty
        else: 
            self.coord_type = t_coord
        
        # ---------- >> Add self to Node Array, then find brothers << ---------- # 
        maze.append(self)

    def manage_brothers(self):
        # Find the coord_nodes next to this one
        # From the left this coord is +1, same to bottom. Opposite from right and top.
        # We need a search algorithm to find the nodes with the corresponding coords.
        my_coord = self.coordinates
        x = my_coord[0] # (x, 0) coordinate
        y = my_coord[1] # (0, y) coordinate

        # --- >> Search for brothers in Array << --- #
        left = search_brothers([x-1, y])
        right = search_brothers([x+1, y])
        bottom = search_brothers([x, y-1])
        top = search_brothers([x, y+1])

        self.left = left
        self.right = right
        self.top = top
        self.bottom = bottom

        self.brother_array = [left, right, bottom, top]
        """ Call this function from the outside, once maze has been generated """
        
# ----------------------------------------------------------------------------> |

class Player():
    # The player will be able to move within the maze
    # He cannot move to a node that is designated as a 'wall'
    class Direction(enum.Enum):
            left = [-1, 0]
            right = [1, 0]
            top = [0, 1]
            bottom = [0, -1]

    left = Direction.left.value
    right = Direction.right.value
    top = Direction.top.value
    bottom = Direction.bottom.value

    def __init__(self, location_node:coord_node):
        self.location_node = location_node
        self.coordinates = location_node.coordinates

    def move(self, direction):
        goal:coord_node = None

        loc_x = self.location_node.coordinates[0] + direction[0]
        loc_y = self.location_node.coordinates[1] + direction[1]
        
        new_loc = [loc_x, loc_y]

        goal = search_brothers(new_loc)

        if (goal != None) and (goal.coord_type != wall):
            self.location_node = goal
            self.coordinates = self.location_node.coordinates
        elif goal == None:
            print("Node doesn't exist!")
        elif goal.coord_type == wall:
            print("Can't go through a wall!")   
# ------------------------------------------------------------------> |

dir_dict = {
    "left" : Player.left,
    "right" : Player.right,
    "top" : Player.top,
    "bottom" : Player.bottom
}

start = coord_node(empty, [1,1])

generate_maze(3,3)
set_all_brothers()

P = Player(start)
P.move(P.top)
print(P.coordinates)

while(True):
    dir:str = input().lower()
    P.move(dir_dict[dir])
    print(P.coordinates)
# ------------------------------------------------------------------> |
