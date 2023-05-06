from KnnLib.NSWG import Object, NSWG
from sortedcontainers import SortedSet
from typing import Type

class PonomarenkoGraph(NSWG):
    __amount_of_close_friends: int

    def __init__(self, obj_type: Type['Object'], amount_of_close_friends: int) -> None:
        super().__init__(obj_type)
        self.__amount_of_close_friends = amount_of_close_friends

    def add_node(self, obj: Object) -> None:
        if not isinstance(obj, self._obj_type):
            raise ValueError("invalid class type")

        mins = self.multi_search(obj)
        self._graph.add_node(obj)

        potential_friends = SortedSet(key=lambda x: x.dist(obj))
        for node in mins:
            potential_friends.add(node)
            potential_friends |= SortedSet(self._graph.neighbors(node), key=lambda x: x.dist(obj))
        for i, node in enumerate(potential_friends):
            if i < self.__amount_of_close_friends:
                self._graph.add_edge(node, obj)
                print(node)
            else:
                break

    def load_nodes(self, obj_list: list[Object]) -> None:
        print('Loading...')
