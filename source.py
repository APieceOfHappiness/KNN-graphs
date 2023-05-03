from dataclasses import dataclass
from sortedcontainers import SortedSet
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


class Graph:
    __db: dict
    
    @property
    def size(this) -> int:
        return len(this.__db.keys())

    def __init__(this) -> None:
        this.__db = dict()
        this.__size = 0

    def find_local_min(this, target: Point) -> Point:  # TODO: improve
        min_ = float('inf')
        res_ = None
        for node in this.__db.keys():
            if d(target, node) < min_:
                min_ = d(target, node)
                res_ = node
            
            for friend in this.__db[node]:
                if d(target, friend) < min_:
                    min_ = d(target, friend)
                    res_ = friend
        return res_

    def multi_search(this, target: Point) -> Point:  # TODO: improve
        mins = set()
        new_element = this.find_local_min(target)
        if new_element is not None:
            mins.add(new_element)
        return mins

    def get_friends(this, p: Point) -> set:
        friends = this.__db.get(p)
        if friends is not None:
            return friends
        else:
            return set()
    
    def add_element(this, new_point: Point, amnt_of_close_frineds: int) -> None:
        if new_point in this.__db:
            return
        
        mins = this.multi_search(new_point)
        this.__db[new_point] = set()

        potential_friends = SortedSet(key=lambda x: d(x, new_point))
        for node in mins:
            potential_friends.add(node)
            potential_friends |= SortedSet(this.get_friends(node), key=lambda x: d(x, new_point))
        for i, node in enumerate(potential_friends):
            if i < amnt_of_close_frineds:
                this.__connect(node, new_point)
                print(node)
            else:
                break
    
    def __str__(this) -> str:
        st = ""
        st += "graph db {\n"
        
        for el in this.__db:
            st += "    " + str(el) + " -> "
            for friend in this.get_friends(el):
                st += str(friend) + " "
            st += "\n"

        st += "} size(" + str(this.size) + ")\n"
        return st
    
    
    def __connect(this, p1: Point, p2: Point) -> None:
        friends = this.__db.get(p1)
        friends.add(p2)

        friends = this.__db.get(p2)
        friends.add(p1)
    



if __name__ == "__main__":

    # db = dict()
    # db[Point(1, 1)] = set()
    # db[Point(1, 1)].add(Point(7, 1))
    # db[Point(7, 1)] = set()
    # db[Point(7, 1)].add(Point(1, 1))

    # db[Point(1, 1)].add(Point(8, 1))
    # db[Point(8, 1)] = set()
    # db[Point(8, 1)].add(Point(1, 1))

    # db[Point(8, 1)].add(Point(7, 4))
    # db[Point(7, 4)] = set()
    # db[Point(7, 4)].add(Point(8, 1))

    # db[Point(1, 1)].add(Point(5, -3))
    # db[Point(5, -3)] = set()
    # db[Point(5, -3)].add(Point(1, 1))

    graph = Graph()
    graph.add_element(Point(1, 1), 2)
    graph.add_element(Point(7, 1), 2)
    graph.add_element(Point(8, 2), 2)
    graph.add_element(Point(7, 4), 2)
    graph.add_element(Point(5, -3), 2)

    print(graph)

    print(graph.find_local_min(Point(5, -4)))
    print(Point(1,1).d(Point(5, -4)))
    print(graph.get_friends(Point(1, 1)))
    print(graph.add_element(Point(2, 2), 2))
    



