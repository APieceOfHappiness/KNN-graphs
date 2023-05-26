from NnLib.Point import Point
from NnLib.PonomarenkoGraph import PonomarenkoGraph
from NnLib.KleinbergGraph import KleinbergGraph
import random

amount_of_close_friends = 2

if __name__ == "__main__":

    # Ponomarenko model:
    graph = PonomarenkoGraph(Point, amount_of_close_friends=6)

    # Kleinberg model:
    # graph = KleinbergGraph(Point, redges_per_node=20)

    nodes: list[Point] = []
    for i in range(100):
        randx = random.randint(0, 1000)
        randy = random.randint(0, 1000)
        nodes.append(Point(randx, randy))

    graph.load_nodes(nodes)

    print(graph)
    
    target = Point(400.5, 400.5) 
    closest = graph.get_nearest_neighbours(target=target, k=5)

    print(f"deg(G) = {graph.degree}")
    print(f"CC(G) = {graph.cc}")

    graph.show(
        target=target,
        closest=closest
    )
    # ----------------------------------------------------------------
    # res = list()
    # for n in range(1, 31, 3):
    #     mean_cc = 0
    #     for _ in range(3):
    #         nodes = list()
    #         for i in range(1000):
    #             randx = random.randint(0, 100)
    #             randy = random.randint(0, 100)
    #             nodes.append(Point(randx, randy))                
    #         graph = KleinbergGraph(Point, n)
    #         graph.load_nodes(nodes)
    #         mean_cc += graph.cc
    #     print(f"loading... {n}")
    #     res.append((graph.degree, mean_cc / 3))

    # with open("./saved_data/Kleinsberg_1000_fixed.txt", "w") as f:
    #     for el in res:
    #         f.write(str(el[0]) + " " + str(el[1]) + "\n") 




