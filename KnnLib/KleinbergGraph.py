from KnnLib.NSWG import Object, NSWG
from typing import Type

import random

class KleinbergGraph(NSWG):
    def __init__(self, obj_type: Type['Object']) -> None:
        super().__init__(obj_type)

    def add_node(self, obj: Object) -> None:
        if not isinstance(obj, self._obj_type):
            raise ValueError("invalid class type")
        
        self._graph.add_node(obj)
        for node in self._graph.nodes():
            if node == obj:
                continue
            comp_dist = 1 / (obj.dist(node) ** 2)
            if random.random() <= comp_dist:
                self._graph.add_edge(obj, node)

    def load_nodes(self, obj_list: list[Object], normalize=False) -> None:
        if normalize:
            pass  # TODO: want to investigate this
        for obj in obj_list:
            self.add_node(obj)
