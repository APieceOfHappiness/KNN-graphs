from NnLib.Point import Point
from NnLib.PonomarenkoGraph import PonomarenkoGraph
from NnLib.KleinbergGraph import KleinbergGraph
import random

amount_of_close_friends = 2

if __name__ == "__main__":

    # Ponomarenko model:
    # graph = PonomarenkoGraph(Point, amount_of_close_friends=10)

    # Kleinberg model:
    graph = KleinbergGraph(Point)

    nodes: list[Point] = []
    for i in range(1500):
        randx = random.randint(0, 100)
        randy = random.randint(0, 100)
        nodes.append(Point(randx, randy))

    graph.load_nodes(nodes)

    print(graph)
    
    target = Point(40.5, 40.5)
    closest = graph.get_nearest_neighbours(target, 10)

    print(closest)

    print(f"deg(G) = {graph.degree}")
    print(f"CC(G) = {graph.cc}")

    graph.show(
        target=target,
        closest=closest
    )



