from NnLib.Point import Point
from NnLib.PonomarenkoGraph import PonomarenkoGraph
from NnLib.KleinbergGraph import KleinbergGraph
import random

amount_of_close_friends = 2

if __name__ == "__main__":

    # Ponomarenko model:
    graph = PonomarenkoGraph(Point, amount_of_close_friends=4)

    # Kleinberg model:
    # graph = KleinbergGraph(Point)

    nodes: list[Point] = []
    for i in range(100):
        randx = random.randint(0, 10)
        randy = random.randint(0, 10)
        graph.add_node(Point(randx, randy))

    # Ponomarenko model:
    graph.load_nodes(nodes, amount_of_queries=10)
    
    # Kleinberg model:
    # graph.load_nodes(nodes)

    print(graph)
    
    print(graph.multi_search(Point(5.5, 5.5), amount_of_queries=10))

    graph.show()



