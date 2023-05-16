from NnLib.NSWG import Object, NSWG
from typing import Type

import random

class KleinbergGraph(NSWG):
    __redges_per_node: int

    def __init__(self, obj_type: Type['Object']) -> None:
        super().__init__(obj_type)
        self.__redges_per_node = 7

    def add_node(self, obj: Object) -> None:
        if not isinstance(obj, self._obj_type):
            raise ValueError("invalid class type")
        
        self._graph.add_node(obj)
        nodes: dict[int] = dict()
        for node in self._graph.nodes():
            if node == obj:
                continue
            nodes[node] = 1 / node.dist(obj) ** 2  #  CHANGEEEEE

        for m in range(self.__redges_per_node):
            if len(nodes) == 0:
                break

            rnode = random.choices(list(nodes.keys()), list(nodes.values()), k=1)[0]
            if not self._graph.has_edge(rnode, node):
                self._graph.add_edge(rnode, obj)
                self._sum_degree += 1

            del nodes[rnode]


    def load_nodes(self, obj_list: list[Object]) -> None:
        self._graph.add_nodes_from(obj_list)

        for node in obj_list:
            nodes: dict[int] = dict()
            for friend in obj_list:
                if node == friend:
                    continue
                nodes[friend] = 1 / node.dist(friend) ** 2      
 
            for m in range(self.__redges_per_node):
                if len(nodes) == 0:
                    break

                rnode = random.choices(list(nodes.keys()), list(nodes.values()), k=1)[0]
                if not self._graph.has_edge(rnode, node):
                    self._graph.add_edge(rnode, node)
                    self._sum_degree += 2

                del nodes[rnode]      

