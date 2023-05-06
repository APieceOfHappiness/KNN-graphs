from KnnLib.Point import Point
from KnnLib.PonomarenkoGraph import PonomarenkoGraph
from KnnLib.KleinbergGraph import KleinbergGraph

amount_of_close_friends = 2

if __name__ == "__main__":

    graph = KleinbergGraph(Point)
    # graph = PonomarenkoGraph(Point, 7)

    for i in range(1, 10):
        for j in range(1, 10):
            graph.add_node(Point(i, j))

    print(graph)
    print(graph.find_local_min(Point(5, -4)))
    
    graph.show()


    # graph = PonomarenkoGraph(Point, amount_of_close_friends)
    # graph.add_node(Point(1, 1))
    # graph.add_node(Point(7, 1))
    # graph.add_node(Point(8, 2))
    # graph.add_node(Point(7, 4))
    # graph.add_node(Point(5, -3))

    # print(graph)

    # print(graph.find_local_min(Point(5, -4)))
    # print(Point(1,1).dist(Point(5, -4)))
    # print(graph.get_friends(Point(1, 1)))
    # print(graph.add_node(Point(2, 2)))
    
    # graph.show()



