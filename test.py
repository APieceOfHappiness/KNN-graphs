from dataclasses import dataclass
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np


@dataclass(frozen=True)
class Point:
    x: float
    y: float
    
    def tpl(this) -> tuple([float, float]):
        return (this.x, this.y)
    
    def d(this, p2) -> float:
        return d(this, p2)
    
    def __str__(this) -> str:
        return "(" + str(this.x) + ", " + str(this.y) + ")"


def d(p1: Point, p2: Point) -> float:
    return np.sqrt((p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2)


G = nx.Graph()

G.add_node(obj=Point(1, 1), pos=(1, 1))
G.add_node(obj=Point(1, 2), pos=(1, 2))
G.add_node(obj=Point(2, 1), pos=(2, 1))
G.add_node(obj=Point(9, 9), pos=(9, 9))
G.add_node(obj=Point(7, 7), pos=(7, 7))

pos = nx.get_node_attributes(G, 'pos')
print(pos)

G.add_edge(Point(1, 1), Point(7, 7))
print(G.nodes)
# G.add_edge(2, 3)
# G.add_edge(1, 2)

nx.draw_networkx_nodes(G, pos)
nx.draw_networkx_edges(G, pos)
print(list(G.neighbors(Point(9, 9))))
# print(G.nodes[0])
# nx.draw(G, with_labels=True)
plt.show()