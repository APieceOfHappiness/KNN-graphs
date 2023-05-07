from KnnLib.Point import Point
from KnnLib.PonomarenkoGraph import PonomarenkoGraph
from KnnLib.KleinbergGraph import KleinbergGraph

amount_of_close_friends = 2

if __name__ == "__main__":

    # graph = KleinbergGraph(Point)
    graph = PonomarenkoGraph(Point, amount_of_close_friends=5)

    nodes: list[Point] = []
    for i in range(1, 10):
        for j in range(1, 10):
            nodes.append(Point(i, j))

    # Ponomarenko model:
    graph.load_nodes(nodes, amount_of_queries=10)
    
    # Kleinberg model:
    # graph.load_nodes(nodes)

    print(graph)
    
    print(graph.multi_search(Point(5.5, 5.5), amount_of_queries=10))

    graph.show()



