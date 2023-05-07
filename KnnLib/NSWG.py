from abc import ABC, abstractmethod

from dataclasses import dataclass
from typing import Callable, Type

from random import randint

import matplotlib.pyplot as plt
import networkx as nx



@dataclass(frozen=True)
class Object(ABC):
    @abstractmethod
    def dist(self, other: 'Object') -> float:  # maybe improve this
        pass

    @abstractmethod
    def __eq__(self, other: 'Object') -> bool:
        pass

class NSWG(ABC):
    _graph: nx.Graph 
    _obj_type: Type['Object']

    def __init__(self, obj_type: Type['Object']) -> None:
        self._graph = nx.Graph()
        self._obj_type = obj_type

    @property
    def size(self) -> int:
        return len(self._graph.nodes())
    
    def add_node(self, obj: Object) -> None:
        pass

    @abstractmethod
    def load_nodes(self, obj_list: list[Object]) -> None:
        pass

    def get_friends(self, el: Object) -> list[Object]:  # that is not quite list
        return self._graph.neighbors(el)

    def __find_local_min(self, target_node: Object, start_node: Object) -> Object:  # TODO: improve
        min_dist = start_node.dist(target_node)
        next_node = None
        current_node = start_node
        for friend_node in self.get_friends(current_node):
            if target_node.dist(friend_node) < min_dist:
                min_dist = target_node.dist(friend_node)
                next_node = friend_node
        if next_node is None:
            return current_node
        else:
            return self.__find_local_min(target_node, next_node)

    def multi_search(self, target: Object, amount_of_queries: int) -> Object:
        local_mins = set()
        for _ in range(amount_of_queries):
            if self.size != 0:
                random_node_idx = randint(0, self.size - 1)
                new_element = self.__find_local_min(target, list(self._graph._node)[random_node_idx])  # TODO: make an inheritence of Graph()
                local_mins.add(new_element)
        return local_mins
    
    def __str__(self) -> str:
        st = ""
        st += "graph db {\n"
        
        for el in self._graph:
            st += "    " + str(el) + " -> "
            for friend in self.get_friends(el):
                st += str(friend) + " "
            st += "\n"

        st += "} size(" + str(self.size) + ")\n"
        return st
    
    def show(self) -> None:
        nx.draw(self._graph, with_labels=True)
        plt.show()



